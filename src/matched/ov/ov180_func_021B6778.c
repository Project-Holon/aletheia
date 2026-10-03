/*
 * function: func_021B6778
 * address: 0x021B6778
 * packet: pkt_ov180_021B6778
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02050C04 0x02050C04 arm
 *   func_0205121C 0x0205121C arm
 *   func_02051230 0x02051230 arm
 *   d_021B8108 0x021B8108 data a4
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern int d_021B8108;
extern void * func_02050C04(void *,int,int,int);
extern void * func_0205121C(int,int,int);
extern void func_02051230(void *,void *,int,int);
void func_021B6778(char *p){*(void **)(p+40)=func_02050C04(p+48,18432,1,141);func_02051230(*(void **)(p+40),func_0205121C(216,*(int *)((u32)&d_021B8108+*(u16 *)(p+37210)*4),141),1,0);}
