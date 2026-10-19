#ifndef GAME_ARM9_GF_PANIC_H
#define GAME_ARM9_GF_PANIC_H

/* Public functions of gf_panic.c, prototypes copied from their definitions. */

void GF_PANIC_SetHandlers(u32 initFunc, u32 printFunc, u32 dieFunc);
void GF_PANIC_SetFailHook(u32 failHook);
void GF_PANIC_Fail(const char *file, u32 line, const char *expr);
void GF_PANIC_FailPrintf(const char *file, u32 line, const char *fmt, ...);
void GF_PANIC_Init(void);
void GF_PANIC_Print(char *text);
void GF_PANIC_Die(void);
void GF_PANIC_RegisterDefaultHandlers(void);

#endif
