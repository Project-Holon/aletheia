/*
 * function: func_021B65FC
 * address: 0x021B65FC
 * packet: pkt_ov180_021B65FC
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021B660A..021B6648 re-read hardware 0x04000008 and 0x04000060; hardware write 0x04000580.
 * symbols:
 *   func_020434DC 0x020434DC arm
 *   func_0207DC44 0x0207DC44 arm
 *   func_0207DD24 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   func_02046BE0 0x02046BE0 arm
 *   d_021B8040 0x021B8040 data a4
 */
typedef unsigned short u16;
extern void func_020434DC(unsigned,unsigned); extern void func_0207DC44(int,int,int,int); extern void func_0207DD24(u16,int,int,int,int);
typedef unsigned int   u32;
extern void G3D_SYSTEM_SetLight(u32 idx, const u16 *src); extern void func_02046BE0(unsigned,unsigned);
extern const unsigned char d_021B8040[];
#define REG(a) (*(volatile u16 *)(a))
void func_021B65FC(void) {
 unsigned i;
 func_020434DC(1,1);
 REG(0x04000008)=REG(0x04000008)&~3;
 REG(0x04000060)=(u16)((REG(0x04000060)&~0x3002)|2);
 REG(0x04000060)&=(u16)~0x3010;
 REG(0x04000060)&=(u16)~0x3004;
 REG(0x04000060)=(u16)((REG(0x04000060)&~0x3000)|8);
 REG(0x04000060)&=(u16)~0x3020;
 func_0207DC44(0,0,0,0); func_0207DD24(0,0,32767,63,0);
 *(volatile unsigned *)0x04000580=0xBFFF0000;
 for(i=0;i<4;i++) G3D_SYSTEM_SetLight((unsigned char)i,(const u16 *)(d_021B8040+i*8));
 func_02046BE0(1,0);
}
