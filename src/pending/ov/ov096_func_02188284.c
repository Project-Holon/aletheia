/*
 * function: func_02188284
 * address:  0x02188284
 * packet:   pkt_ov096_02188284
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * note (2026-10-04, wave D3 lane 13): same size (824), 24 bytes differ, rest identical.
 *   Sibling logic: ov096_func_0218814C (candidate draw) and ov096_func_021885BC.
 *   Residue 1 (+0x8C): `opp != side` compare, original loads opp into r2 and side
 *   into r1 (cmp r2,r1), ours r1/r0.  Swapping operands made it worse (43 bytes).
 *   Residue 2 (+0x1AE, first draw_below site): original `movs r1,#0` right after
 *   func_0203F0A8 and idx in r0 with the ids base in r1 (`ldrb r1,[r1,r0]`); ours
 *   copies r0 to r1 and uses base r0 / idx r1.  Tried: temp int for the draw, temp
 *   for the index.  Fixes found: ids2[6] as a separate array (frame 0x24), declaring
 *   `u8 j` before `int h`, storing ids2[0] before n in the second tie loop.
 *   Callees func_021B8DE4 and func_021B8CE8 are unresolved (12 overlays overlap 0x021B8xxx; ov067 is a guess, the tool rejects the hint); the overlay that holds them needs a witness.
 *
 * note (2026-10-05, wD4 lane05): 17 bytes, one site left. Closed: func_021D5B68 takes one argument, b->fc0
 *   (keeps r0 live, fixes the opp/side compare); func_021B8DE4 and func_021B8CE8 resolve with the ov093 hint
 *   (ov093 sits beside ov096). Residue: first draw_below site (+0x1AE), original makes the u64 hi zero in r1 and
 *   copies it to r3 for n, result in r0; ours makes r3 = 0 first and the result lands in r1. An explicit block
 *   with signed n gives the right registers but adds asrs r3,r6,#0x1f; with (u32)n it is back to the inline result.
 *   Also tried (no change): n as u32 or int, the draw result in i or v before the index, (u32)n * random.
 *
 * symbols:
 *   func_0218A2FC 0x0218A2FC thumb ov096
 *   func_0218A310 0x0218A310 thumb ov096
 *   func_0218A324 0x0218A324 thumb ov096
 *   func_0218A378 0x0218A378 thumb ov096
 *   func_0218A384 0x0218A384 thumb ov096
 *   func_021885BC 0x021885BC thumb ov096
 *   func_021D5448 0x021D5448 thumb ov093
 *   func_021D54C0 0x021D54C0 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021B9A6C 0x021B9A6C thumb ov093
 *   func_021B8DE4 0x021B8DE4 thumb ov093
 *   func_021B8CE8 0x021B8CE8 thumb ov093
 *   func_020870D0 0x020870D0 arm
 *   func_0203F0A8 0x0203F0A8 arm
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
extern u8 *func_0218A2FC(u8 *, u8);
extern void func_0218A310(unsigned int a);
extern void func_0218A324(u8 *);
extern int func_0218A378(Obj *, int, int);
extern int func_0218A384(Obj *, int, int);
extern void func_021885BC(int, u8 *);
extern u8 func_021D5448(u8 *);
extern u16 func_021D54C0(u8 *p, int i);
extern int func_021D5B68(u8 *);
extern int func_021B9A6C(int, u32);
extern int func_021B8DE4(int, u8);
extern int func_021B8CE8(int, int, int);
extern u64 func_020870D0(void);
extern u32 func_0203F0A8(void);
inline static u32 draw_below(u32 n) { u64 random=func_0203F0A8(); if(n!=0) random=(random*n)>>32; return random; }
int func_02188284(int a, Obj *b)
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
        b->fbc = func_0218A2FC((u8 *)b, b->side);
        b->fc0 = func_0218A2FC((u8 *)b, b->opp);
        if (!(b->flags & 16)) {
            if (b->fc0 == 0) {
                b->s30[b->opp] = -1;
                b->h24[b->opp] = -1;
                goto next;
            }
            if (b->opp == b->side || func_021D5B68(b->fc0) == 1) {
                b->s30[b->opp] = -1;
                b->h24[b->opp] = -1;
                goto next;
            }
            func_0218A310((unsigned int)((u8 *)b));
            func_0218A324((u8 *)b);
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
                    func_021885BC(a, (u8 *)b);
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
            if (i < func_021D5448(b->fbc)) {
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
        if (func_021B8CE8(b->fb0, func_021B8DE4(b->fb0, b->side), func_021B8DE4(b->fb0, b->opp)) == 0) {
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
    if (func_0218A378(b, func_021D54C0(b->fbc, b->slot), 27) == 1 && !(b->target & 1))
        b->target = b->side;
    v = func_021D54C0(b->fbc, b->slot);
    if (b->mode == 2 && func_021B9A6C(b->side, b->target) == 0 && func_0218A384(b, v, 11) == 0)
        b->target = (b->target & 1) + 2;
    return 0;
}
