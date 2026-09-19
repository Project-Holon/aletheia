/*
 * function: func_02046B40
 * address:  0x02046B40
 * packet:   pkt_02046B40
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_0207BCA0    0x0207BCA0  arm
 *   g_02146A5C       0x02146A5C  data
 *   g_02148B4C       0x02148B4C  data
 *   g_02148B98       0x02148B98  data
 *   g_02148D8C       0x02148D8C  data
 *   g_02148D98       0x02148D98  data
 *   g_02148DA4       0x02148DA4  data
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u32 w[3];
} Blk;

extern u32 *g_02146A5C;
extern Blk g_02148D8C;
extern Blk g_02148D98;
extern Blk g_02148DA4;
extern Blk g_02148B98;
extern u32 g_02148B4C[];

extern void func_0207BCA0(void *a0, void *a1, void *a2, void *a3);

void func_02046B40(u8 *a0)
{
    u8 *o = (u8 *)g_02146A5C;

    *(Blk *)(o + 0x5C) = *(Blk *)a0;
    *(Blk *)(o + 0x68) = *(Blk *)(a0 + 0xC);
    *(Blk *)(o + 0x74) = *(Blk *)(a0 + 0x18);
    g_02148D8C = *(Blk *)(o + 0x5C);
    g_02148D98 = *(Blk *)(o + 0x68);
    g_02148DA4 = *(Blk *)(o + 0x74);
    func_0207BCA0(o + 0x5C, o + 0x68, o + 0x74, &g_02148B98);
    g_02148B4C[0x3F] &= ~0xE8u;
}
