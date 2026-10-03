/*
 * function: func_0220B07C
 * address: 0x0220B07C
 * packet: pkt_ov196_0220B07C
 * region: ov196
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * EXACT* tail: two zero alignment bytes after the function.
 * symbols:
 *   sub_02045374 0x02045374 arm
 *   sub_02045730 0x02045730 arm
 *   sub_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Descriptor;
struct Cfg;
extern void sub_02045374(struct Cfg *);
extern u8 sub_02045730(struct Descriptor *);
extern void sub_02041B6C(u32);
void func_0220B07C(void **p) { sub_02045374((struct Cfg *)*p); sub_02041B6C(sub_02045730((struct Descriptor *)*p)); }
