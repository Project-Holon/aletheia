/*
 * unit:     yes
 * function: func_0219E854, func_0219E864, func_0219E870, func_0219E87C, func_0219E888, func_0219E894, func_0219E8A0, func_0219E8AC, func_0219E8B8, func_0219E8C4, func_0219E8D0, func_0219E8DC, func_0219E8E8, func_0219E8F0, func_0219E8F8, func_0219E904, func_0219E910, func_0219E918, func_0219E920, func_0219E928, func_0219E930
 * address:  0x0219E854
 * packet:   pkt_ov021_0219E854
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   func_0219EAB8  0x0219EAB8  thumb  ov021
 *   func_0219EB18  0x0219EB18  thumb  ov021
 *   func_0219EB4C  0x0219EB4C  thumb  ov021
 *   func_0219EB90  0x0219EB90  thumb  ov021
 *   func_0219EBA0  0x0219EBA0  thumb  ov021
 *   func_0219EBF4  0x0219EBF4  thumb  ov021
 *   func_0219ED7C  0x0219ED7C  thumb  ov021
 *   func_0219ED8C  0x0219ED8C  thumb  ov021
 *   func_0219EDC4  0x0219EDC4  thumb  ov021
 *   func_0219EF04  0x0219EF04  thumb  ov021
 * Addresses are Black-image addresses.
 * func_0219E854 is followed by twenty unlabelled tail-call thunks (pool
 * word plus `bx r3`), eleven of them passing a state index 0..10 to
 * func_0219EB18; the unit covers the whole 228-byte run.
 */

typedef unsigned int u32;

extern u32 func_0216D69C();
extern int func_0219EAB8();
extern int func_0219EB18();
extern int func_0219EB4C(u32 o);
extern int func_0219EB90();
extern void func_0219EBA0(u32 o, u32 k);
extern int func_0219EBF4(u32 o);
extern int func_0219ED7C();
extern int func_0219ED8C();
extern int func_0219EDC4(u32 o);
extern int func_0219EF04();

int func_0219E854(u32 o)
{
    return func_0219EAB8(func_0216D69C(o), o);
}

int func_0219E864(u32 o) { return func_0219EB18(o, 0); }
int func_0219E870(u32 o) { return func_0219EB18(o, 1); }
int func_0219E87C(u32 o) { return func_0219EB18(o, 2); }
int func_0219E888(u32 o) { return func_0219EB18(o, 3); }
int func_0219E894(u32 o) { return func_0219EB18(o, 4); }
int func_0219E8A0(u32 o) { return func_0219EB18(o, 5); }
int func_0219E8AC(u32 o) { return func_0219EB18(o, 6); }
int func_0219E8B8(u32 o) { return func_0219EB18(o, 7); }
int func_0219E8C4(u32 o) { return func_0219EB18(o, 8); }
int func_0219E8D0(u32 o) { return func_0219EB18(o, 9); }
int func_0219E8DC(u32 o) { return func_0219EB18(o, 10); }
int func_0219E8E8(u32 o) { return func_0219EB4C(o); }
int func_0219E8F0(u32 o) { return func_0219EB90(o); }
void func_0219E8F8(u32 o) { func_0219EBA0(o, 0); }
void func_0219E904(u32 o) { func_0219EBA0(o, 9); }
int func_0219E910(u32 o) { return func_0219EBF4(o); }
int func_0219E918(u32 o) { return func_0219ED7C(o); }
int func_0219E920(u32 o) { return func_0219ED8C(o); }
int func_0219E928(u32 o) { return func_0219EDC4(o); }
int func_0219E930(u32 o) { return func_0219EF04(o); }
