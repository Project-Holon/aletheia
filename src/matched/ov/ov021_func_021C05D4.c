/*
 * function: func_021C05D4
 * address:  0x021C05D4
 * packet:   pkt_ov021_021C05D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_02030734  0x02030734  arm
 *   d_021DE3A0  0x021DE3A0  data  ov021  a1
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

typedef struct {
    u32 n;
    u8 *e;
} Tab;

extern u8 d_021DE3A0[];
extern void *sub_02030734(u32 heap, u32 size, int align, const char *file, unsigned short line);

Tab *func_021C05D4(u32 n, u32 heap)
{
    u8 i;
    Tab *t;

    i = 0;
    t = (Tab *)sub_02030734(heap, 8, 0, (const char *)d_021DE3A0, 0x5a);
    t->e = (u8 *)sub_02030734(heap, n * 0x1c, 0, (const char *)d_021DE3A0, 0x5b);
    t->n = n;
    for (i = 0; i < n; i++) {
        *(u32 *)(t->e + i * 0x1c + 0x14) = 0;
    }
    return t;
}
