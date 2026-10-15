/*
 * function: TR_AI_ThinkSingle
 * address: 0x0218814C
 * packet: pkt_ov096_0218814C
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Lever: guarded named field pointers retain the 0x18 frame; entry/mask
 * declaration order fixes r7/r6; u64 draw puts its high-word zero before
 * the count guard. All 9 relocation sites resolve.
 * symbols:
 *   TR_AI_GetPoke 0x0218A2FC thumb ov096
 *   TR_AI_ResetScores 0x0218A310 thumb ov096
 *   TR_AI_RememberLastMove 0x0218A324 thumb ov096
 *   TR_AI_RunScripts 0x021885BC thumb ov096
 *   BTL_POKEPARAM_GetMoveCount 0x021D5448 thumb ov093
 *   func_020870D0 0x020870D0 arm
 *   GF_STANDARD_Rand 0x0203F0A8 arm
 *   _ull_mul 0x0209C054 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef enum { COUNT_ONE = 1 } Count;
typedef struct { u8 state, index; unsigned short move; int scores[4]; u8 p14[0x28]; u32 mask, all; u8 flags, entry, slot, target; u8 p48[0x4c]; u8 side, opp; u8 p96[0x1a]; int fb0, fb4, fb8; u8 *fbc, *fc0; int fc4; u8 pc8[8]; u64 tick; } Obj;
extern u8 *TR_AI_GetPoke(u8 *, u8);
extern void TR_AI_ResetScores(unsigned int a);
extern void TR_AI_RememberLastMove(u8 *);
extern void TR_AI_RunScripts(int, u8 *);
struct QG;
extern u8 BTL_POKEPARAM_GetMoveCount(struct QG *p);
extern u64 func_020870D0(void);
extern u32 GF_STANDARD_Rand(void);
inline static u32 draw_below(u32 n) { u64 random=GF_STANDARD_Rand(); if(n!=0) random=(random*n)>>32; return random; }
int TR_AI_ThinkSingle(int a, Obj *b)
{
    int scores[4];
    u8 ids[4];
    long i;
    int v;
    Count n;

    u32 mask;
    int next;
    u8 *entryPtr;
    u32 *maskPtr;
    u8 *flagsPtr;
    b->fbc = TR_AI_GetPoke((u8 *)b, b->side);
    b->fc0 = TR_AI_GetPoke((u8 *)b, b->opp);
    if (!(b->flags & 16)) {
        TR_AI_ResetScores((unsigned int)((u8 *)b));
        TR_AI_RememberLastMove((u8 *)b);
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
    } else {
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
        b->slot = ids[draw_below(n)];
    }
    b->target = b->opp;
    return 0;
}
