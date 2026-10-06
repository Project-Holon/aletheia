/*
 * function: func_021A3FC0
 * address:  0x021A3FC0
 * packet:   pkt_ov021_021A3FC0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A3D50  0x021A3D50  thumb  ov021
 */

typedef unsigned char u8;

typedef struct {
    u8 pad[0x30];
    short step;
} Obj021A3FC0;

typedef unsigned int   u32;
int func_021A3D50(u32 a, u32 b);

int func_021A3FC0(Obj021A3FC0 *p)
{
    if (func_021A3D50((u32)p, 9) != 1)
        p->step++;
    return 0;
}
