/*
 * function: func_02168174
 * address:  0x02168174
 * packet:   pkt_02168174
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02191388  0x02191388  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_021912D8  0x021912D8  thumb
 *   func_021912F8  0x021912F8  thumb
 *   func_02045808  0x02045808  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02191388();
extern u32 func_020362DC(void);
extern int func_021912D8();
extern int func_021912F8();
extern int func_02045808();

int func_02168174(int a0, int a1, int a2)
{
    int t4;
    int t5;

t5 = a1 + 0;
a0 = *(int *)((char *)t5);
t4 = a2 + 0;
    if (a0 == 0) goto loc_0216818A;
loc_02168180:
    if (a0 == 1) goto loc_0216819C;
loc_02168184:
    if (a0 == 2) goto loc_021681AE;
loc_02168188:
    goto loc_021681C2;
loc_0216818A:
a0 = *(int *)((char *)t4 + 0x10);
    a0 = func_02191388(a0);
loc_02168190:
    if (a0 != 1) goto loc_021681C2;
loc_02168194:
a0 = *(int *)((char *)t5);
a0 = a0 + 1;
*(int *)((char *)t5) = a0;
    goto loc_021681C2;
loc_0216819C:
    a0 = func_020362DC();
loc_021681A0:
a1 = 3;
    if ((a0 & a1) == 0) goto loc_021681C2;
loc_021681A6:
a0 = *(int *)((char *)t4 + 0x10);
    a0 = func_021912D8(a0);
loc_021681AC:
    goto loc_02168194;
loc_021681AE:
a0 = *(int *)((char *)t4 + 0x10);
    a0 = func_021912F8(a0);
loc_021681B4:
    if (a0 != 1) goto loc_021681C2;
loc_021681B8:
a0 = *(int *)((char *)t4 + 0x14);
    a0 = func_02045808(a0);
loc_021681BE:
a0 = 1;
    return a0;
loc_021681C2:
a0 = 0;
    return a0;}
