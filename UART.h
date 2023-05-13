//UART0
void UART0_Init(void);

char UART0_RecieveChar (void);
void UART0_TransmitChar (char data);
void UART0_TransmitString(char *str);
void UART0_RecieveString(char *str, char stopCh);

//UART 5
void UART5_Init(void);

char UART5_RecieveChar (void);
void UART5_TransmitChar (char data);
void UART5_TransmitString(char *str);
void UART5_ReceiveString(char *str, char stopCh);
