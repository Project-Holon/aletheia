/*
 * function: func_021A408C
 * address:  0x021A408C
 * packet:   pkt_ov021_021A408C
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
} Obj021A408C;

int func_021A3D50(Obj021A408C *p, int a);

int func_021A408C(Obj021A408C *p)
{
    if (func_021A3D50(p, 8) != 1)
        p->step++;
    return 0;
}
