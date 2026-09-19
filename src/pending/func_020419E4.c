/*
 * function: func_020419E4
 * address:  0x020419E4
 * packet:   pkt_020416D4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 * Both callees (0x02041B94, 792 bytes, pkt_02041B94 claimed by wave3-2, and
 * 0x02041A1C, 332 bytes, the same packet as this row) have exactly one witness
 * image wide and it is the branch inside this range, so no cut of a
 * one-function file can free them; either one being matched to EXACT closes
 * this file.  The global resolves on `literal`.
 *
 * symbols:
 *   g_02146A44      0x02146A44  data
 *   func_02041B94   0x02041B94  arm
 *   func_02041A1C   0x02041A1C  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx {
    u8  pad_00[4];
    u16 unk_04;
    u16 unk_06;
};

extern struct Ctx *g_02146A44;

extern void func_02041B94(void);
extern void func_02041A1C(void);

void func_020419E4(void)
{
    if (g_02146A44 == 0)
        return;

    func_02041B94();
    func_02041A1C();
    g_02146A44->unk_04 = 0;
    g_02146A44->unk_06 = 0;
}
