/*
 * function: func_0204BFF4
 * address:  0x0204BFF4
 * packet:   pkt_0204BE84
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * symbols:
 *   g_02146A74     0x02146A74  data
 *   func_0204BF40  0x0204BF40  arm
 *
 * Same forward as func_0204BFC4, but aimed at the sub-command block at
 * +0x20 of the manager, whose id and payload sit at +0xf2 / +0xf4.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Mgr {
    u8  pad_000[0xf0];
    u16 unk_f0;
    u16 unk_f2;
    u32 unk_f4;
};

extern struct Mgr *g_02146A74;

extern void func_0204BF40(void *block, u32 a0, u32 a1, u32 id, u32 payload);

void func_0204BFF4(u32 a0, u32 a1)
{
    func_0204BF40((u8 *)g_02146A74 + 0x20, a0, a1,
                  g_02146A74->unk_f2, g_02146A74->unk_f4);
}
