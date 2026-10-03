/*
 * function: func_021DCBFC
 * address: 0x021DCBFC
 * packet: pkt_ov137_021DCBFC
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02039338 0x02039338 arm
 *   func_021DE08C 0x021DE08C thumb ov137
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
extern int func_02039338(void);
extern void func_021DE08C(char *,int,u8);
void func_021DCBFC(int a,int b,int c,u8 *p) {if(func_02039338()!=0) {*(u32 *)(p+32)=0;*(u32 *)(p+36)=1;func_021DE08C(*(char **)(*(u8 **)p+32),27,a);}}
