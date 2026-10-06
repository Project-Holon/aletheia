/*
 * function: func_021B9F80
 * address: 0x021B9F80
 * packet: pkt_ov100_021B9F80
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203A574 0x0203A574 arm
 *   d_021BB6C0 0x021BB6C0 data a4
 *   func_020399A8 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_0203D7B0 0x0203D7B0 arm
 *   func_0203D7BC 0x0203D7BC arm
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021B9EF8 0x021B9EF8 thumb ov100
 */
extern void func_0203A574(unsigned,unsigned,unsigned,unsigned);
extern const unsigned d_021BB6C0[];
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern void func_02039C68(struct Link *p, unsigned int lo, unsigned int hi);
typedef unsigned char  u8;
extern void func_0203D7B0(u8 a0);
extern void func_0203D7BC(u8 a0);
extern void func_021B95B8(unsigned char *,unsigned);
extern void func_021B9EF8(u8 *a);
void func_021B9F80(unsigned a)
{
 func_0203A574(0xc00,(unsigned)d_021BB6C0,6,a);
 func_02039C68((struct Link *)func_020399A8(),0x78,12);
 func_0203D7B0(1);func_0203D7BC(1);
 func_021B95B8((unsigned char *)a,(unsigned)func_021B9EF8);
}
