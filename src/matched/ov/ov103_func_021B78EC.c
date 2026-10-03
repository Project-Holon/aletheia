/*
 * function: func_021B78EC
 * address: 0x021B78EC
 * packet: pkt_ov103_021B78EC
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_021B8C40 0x021B8C40 thumb ov103
 *   func_021B7D08 0x021B7D08 thumb ov103
 *   func_021B7AE8 0x021B7AE8 thumb ov103
 *   func_021B7C08 0x021B7C08 thumb ov103
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Node;
extern void func_02030EAC(struct Node *n);
extern void func_021B8C40(void *);
extern void func_021B7D08(u8 *p);
extern void func_021B7AE8(u32 *);
extern void func_021B7C08(u8 *);
void func_021B78EC(u8 *p) { func_02030EAC(*(void **)(p+368)); func_021B8C40(p+352); func_021B7D08(p+4); func_021B7AE8((u32 *)p); func_021B7C08(p+204); }
