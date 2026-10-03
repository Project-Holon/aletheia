/*
 * function: func_021C4800
 * address: 0x021C4800
 * packet: pkt_ov127_021C4800
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Follower of 021C47E4, separate because 021C47F8/47FC already have shards.
 * symbols:
 *   func_02082D44 0x02082D44 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02082D44(void *,const void *,u32);
void func_021C4800(u8 *p,void *out) { func_02082D44(out,*(void **)(p+4),*(u16 *)p * *(u16 *)(p+2) * 4); }
