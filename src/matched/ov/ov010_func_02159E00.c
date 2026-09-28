/*
 * function: func_02159E00
 * address:  0x02159E00
 * packet:   pkt_ov010_02159E00
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02159E60  0x02159E60  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02159E60(int);

int func_02159E00(u8 *a, u32 *b, u32 *c)
{
    u8 *r4 = a + 0x1a;
    u8 *r5 = a + 0xc;
    int sel = r4[3];
    u32 old = *(u16 *)(r4 + 4);
    int idx;
    u32 cur;
    switch (sel) {
    case 0:
        idx = r5[0];
        break;
    case 1:
        idx = r5[1];
        break;
    case 2:
        idx = r5[2];
        break;
    default:
        idx = (r5 + func_02159E60(sel))[3];
        break;
    }
    cur = *(u16 *)(r4 + idx * 2 + 4);
    *b = old;
    *c = cur;
    if (old == cur)
        return 0;
    if (r4[2] == 1)
        return 2;
    if (r4[2] == 0)
        return 1;
    return 0;
}
