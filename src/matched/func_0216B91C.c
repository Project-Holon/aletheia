/*
 * function: func_0216B91C
 * address:  0x0216B91C
 * packet:   pkt_0216B91C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0200E394  0x0200E394  thumb
 *   func_0200C0E8  0x0200C0E8  thumb
 *   func_0216BB70  0x0216BB70  thumb  ov010
 *   func_0216B994  0x0216B994  thumb  ov010
 *   func_0216BA40  0x0216BA40  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0200E394();
extern int func_0200C0E8();
extern int func_0216BB70();
extern int func_0216B994();
extern int func_0216BA40();

int func_0216B91C(int a0, int a1, int a2)
{
    int t4;
    int t5;
    int t6;
    int t7;

t7 = a0 + 0;
t5 = a1 + 0;
t4 = a2 + 0;
    a0 = func_0200E394();
loc_0216B928:
t6 = a0 + 0;
a0 = t7 + 0;
    a0 = func_0200C0E8(a0);
loc_0216B930:
a0 = t5 + 0;
    a0 = func_0216BB70(a0);
loc_0216B936:
a0 = a0 << 0x18;
a0 = (unsigned)a0 >> 0x18;
    if (a0 != 0) goto loc_0216B954;
loc_0216B93C:
a0 = t6 + 0;
a1 = t5 + 0;
    a0 = func_0216B994(a0, a1);
loc_0216B944:
    if (a0 == 0) goto loc_0216B94E;
loc_0216B948:
a0 = 1;
*(u16 *)((char *)t4) = a0;
    return a0;
loc_0216B94E:
a0 = 2;
*(u16 *)((char *)t4) = a0;
    return a0;
loc_0216B954:
    if (a0 != 1) goto loc_0216B96E;
loc_0216B958:
a0 = t6 + 0;
a1 = t5 + 0;
    a0 = func_0216BA40(a0, a1);
loc_0216B960:
    if (a0 == 0) goto loc_0216B96A;
loc_0216B964:
a0 = 1;
*(u16 *)((char *)t4) = a0;
    return a0;
loc_0216B96A:
a0 = 3;
*(u16 *)((char *)t4) = a0;
loc_0216B96E:
    return a0;}
