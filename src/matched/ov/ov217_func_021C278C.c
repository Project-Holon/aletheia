/*
 * function: func_021C278C
 * address:  0x021C278C
 * packet:   pkt_ov217_021C278C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C28EC  0x021C28EC  thumb  ov217
 *   func_021C28DC  0x021C28DC  thumb  ov217
 *   func_021C28CC  0x021C28CC  thumb  ov217
 *   func_021C28BC  0x021C28BC  thumb  ov217
 *   func_021C28A4  0x021C28A4  thumb  ov217
 *   func_021C2894  0x021C2894  thumb  ov217
 *   CLACT_SetActorAnimFrame  0x0204B8C4  arm  arm9
 *   CLACT_StopActorAnim  0x0204B974  arm  arm9
 *   CLACT_SetActorAnimSeq  0x0204B878  arm  arm9
 */
#include "../include/Obj03957.h"
#include "../include/Obj03958.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

struct Obj;
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
struct Actor;
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_SetActorAnimFrame(struct Obj *p, u32 value);
extern void CLACT_StopActorAnim(struct Actor *a);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_021C28EC(const u32 *p, u16 *a, u16 *b);
extern void func_021C28DC(const u32 *p, u16 *a, u16 *b);
extern void func_021C28CC(const u32 *p, u16 *a, u16 *b);
extern u8 func_021C28BC(char *p);
extern u8 func_021C28A4(char *p);
extern u8 func_021C2894(char *p);

void func_021C278C(u8 *p)
{
    u32 z = 0;
    void *h = ((struct Obj03957 *)p)->f10;
    u8 *q = p + 0x20;
    u16 pos[2];

    pos[0] = ((struct Obj03957 *)p)->f4;
    pos[1] = ((struct Obj03957 *)p)->f8;

    func_0204B404(h, (const struct Vec2 *)pos, ((struct Obj03958 *)q)->fC);
    CLACT_SetActorAnimSeq(h, ((struct Obj03958 *)q)->f10);

    CLACT_SetActorAnimFrame(h, 0);
    CLACT_StopActorAnim(h);
    func_0204B3DC(h, 0);

    h = ((struct Obj03957 *)p)->f14;
    func_021C28EC((const u32 *)p, pos, pos + 1);
    func_0204B404(h, (const struct Vec2 *)pos, ((struct Obj03958 *)q)->fC);
    CLACT_SetActorAnimSeq(h, ((struct Obj03958 *)q)->fE);
    CLACT_SetActorAnimFrame(h, func_021C28BC((char *)p) << 12);
    CLACT_StopActorAnim(h);
    func_0204B3DC(h, 0);

    h = ((struct Obj03957 *)p)->f18;
    func_021C28DC((const u32 *)p, pos, pos + 1);
    func_0204B404(h, (const struct Vec2 *)pos, ((struct Obj03958 *)q)->fC);
    CLACT_SetActorAnimSeq(h, ((struct Obj03958 *)q)->fE);
    CLACT_SetActorAnimFrame(h, func_021C28A4((char *)p) << 12);
    CLACT_StopActorAnim(h);
    func_0204B3DC(h, 0);

    h = ((struct Obj03957 *)p)->f1C;
    func_021C28CC((const u32 *)p, pos, pos + 1);
    func_0204B404(h, (const struct Vec2 *)pos, ((struct Obj03958 *)q)->fC);
    CLACT_SetActorAnimSeq(h, ((struct Obj03958 *)q)->fE);
    CLACT_SetActorAnimFrame(h, func_021C2894((char *)p) << 12);
    CLACT_StopActorAnim(h);
    func_0204B3DC(h, z);
}
