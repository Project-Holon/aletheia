/*
 * function: func_021DDFBC
 * address:  0x021DDFBC
 * packet:   pkt_021DDFBC
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02182AC0   0x02182AC0  arm  ov009
 *   func_021DDBE4   0x021DDBE4  arm  ov175
 *   g_021E3A8C      0x021E3A8C  data
 *   g_021E3B4C      0x021E3B4C  data
 *
 * Forwarder: registers the two descriptor tables with the ov009 helper
 * using the +8 block's first word and the object's +0x18 cursor, then
 * hands the object and the block's next two words to func_021DDBE4.
 */

typedef unsigned int u32;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
} Blk;

extern void func_02182AC0(u32 a, u32 b, u32 c, u32 d);
extern void func_021DDBE4(u32 a, u32 b, u32 c);
extern u32 g_021E3A8C[];
extern u32 g_021E3B4C[];

u32 func_021DDFBC(char *obj)
{
    Blk *b = *(Blk **)(obj + 8);

    func_02182AC0(*(u32 *)(obj + 0x18), (u32)g_021E3A8C, (u32)g_021E3B4C, b->f0);
    func_021DDBE4((u32)obj, b->f4, b->f8);
    return 0;
}
