/*
 * function: func_021D634C
 * address: 0x021D634C
 * packet: pkt_ov123_021D634C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: indexed p+0x74 array base and non-const table retain the original scheduling.
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B8C4 0x0204B8C4 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B570 0x0204B570 arm
 *   d_021DAACC 0x021DAACC data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Point { s16 x,y; u16 f4; u8 f6,f7; };
struct Entry { int x,y,n; };
extern struct Entry d_021DAACC[];
struct Actor;
struct Obj;
extern void func_0204B3B4(struct Obj *p);
extern void *func_0204B294(u32, void *, u32, u32, struct Point *, u16, u16);
extern void func_0204B8C4(struct Obj *p, u32 value);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B570(struct Actor *actor, u32 value);
void func_021D634C(u8 *p, unsigned int i)
{
    struct Point pt;
    if (*(void **)(p + i*4 + 0x74)) func_0204B3B4(*(void **)(p+i*4+0x74));
    pt.x = d_021DAACC[i].x; pt.y = d_021DAACC[i].y;
    pt.f4 = i; pt.f6 = d_021DAACC[i].n; pt.f7 = 1;
    ((void **)(p + 0x74))[i] = func_0204B294(*(u32 *)(p+0xc), *(void **)(p+0x38), *(u32 *)(p+0x20), *(u32 *)(p+0x54), &pt, 0, *(u16 *)(p+0x43c4));
    func_0204B8C4(((void **)(p+0x74))[i],0);
    func_0204B92C(((void **)(p+0x74))[i],1);
    func_0204B3DC(((void **)(p+0x74))[i],1);
    func_0204B570(((void **)(p+0x74))[i],2);
}
