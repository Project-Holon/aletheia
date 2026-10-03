/*
 * function: func_021B9C9C
 * address: 0x021B9C9C
 * packet: pkt_ov099_021B9C9C
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021B9A34 0x021B9A34 thumb ov099
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021B9A34(void *);
void func_021B9C9C(u8 *p) { int i; int offset; u8 *base; i=0; base=p+48; for(;i<48;i++) { offset=i*28; if (*(u32 *)(p+offset+48)) { if ((*(int (**)(void *,void *))(p+offset+64))(p,base+offset)==1) func_021B9A34(base+offset); } } }
