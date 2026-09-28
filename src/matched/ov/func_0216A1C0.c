/*
 * function: func_0216A1C0
 * address:  0x0216A1C0
 * packet:   pkt_0216A1C0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188CB4  0x02188CB4  thumb
 *   func_021A3208  0x021A3208  thumb
 *   func_021A3074  0x021A3074  thumb
 *   func_021A2F48  0x021A2F48  thumb
 *   func_0216DB04  0x0216DB04  thumb  ov010
 *   func_0216D550  0x0216D550  thumb  ov010
 *   func_021A2F54  0x021A2F54  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02188CB4();
extern int func_021A3208();
extern int func_021A3074();
extern int func_021A2F48();
extern int func_0216DB04();
extern int func_0216D550();
extern int func_021A2F54();

int func_0216A1C0(int a0, int a1)
{
    int t4;
    int t5;

a0 = *(int *)((char *)a0 + 8);
    a0 = func_02188CB4(a0);
loc_0216A1C8:
t5 = a0 + 0;
    a0 = func_021A3208();
loc_0216A1CE:
    if (a0 != 1) goto loc_0216A1F6;
loc_0216A1D2:
a0 = t5 + 0;
    a0 = func_021A3074(a0);
loc_0216A1D8:
t4 = a0 + 0;
a0 = t5 + 0;
a1 = 0x20;
    a0 = func_021A2F48(a0, a1);
loc_0216A1E2:
a0 = t4 + 0;
    a0 = func_0216DB04(a0);
loc_0216A1E8:
a0 = t4 + 0;
a1 = 0x10;
    a0 = func_0216D550(a0, a1);
loc_0216A1F0:
a0 = t5 + 0;
    a0 = func_021A2F54(a0);
loc_0216A1F6:
    return a0;}
