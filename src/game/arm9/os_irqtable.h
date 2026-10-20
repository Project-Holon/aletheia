#ifndef GAME_ARM9_OS_IRQTABLE_H
#define GAME_ARM9_OS_IRQTABLE_H

/* Public functions of os_irqtable.c, prototypes copied from their definitions. */

void OSi_IrqCallback(int index);
void OSi_IrqDma0(void);
void OSi_IrqDma1(void);
void OSi_IrqDma2(void);
void OSi_IrqDma3(void);
void OSi_IrqTimer0(void);
void OSi_IrqTimer1(void);
void OSi_IrqTimer2(void);
void OSi_IrqTimer3(void);
void OSi_IrqNDma0(void);
void OSi_IrqNDma1(void);
void OSi_IrqNDma2(void);
void OSi_IrqNDma3(void);

#endif
