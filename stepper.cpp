#include "config.h"
#include "stepper.h"


Stepper::Stepper)
{
}

void Stepper::init(int motorPin1, int motorPin2, int motorPin3, int motorPin4)
{
#ifdef DEBUG
  Serial.begin(BAUD_DEFAULT);
#endif

  m_iMotorPin1 = motorPin1;  // Blue   - In 1
  m_iMotorPin2 = motorPin2;  // Pink   - In 2
  m_iMotorPin3 = motorPin3; // Yellow - In 3
  m_iMotorPin4 = motorPin4; // Orange - In 4
  // Red    - pin 5 (VCC)
  
  m_iSteps =  1000;

  m_lOpenTime = 4000;
  m_lCloseTime = 4000;
  m_lDelay = 15;

  m_lCurrentDelay = 0;

  m_iState = 0;
  m_iTargetPosMax = 180;
  int m_iTargetPosMin = 0;

  m_iCurrentPos = 0;

  m_lPreviousMillis = 0;
  m_lPreviousMoveMillis = 0;

  pinMode(m_iMotorPin1, OUTPUT);
  pinMode(m_iMotorPin2, OUTPUT);
  pinMode(m_iMotorPin3, OUTPUT);
  pinMode(m_iMotorPin4, OUTPUT);
#ifdef DEBUG
  Serial.println("Stepper::init()");
#endif

}

void Stepper::update()
{
  
  unsigned long currentMillis = millis();
  if ((currentMillis - m_lPreviousMoveMillis) >= m_lCurrentDelay)
  {
    if (m_lCurrentDelay == m_lOpenTime || m_lCurrentDelay == m_lCloseTime)
    {
      m_lCurrentDelay = m_lDelay; // after long break, back to normal;
    }

    if (m_iState == 0)
    {
      rechtsrum(m_iSteps);
    }
    else
    {
      linksrum(-m_iSteps);
    }

    if (m_iState == 0)
    {
      m_iState = 1;
      m_lCurrentDelay = m_lOpenTime; // take a longer break
    }
    else if (m_iState == 1)
    {
      m_iState = 0;
      m_lCurrentDelay = m_lCloseTime; // take a longer break
    }
#ifdef DEBUG
    Serial.print("Stepper: ");
    Serial.print(m_iState);
    Serial.print(": ");
    //Serial.print(m_iCurrentPos);
    Serial.print(" --- ");
    Serial.print(m_lCurrentDelay);
    Serial.println("");
#endif
    m_lPreviousMoveMillis = currentMillis;  // Remember the time
  }
}

void Stepper::rechtsrum(unsigned int motorSpeed)
{
  // 1
  move(HIGH, LOW, LOW, LOW);

  // 2
  move(HIGH, HIGH, LOW, LOW);

  // 3
  move(LOW, HIGH, LOW, LOW);

  // 4
  move(LOW, HIGH, HIGH, LOW);

  // 5
  move(LOW, LOW, HIGH, LOW);

  // 6
  move(LOW, LOW, HIGH, HIGH);

  // 7
  move(LOW, LOW, LOW, HIGH);

  // 8
  move(HIGH, LOW, LOW, HIGH);
}

void Fallgatter::linksrum(unsigned int motorSpeed)
{
  // 1
  move(HIGH, LOW, LOW, LOW);

  // 2
  move(HIGH, HIGH, LOW, LOW);

  // 3
  move(LOW, HIGH, LOW, LOW);

  // 4
  move(LOW, HIGH, HIGH, LOW);

  // 5
  move(LOW, LOW, HIGH, LOW);

  // 6
  move(LOW, LOW, HIGH, HIGH);

  // 7
  move(LOW, LOW, LOW, HIGH);

  // 8
  move(HIGH, LOW, LOW, HIGH);
}

void Stepper::stop()
{ 
  digitalWrite(m_iMotorPin4, LOW);
  digitalWrite(m_iMotorPin3, LOW);
  digitalWrite(m_iMotorPin2, LOW);
  digitalWrite(m_iMotorPin1, LOW);
}

void Stepper::step()
{
  int steps_left = abs(steps_to_move);  // how many steps to take

  // determine direction based on whether steps_to_mode is + or -:
  if (steps_to_move > 0) { this->direction = 1; }
  if (steps_to_move < 0) { this->direction = 0; }
  
  while (steps_left > 0)
  {
    unsigned long now = micros();
    // move only if the appropriate delay has passed:
    if (now - this->last_step_time >= this->step_delay)
    {
      // get the timeStamp of when you stepped:
      this->last_step_time = now;
      // increment or decrement the step number,
      // depending on direction:
      if (this->direction == 1)
      {
        this->step_number++;
        if (this->step_number == this->number_of_steps) {
          this->step_number = 0;
        }
      }
      else
      {
        if (this->step_number == 0) {
          this->step_number = this->number_of_steps;
        }
        this->step_number--;
      }
      // decrement the steps left:
      steps_left--;
      // step the motor to step number 0, 1, ..., {3 or 10}
      if (this->pin_count == 5)
        stepMotor(this->step_number % 10);
      else
        stepMotor(this->step_number % 4);
    }
  }
}

void Stepper::move(int state1, int state2, int state3, int state4) 
{
	unsigned long currentMillis = millis();

	if (currentMillis - m_lPreviousMoveMillis2 >= motorSpeed) {
		m_lPreviousMoveMillis2 = currentMillis;

		digitalWrite(m_iMotorPin1, state1);
		digitalWrite(m_iMotorPin2, state2);
		digitalWrite(m_iMotorPin3, state3);
		digitalWrite(m_iMotorPin4, state4);
	}
}