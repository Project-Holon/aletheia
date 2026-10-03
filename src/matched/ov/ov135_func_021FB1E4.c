/*
 * function: func_021FB1E4
 * address: 0x021FB1E4
 * packet: pkt_ov135_021FB1E4
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent remainder: 2-byte zero alignment padding.
 * symbols:
 *   func_0204B98C 0x0204B98C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021F9660 0x021F9660 thumb ov135
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Actor;
struct Obj;
extern u32 func_0204B98C(struct Actor *a);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_021F9660(void *,u32);
int func_021FB1E4(u8 *p) { if(func_0204B98C(*(void **)(p+8)))return -1;func_0204B3DC(*(void **)(p+8),0);func_021F9660(p,5);if(*(s16 *)(p+58)>=0)*(u32 *)(p+72)=14;else *(u32 *)(p+72)=9;return -1; }
