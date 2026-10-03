/*
 * function: func_021FB5E4
 * address: 0x021FB5E4
 * packet: pkt_ov135_021FB5E4
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B98C 0x0204B98C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021F9660 0x021F9660 thumb ov135
 *   func_0201F868 0x0201F868 thumb
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
extern void func_0201F868(void *);
int func_021FB5E4(u8 *p) { if(func_0204B98C(*(void **)(p+8)))return -1;func_0204B3DC(*(void **)(p+8),0);func_021F9660(p,0);func_0201F868(*(void **)(p+48));return *(s16 *)(p+60); }
