/*
 * function: func_021B9E08
 * address: 0x021B9E08
 * packet: pkt_ov213_021B9E08
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204E804 0x0204E804 arm
 *   func_021B9830 0x021B9830 thumb ov213
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_0204E804(void);
extern void func_021B9830(void *,void *);
int func_021B9E08(void *a,void *b) {if(func_0204E804()==1)return 0;func_021B9830(a,b);return 1;}
