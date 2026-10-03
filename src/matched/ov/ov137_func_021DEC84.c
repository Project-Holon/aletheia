/*
 * function: func_021DEC84
 * address: 0x021DEC84
 * packet: pkt_ov137_021DEC84
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0202F038 0x0202F038 thumb
 *   func_02039C68 0x02039C68 arm
 */
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Entry;
struct Link;
extern struct Entry *func_020399A8(void);
extern void func_0202F038(u8 *p);
extern void func_02039C68(struct Link *p, u32 lo, u32 hi);
int func_021DEC84(char *p) {void *v;v=func_020399A8();func_0202F038(*(void **)(p+3496));*(void **)(p+3496)=0;func_02039C68(v,202,40);*(int *)p=11;return 0;}
