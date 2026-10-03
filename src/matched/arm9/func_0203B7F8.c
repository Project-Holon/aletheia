/*
 * function: func_0203B7F8
 * address:  0x0203B7F8
 * packet:   pkt_0203B6EC
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
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B7F8.c \
 *       --func func_0203B7F8 --addr 0x0203B7F8 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern u8 *g_021469DC;

struct B794 {
    u8     pad_00[0x2C];
    void (*unk_2C)(u32);
};

extern void *func_0203D798(void);
extern void func_0203AD80(u32 a, u32 b, u32 c, u32 d);
extern u32 func_0203996C(u32 a);
extern u32 func_020399A8(u32 a);
extern u32 func_020399EC(u32 a);
extern u16 func_02039338(void);
extern u32 func_0203D650(void);

void func_0203B7F8(struct B794 *p)
{
    func_0203D798();

    if ((int)func_020399EC(func_020399A8(func_0203996C(0xFF))) < 2)
        return;

    func_02039338();

    if (p->unk_2C != 0) {
        p->unk_2C(func_0203D650());
        p->unk_2C = 0;
    }

    func_0203AD80((u32)g_021469DC, 0x0203C00C, 0, 0x33F);
}
