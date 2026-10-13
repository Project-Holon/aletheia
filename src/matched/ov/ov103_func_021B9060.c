/*
 * function: func_021B9060
 * address: 0x021B9060
 * packet: pkt_ov103_021B9060
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_021B8FA0 0x021B8FA0 thumb ov103
 *   func_02041300 0x02041300 arm
 *   func_02041B6C 0x02041B6C arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_021B8FA0(int a, int b, int c, int d, u8 e, u8 f, u8 g, u8 h, u8 i, u8 j, u8 k, u8 l, u8 m, int n, u16 o);
extern void func_02041300(u8,u8,u8,u8,u8,u8,u8);
typedef unsigned int   u32;
extern void func_02041B6C(u32 bit);
extern void ARC_TOOL_DeleteHandle(void *);
void func_021B9060(int a,u16 b) {
 void *p = func_020490F4(94,b);
 if(a&1)func_021B8FA0((int)p,7,2,0,0,0,16,24,0,0,16,24,9,0,b);
 else func_02041300(2,0,0,0,16,24,9);
 if(a&2)func_021B8FA0((int)p,8,2,0,0,0,16,24,16,0,16,24,9,0,b);
 else func_02041300(2,0,16,0,16,24,9);
 func_02041B6C(2);ARC_TOOL_DeleteHandle(p);
}
