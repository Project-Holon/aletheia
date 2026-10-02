/*
 * function: func_021652EC
 * address: 0x021652EC
 * packet: pkt_ov010_021652EC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202744C 0x0202744C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0202744C(void *);
typedef struct Obj { u8 pad[3]; u8 lo:7; u8 hi:1; u8 gap[0x2c]; u16 event; } Obj;
void func_021652EC(Obj *p,u32 v) { p->event=0x12; p->lo=(u8)v; func_0202744C(p); }
