/*
 * function: func_0202EB04
 * address:  0x0202EB04
 * packet:   pkt_0202EA40
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * blink_palanm.c: resets the fade phase word at +0x10 of the blink context
 * (the word func_0202EA40 advances by 0x400 per frame).  An unlabelled leaf
 * with no prologue sitting after func_0202EA40's pool word at 0x0202EB00, so
 * the listing folds it into func_0202EA40's extent (204 against the real
 * 196); seed 0x0202EB04 into layout/function_starts.txt.
 */
typedef unsigned short u16;
typedef unsigned int   u32;

struct CodeIn {
    void *w00;
    void *w04;
    void *buf;
    u16   h0c;
    u16   h0e;
    u16   h10;
};

void func_0202EB04(struct CodeIn *p)
{
    p->h10 = 0;
}
