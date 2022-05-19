const int NOORD = A1;
const int OOST = A3;
const int ZUID = A2;
const int WEST = A0;

int knoppen[] = {NOORD, OOST, ZUID, WEST};
const int AANTAL_BUTTONS = 4;

const int BUTTON_STATE_NOORD_RELEASED = 0;
const int BUTTON_STATE_NOORD_CHECK_PRESSED = 1;
const int BUTTON_STATE_NOORD_PRESSED = 2;
const int BUTTON_STATE_NOORD_CHECK_RELEASED = 3;

const int BUTTON_STATE_OOST_RELEASED = 4;
const int BUTTON_STATE_OOST_CHECK_PRESSED = 5;
const int BUTTON_STATE_OOST_PRESSED = 6;
const int BUTTON_STATE_OOST_CHECK_RELEASED = 7;

const int BUTTON_STATE_ZUID_RELEASED = 8;
const int BUTTON_STATE_ZUID_CHECK_PRESSED = 9;
const int BUTTON_STATE_ZUID_PRESSED = 10;
const int BUTTON_STATE_ZUID_CHECK_RELEASED = 11;

const int BUTTON_STATE_WEST_RELEASED = 12;
const int BUTTON_STATE_WEST_CHECK_PRESSED = 13;
const int BUTTON_STATE_WEST_PRESSED = 14;
const int BUTTON_STATE_WEST_CHECK_RELEASED = 15;

// Current state
int button_State_Noord;
int button_State_Oost;
int button_State_Zuid;
int button_State_West;

// Timer variables
const int BUTTON_INTERVAL = 10;
unsigned long button_Previous;

// Click variable
boolean button_Noord_Click;
boolean button_Oost_Click;
boolean button_Zuid_Click;
boolean button_West_Click;

void buttonSetup() {
  for (int i = 0; i < AANTAL_BUTTONS; i++) {
    pinMode(knoppen[i], INPUT);
  }
  button_Noord_Click = false;
  button_Oost_Click = false;
  button_Zuid_Click = false;
  button_West_Click = false;

  button_State_Noord = BUTTON_STATE_NOORD_RELEASED;
  button_State_Oost = BUTTON_STATE_OOST_RELEASED;
  button_State_Zuid = BUTTON_STATE_ZUID_RELEASED;
  button_State_West = BUTTON_STATE_WEST_RELEASED;
}

void buttonLoop() {
  switch(button_State_Noord) {
    case BUTTON_STATE_NOORD_RELEASED:
      button_Noord_Released_Do();
      if(buttonHardwareDown(N)) {
        button_Noord_Released_Exit();
        button_State_Noord = BUTTON_STATE_NOORD_CHECK_PRESSED;
        button_Noord_Check_Pressed_Entry();
      }
      break;
    case BUTTON_STATE_NOORD_CHECK_PRESSED:
      button_Noord_Check_Pressed_Do();
      if (buttonHardwareUp(N)) {
        button_Noord_Check_Pressed_Exit();
        button_State_Noord = BUTTON_STATE_NOORD_RELEASED;
        button_Noord_Released_Entry();
      } else if ((buttonHardwareDown(N)) && (millis() - BUTTON_INTERVAL >= button_Previous)) {
        // TODO: button ingedrukt en nu
        button_Noord_Check_Pressed_Exit();
        button_State_Noord = BUTTON_STATE_NOORD_PRESSED;
        button_Noord_Pressed_Entry();
      }
      break;
    case BUTTON_STATE_NOORD_PRESSED:
      button_Noord_Pressed_Do();
      if (buttonHardwareUp(N)) {
        button_Noord_Pressed_Exit();
        button_State_Noord = BUTTON_STATE_NOORD_CHECK_RELEASED;
        button_Noord_Check_Released_Entry();
      }
      break;
    case BUTTON_STATE_NOORD_CHECK_RELEASED:
      button_Noord_Check_Released_Do();
      if (buttonHardwareDown(N)) {
        button_Noord_Check_Released_Exit();
        button_State_Noord = BUTTON_STATE_NOORD_PRESSED;
        button_Noord_Pressed_Entry();
      } else if ((buttonHardwareUp(N)) && (millis() - BUTTON_INTERVAL >= button_Previous)) {
        button_Noord_Check_Released_Exit();
        button_State_Noord = BUTTON_STATE_NOORD_RELEASED;
        button_Noord_Click = true;
        button_Noord_Released_Entry();
      }
      break;  
  }
  switch(button_State_Oost) {
    case BUTTON_STATE_OOST_RELEASED:
      button_Oost_Released_Do();
      if (buttonHardwareDown(O)) {
        button_Oost_Released_Exit();
        button_State_Oost = BUTTON_STATE_OOST_CHECK_PRESSED;
        button_Oost_Check_Pressed_Entry();
      }
      break;
    case BUTTON_STATE_OOST_CHECK_PRESSED:
    button_Oost_Check_Pressed_Do();
    if (buttonHardwareUp(O)) {
      button_Oost_Check_Pressed_Exit();
      button_State_Oost = BUTTON_STATE_OOST_RELEASED;
      button_Oost_Released_Entry();
    } else if ((buttonHardwareDown(O)) && (millis() - BUTTON_INTERVAL >= button_Previous)) {
      button_Oost_Check_Pressed_Exit();
      button_State_Oost = BUTTON_STATE_OOST_PRESSED;
      button_Oost_Pressed_Entry();
    }
      break;
    case BUTTON_STATE_OOST_PRESSED:
      button_Oost_Pressed_Do();
      if (buttonHardwareUp(O)) {
        button_Oost_Pressed_Exit();
        button_State_Oost = BUTTON_STATE_OOST_CHECK_RELEASED;
        button_Oost_Check_Released_Entry();
      }
      break;
    case BUTTON_STATE_OOST_CHECK_RELEASED:
      button_Oost_Check_Released_Do();
      if (buttonHardwareDown(O)) {
        button_Oost_Check_Released_Exit();
        button_State_Oost = BUTTON_STATE_OOST_PRESSED;
        button_Oost_Check_Released_Entry();
      } else if ((buttonHardwareUp(O)) && (millis() - BUTTON_INTERVAL >= button_Previous)) {
        button_Oost_Check_Released_Exit();
        button_State_Oost = BUTTON_STATE_OOST_RELEASED;
        button_Oost_Click = true;
        button_Oost_Released_Entry();
      }
      break; 
  }
  switch(button_State_Zuid) {
    case BUTTON_STATE_ZUID_RELEASED:
      button_Zuid_Released_Do();
      if (buttonHardwareDown(Z)) {
        button_Zuid_Released_Exit();
        button_State_Zuid = BUTTON_STATE_ZUID_CHECK_PRESSED;
        button_Zuid_Check_Pressed_Entry();
      }
      break;
    case BUTTON_STATE_ZUID_CHECK_PRESSED:
      button_Zuid_Check_Pressed_Do();
      if (buttonHardwareUp(Z)) {
        button_Zuid_Check_Pressed_Exit();
        button_State_Zuid = BUTTON_STATE_ZUID_RELEASED;
        button_Zuid_Released_Entry();
      } else if ((buttonHardwareDown(Z)) && (millis() - BUTTON_INTERVAL >= button_Previous)) {
        button_Zuid_Check_Pressed_Exit();
        button_State_Zuid = BUTTON_STATE_ZUID_PRESSED;
        button_Zuid_Pressed_Entry();
      }
      break;
    case BUTTON_STATE_ZUID_PRESSED:
      button_Zuid_Pressed_Do();
      if (buttonHardwareUp(Z)) {
        button_Zuid_Pressed_Exit();
        button_State_Zuid = BUTTON_STATE_ZUID_CHECK_RELEASED;
        button_Zuid_Check_Released_Entry();
      }
      break;
    case BUTTON_STATE_ZUID_CHECK_RELEASED:
      button_Zuid_Check_Released_Do();
      if (buttonHardwareDown(Z)) {
        button_Zuid_Check_Released_Exit();
        button_State_Zuid = BUTTON_STATE_ZUID_PRESSED;
        button_Zuid_Pressed_Entry();
      } else if ((buttonHardwareUp(Z)) && (millis() - BUTTON_INTERVAL >= button_Previous)) {
        button_Zuid_Check_Released_Exit();
        button_State_Zuid = BUTTON_STATE_ZUID_RELEASED;
        button_Zuid_Click = true;
        button_Zuid_Released_Entry();
      }
      break; 
  }
  switch(button_State_West) {
    case BUTTON_STATE_WEST_RELEASED:
      button_West_Released_Do();
      if (buttonHardwareDown(W)) {
        button_West_Released_Exit();
        button_State_West = BUTTON_STATE_WEST_CHECK_PRESSED;
        button_West_Check_Pressed_Entry();
      }
      break;
    case BUTTON_STATE_WEST_CHECK_PRESSED:
      button_West_Check_Pressed_Do();
      if (buttonHardwareUp(W)) {
        button_West_Check_Pressed_Exit();
        button_State_West = BUTTON_STATE_WEST_RELEASED;
        button_West_Released_Entry();
      } else if ((buttonHardwareDown(W)) && (millis() - BUTTON_INTERVAL >= button_Previous)) {
        button_West_Check_Pressed_Exit();
        button_State_West = BUTTON_STATE_WEST_PRESSED;
        button_West_Pressed_Entry();
      }
      break;
    case BUTTON_STATE_WEST_PRESSED:
      button_West_Check_Released_Do();
      if (buttonHardwareUp(W)) {
        button_West_Released_Exit();
        button_State_West = BUTTON_STATE_WEST_CHECK_RELEASED;
        button_West_Check_Released_Entry();
      }
      break;
    case BUTTON_STATE_WEST_CHECK_RELEASED:
      button_West_Check_Released_Do();
      if (buttonHardwareDown(W)) {
        button_West_Check_Released_Exit();
        button_State_West = BUTTON_STATE_WEST_PRESSED;
        button_West_Pressed_Entry();
      } else if ((buttonHardwareUp(W)) && (millis() - BUTTON_INTERVAL >= button_Previous)) {
        button_West_Check_Released_Exit();
        button_State_West = BUTTON_STATE_WEST_RELEASED;
        button_West_Click = true;
        button_West_Released_Entry();
      }
      break; 
  }
}


boolean isClicked(int input) {
  switch (input) {
    case 0:
      if (button_Noord_Click) {
        button_Noord_Click = false;
        return true;
      }
      return false;
    case 1:
      if (button_Oost_Click) {
        button_Oost_Click = false;
        return true;
      }
      return false;
    case 2:
      if (button_Zuid_Click) {
        button_Zuid_Click = false;
        return true;
      }
      return false;
    case 3:
      if (button_West_Click) {
        button_West_Click = false;
        return true;
      }
      return false;
  }

}

// --- BUTTON_STATE_NOORD_RELEASED -----------
void button_Noord_Released_Entry() {
// <nothing>
}
void button_Noord_Released_Do() {
// <nothing>
}

void button_Noord_Released_Exit() {
// <nothing>
}
// --- BUTTON_STATE_NOORD_CHECK_PRESSED -----------
void button_Noord_Check_Pressed_Entry() {
button_Previous = millis();
}
void button_Noord_Check_Pressed_Do() {
// <nothing>
}
void button_Noord_Check_Pressed_Exit() {
// <nothing>
}
// --- BUTTON_STATE_NOORD_PRESSED -----------
void button_Noord_Pressed_Entry() {
// <nothing>
}
void button_Noord_Pressed_Do() {
// <nothing>
}
void button_Noord_Pressed_Exit() {
// <nothing>
}
// --- BUTTON_STATE_NOORD_CHECK_RELEASED -----------
void button_Noord_Check_Released_Entry() {
button_Previous = millis();
}
void button_Noord_Check_Released_Do() {
// <nothing>
}
void button_Noord_Check_Released_Exit() {
// <nothing>
}

// --- BUTTON_STATE_OOST_RELEASED -----------
void button_Oost_Released_Entry() {
// <nothing>
}
void button_Oost_Released_Do() {
// <nothing>
}

void button_Oost_Released_Exit() {
// <nothing>
}
// --- BUTTON_STATE_OOST_CHECK_PRESSED -----------
void button_Oost_Check_Pressed_Entry() {
button_Previous = millis();
}
void button_Oost_Check_Pressed_Do() {
// <nothing>
}
void button_Oost_Check_Pressed_Exit() {
// <nothing>
}
// --- BUTTON_STATE_OOST_PRESSED -----------
void button_Oost_Pressed_Entry() {
// <nothing>
}
void button_Oost_Pressed_Do() {
// <nothing>
}
void button_Oost_Pressed_Exit() {
// <nothing>
}
// --- BUTTON_STATE_OOST_CHECK_RELEASED -----------
void button_Oost_Check_Released_Entry() {
button_Previous = millis();
}
void button_Oost_Check_Released_Do() {
// <nothing>
}
void button_Oost_Check_Released_Exit() {
// <nothing>
}


// --- BUTTON_STATE_ZUID_RELEASED -----------
void button_Zuid_Released_Entry() {
// <nothing>
}
void button_Zuid_Released_Do() {
// <nothing>
}

void button_Zuid_Released_Exit() {
// <nothing>
}
// --- BUTTON_STATE_ZUID_CHECK_PRESSED -----------
void button_Zuid_Check_Pressed_Entry() {
button_Previous = millis();
}
void button_Zuid_Check_Pressed_Do() {
// <nothing>
}
void button_Zuid_Check_Pressed_Exit() {
// <nothing>
}
// --- BUTTON_STATE_ZUID_PRESSED -----------
void button_Zuid_Pressed_Entry() {
// <nothing>
}
void button_Zuid_Pressed_Do() {
// <nothing>
}
void button_Zuid_Pressed_Exit() {
// <nothing>
}
// --- BUTTON_STATE_ZUID_CHECK_RELEASED -----------
void button_Zuid_Check_Released_Entry() {
button_Previous = millis();
}
void button_Zuid_Check_Released_Do() {
// <nothing>
}
void button_Zuid_Check_Released_Exit() {
// <nothing>
}


// --- BUTTON_STATE_WEST_RELEASED -----------
void button_West_Released_Entry() {
// <nothing>
}
void button_West_Released_Do() {
// <nothing>
}

void button_West_Released_Exit() {
// <nothing>
}
// --- BUTTON_STATE_WEST_CHECK_PRESSED -----------
void button_West_Check_Pressed_Entry() {
button_Previous = millis();
}
void button_West_Check_Pressed_Do() {
// <nothing>
}
void button_West_Check_Pressed_Exit() {
// <nothing>
}

// --- BUTTON_STATE_WEST_PRESSED -----------
void button_West_Pressed_Entry() {
// <nothing>
}
void button_West_Pressed_Do() {
// <nothing>
}
void button_West_Pressed_Exit() {
// <nothing>
}

// --- BUTTON_STATE_WEST_CHECK_RELEASED -----------
void button_West_Check_Released_Entry() {
button_Previous = millis();
}
void button_West_Check_Released_Do() {
// <nothing>
}
void button_West_Check_Released_Exit() {
// <nothing>
}

boolean buttonHardwareDown(int buttonPin) {
  return (digitalRead(knoppen[buttonPin]) == LOW);
}

boolean buttonHardwareUp(int buttonPin) {
  return !buttonHardwareDown(buttonPin);
}

boolean getbutton_West_Click() {
  return button_West_Click;
}

boolean getbutton_Oost_Click() {
  return button_Oost_Click;
}
