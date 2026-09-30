/*
 * function: func_021B9110
 * address: 0x021B9110
 * packet: pkt_ov103_021B9110
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_021B793C 0x021B793C thumb ov103
 *   func_021B9184 0x021B9184 thumb ov103
 */
typedef unsigned char u8;
extern void func_02082BCC(void *,int,int);
extern int func_021B793C(void *,int);
extern void func_021B9184(void *,int,int,u8);
void func_021B9110(u8 *p,void *q,int a,int b,int c,u8 d) {
 int i;
 func_02082BCC(p,0,0x590);
 *(int *)(p+0x580)=a;*(int *)(p+0x584)=b;
 *(int *)(p+0x588)=0;*(int *)(p+0x58c)=10;
 for(i=0;i<32;i++)func_021B9184(p+i*0x2c,func_021B793C(q,c+i),b,d);
}
