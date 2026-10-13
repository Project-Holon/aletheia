/*
 * function: func_021BA2B4
 * address: 0x021BA2B4
 * packet: pkt_ov223_021BA2B4
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   _fgr 0x0209BBB0 arm
 *   _ffltu 0x0209BE04 arm
 *   _ffix 0x0209C494 arm
 *   _fmul 0x0209C77C arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _fdiv 0x0209CE10 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorScale 0x0204B5AC arm
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_SetActorDrawPriority 0x0204B800 arm
 *   CLACT_SetActorBgPriority 0x0204B84C arm
 *   func_021BA0AC 0x021BA0AC thumb ov223
 *   d_021BC7F0 0x021BC7F0 data
 *   d_021BC8C0 0x021BC8C0 data ov223
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef struct Vec2 { s16 x, y; } Vec2;
typedef struct FxPair { int x, y; } FxPair;
struct Obj;
typedef struct Entry {
    u8 pad0[0x18];
    struct Obj *f18;
    struct Obj *f1C;
    u8 pad20[0x84 - 0x20];
    u16 f84;
    u16 pad86;
    u32 f88;
    int f8C;
    int f90;
} Entry;
typedef struct Main {
    u8 pad0[0x54];
    Entry ents[3];
    u8 pad210[0x230 - 0x210];
    int f230;
} Main;
#define FIX(x) ((int)(((x)>0)?((x)*4096.0f+.5f):((x)*4096.0f-.5f)))
extern const u8 d_021BC7F0[3][14];
extern const u8 d_021BC8C0[3];
extern void CLACT_SetActorDrawEnable(struct Obj *, u32);
extern void CLACT_AddActorSurfacePos(struct Obj *, const Vec2 *, u32);
struct Pair;
extern void CLACT_SetActorScale(struct Obj *dst, struct Pair *src);
struct Actor;
struct Node;
struct PtS;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
extern void CLACT_SetActorDrawPriority(struct Node *node, u32 val);
extern void CLACT_SetActorBgPriority(struct Obj *, u32);
extern int func_021BA0AC(s16 *pos, int *size, u16 a, u16 b, u8 c, u8 d, u8 e, u8 f, u32 duration, u8 amplitude, u32 time);
void func_021BA2B4(Main *p)
{
    int flags[3] = {0, 0, 0};
    s16 res[3];
    u8 i;
    for (i = 0; i < 3; i++) {
        Entry *e = &p->ents[i];
        const u8 *t = d_021BC7F0[i];
        int d = 0;
        if (e->f8C == 0)
            continue;
        switch (e->f8C) {
        case 0: break;
        case 1: d = 1; break;
        case 2: d = -1; break;
        }
        if (d < 0) {
            e->f84 = 0;
            e->f88 = 1;
        }
        switch (e->f88) {
        case 0:
            if (d > 0) {
                CLACT_SetActorDrawEnable(e->f18, 0);
                CLACT_SetActorDrawEnable(e->f1C, 1);
                e->f84 = 0;
                e->f88 = 1;
                e->f90 = 0;
            } else {
                if (e->f8C == 2)
                    e->f8C = 0;
                break;
            }
        case 1:
            if (e->f84 == 0) {
                Vec2 v1;
                FxPair s1;
                u8 n1;
                v1.x = t[0];
                v1.y = t[1];
                n1 = t[6];
                s1.x = s1.y = FIX((float)n1 / 16.0f);
                CLACT_AddActorSurfacePos(e->f1C, &v1, 1);
                CLACT_SetActorScale(e->f1C, (struct Pair *)(&s1));
            } else {
                Vec2 a1;
                FxPair b1;
                res[i] = func_021BA0AC((s16 *)(&a1), (int *)(&b1), t[0], t[1], t[2], t[3], t[6], t[7], t[10], t[12], e->f84);
                flags[i] = 1;
                CLACT_AddActorSurfacePos(e->f1C, &a1, 1);
                CLACT_SetActorScale(e->f1C, (struct Pair *)(&b1));
            }
            if (e->f84 == 0 && d < 0) {
                CLACT_SetActorDrawEnable(e->f18, 1);
                CLACT_SetActorDrawEnable(e->f1C, 0);
                e->f84 = 0;
                e->f88 = 0;
                e->f90 = 0;
                break;
            }
            e->f84 = e->f84 + d;
            e->f90 = 0;
            if (e->f84 == t[10]) {
                e->f84 = 0;
                e->f88 = 2;
            }
            break;
        case 2: {
            Vec2 v2;
            FxPair s2;
            u8 n2;
            v2.x = t[2];
            v2.y = t[3];
            n2 = t[7];
            s2.x = s2.y = FIX((float)n2 / 16.0f);
            CLACT_AddActorSurfacePos(e->f1C, &v2, 1);
            CLACT_SetActorScale(e->f1C, (struct Pair *)(&s2));
            if (e->f84 == 0 && d < 0) {
                e->f84 = t[10] - 1;
                e->f88 = 1;
                e->f90 = 0;
                break;
            }
            e->f84 = e->f84 + d;
            e->f90 = 0;
            if (e->f84 == t[9]) {
                e->f84 = 0;
                e->f88 = 3;
            }
            break;
        }
        case 3:
            if (e->f84 == 0) {
                Vec2 v3;
                FxPair s3;
                u8 n3;
                v3.x = t[2];
                v3.y = t[3];
                n3 = t[7];
                s3.x = s3.y = FIX((float)n3 / 16.0f);
                CLACT_AddActorSurfacePos(e->f1C, &v3, 1);
                CLACT_SetActorScale(e->f1C, (struct Pair *)(&s3));
            } else {
                Vec2 a3;
                FxPair b3;
                res[i] = func_021BA0AC((s16 *)(&a3), (int *)(&b3), t[2], t[3], t[4], t[5], t[7], t[8], t[11], t[13], e->f84);
                flags[i] = 1;
                CLACT_AddActorSurfacePos(e->f1C, &a3, 1);
                CLACT_SetActorScale(e->f1C, (struct Pair *)(&b3));
            }
            if (e->f84 == 0 && d < 0) {
                e->f84 = t[9] - 1;
                e->f88 = 2;
                e->f90 = 0;
                break;
            }
            e->f84 = e->f84 + d;
            e->f90 = 0;
            if (e->f84 == t[11]) {
                e->f84 = 0;
                e->f88 = 4;
            }
            break;
        case 4: {
            Vec2 v4;
            FxPair s4;
            u8 n4;
            v4.x = t[4];
            v4.y = t[5];
            n4 = t[8];
            s4.x = s4.y = FIX((float)n4 / 16.0f);
            CLACT_AddActorSurfacePos(e->f1C, &v4, 1);
            CLACT_SetActorScale(e->f1C, (struct Pair *)(&s4));
            if (d < 0) {
                CLACT_SetActorBgPriority(e->f1C, 3);
                e->f84 = t[11] - 1;
                e->f88 = 3;
                e->f90 = 0;
                break;
            }
            if (e->f8C == 1) {
                CLACT_SetActorBgPriority(e->f1C, 2);
                e->f8C = 0;
                if (e->f90 == 0)
                    p->f230 = 1;
            }
            break;
        }
        }
    }
    {
    u8 order[3];
    s16 z[3];
    Vec2 pos;
    u8 j;
    order[0] = d_021BC8C0[0];
    order[1] = d_021BC8C0[1];
    order[2] = d_021BC8C0[2];
    for (i = 0; i < 3; i++) {
        if (flags[i]) {
            z[i] = res[i];
        } else {
            CLACT_GetActorSurfacePos((struct Actor *)p->ents[i].f1C, (struct PtS *)(&pos), 1);
            z[i] = pos.y;
        }
    }
    for (i = 0; i < 3; i++) {
        for (j = 2; j > i; j--) {
            u8 a = order[j - 1];
            u8 b = order[j];
            if (z[b] > z[a]) {
                order[j - 1] = b;
                order[j] = a;
            }
        }
    }
    for (i = 0; i < 3; i++) {
        u32 pr;
        if (order[0] == i)
            pr = 0;
        else {
            pr = 1;
            if (order[1] != i)
                pr = 2;
        }
        CLACT_SetActorDrawPriority((struct Node *)p->ents[i].f1C, pr);
    }
    }
}
