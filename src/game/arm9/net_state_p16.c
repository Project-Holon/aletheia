/*
 * file:     net_state_p16.c
 * unit:     yes
 * function: func_0203B170, func_0203B1B0
 * address:  0x0203B170
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021469DC     0x021469DC  data
 *   func_0203AD80  0x0203AD80  arm
 */
struct NetState;
typedef unsigned int u32;

typedef unsigned short u16;

extern u32 func_02037928(u32 a0, u16 a1);
extern void func_0203AD80(struct NetState *s, void *p, u16 v, int line);
void func_0203B170(void);
void func_0203B1B0(void);
extern void *g_021469DC;


/*
 * The same 0x200-byte channel-1 start as func_0203B084 with no context
 * refresh, reporting at line 0x1AE (430).  0x1AE is not ARM-encodable, so the
 * constant is materialised off the 0x200 argument register as
 * `sub r3, r4, #0x52`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B170.c \
 *       --func func_0203B170 --addr 0x0203B170 --cc 1.1p1 --arm
 */
void func_0203B170(void)
{
    if (func_02037928(1, 0x200) != 0)
        func_0203AD80((struct NetState *)((int)*(int *)((char *)(0x21469DC))), (void *)0x203B16C, 0, 0x1AE);
}


/*
 * Tail-call wrapper over func_0203AD80 (the object at 0x021469DC, the
 * callback func_0203B170, 0, 0x1BC).  An unlabelled ARM leaf, filed as the
 * witness chain for func_0203D010 (state 10 of func_0203DC70).
 */
void func_0203B1B0(void)
{
    func_0203AD80(g_021469DC, func_0203B170, 0, 0x1BC);
}
