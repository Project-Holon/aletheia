/*
 * function: func_021D4278
 * address: 0x021D4278
 * packet: pkt_ov120_021D4278
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
 *   func_02008468 0x02008468 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Entry; struct Link;
extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(struct Link *);
extern void func_02082D44(const void *,void *,u32);
extern int func_02008468(void);
void func_021D4278(u32 id,int b,const void *src,u8 *p,struct Entry *entry) { u8 *q; q=*(u8 **)(p+0x48); if(entry==func_020399A8() && id!=func_0203D1A4((struct Link *)func_020399A8())) func_02082D44(src,*(void **)(q+0x18),func_02008468()); }
