/*
 * function: func_021F3908
 * address: 0x021F3908
 * packet: pkt_ov048_021F3908
 * region: ov048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02012EC0 0x02012EC0 thumb
 *   func_0200C0E8 0x0200C0E8 thumb
 *   func_0200C3B0 0x0200C3B0 thumb
 */
typedef unsigned short u16;
struct Big;
struct Blk34;
extern void *func_02012EC0(struct Big *p);
extern void *func_0200C0E8(void *p);
extern u16 func_0200C3B0(struct Blk34 *p);
void func_021F3908(int *p) { if(p[4]==0) { *(u16 *)((char *)p+0x64)=func_0200C3B0(func_0200C0E8(func_02012EC0((void *)p[2]))); p[4]=1; } }
