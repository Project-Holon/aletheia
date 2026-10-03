/*
 * function: func_021B7590
 * address: 0x021B7590
 * packet: pkt_ov173_021B7590
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B7460 0x021B7460 thumb ov173
 *   func_021B7568 0x021B7568 thumb ov173
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021B7460(char *,u32);
extern u8 func_021B7568(void ***);
int func_021B7590(u8 *p) {func_021B7460((char *)p,3);(*(u8 **)p)[27]=func_021B7568((void ***)p);*(u32 *)(p+432)=5;return 2;}
