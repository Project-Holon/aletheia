#ifndef GAME_ARM9_OS_TERMINATE_PROCESSOR_H
#define GAME_ARM9_OS_TERMINATE_PROCESSOR_H

/* Public functions of os_terminate_processor.c, prototypes copied from their definitions. */

void OS_Terminate(void);
void OSi_DisableInterruptsAndHalt(void);
void OS_Halt(void);

#endif
