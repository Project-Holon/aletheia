/*
 * function: func_02064100
 * address:  0x02064100
 * packet:   pkt_020640DC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * The rotation setter of the same three-function family as func_020640DC:
 * four bytes short for the same reason, the original's predicated early
 * return (`bxne lr`) against this compiler's if-converted block.  See
 * docs/notes/g2d_srt_setters.c.txt.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02064100.c \
 *       --func func_02064100 --addr 0x02064100 --arm --cc 1.1p1
 */

typedef unsigned short u16;
typedef signed short   s16;
typedef signed int     s32;
typedef unsigned int   u32;

struct Srt02064100 {
    u32 mode;
    s32 scaleX;
    s32 scaleY;
    s16 tx;
    s16 ty;
    u16 rot;
    u16 dirty;
};

void func_02064100(volatile struct Srt02064100 *p, u16 rot)
{
    if (p->mode != 1) {
        return;
    }
    p->dirty |= 4;
    p->rot = rot;
}
