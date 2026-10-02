/*
 * function: func_02159728
 * address:  0x02159728
 * packet:   pkt_02159728
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0201296C  0x0201296C  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02014314  0x02014314  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5E4();
extern int func_0201296C();
extern int func_02159B10();
extern int func_02014314();

int func_02159728(int a0, int a1)
{
    int t4;
    int t5;
    int t6;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    a0 = func_0215A5E4(a0);
loc_02159734:
    a0 = func_0201296C(a0);
loc_02159738:
t4 = a0 + 0;
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02159B10(a0, a1);
loc_02159742:
a1 = a0 + 0;
a0 = t4 + 0;
    a0 = func_02014314(a0, a1);
loc_0215974A:
a0 = 0;
    return a0;}
