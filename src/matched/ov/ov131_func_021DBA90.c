/*
 * function: func_021DBA90
 * address: 0x021DBA90
 * packet: pkt_ov131_021DBA90
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021DC854 0x021DC854 data a1
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u32,u32,u32,const char *,u32);
extern const char d_021DC854[];
struct S { u32 f0; u16 f4; u16 pad; int f8[3]; };
struct S *func_021DBA90(u32 a, u32 b) {
 struct S *p = func_02030734(a, 0x14, 1, d_021DC854, 0x5d);
 int i;
 p->f4 = a;
 p->f0 = b;
 for (i = 0; i < 3; i++) p->f8[i] = -1;
 return p;
}
