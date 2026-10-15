/*
 * function: DUP_FITTING_UpdateActorTimers
 * address: 0x021B9F5C
 * packet: pkt_ov133_021B9F5C
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: Pointer addition for timer stores and unsigned address addition for the guard preserve four independent offset homes and the decrement reload. Uniform integer addition gave 292 bytes; uniform pointer addition gave 304.
 * note 2026-10-05 (wave D9r lane 131): removed the 5 dead first assignments
 * (`a = 0x1890;` before `a = 0x18b8;`; `b = 0x1890;` before `b = 0x18b8;`
 * and 3 more). Game code has no line table, so these were stand-ins. The
 * plain single assignment gives EXACT in --lang c99 and --lang c: the output
 * bytes do not change. Older text in this header that asks for the double
 * assignment is superseded.
 *
 * symbols:
 *   BG_SYS_Get 0x020416D4 arm
 *   CLACT_SetActorBgPriority 0x0204B84C arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   GF_STANDARD_Rand 0x0203F0A8 arm
 *   _ull_mul 0x0209C054 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
#include "../include/Obj06502.h"
#include "../include/Obj10572.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef short s16;
typedef struct { s16 x, y; } Pos;
extern u8 BG_SYS_Get(u32);
extern void CLACT_SetActorBgPriority(void *, u32);
struct Actor;
struct Obj;
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
extern u32 GF_STANDARD_Rand(void);
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern u32 CLACT_GetActorDrawEnable(struct Obj *p);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
void DUP_FITTING_UpdateActorTimers(u8 *p)
{
    int a, b, delay, c, d;
    Pos pos;
    u8 i;
    u8 *q, *t;
    a = 0x18b8;
    b = 0x18b8;
    delay = 0x190;
    c = 0x18b8;
    d = 0x18b8;
    for (i = 0; i < 8; i++) {
        q = p + i * 4;
        CLACT_SetActorBgPriority(((struct Obj06502 *)q)->f1890, BG_SYS_Get(4));
        CLACT_SetActorObjMode(((struct Obj06502 *)q)->f1890, 0);
        t = p + i;
        if (*(u8 *)((u32)p+(u32)i+(u32)d) == 0) {
            pos.x = ((u64)GF_STANDARD_Rand() * 56) >> 32;
            if ((u32)(((u64)GF_STANDARD_Rand() * 2) >> 32) == 1) pos.x = 256 - pos.x;
            pos.y = ((u64)GF_STANDARD_Rand() * 192) >> 32;
            CLACT_AddActorSurfacePos(((struct Obj06502 *)q)->f1890, (const struct Vec2 *)(&pos), 1);
            if (pos.y > 90) CLACT_SetActorAnimSeq(((struct Obj06502 *)q)->f1890, ((u64)GF_STANDARD_Rand() * 2) >> 32);
            else CLACT_SetActorAnimSeq(((struct Obj06502 *)q)->f1890, (((u64)GF_STANDARD_Rand() * 2) >> 32) + 2);
            t[c] = (((u64)GF_STANDARD_Rand() * 200) >> 32) + delay;
        } else {
            t[b] = t[a] - 1;
        }
    }
    if (CLACT_GetActorDrawEnable(((struct Obj10572 *)p)->f18B4) == 1 && CLACT_IsActorAnimActive(((struct Obj10572 *)p)->f18B4) == 0) {
        CLACT_SetActorDrawEnable(((struct Obj10572 *)p)->f18B4, 0);
    }
}
