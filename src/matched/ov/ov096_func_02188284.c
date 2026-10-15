/*
 * function: TR_AI_ThinkMulti
 * address:  0x02188284
 * packet:   pkt_ov096_02188284
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * note (2026-10-05, wD5 lane16): EXACT. The draw helper holds the random value in a u32 and
 *   widens a copy to u64 before the test (`u32 r = f(); u64 random = r; if (n) r = (random * n) >> 32;`).
 *   That makes the hi zero before the n test and keeps the result in r0, as at both original sites.
 *
 * symbols:
 *   TR_AI_GetPoke 0x0218A2FC thumb ov096
 *   TR_AI_ResetScores 0x0218A310 thumb ov096
 *   TR_AI_RememberLastMove 0x0218A324 thumb ov096
 *   TR_AI_GetMoveParam 0x0218A378 thumb ov096
 *   TR_AI_GetMoveFlag 0x0218A384 thumb ov096
 *   TR_AI_RunScripts 0x021885BC thumb ov096
 *   BTL_POKEPARAM_GetMoveCount 0x021D5448 thumb ov093
 *   BTL_POKEPARAM_GetMoveId 0x021D54C0 thumb ov093
 *   BTL_POKEPARAM_IsFainted 0x021D5B68 thumb ov093
 *   BTL_MAIN_IsPosInTable 0x021B9A6C thumb ov093
 *   BTL_MAIN_GetSlotClientIdThunk 0x021B8DE4 thumb ov093
 *   BTL_MAIN_IsOpposingPos 0x021B8CE8 thumb ov093
 *   func_020870D0 0x020870D0 arm
 *   GF_STANDARD_Rand 0x0203F0A8 arm
 *   _ull_mul 0x0209C054 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef enum { COUNT_ONE = 1 } Count;
typedef struct {
    u8 state, index;
    u16 move;
    int scores[4];
    u8 p14[0x10];
    short h24[6];
    signed char s30[6];
    u8 p36[6];
    u32 mask, all;
    u8 flags, entry, slot, target;
    u8 p48[0x4c];
    u8 side, opp;
    u8 p96[2];
    int mode;
    u8 p9c[0x14];
    int fb0, fb4, fb8;
    u8 *fbc, *fc0;
    int fc4;
    u8 pc8[8];
    u64 tick;
} Obj;
extern u8 *TR_AI_GetPoke(u8 *, u8);
extern void TR_AI_ResetScores(unsigned int a);
extern void TR_AI_RememberLastMove(u8 *);
extern int TR_AI_GetMoveParam(Obj *, int, int);
extern int TR_AI_GetMoveFlag(Obj *, int, int);
extern void TR_AI_RunScripts(int, u8 *);
struct QG;
extern u8 BTL_POKEPARAM_GetMoveCount(struct QG *p);
extern u16 BTL_POKEPARAM_GetMoveId(u8 *p, int i);
extern int BTL_POKEPARAM_IsFainted(void *p);
extern int BTL_MAIN_IsPosInTable(int, u32);
extern u8 BTL_MAIN_GetSlotClientIdThunk(char *p, int i);
extern int BTL_MAIN_IsOpposingPos(int, int, int);
extern u64 func_020870D0(void);
extern u32 GF_STANDARD_Rand(void);
inline static u32 draw_below(u32 n)
{
    u32 r = GF_STANDARD_Rand();
    u64 random = r;
    if (n != 0)
        r = (random * n) >> 32;
    return r;
}
int TR_AI_ThinkMulti(int a, Obj *b)
{
    int limit;
    int scores[4];
    u8 ids[4];
    u8 ids2[6];
    u32 mask;
    int next;
    u8 *entryPtr;
    u32 *maskPtr;
    u8 *flagsPtr;
    Count n;
    int i;
    int v;
    u8 j;
    int h;

    limit = (b->mode == 1) ? 4 : 6;
    if (!(b->flags & 16))
        b->opp = 0;
    while (b->opp < limit) {
        b->fbc = TR_AI_GetPoke((u8 *)b, b->side);
        b->fc0 = TR_AI_GetPoke((u8 *)b, b->opp);
        if (!(b->flags & 16)) {
            if (b->fc0 == 0) {
                b->s30[b->opp] = -1;
                b->h24[b->opp] = -1;
                goto next;
            }
            if (b->opp == b->side || BTL_POKEPARAM_IsFainted(b->fc0) == 1) {
                b->s30[b->opp] = -1;
                b->h24[b->opp] = -1;
                goto next;
            }
            TR_AI_ResetScores((unsigned int)((u8 *)b));
            TR_AI_RememberLastMove((u8 *)b);
            b->entry = 0;
            mask = b->all;
            b->index = 0;
            b->mask = mask;
        }
        if ((mask = b->mask) != 0) {
            flagsPtr = &b->flags;
            maskPtr = &b->mask;
            entryPtr = &b->entry;
            do {
                if (mask & 1) {
                    if (!(b->flags & 16)) b->state = 0;
                    *flagsPtr &= ~16;
                    b->tick = func_020870D0();
                    TR_AI_RunScripts(a, (u8 *)b);
                    if (b->flags & 16) return 1;
                }
                next = *entryPtr + 1;
                mask = *maskPtr >> 1;
                *entryPtr = next;
                *maskPtr = mask;
                b->index = 0;
            } while ((mask = *maskPtr) != 0);
        }
        if (b->flags & 2) {
            b->slot = 4;
            goto next;
        }
        n = COUNT_ONE;
        scores[0] = b->scores[0];
        ids[0] = 0;
        for (i = 1; i < 4; i++) {
            if (i < BTL_POKEPARAM_GetMoveCount((struct QG *)b->fbc)) {
                v = b->scores[i];
                if (scores[0] == v) {
                    scores[n] = v;
                    ids[n] = i;
                    n++;
                }
                if (scores[0] < v) {
                    scores[0] = v;
                    n = COUNT_ONE;
                    ids[0] = i;
                }
            }
        }
        b->s30[b->opp] = ids[draw_below(n)];
        b->h24[b->opp] = scores[0];
        if (BTL_MAIN_IsOpposingPos(b->fb0, BTL_MAIN_GetSlotClientIdThunk((char *)b->fb0, b->side), BTL_MAIN_GetSlotClientIdThunk((char *)b->fb0, b->opp)) == 0) {
            if (b->h24[b->opp] < 100)
                b->h24[b->opp] = -1;
        }
    next:
        b->opp = b->opp + 1;
    }
    h = b->h24[0];
    n = COUNT_ONE;
    ids2[0] = 0;
    for (j = 1; j < limit; j++) {
        v = b->h24[j];
        if (h == v) {
            ids2[n] = j;
            n++;
        }
        if (h < v) {
            h = v;
            ids2[0] = j;
            n = COUNT_ONE;
        }
    }
    b->target = ids2[draw_below(n)];
    b->slot = b->s30[b->target];
    if (TR_AI_GetMoveParam(b, BTL_POKEPARAM_GetMoveId(b->fbc, b->slot), 27) == 1 && !(b->target & 1))
        b->target = b->side;
    v = BTL_POKEPARAM_GetMoveId(b->fbc, b->slot);
    if (b->mode == 2 && BTL_MAIN_IsPosInTable(b->side, b->target) == 0 && TR_AI_GetMoveFlag(b, v, 11) == 0)
        b->target = (b->target & 1) + 2;
    return 0;
}
