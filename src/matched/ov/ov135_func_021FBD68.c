/*
 * function: func_021FBD68
 * address: 0x021FBD68
 * packet: pkt_ov135_021FBD68
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
extern u32 func_0204B98C(void *);
extern void func_0204B3DC(void *,u32);
extern void func_021F9660(void *,u32);
int func_021FBD68(u8 *p) { if(func_0204B98C(*(void **)(p+8)))return -1;func_0204B3DC(*(void **)(p+8),0);func_021F9660(p,1);return *(s8 *)(p+64); }
