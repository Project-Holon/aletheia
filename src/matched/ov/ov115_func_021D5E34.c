/*
 * function: func_021D5E34
 * address: 0x021D5E34
 * packet: pkt_ov115_021D5E34
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02027858 0x02027858 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct TaskMenu;
extern void func_02027858(struct TaskMenu *);
enum Kind { K0,K1 };
void func_021D5E34(u8 *p) { switch(*(enum Kind *)p) { case K0: func_02027858(*(struct TaskMenu **)(p+32)); break; case K1: break; } }
