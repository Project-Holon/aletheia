/*
 * function: func_021B817C
 * address: 0x021B817C
 * packet: pkt_ov173_021B817C
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: select flag into a u8 local and store it after the branch;
 *        stores written in each arm rematerialized 0x1B0 (+4 bytes).
 * symbols:
 *   func_021B7568 0x021B7568 thumb ov173
 *   func_021B7460 0x021B7460 thumb ov173
 */
typedef unsigned char  u8;
extern u8 func_021B7568(void ***p);extern void func_021B7460(char *,unsigned);
int func_021B817C(char *p) {unsigned char flag;if(func_021B7568((void ***)p)<4) {func_021B7460(p,1);flag=0;} else {func_021B7460(p,4);flag=2;}*(unsigned char *)(p+0x1ba)=flag;*(unsigned *)(p+0x1ba-10)=3;return 2;}
