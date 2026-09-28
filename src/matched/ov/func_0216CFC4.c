/*
 * function: func_0216CFC4
 * address:  0x0216CFC4
 * packet:   pkt_0216CFC4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D584  0x0216D584  thumb  ov010
 *   func_0216D59C  0x0216D59C  thumb  ov010
 *   func_0216D5A4  0x0216D5A4  thumb  ov010
 *   func_0216D5AC  0x0216D5AC  thumb  ov010
 *   func_0216D5B4  0x0216D5B4  thumb  ov010
 *   func_0216D620  0x0216D620  thumb  ov010
 *   func_0216D65C  0x0216D65C  thumb  ov010
 *   func_0216D668  0x0216D668  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0216D584();
extern int func_0216D59C();
extern int func_0216D5A4();
extern int func_0216D5AC();
extern int func_0216D5B4();
extern int func_0216D620();
extern int func_0216D65C();
extern int func_0216D668();

int func_0216CFC4(int a0, int a1, int a2)
{
    int t4;
    int t5;

t4 = a1 + 0;
a1 = *(u16 *)((char *)t4);
t5 = a0 + 0;
    a0 = func_0216D584(a0, a1);
loc_0216CFD0:
a1 = *(u16 *)((char *)t4 + 4);
a0 = t5 + 0;
    a0 = func_0216D59C(a0, a1);
loc_0216CFD8:
a1 = *(u16 *)((char *)t4 + 6);
a0 = t5 + 0;
    a0 = func_0216D5A4(a0, a1);
loc_0216CFE0:
a1 = *(u16 *)((char *)t4 + 8);
a0 = t5 + 0;
    a0 = func_0216D5AC(a0, a1);
loc_0216CFE8:
a1 = *(u16 *)((char *)t4 + 0xa);
a0 = t5 + 0;
    a0 = func_0216D5B4(a0, a1);
loc_0216CFF0:
a0 = *(u16 *)((char *)t4 + 0xc);
a1 = *(u16 *)((char *)t4 + 0xe);
a2 = 0;
*(u16 *)((char *)t5 + 0x16) = a0;
*(u16 *)((char *)t5 + 0x1a) = a0;
a0 = t5 + 0;
    a0 = func_0216D620(a0, a1, a2);
loc_0216D000:
a1 = *(u16 *)((char *)t4 + 0x10);
a0 = t5 + 0;
a2 = 1;
    a0 = func_0216D620(a0, a1, a2);
loc_0216D00A:
a1 = *(u16 *)((char *)t4 + 0x12);
a0 = t5 + 0;
a2 = 2;
    a0 = func_0216D620(a0, a1, a2);
loc_0216D014:
a1 = 0x14;
a1 = *(short *)((char *)t4 + a1);
a0 = t5 + 0;
    a0 = func_0216D65C(a0, a1);
loc_0216D01E:
a1 = 0x16;
a1 = *(short *)((char *)t4 + a1);
a0 = t5 + 0;
    a0 = func_0216D668(a0, a1);
loc_0216D028:
    return a0;}
