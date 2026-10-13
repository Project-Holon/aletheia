/*
 * function: func_021BA328
 * address:  0x021BA328
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   func_021BA3E0  0x021BA3E0  thumb  ov217
 *   CLACT_SetActorAnimFrame  0x0204B8C4  arm  arm9
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Obj;
extern void func_0204B3DC(struct Obj *, unsigned int);
extern u32 CLACT_SetActorAnimFrame();
struct Obj;
extern void func_0204B92C(struct Obj *p, unsigned int v);
struct Actor;
extern void func_0204B954(struct Actor *a, u32 v);
extern u32 func_021BA3E0(void *p, u32 i);
u32 func_021BA328(u32 a0)
{
    u32 v1 = func_021BA3E0((void *)a0, 0);
    func_0204B3DC((struct Obj *)v1, 1);
    func_0204B92C((struct Obj *)v1, 1);
    func_0204B954((struct Actor *)v1, 4096);
    return CLACT_SetActorAnimFrame(v1, 0);
}

