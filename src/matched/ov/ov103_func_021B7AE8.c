/*
 * function: func_021B7AE8
 * address: 0x021B7AE8
 * packet: pkt_ov103_021B7AE8
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: The packed word passes its low and high halfwords to func_0203FB44; data hint omitted for sole-ref.
 * volatile: hardware register at 0x04000050 written at 021B7AEE.
 * symbols:
 *   d_021B927C 0x021B927C data a4
 *   func_0203FB44 0x0203FB44 arm
 *   func_02040DA8 0x02040DA8 arm
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
extern void func_0203FB44(int,u16,u16); extern void func_02040DA8(int,int,int); extern void func_020403F4(u8); extern void func_020450C8(void); extern void func_0203F9B4(void); extern const int d_021B927C[];
void func_021B7AE8(unsigned *p) {int i; *(volatile u16 *)0x04000050=0; func_0203FB44(5,*p,(u16)(*p>>16)); func_02040DA8(5,1,0); for(i=0;i<7;i++)func_020403F4(d_021B927C[i]); func_020450C8(); func_0203F9B4(); }
