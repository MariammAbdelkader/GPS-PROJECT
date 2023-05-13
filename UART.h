//UART0
void UART0_Init(void);

char UART0_RecieveChar (void);
void UART0_TransmitChar (char data);
void UART0_TransmitString(char *str);
void UART0_RecieveString(char *str, char stopCh);
