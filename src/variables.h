// Define flags for motor
#define MOTOR_STOPPED 0
#define MOTOR_RUNNING 1

// Define commands
#define CLOSE    -1
#define STOP     -2
#define OPEN     -3
#define SET_MAX  -4
#define SET_MIN  -5

// Define connections to BTT TMC2209 V1.2 UART
#define EN_PIN           23 // Enable
#define STEP_PIN         19 // Steps
#define DIR_PIN          18 // Direction
#define SERIAL_PORT Serial2 // TMC2209 HardwareSerial port
#define LED_PIN           2 // LED tied to GPIO2 on HiLetGo board
#define R_SENSE       0.11f // Match to your driver, SilentStepStick series use 0.11
#define DRIVER_ADDR    0b00 // 0b00 is slave, since there're no other drivers

// Calulations to convert travel distance
const float gear_ratio = 5.18;  // Use 1 if stepper motor doesn't have a gearbox
const uint16_t microsteps = 8;
const int steps_per_rev = 200 * gear_ratio * microsteps;
int velocity = steps_per_rev;
int acceleration = steps_per_rev * 10;
int motor_flag = MOTOR_STOPPED;
uint32_t previous_position = 0;
bool set_max = false;
bool set_min = false;

// For WiFi
char ssid[] = "NalaSecretBase_2.4";  // Network SSID (name)
char pass[] = "2063832037s";         // Network password

// For MQTT
char mqtt_user[] = "mqtt-user";
char mqtt_pass[] = "jnkjnk37";
const char broker[] = "192.168.1.26"; // Address of the MQTT server
int        port     = 1883;
const char topic[]  = "/arduino/simple";
const char subtopic[] = "/arduino/receive";