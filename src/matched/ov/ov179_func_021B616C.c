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
 *   BUTTON_MAN_RotScaleMtx22 0x02051E74 arm
 *   func_0207D59C 0x0207D59C arm
 *   func_02030734 0x02030734 arm
 *   GX_LoadBG2Scr 0x0207EB78 arm
 *   func_0207ECF0 0x0207ECF0 arm
 *   func_020307B0 0x020307B0 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   d_021B6B00 0x021B6B00 data a4
 */
typedef struct {int m[4];} Mtx;
extern void func_0207D4B0(int,int,int);
typedef unsigned char  u8;
struct Mtx22;
extern void BUTTON_MAN_RotScaleMtx22(struct Mtx22 *mtx, unsigned int ang, const void *v1, const void *v2, u8 mode);
extern void func_0207D59C(void *,const Mtx *,int,int,int,int);
extern void *func_02030734(unsigned int,unsigned int,int,const char *,unsigned short);
extern void GX_LoadBG2Scr(void *,int,int);
extern void func_0207ECF0(void *,int,int);
extern unsigned int func_020307B0(void *p);
typedef unsigned int   u32;
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern unsigned char d_021B6B00[];
void func_021B616C(char *unused)
{
 Mtx m;
 void *p;
 func_0207D4B0(1,5,0);
 *(volatile unsigned short *)0x0400000C=(*(volatile unsigned short *)0x0400000C&0x43)|0x4084;
 *(volatile unsigned short *)0x0400000E=(*(volatile unsigned short *)0x0400000E&0x43)|0x4884;
 BUTTON_MAN_RotScaleMtx22((struct Mtx22 *)(&m),0,(void *)0x1000,(void *)0x1000,0);
 func_0207D59C((void *)0x04000020,&m,0,0,0,0);
 func_0207D59C((void *)0x04000030,&m,0,0,0,0);
 p=func_02030734(0x807F,0x18000,1,(const char *)d_021B6B00,0x5B);
 GX_LoadBG2Scr(p,0,0x18000);func_0207ECF0(p,0,0x18000);func_020307B0(p);
 BG_SYS_SetMainPlaneVisible(0x13,0);BG_SYS_SetMainPlaneVisible(0xC,1);
}
