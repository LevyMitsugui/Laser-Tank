
//Class to control two motors using a driver
class MotorController {
  public:
    /**
     * @brief Construct a new Motor Controller object
     * 
     * @param IN1 Pin connected on input port 1 from the driver
     * @param IN2 Pin connected on input port 2 from the driver
     * @param IN3 Pin connected on input port 3 from the driver
     * @param IN4 Pin connected on input port 4 from the driver
     */
    MotorController(int IN1, int IN2, int IN3, int IN4);
    
    /**
     * @brief Starts Motors, i.e couples pins as outputs
     * 
     */
    void begin();

    /**
     * @brief Set the Motor Speed of a singular motor
     * 
     * @param speed Speed from -100 to 100
     * @param motor Wich motor (1 or 2) to set the speed
     */
    void setMotorSpeed(float speed, int motor);

    /**
     * @brief Set the Motor Speed of both motors
     * 
     * @param speed Speed from -100 to 100
     */
    void setMotors(float speed);

    /**
     * @brief Locks motors still
     * 
     */
    void stopMotors();

    /**
     * @brief Turn motors off, does not lock them, allowing to coast
     * 
     */
    void coastMotors();

    /**
     * @brief Returns Last speed setted to a given motor
     * 
     * @param Motor Wich motor to return its speed
     * @return int 
     */
    int getSpeed(int Motor);

    /**
     * @brief Test both motor activation with a routine
     * 
     */
    void testMotors();

  private:
    // pin nums
    int EN_A;
    int IN_1;
    int IN_2;
    int IN_3;
    int IN_4;
    int EN_B;

    // Speed Values
    float motor1Speed;
    float motor2Speed;
};