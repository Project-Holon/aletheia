/*
 * function: func_02022640
 * address:  0x02022640
 * packet:   pkt_02022174
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Arms the deferred screen task for one of the two sub-objects func_0202208C
 * built, but only for a screen that is still idle: the task handle at +0x28
 * must be null, the resolved sentinel value at +0x24 must be either the
 * pass-through 0x7FFF or zero, and the second handle at +0x2C must be null
 * too.  All three rejections share one epilogue, so the guard is written as a
 * single conjunction rather than a chain of early returns; see
 * docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md.
 *
 * symbols:
 *   func_020056A0  0x020056A0  thumb
 *   func_0202262C  0x0202262C  thumb
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022640.c \
 *       --func func_02022640 --addr 0x02022640 --cc 1.1p1 --thumb
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef void (*Task)(void *p);

struct Screen {
    u8    pad00[0x24];
    u16   f24;
    u16   f26;
    void *f28;
    void *f2C;
};

extern void func_020056A0(Task fn, void *arg, u32 prio);
extern void func_0202262C(void *p);

void func_02022640(struct Screen *s)
{
    if (s->f28 == 0 && (s->f24 == 0x7FFF || s->f24 == 0) && s->f2C == 0)
        func_020056A0(func_0202262C, s, 1 << 10);
}
