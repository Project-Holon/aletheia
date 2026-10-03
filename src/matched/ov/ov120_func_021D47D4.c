/*
 * function: func_021D47D4
 * address: 0x021D47D4
 * packet: pkt_ov120_021D47D4
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D4798 0x021D4798 thumb ov120
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Entry;
extern struct Entry *func_020399A8(void); extern int func_0203D3A8(void *,u16,u16,u32); extern void func_021D4244(int,void (*)(int),int); extern void func_021D4798(int);
void func_021D47D4(u8 *p) { if (func_0203D3A8(func_020399A8(),0x2202,12,(u32)(p+360))) func_021D4244((int)p,func_021D4798,0x2cf); }
