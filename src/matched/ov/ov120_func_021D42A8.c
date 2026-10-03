/*
 * function: func_021D42A8
 * address: 0x021D42A8
 * packet: pkt_ov120_021D42A8
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_02082D44 0x02082D44 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Entry; struct Link;
extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(struct Link *);
extern void func_02082D44(const void *,void *,u32);
void func_021D42A8(u32 id,int b,const void *src,u8 *p,struct Entry *entry) { if(entry==func_020399A8() && id!=func_0203D1A4((struct Link *)func_020399A8())) func_02082D44(src,p+0x174,12); }
