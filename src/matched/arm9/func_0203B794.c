/*
 * function: func_0203B794
 * address:  0x0203B794
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
 *   python tools/match.py one --src src/matched/func_0203B794.c \
 *       --func func_0203B794 --addr 0x0203B794 --cc 1.1p1 --arm
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
struct Entry;
extern struct Entry *func_020399A8(void);
extern u32 func_020399B8(u32 a);
extern u32 func_0203D650(void);

void func_0203B794(struct B794 *p)
{
    u8 *s = func_0203D798();

    if (func_020399B8((u32)func_020399A8()) == 0)
        return;

    if (p->unk_2C != 0) {
        p->unk_2C(func_0203D650());
        p->unk_2C = 0;
    }

    func_0203AD80((u32)g_021469DC, 0x0203C00C, 0, 0x325);
}
