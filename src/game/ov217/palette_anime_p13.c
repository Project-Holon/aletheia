/*
 * file:     palette_anime_p13.c
 * unit:     yes
 * function: func_021C2740, func_021C2748, func_021C278C
 * address:  0x021C2740
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C28A4  0x021C28A4  thumb  ov217
 *   func_021C28BC  0x021C28BC  thumb  ov217
 *   func_021C28EC  0x021C28EC  thumb  ov217
 *   func_021C28DC  0x021C28DC  thumb  ov217
 *   func_021C28CC  0x021C28CC  thumb  ov217
 *   func_021C2894  0x021C2894  thumb  ov217
 */
#include "../../matched/include/Obj08445.h"
#include "../../matched/include/Obj03957.h"
#include "../../matched/include/Obj03958.h"

struct Obj;
struct Vec2;
struct Actor;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef signed char    s8;

typedef signed short   s16;

extern void func_0204B3DC(struct Obj *, unsigned int);
extern u8 func_021C28A4(char *p);
extern u8 func_021C28BC(char *p);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B8C4(struct Obj *p, u32 value);
extern void func_0204B974(struct Actor *a);
extern void func_021C28EC(const u32 *p, u16 *a, u16 *b);
extern void func_021C28DC(const u32 *p, u16 *a, u16 *b);
extern void func_021C28CC(const u32 *p, u16 *a, u16 *b);
extern u8 func_021C2894(char *p);
void func_021C2740(unsigned int a0, unsigned int a1);
void func_021C2748(u32 a0, u32 a1);
void func_021C278C(u8 *p);


/*
 * Tail-call veneer: branch to func_021C2748.
 *
 * Addresses are Black-image addresses.
 */
void func_021C2740(unsigned int a0, unsigned int a1)
{
    func_021C2748(a0, a1);
}

/*
 * Pushes the +0x10 body through func_0204B3DC, then the +0x14 body when
 * func_021C28BC() is busy, the +0x18 body when either query fires, and the
 * +0x1c body unconditionally.
 *
 * Addresses are Black-image addresses.
 */
void func_021C2748(u32 a0, u32 a1)
{
    func_0204B3DC((struct Obj *)((struct Obj08445 *)(((u8*)a0)))->f10, a1);
    if (func_021C28BC((char *)a0) != 0) {
    func_0204B3DC((struct Obj *)((struct Obj08445 *)(((u8*)a0)))->f14, a1);
    }
    if (func_021C28BC((char *)a0) != 0 || func_021C28A4((char *)a0) != 0) {
    func_0204B3DC((struct Obj *)((struct Obj08445 *)(((u8*)a0)))->f18, a1);
    }
    func_0204B3DC((struct Obj *)((struct Obj08445 *)(((u8*)a0)))->f1C, a1);
}


void func_021C278C(u8 *p)
{
    u32 z = 0;
    void *h = ((struct Obj03957 *)p)->f10;
    u8 *q = p + 0x20;
    u16 pos[2];

    pos[0] = ((struct Obj03957 *)p)->f4;
    pos[1] = ((struct Obj03957 *)p)->f8;

    func_0204B404(h, (const struct Vec2 *)pos, ((struct Obj03958 *)q)->fC);
    func_0204B878(h, ((struct Obj03958 *)q)->f10);

    func_0204B8C4(h, 0);
    func_0204B974(h);
    func_0204B3DC(h, 0);

    h = ((struct Obj03957 *)p)->f14;
    func_021C28EC((const u32 *)p, pos, pos + 1);
    func_0204B404(h, (const struct Vec2 *)pos, ((struct Obj03958 *)q)->fC);
    func_0204B878(h, ((struct Obj03958 *)q)->fE);
    func_0204B8C4(h, func_021C28BC((char *)p) << 12);
    func_0204B974(h);
    func_0204B3DC(h, 0);

    h = ((struct Obj03957 *)p)->f18;
    func_021C28DC((const u32 *)p, pos, pos + 1);
    func_0204B404(h, (const struct Vec2 *)pos, ((struct Obj03958 *)q)->fC);
    func_0204B878(h, ((struct Obj03958 *)q)->fE);
    func_0204B8C4(h, func_021C28A4((char *)p) << 12);
    func_0204B974(h);
    func_0204B3DC(h, 0);

    h = ((struct Obj03957 *)p)->f1C;
    func_021C28CC((const u32 *)p, pos, pos + 1);
    func_0204B404(h, (const struct Vec2 *)pos, ((struct Obj03958 *)q)->fC);
    func_0204B878(h, ((struct Obj03958 *)q)->fE);
    func_0204B8C4(h, func_021C2894((char *)p) << 12);
    func_0204B974(h);
    func_0204B3DC(h, z);
}
