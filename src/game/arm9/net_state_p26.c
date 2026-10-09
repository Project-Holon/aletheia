/*
 * file:     net_state_p26.c
 * unit:     yes
 * function: func_0203C238, func_0203C2B0
 * address:  0x0203C238
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
 */
struct NetState;
typedef signed char   s8;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int  u32;

extern void *func_0203D788(void);
extern void *func_0203D798(void);
extern void func_0203AD80(struct NetState *s, void *p, u16 v, int line);
extern void func_02037D78(void);
extern void func_020398B4(u32 a);
extern void func_02039834(u32 a);
extern u32 func_0203778C(u32 p);
void func_0203C238(s8 *p);
int func_0203C2B0(int a);
extern u8 *g_021469DC;


/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C238.c \
 *       --func func_0203C238 --addr 0x0203C238 --cc 1.1p1 --arm
 */
void func_0203C238(s8 *p)
{
    u8 *s = func_0203D788();
    u8 *q = func_0203D798();

    if ((*(u32 (**)(int, u32, u32))(*(u32 *)(s + 0x340) + 0x50))(p[0x48], q[0x60], 0) != 0)
        return;

    func_02037D78();
    func_020398B4((u32)s);
    func_02039834((u32)s);
    func_0203AD80((struct NetState *)g_021469DC, (void *)0x0203C0F4, 0, 0x5AC);
}


/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C2B0.c \
 *       --func func_0203C2B0 --addr 0x0203C2B0 --cc 1.1p1 --arm
 */
int func_0203C2B0(int a)
{
    if (a != -1) {
        if (func_0203778C((u32)a) == 0)
            return 0;
    }

    g_021469DC[0x48] = (u8)a;
    func_0203AD80((struct NetState *)g_021469DC, (void *)0x0203C238, 0, 0x5C4);
    return 1;
}
