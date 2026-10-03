/*
 * function: func_021D4774
 * address: 0x021D4774
 * packet: pkt_ov120_021D4774
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D46A4 0x021D46A4 thumb ov120
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Entry;
extern struct Entry *func_020399A8(void); extern void func_02039C68(void *,u32,u32); extern void func_021D4244(int,void (*)(int),int); extern void func_021D46A4(int);
void func_021D4774(int p) { func_02039C68(func_020399A8(),3,34); func_021D4244(p,func_021D46A4,0x2ac); }
