/*
 * function: WIPE_SUB_InitRectInterp
 * address:  0x02022940
 * packet:   pkt_02022940
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   WIPE_SUB_CalcStep  0x0202290C  thumb
 *
 * wipe.c: seeds a four-channel fade.  cur = from << 7 (fixed point), end =
 * to, step = WIPE_SUB_CalcStep(from, to, frames) per channel; called from
 * WIPE_SUB_BoxInit with (obj, &obj->f20, &obj->f10, cfg, cfg + 4, frames).
 * WIPE_SUB_CalcStep returns its tail callee's value here (the unit that
 * matched it declares it void; the caller stores r0).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SUB_InitRectInterp.c  *       --func WIPE_SUB_InitRectInterp --addr 0x02022940 --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef int           s32;

struct Quad {
    s32 a, b, c, d;
};

extern s32 WIPE_SUB_CalcStep(s32 a, s32 b, s32 c);

void WIPE_SUB_InitRectInterp(struct Quad *cur, struct Quad *end, struct Quad *step,
                   const u8 *from, const u8 *to, s32 frames)
{
    cur->a = from[0] << 7;
    cur->b = from[1] << 7;
    cur->c = from[2] << 7;
    cur->d = from[3] << 7;
    end->a = to[0];
    end->b = to[1];
    end->c = to[2];
    end->d = to[3];
    step->a = WIPE_SUB_CalcStep(from[0], to[0], frames);
    step->b = WIPE_SUB_CalcStep(from[1], to[1], frames);
    step->c = WIPE_SUB_CalcStep(from[2], to[2], frames);
    step->d = WIPE_SUB_CalcStep(from[3], to[3], frames);
}
