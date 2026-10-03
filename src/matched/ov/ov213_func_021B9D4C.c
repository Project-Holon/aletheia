/*
 * function: func_021B9D4C
 * address: 0x021B9D4C
 * packet: pkt_ov213_021B9D4C
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B98DC 0x021B98DC thumb ov213
 *   func_020061E4 0x020061E4 thumb
 *   func_021B61F8 0x021B61F8 thumb ov067
 *   func_021B9830 0x021B9830 thumb ov213
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021B98DC(int,int);
extern void func_020061E4(int);
extern void func_021B61F8(u8 *,u16);
extern void func_021B9830(void *,void *);
int func_021B9D4C(u8 *task,char *p) {if(*(u32 *)(p+0x49CC)==2){func_020061E4(func_021B98DC(4,*(int *)(*(char **)(p+4)+0x50)));func_021B61F8(task,2);return 1;}func_021B9830(task,p);return 1;}
