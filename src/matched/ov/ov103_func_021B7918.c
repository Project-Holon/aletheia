/*
 * function: func_021B7918
 * address: 0x021B7918
 * packet: pkt_ov103_021B7918
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021B7C4C 0x021B7C4C thumb ov103
 *   func_021B7D30 0x021B7D30 thumb ov103
 *   func_021B8C4C 0x021B8C4C thumb ov103
 *   func_021B7D44 0x021B7D44 thumb ov103
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021B7C4C(void *);
extern void func_021B7D30(void *);
extern void func_021B8C4C(u8 **);
extern void func_021B7D44(void *);
void func_021B7918(u8 *p) { func_021B7C4C(p+204); func_021B7D30(p+4); func_021B8C4C((u8 **)(p+352)); func_021B7D44(p+4); }
