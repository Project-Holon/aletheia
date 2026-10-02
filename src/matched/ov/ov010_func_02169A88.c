/*
 * function: func_02169A88
 * address: 0x02169A88
 * packet: pkt_ov010_02169A88
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020493D4 0x020493D4 arm
 *   func_0204932C 0x0204932C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct ArcFile;
extern u32 func_020493D4(struct ArcFile *,u32);
extern void func_0204932C(struct ArcFile *,u32,void *);
void func_02169A88(u8 *p,u32 n) { void *out; u32 v; out=*(void **)(p+0xd4); v=func_020493D4(*(struct ArcFile **)(p+0x10),n); func_0204932C(*(struct ArcFile **)(p+0x10),n,out); *(u32 *)(p+0xbc)=v; *(u32 *)(p+0xb4)=v; *(u32 *)(p+0xb8)=v; }
