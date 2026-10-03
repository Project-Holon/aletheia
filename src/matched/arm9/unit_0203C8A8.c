/*
 * unit:     yes
 * function: func_0203C8A8
 * address:  0x0203C8A8
 * packet:   pkt_0203C65C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469DC     0x021469DC  data
 *
 * 140 bytes, three functions.  The middle one, 0x0203C8E8, is a 16-byte leaf
 * that saves nothing and so carries no label in the generated listing; the
 * per-function file for 0x0203C8A8 therefore reported an `EXACT*`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0203C8A8.c \
 *       --addr 0x0203C8A8 --arm --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u8 *g_021469DC;

extern void *func_0203D788(void);
extern void func_0203C864(void);
extern int  func_020392EC(void);
extern void *func_0203D798(void);
extern void func_0203516C(u32 a);
extern void func_0203AD80(u32 a, u32 b, u32 c, u32 d);

void func_0203C8A8(void)
{
    if (func_020392EC() != 0)
        return;

    func_0203D798();
    func_0203516C(1);
    func_0203AD80((u32)g_021469DC, 0x0203C864, 0, 0x760);
}

void func_0203C8E8(u8 v)
{
    if (g_021469DC != 0)
        g_021469DC[0x4F] = v;
}

void func_0203C900(u8 v)
{
    u8 *s = func_0203D788();

    if (g_021469DC != 0)
        g_021469DC[0x50] = v;

    (*(void (**)(u32))(*(u32 *)(s + 0x340) + 0x8C))(v);
}
