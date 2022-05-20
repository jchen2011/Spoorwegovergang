const int N = 0;
const int O = 1;
const int Z = 2;
const int W = 3;

int laatsteRichting;

boolean treinGedetecteerd() {
  if (isClicked(W)) {
    laatsteRichting = W;
  } else if (isClicked(O)) {
    laatsteRichting = O;
  } else {
    return false;
  }
  return true;
}

boolean treinGedetecteerdOversteken() {
  if (getbutton_West_Click()) {
    laatsteRichting = W;
  } else if (getbutton_Oost_Click()) {
    laatsteRichting = O;
  } else {
    return false;
  }
  return true;
}

boolean treinGepasseerd() {
  return (isClicked(W) && laatsteRichting == O) || (isClicked(O) && laatsteRichting == W);
}

boolean ontruimingstijdVerlopen(unsigned long timer, unsigned long interval) {
  return timerIsPassed(timer, interval);
}

void controleerInput() {
  char input = serialRead();

  switch (input) {
    case 'R': 
      resetSlagboomTeller();
  }
}

int getN() {
  return N;
}

int getO() {
  return O;
}

int getZ() {
  return Z;
}

int getW() {
  return W;
}
