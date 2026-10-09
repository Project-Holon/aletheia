/*
 * file:     net_state_p15.c
 * unit:     yes
 * function: func_0203B0C4, func_0203B16C, func_0203B170, func_0203B1B0
 * address:  0x0203B0C4
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
 *   s_020A7BA8     0x020A7BA8  data
 *   s_020A7BC8     0x020A7BC8  data
 *   func_02034714  0x02034714  arm
 *   func_02082D44  0x02082D44  arm
 *   func_0203AD80  0x0203AD80  arm
 *   func_0203B084  0x0203B084  arm
 *   func_0203B038  0x0203B038  arm
 */
struct NetState;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02082D44(int a0, int a1, int a2);
extern void func_0203AD80(struct NetState *s, void *p, u16 v, int line);
extern void func_0203B084(void);
extern void func_0203B038(u8 *a0);
extern u32 func_02037928(u32 a0, u16 a1);
void func_0203B0C4(int a0, int a1);
void func_0203B16C(void);
void func_0203B170(void);
void func_0203B1B0(void);
extern void *g_021469DC;
extern char s_020A7BA8[];
extern char s_020A7BC8[];


void func_0203B0C4(int a0, int a1)
{
    if (((int)g_021469DC + 0x40) & 1) {
        func_02034714(s_020A7BA8, 395, s_020A7BC8);
    }
    if (a0 != 0) {
        func_02082D44(a0, (int)g_021469DC + 0x40, 6);
    }
    if (a1 != 0) {
        func_0203AD80((struct NetState *)g_021469DC, (void *)func_0203B084, 0, 400);
    } else {
        func_0203AD80((struct NetState *)g_021469DC, (void *)func_0203B038, 0, 403);
    }
}


void func_0203B16C(void)
{
}



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
