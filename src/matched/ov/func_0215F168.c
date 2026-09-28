/*
 * function: func_0215F168
 * address:  0x0215F168
 * packet:   pkt_0215F168
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02012138  0x02012138  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02158FB4  0x02158FB4  thumb  ov010
 *   func_02189734  0x02189734  thumb
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5DC();
extern int func_0215A5F4();
extern int func_02012138();
extern int func_0201210C();
extern int func_02158FB4();
extern int func_02189734();
extern int func_020307B0();

int func_0215F168(int a0, int a1)
{
    int t4;
    int t5;
    int t6;

t4 = a1 + 0;
a0 = t4 + 0;
    a0 = func_0215A5DC(a0);
loc_0215F172:
t5 = a0 + 0;
a0 = t4 + 0;
    a0 = func_0215A5F4(a0);
loc_0215F17A:
t4 = a0 + 0;
a0 = t5 + 0;
    a0 = func_02012138(a0);
loc_0215F182:
t6 = a0 + 0;
a0 = t5 + 0;
    a0 = func_0201210C(a0);
loc_0215F18A:
a0 = t4 + 0;
    a0 = func_02158FB4(a0);
loc_0215F190:
t4 = *(int *)((char *)a0);
a0 = t6 + 0;
    a0 = func_02189734(a0);
loc_0215F198:
    if (a0 == 0) goto loc_0215F1A6;
loc_0215F19C:
    if (a0 == 1) goto loc_0215F1AA;
loc_0215F1A0:
    if (a0 == 2) goto loc_0215F1B4;
loc_0215F1A4:
    goto loc_0215F1C4;
loc_0215F1A6:
a0 = 0;
    return a0;
loc_0215F1AA:
a0 = t4 + 0;
    a0 = func_020307B0(a0);
loc_0215F1B0:
a0 = 1;
    return a0;
loc_0215F1B4:
a0 = *(int *)((char *)t4);
a1 = 2;
*(u16 *)((char *)a0) = a1;
a0 = t4 + 0;
    a0 = func_020307B0(a0);
loc_0215F1C0:
a0 = 1;
    return a0;
loc_0215F1C4:
a0 = 0;
    return a0;}
