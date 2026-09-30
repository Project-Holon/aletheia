/*
 * function: func_021B7AD4
 * address: 0x021B7AD4
 * packet: pkt_ov104_021B7AD4
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02040DA8 0x02040DA8 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   d_021B8F5C 0x021B8F5C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void func_02040DA8(u32,u32,u32);
extern void func_0203FB44(u32,u16,u16);
extern void func_020403F4(u8);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern const int d_021B8F5C[];
void func_021B7AD4(u32 *p) { int i; func_02040DA8(2,1,0); func_0203FB44(5,*p,*p>>16); func_02040DA8(5,1,0); for(i=0;i<7;i++) func_020403F4(d_021B8F5C[i]); func_020450C8(); func_0203F9B4(); }
