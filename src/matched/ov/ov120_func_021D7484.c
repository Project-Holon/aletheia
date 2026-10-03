/*
 * function: func_021D7484
 * address: 0x021D7484
 * packet: pkt_ov120_021D7484
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing 2-byte alignment padding only.
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B3B4 0x0204B3B4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B3B4(struct Obj *p);
void func_021D7484(char *p) { func_0204B3DC(*(void **)(p+0x12c),0); func_0204B3B4(*(void **)(p+0x12c)); func_0204B3DC(*(void **)(p+0x130),0); func_0204B3B4(*(void **)(p+0x130)); }
