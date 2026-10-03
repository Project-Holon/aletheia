/*
 * function: func_020238B4
 * address:  0x020238B4
 * packet:   pkt_0202384C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02023964  0x02023964  thumb
 *
 * The constructor of the wipe task whose per-frame step is func_0202390C:
 * it allocates the 0x334-byte sub-object from the task's own heap id,
 * zeroes it, hands the task's five parameter words to func_02023964 and
 * advances the phase.  The sibling of func_02023464 (which builds the
 * 0x4c-byte object at the other end of the family) and of func_020235F0.
 *
 * 0x334 is past every Thumb immediate, and it is needed TWICE (the
 * allocation size and the memset length), so it is materialised once into
 * a callee-saved register (movs #0xcd / lsls #2) and reused rather than
 * spelled at each site; writing it as a literal at both sites costs a pool
 * word.  That is what makes r6 live across the first call.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020238B4.c \
 *       --func func_020238B4 --addr 0x020238B4 --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Task {
    u32   f00;
    u32   f04;
    u32   f08;
    u32   phase;  /* 0x0c */
    u32   f10;
    void *obj;    /* 0x14 */
    u32   f18;
    u32   f1c;
    u32   f20;    /* 0x20 */
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void  func_02082BCC(void *p, u32 v, u32 n);
extern void  func_02023964(void *obj, u32 a1, u32 a2, u32 a3, u32 a4,
                           u32 a5, u32 a6, u32 a7);

void func_020238B4(struct Task *t, u32 a1)
{
    t->obj = func_02030734((u16)t->f20, 0x334, 0, (const char *)0x020A7450, 0x1354);
    func_02082BCC(t->obj, 0, 0x334);
    func_02023964(t->obj, a1, t->f04, t->f08, t->f10, t->f18, t->f1c,
                  t->f20);
    t->phase = t->phase + 1;
}
