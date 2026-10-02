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
 *   func_02049238 0x02049238 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void *func_020490F4(unsigned int id, u16 heap);
extern void func_021B8FA0(void *,int,int,int,u8,u8,u8,u8,u8,u8,u8,u8,u8,int,u16);
extern void func_02041300(u8,u8,u8,u8,u8,u8,u8);
extern void func_02041B6C(u8);
extern void func_02049238(void *);
void func_021B9060(int a,u16 b) {
 void *p = func_020490F4(94,b);
 if(a&1)func_021B8FA0(p,7,2,0,0,0,16,24,0,0,16,24,9,0,b);
 else func_02041300(2,0,0,0,16,24,9);
 if(a&2)func_021B8FA0(p,8,2,0,0,0,16,24,16,0,16,24,9,0,b);
 else func_02041300(2,0,16,0,16,24,9);
 func_02041B6C(2);func_02049238(p);
}
