/*
 * function: func_021B756C
 * address: 0x021B756C
 * packet: pkt_ov180_021B756C
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * EXACT* tail: two zero alignment bytes after the function.
 * symbols:
 *   func_021B7510 0x021B7510 thumb ov180
 *   func_021B7530 0x021B7530 thumb ov180
 *   func_021B7550 0x021B7550 thumb ov180
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void func_021B7510(char *,int),func_021B7530(char *,int),func_021B7550(char *,int);
void func_021B756C(char *p) { u32 i; for(i=0;i<6;i++) func_021B7510(p,i); for(i=0;i<7;i++) func_021B7530(p,i); for(i=0;i<6;i++) func_021B7550(p,i); }
