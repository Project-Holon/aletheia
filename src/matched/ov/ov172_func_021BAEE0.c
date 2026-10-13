/*
 * function: func_021BAEE0
 * address:  0x021BAEE0
 * packet:   pkt_ov172_021BAEE0
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TOUCHPANEL_HitTrg  0x02035C08  arm
 *   CLACT_GetActorDrawEnable  0x0204B3F4  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   func_021BB54C  0x021BB54C  thumb  ov172
 *   func_021BE0B8  0x021BE0B8  thumb  ov172
 *   CLACT_RestartActorAnim  0x0204B9A0  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   KEY_GetTrg  0x020362DC  arm
 *   func_021BB65C  0x021BB65C  thumb  ov172
 *   func_021BB9E4  0x021BB9E4  thumb  ov172
 *   CLACT_IsActorAnimActive  0x0204B98C  arm
 *   d_021C6FF8     0x021C6FF8  data
 *   d_021C7014     0x021C7014  data
 *   d_021C6FBC     0x021C6FBC  data
 *   d_021C7030     0x021C7030  data
 *   d_021C6FDC     0x021C6FDC  data
 *   d_021C6FC8     0x021C6FC8  data
 *   d_021C7034     0x021C7034  data
 *   d_021C7038     0x021C7038  data
 *   d_021C703C     0x021C703C  data
 */
#include "../include/Obj00024.h"

typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned long u32;

struct SpritePos {
    s16 x;
    s16 y;
};

extern int TOUCHPANEL_HitTrg(const void *p);
struct Actor;
struct Obj;
extern u32 CLACT_GetActorDrawEnable(struct Obj *p);
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern void CLACT_SetActorAutoAnim(struct Obj *p, unsigned int v);
extern void GFL_USE_PlaySeDefaultVolume(u32 id);
extern void func_021BB54C(void *ctx, u8 *p);
extern void func_021BE0B8(void *ctx);
extern void CLACT_RestartActorAnim(struct Actor *a);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern u32 KEY_GetTrg(void);
extern void func_021BB65C(void *ctx, u8 *p, int v);
extern void func_021BB9E4(void *a0, char *a1);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern const u8 d_021C6FF8[];
extern const u8 d_021C7014[];
extern const u32 d_021C6FBC[];
extern const struct SpritePos d_021C7030;
extern const u8 d_021C6FDC[];
extern const u32 d_021C6FC8[];
extern const struct SpritePos d_021C7034;
extern const struct SpritePos d_021C7038;
extern const struct SpritePos d_021C703C;

void func_021BAEE0(void *ctx, u8 *p)
{
    struct SpritePos pa;
    struct SpritePos pb;
    struct SpritePos pc;
    struct SpritePos pd;
    int k;
    int j;

    k = TOUCHPANEL_HitTrg(d_021C6FF8);
    if (k == 0 && CLACT_GetActorDrawEnable(((struct Obj00024 *)p)->f8C) == 0) {
        ((struct Obj00024 *)p)->f28 = 0;
        ((struct Obj00024 *)p)->f24 = 0;
        func_021BB54C(ctx, p);
        ((struct Obj00024 *)p)->f8 = 1;
        ((struct Obj00024 *)p)->f10 = 1;
        CLACT_SetActorDrawEnable(((struct Obj00024 *)p)->f84, 1);
        CLACT_SetActorAutoAnim(((struct Obj00024 *)p)->f84, 1);
        GFL_USE_PlaySeDefaultVolume(0x66c);
    }
    if (k == 1) {
        ((struct Obj00024 *)p)->f28 = 1;
        func_021BB54C(ctx, p);
        ((struct Obj00024 *)p)->f8 = 1;
        GFL_USE_PlaySeDefaultVolume(0x66c);
    }
    if (k == 2) {
        ((struct Obj00024 *)p)->f28 = 2;
        func_021BB54C(ctx, p);
        ((struct Obj00024 *)p)->f8 = 1;
        GFL_USE_PlaySeDefaultVolume(0x66c);
    }
    if (k == 3 && CLACT_GetActorDrawEnable(((struct Obj00024 *)p)->f8C) == 0) {
        ((struct Obj00024 *)p)->f28 = 3;
        ((struct Obj00024 *)p)->f24 = 1;
        func_021BB54C(ctx, p);
        ((struct Obj00024 *)p)->f8 = 1;
        ((struct Obj00024 *)p)->f14 = 1;
        CLACT_SetActorDrawEnable(((struct Obj00024 *)p)->f88, 1);
        CLACT_SetActorAutoAnim(((struct Obj00024 *)p)->f88, 1);
        GFL_USE_PlaySeDefaultVolume(0x66c);
    }
    if (k == 4) {
        func_021BE0B8(ctx);
        func_021BB54C(ctx, p);
        ((struct Obj00024 *)p)->f8 = 1;
        GFL_USE_PlaySeDefaultVolume(0x66f);
    }
    if (((struct Obj00024 *)p)->f10 == 1) {
        j = TOUCHPANEL_HitTrg(d_021C7014);
        if (j != -1) {
            p[0x36] = d_021C6FBC[j];
            ((struct Obj00024 *)p)->f8 = 1;
            pa = d_021C7030;
            CLACT_SetActorDrawEnable(((struct Obj00024 *)p)->f8C, 1);
            CLACT_RestartActorAnim(((struct Obj00024 *)p)->f8C);
            CLACT_SetActorAutoAnim(((struct Obj00024 *)p)->f8C, 1);
            CLACT_SetActorAnimSeq(((struct Obj00024 *)p)->f8C, (u16)(j + 0x11));
            CLACT_AddActorSurfacePos(((struct Obj00024 *)p)->f8C, (const struct Vec2 *)(&pa), 0);
            CLACT_SetActorDrawEnable(((struct Obj00024 *)p)->f90, 0);
            GFL_USE_PlaySeDefaultVolume(0x66c);
        }
    }
    if (((struct Obj00024 *)p)->f14 == 1) {
        j = TOUCHPANEL_HitTrg(d_021C6FDC);
        if (j != -1) {
            p[0x37] = d_021C6FC8[j];
            ((struct Obj00024 *)p)->f8 = 1;
            GFL_USE_PlaySeDefaultVolume(0x66c);
            pb = d_021C7034;
            CLACT_SetActorDrawEnable(((struct Obj00024 *)p)->f8C, 1);
            CLACT_RestartActorAnim(((struct Obj00024 *)p)->f8C);
            CLACT_SetActorAutoAnim(((struct Obj00024 *)p)->f8C, 1);
            CLACT_SetActorAnimSeq(((struct Obj00024 *)p)->f8C, (u16)(j + 0x14));
            CLACT_AddActorSurfacePos(((struct Obj00024 *)p)->f8C, (const struct Vec2 *)(&pb), 0);
            CLACT_SetActorDrawEnable(((struct Obj00024 *)p)->f90, 0);
        }
    }
    if ((KEY_GetTrg() & 0x400) || (KEY_GetTrg() & 2) || k == 5) {
        if (*(int *)&((struct Obj00024 *)p)->f38 == 0) {
            ((struct Obj00024 *)p)->f0 = 4;
            p[4] = 0x18;
            ((struct Obj00024 *)p)->f8 = 1;
            func_021BB65C(ctx, p, 0);
            func_021BB9E4(ctx, (char *)p);
            GFL_USE_PlaySeDefaultVolume(0x551);
            CLACT_SetActorAnimSeq(((struct Obj00024 *)p)->f6C, 9);
        }
    }
    if (KEY_GetTrg() & 0xc) {
        func_021BE0B8(ctx);
        func_021BB54C(ctx, p);
        GFL_USE_PlaySeDefaultVolume(0x66f);
    }
    if (CLACT_GetActorDrawEnable(((struct Obj00024 *)p)->f8C) == 1 && CLACT_IsActorAnimActive(((struct Obj00024 *)p)->f8C) == 0) {
        func_021BB9E4(ctx, (char *)p);
    }
    if (((struct Obj00024 *)p)->f10 == 1 && CLACT_IsActorAnimActive(((struct Obj00024 *)p)->f84) == 0 && CLACT_GetActorDrawEnable(((struct Obj00024 *)p)->f90) == 0) {
        pc = d_021C7038;
        switch (p[0x36]) {
        case 1:
            pc.x = pc.x + 0x10;
            break;
        case 0:
            pc.x = pc.x + 0x20;
            break;
        case 2:
            break;
        }
        CLACT_AddActorSurfacePos(((struct Obj00024 *)p)->f90, (const struct Vec2 *)(&pc), 0);
        CLACT_SetActorDrawEnable(((struct Obj00024 *)p)->f90, 1);
    }
    if (((struct Obj00024 *)p)->f14 == 1 && CLACT_IsActorAnimActive(((struct Obj00024 *)p)->f88) == 0 && CLACT_GetActorDrawEnable(((struct Obj00024 *)p)->f90) == 0) {
        pd = d_021C703C;
        switch (p[0x37]) {
        case 3:
            pd.x = pd.x - 0x20;
            break;
        case 4:
            pd.x = pd.x - 0x10;
            break;
        case 6:
            pd.x = pd.x + 0x10;
            break;
        case 7:
            pd.x = pd.x + 0x20;
            break;
        }
        CLACT_AddActorSurfacePos(((struct Obj00024 *)p)->f90, (const struct Vec2 *)(&pd), 0);
        CLACT_SetActorDrawEnable(((struct Obj00024 *)p)->f90, 1);
    }
}
