/*
 * function: func_021B7A3C
 * address: 0x021B7A3C
 * packet: pkt_ov105_021B7A3C
 * region: ov105
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203FB44 0x0203FB44 arm
 *   func_02040DA8 0x02040DA8 arm
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   d_021B89B8 0x021B89B8 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0203FB44(u32,u16,u16);
extern void func_02040DA8(u32,u32,u32);
extern void func_020403F4(u8);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern const int d_021B89B8[];
void func_021B7A3C(u32 *p) {
 int i;
 func_0203FB44(5,*p,*p>>16);
 func_02040DA8(5,1,0);
 for(i=0;i<8;i++) func_020403F4(d_021B89B8[i]);
 func_020450C8(); func_0203F9B4();
}
