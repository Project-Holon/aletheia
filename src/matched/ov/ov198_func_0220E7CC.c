/*
 * function: func_0220E7CC
 * address:  0x0220E7CC
 * packet:   pkt_0220E7CC
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm  arm9
 *   CLACT_AddActorSurfacePos  0x0204B404  arm  arm9
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);

void func_0220E7CC(u8 *p, u32 b)
{
    CLACT_SetActorDrawEnable((struct Obj *)p, 1);
    CLACT_AddActorSurfacePos((struct Obj *)p, (const struct Vec2 *)b, 1);
}

