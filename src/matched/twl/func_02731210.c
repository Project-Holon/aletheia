/*
 * function: MI_UnlockWramManager
 * address:  0x02731210
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_UnlockByWord 0x02084CEC arm
 *   OS_ReleaseLockID 0x02084F10 arm
 */
typedef unsigned int u32;

extern void OS_UnlockByWord(u32, void *, void *);
extern void OS_ReleaseLockID(u32);

void MI_UnlockWramManager(u32 id)
{
    OS_UnlockByWord(id, (void *)0x02FFF680, 0);
    OS_ReleaseLockID(id);
}
