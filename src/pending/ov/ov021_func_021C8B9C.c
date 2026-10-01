/*
 * function: func_021C8B9C
 * address:  0x021C8B9C
 * packet:   pkt_ov021_021C8B9C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-01: DIFF is a base/offset register swap only (original: table
 * base r3, i*6 offset r4; compiled the reverse). The stride-4 sibling
 * func_021C8BD8 matched with the same shape. Tried: operand order, int/u8/u32
 * index, local table pointer, per-element pointer, u16[4][3], byte arithmetic.
 *
 * symbols:
 *   d_021DAB54  0x021DAB54  data  ov021  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 x, y, z; } V;
typedef struct { u32 f0; u32 f4; u32 f8; u32 fC; void *f10; } P;
typedef struct { u16 id; u16 a; u16 b; } E;
extern E d_021DAB54[4];
E *func_021C8B9C(u16 id)
{
    u32 i;
    for (i = 0; i < 4; i++) {
        if (d_021DAB54[i].id == id)
            return &d_021DAB54[i];
    }
    return 0;
}
