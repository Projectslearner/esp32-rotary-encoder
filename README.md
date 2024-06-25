# ESP32 Rotary Encoder Project

### Project Overview
The ESP32 Rotary Encoder project demonstrates how to interface a rotary encoder with an ESP32 microcontroller to detect rotational movement and button presses. Rotary encoders are commonly used in applications requiring precise control over rotation and switch events, such as volume control, menu navigation, and parameter adjustment.

### Components Needed
- **ESP32 Microcontroller**: The main controller that processes encoder signals.
- **Rotary Encoder**: A rotary input device that converts rotational movement into electrical signals.
- **Jumper Wires**: Connect the rotary encoder to the ESP32.
- **Breadboard**: Optional, for organizing the circuit connections.

### Block Diagram

### Circuit Setup
1. **Connecting the Rotary Encoder to ESP32:**
   - **CLK Pin (CLK_PIN)**: Connect the CLK (Clock) pin of the rotary encoder to GPIO 23 on the ESP32.
   - **DT Pin (DT_PIN)**: Connect the DT (Data) pin of the rotary encoder to GPIO 22 on the ESP32.
   - **SW Pin (SW_PIN)**: Connect the SW (Switch) pin of the rotary encoder to GPIO 21 on the ESP32.
   - **Optional**: Connect GND and VCC pins of the rotary encoder to suitable power and ground sources.

### Instructions
1. **Setup:**
   - Initialize serial communication for debugging purposes using `Serial.begin(9600)`.
   - Configure the CLK, DT, and SW pins as inputs with internal pull-up resistors using `pinMode()`.

2. **Operation:**
   - **Rotational Movement Detection:**
     - Use an interrupt to detect changes in the CLK pin state (`attachInterrupt()`).
     - Implement an interrupt service routine (`handleEncoder()`) to update the encoder position based on changes in the DT pin state.
     - Print the current encoder position to the Serial Monitor when it changes.

   - **Button Press Detection (Optional):**
     - Poll the state of the SW pin using `digitalRead()` to detect button presses.
     - Print a message to the Serial Monitor when the button is pressed.

3. **Considerations:**
   - **Debounce:** Implement debounce techniques (e.g., software debouncing or adding delay) to handle switch bouncing.
   - **Encoder Resolution:** Adjust software handling based on the encoder's resolution and your application requirements.

### Applications
- **Volume Control:** Adjust audio volume levels smoothly using rotary movement.
- **Menu Navigation:** Scroll through menus or options in embedded systems.
- **Parameter Adjustment:** Fine-tune parameters in various applications, such as robotics and instrumentation.

### Useful Links
🌐 [ProjectsLearner - ESP32 Rotary Encoder](https://projectslearner.com/learn/esp32-rotary-encoder)  
📧 [Email](mailto:projectslearner@gmail.com)  
📸 [Instagram](https://www.instagram.com/projectslearner/)  
📘 [Facebook](https://www.facebook.com/projectslearner)  
▶️ [YouTube](https://www.youtube.com/@ProjectsLearner)  
📘 [LinkedIn](https://www.linkedin.com/in/projectslearner)

Created with ❤️ by ProjectsLearner
