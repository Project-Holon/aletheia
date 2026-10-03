/*
 * function: func_021B616C
 * address: 0x021B616C
 * packet: pkt_ov179_021B616C
 * region: ov179
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware reads 021B6180 and 021B618E, writes 021B618C and 021B619A.
 * symbols:
 *   func_0207D4B0 0x0207D4B0 arm
 *   func_02051E74 0x02051E74 arm
 *   func_0207D59C 0x0207D59C arm
 *   func_02030734 0x02030734 arm
 *   func_0207EB78 0x0207EB78 arm
 *   func_0207ECF0 0x0207ECF0 arm
 *   func_020307B0 0x020307B0 arm
 *   func_020434DC 0x020434DC arm
 *   d_021B6B00 0x021B6B00 data a4
 */
typedef struct {int m[4];} Mtx;
extern void func_0207D4B0(int,int,int);
extern void func_02051E74(Mtx *,unsigned,const void *,const void *,unsigned char);
extern void func_0207D59C(void *,const Mtx *,int,int,int,int);
extern void *func_02030734(unsigned int,unsigned int,int,const char *,unsigned short);
extern void func_0207EB78(void *,int,int);
extern void func_0207ECF0(void *,int,int);
extern void func_020307B0(void *);
typedef unsigned int   u32;
extern void func_020434DC(u32 mask, u32 enable);
extern unsigned char d_021B6B00[];
void func_021B616C(char *unused)
{
 Mtx m;
 void *p;
 func_0207D4B0(1,5,0);
 *(volatile unsigned short *)0x0400000C=(*(volatile unsigned short *)0x0400000C&0x43)|0x4084;
 *(volatile unsigned short *)0x0400000E=(*(volatile unsigned short *)0x0400000E&0x43)|0x4884;
 func_02051E74(&m,0,(void *)0x1000,(void *)0x1000,0);
 func_0207D59C((void *)0x04000020,&m,0,0,0,0);
 func_0207D59C((void *)0x04000030,&m,0,0,0,0);
 p=func_02030734(0x807F,0x18000,1,(const char *)d_021B6B00,0x5B);
 func_0207EB78(p,0,0x18000);func_0207ECF0(p,0,0x18000);func_020307B0(p);
 func_020434DC(0x13,0);func_020434DC(0xC,1);
}
