/*
 * function: func_0215DE44
 * address:  0x0215DE44
 * packet:   pkt_0215DE44
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FC684  0x021FC684  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021FC684();

void func_0215DE44(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = *(int *)((char *)t4 + 4);
    if (a0 == 0) goto loc_0215DE56;
loc_0215DE4E:
    a0 = func_021FC684();
loc_0215DE52:
a0 = 0;
*(int *)((char *)t4 + 4) = a0;
loc_0215DE56:
    return;}
