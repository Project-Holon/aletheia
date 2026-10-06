/*
 * function: func_0203C494
 * address:  0x0203C494
 * packet:   pkt_0203C494
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469DC     0x021469DC  data
 *   func_0203C464  0x0203C464  arm
 *   func_0203C05C  0x0203C05C  arm
 *
 * The other half of the connect/disconnect pair whose partner is
 * src/matched/func_0203C554.c: it turns the state byte at +0x4B into the
 * vtable's +0x54 hook, then either starts the link layer or, when the +0x0C
 * hook reports a negative result, files line 0x655.
 *
 * `v` is materialised as 0 before the first call and raised to 1 by
 * `moveq` on the state byte's own compare, so the hook's first argument
 * shares a register with the loop's zero rather than being rematerialised.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C494.c \
 *       --func func_0203C494 --addr 0x0203C494 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u8 *g_021469DC;

extern void *func_0203D788(void);
extern int func_0203C464(int a0, int a1, int a2, int a3);
extern void func_0203C05C(void);
typedef unsigned short u16;
struct NetState;
extern void func_0203AD80(struct NetState *s, void *p, u16 v, int line);
extern void func_020394DC(u8 v);
extern void func_02037D78(void);
extern void func_020398B4(u32 a);
extern void func_02039834(u32 a);

void func_0203C494(u8 *p)
{
    u8 *s = func_0203D788();
    u32 v = 0;

    func_020394DC(0);

    if (p[0x4B] == 0)
        v = 1;

    if ((*(u32 (**)(u32, u32))(*(u32 *)(s + 0x340) + 0x54))(v, 0) != 0) {
        func_02037D78();
        func_020398B4((u32)s);
        func_02039834((u32)s);
        func_0203AD80((struct NetState *)g_021469DC, (void *)func_0203C464, 0, 0x64F);
    } else if ((*(int (**)(u32))(*(u32 *)(s + 0x340) + 0x0C))(0) < 0) {
        func_0203AD80((struct NetState *)g_021469DC, (void *)func_0203C05C, 0, 0x655);
    }
}
