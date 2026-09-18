/*
 * function: func_0203B868
 * address:  0x0203B868
 * packet:   pkt_0203B868
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469DC      0x021469DC  data
 *   func_0203D788   0x0203D788  arm
 *   func_0203D798   0x0203D798  arm
 *   func_02039ACC   0x02039ACC  arm
 *   func_0203DA4C   0x0203DA4C  arm
 *   func_0203D650   0x0203D650  arm
 *   func_0203AD80   0x0203AD80  arm
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B868.c \
 *       --func func_0203B868 --addr 0x0203B868 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct B868 {
    u8     pad_00[0x2C];
    void (*unk_2C)(u32);
};

extern u8 *g_021469DC;

extern void func_0203D798(void);
extern u8  *func_0203D788(void);
extern u32  func_02039ACC(void);
extern u32  func_0203DA4C(void);
extern u32  func_0203D650(void);
extern void func_0203AD80(u32 a, u32 b, u32 c, u32 d);

void func_0203B868(struct B868 *p)
{
    func_0203D798();

    if ((*(u32 (**)(void))(*(u32 *)(func_0203D788() + 0x340) + 0xA8))() != 1)
        return;
    if (func_02039ACC() == 0)
        return;

    if (func_0203DA4C() == 1) {
        func_0203AD80((u32)g_021469DC, 0x0203B7F8, 0, 0x354);
        return;
    }

    if (p->unk_2C != 0) {
        p->unk_2C(func_0203D650());
        p->unk_2C = 0;
    }

    func_0203AD80((u32)g_021469DC, 0x0203C00C, 0, 0x35B);
}
