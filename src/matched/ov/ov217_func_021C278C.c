/*
 * function: PERCENTAGE_Layout
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
 *   PERCENTAGE_GetHundredsPosition  0x021C28EC  thumb  ov217
 *   PERCENTAGE_GetTensPosition  0x021C28DC  thumb  ov217
 *   PERCENTAGE_GetOnesPosition  0x021C28CC  thumb  ov217
 *   PERCENTAGE_GetHundredsDigit  0x021C28BC  thumb  ov217
 *   PERCENTAGE_GetTensDigit  0x021C28A4  thumb  ov217
 *   PERCENTAGE_GetOnesDigit  0x021C2894  thumb  ov217
 *   CLACT_SetActorAnimFrame  0x0204B8C4  arm  arm9
 *   CLACT_StopActorAnim  0x0204B974  arm  arm9
 *   CLACT_SetActorAnimSeq  0x0204B878  arm  arm9
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm  arm9
 *   CLACT_AddActorSurfacePos  0x0204B404  arm  arm9
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
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
struct Actor;
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_SetActorAnimFrame(struct Obj *p, u32 value);
extern void CLACT_StopActorAnim(struct Actor *a);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void PERCENTAGE_GetHundredsPosition(const u32 *p, u16 *a, u16 *b);
extern void PERCENTAGE_GetTensPosition(const u32 *p, u16 *a, u16 *b);
extern void PERCENTAGE_GetOnesPosition(const u32 *p, u16 *a, u16 *b);
extern u8 PERCENTAGE_GetHundredsDigit(char *p);
extern u8 PERCENTAGE_GetTensDigit(char *p);
extern u8 PERCENTAGE_GetOnesDigit(char *p);

void PERCENTAGE_Layout(u8 *p)
{
    u32 z = 0;
    void *h = ((struct Obj03957 *)p)->f10;
    u8 *q = p + 0x20;
    u16 pos[2];

    pos[0] = ((struct Obj03957 *)p)->f4;
    pos[1] = ((struct Obj03957 *)p)->f8;

    CLACT_AddActorSurfacePos(h, (const struct Vec2 *)pos, ((struct Obj03958 *)q)->fC);
    CLACT_SetActorAnimSeq(h, ((struct Obj03958 *)q)->f10);

    CLACT_SetActorAnimFrame(h, 0);
    CLACT_StopActorAnim(h);
    CLACT_SetActorDrawEnable(h, 0);

    h = ((struct Obj03957 *)p)->f14;
    PERCENTAGE_GetHundredsPosition((const u32 *)p, pos, pos + 1);
    CLACT_AddActorSurfacePos(h, (const struct Vec2 *)pos, ((struct Obj03958 *)q)->fC);
    CLACT_SetActorAnimSeq(h, ((struct Obj03958 *)q)->fE);
    CLACT_SetActorAnimFrame(h, PERCENTAGE_GetHundredsDigit((char *)p) << 12);
    CLACT_StopActorAnim(h);
    CLACT_SetActorDrawEnable(h, 0);

    h = ((struct Obj03957 *)p)->f18;
    PERCENTAGE_GetTensPosition((const u32 *)p, pos, pos + 1);
    CLACT_AddActorSurfacePos(h, (const struct Vec2 *)pos, ((struct Obj03958 *)q)->fC);
    CLACT_SetActorAnimSeq(h, ((struct Obj03958 *)q)->fE);
    CLACT_SetActorAnimFrame(h, PERCENTAGE_GetTensDigit((char *)p) << 12);
    CLACT_StopActorAnim(h);
    CLACT_SetActorDrawEnable(h, 0);

    h = ((struct Obj03957 *)p)->f1C;
    PERCENTAGE_GetOnesPosition((const u32 *)p, pos, pos + 1);
    CLACT_AddActorSurfacePos(h, (const struct Vec2 *)pos, ((struct Obj03958 *)q)->fC);
    CLACT_SetActorAnimSeq(h, ((struct Obj03958 *)q)->fE);
    CLACT_SetActorAnimFrame(h, PERCENTAGE_GetOnesDigit((char *)p) << 12);
    CLACT_StopActorAnim(h);
    CLACT_SetActorDrawEnable(h, z);
}
