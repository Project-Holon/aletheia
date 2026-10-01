/*
 * function: func_021CF564
 * address:  0x021CF564
 * packet:   pkt_ov021_021CF564
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02034AC4  0x02034AC4  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Res021CF {
    u8 pad0[0xc];
    u32 ids[3];
    int n;
} Res021CF;

extern void func_02034AC4(u32 v);

void func_021CF564(Res021CF *r, u32 id)
{
    func_02034AC4(id);
    r->ids[r->n++] = id;
}
