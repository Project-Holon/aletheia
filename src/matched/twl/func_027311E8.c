/*
 * function: MI_LockWramManager
 * address:  0x027311E8
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_LockByWord 0x02084C68 arm
 *   OS_GetLockID 0x02084EB8 arm
 */
typedef unsigned short u16;
typedef unsigned int u32;

extern void OS_LockByWord(u32, void *, void *);
extern u32 OS_GetLockID(void);

void MI_LockWramManager(u16 *p)
{
    *p = OS_GetLockID();
    OS_LockByWord(*p, (void *)0x02FFF680, 0);
}
