/*
 * function: func_02064120
 * address:  0x02064120
 * packet:   pkt_020640DC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * The scale setter of the same three-function family as func_020640DC: four
 * bytes short for the same reason, the original's predicated early return
 * (`bxne lr`) against this compiler's if-converted block.  The two scale words
 * fuse into one `stmib r0, {r1, r2}`.  See
 * docs/notes/g2d_srt_setters.c.txt.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02064120.c \
 *       --func func_02064120 --addr 0x02064120 --arm --cc 1.1p1
 */

typedef unsigned short u16;
typedef signed short   s16;
typedef signed int     s32;
typedef unsigned int   u32;

struct Srt02064120 {
    u32 mode;
    s32 scaleX;
    s32 scaleY;
    s16 tx;
    s16 ty;
    u16 rot;
    u16 dirty;
};

void func_02064120(volatile struct Srt02064120 *p, s32 scaleX, s32 scaleY)
{
    if (p->mode != 1) {
        return;
    }
    p->dirty |= 2;
    p->scaleX = scaleX;
    p->scaleY = scaleY;
}
