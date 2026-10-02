/*
 * function: func_0216B8B8
 * address:  0x0216B8B8
 * packet:   pkt_0216B8B8
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
 *   func_0200C32C  0x0200C32C  thumb
 *   func_0216BB70  0x0216BB70  thumb  ov010
 *   func_0216B994  0x0216B994  thumb  ov010
 *   func_0216B9D8  0x0216B9D8  thumb  ov010
 *   func_0216BA08  0x0216BA08  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0200E394(void *a0);
extern void *func_0200C0E8(void *sys);
extern int func_0200C32C();
extern int func_0216BB70();
extern int func_0216B994();
extern int func_0216B9D8();
extern int func_0216BA08();

int func_0216B8B8(int a0, u16 *a1)
{
    u16 *t4;
    int t5;
    void *t6;
    int t7;
    void *p;

t5 = a0 + 0;
t4 = a1 + 0;
    t6 = func_0200E394((void *)a0);
loc_0216B8C2:
a0 = t5 + 0;
    p = func_0200C0E8((void *)a0);
loc_0216B8CA:
    a0 = func_0200C32C(p);
loc_0216B8CE:
t7 = a0 + 0;
    a0 = func_0216BB70(a0);
loc_0216B8D4:
a0 = a0 << 0x18;
a0 = (unsigned)a0 >> 0x18;
    if (a0 != 0) goto loc_0216B8F2;
loc_0216B8DA:
    a0 = func_0216B994(t6, t7);
loc_0216B8E2:
    if (a0 == 0) goto loc_0216B8EC;
loc_0216B8E6:
a0 = 1;
*t4 = a0;
    return a0;
loc_0216B8EC:
a0 = 2;
*t4 = a0;
    return a0;
loc_0216B8F2:
    if (a0 != 1) goto loc_0216B91A;
loc_0216B8F6:
a0 = t5 + 0;
    a0 = func_0216B9D8(a0);
loc_0216B8FC:
    if (a0 == 0) goto loc_0216B916;
loc_0216B900:
a0 = t5 + 0;
    a0 = func_0216BA08(a0);
loc_0216B906:
    if (a0 == 0) goto loc_0216B910;
loc_0216B90A:
a0 = 1;
*t4 = a0;
    return a0;
loc_0216B910:
a0 = 4;
*t4 = a0;
    return a0;
loc_0216B916:
a0 = 3;
*t4 = a0;
loc_0216B91A:
    return a0;}
