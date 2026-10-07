/*
 * file:     unit_021B1498_p01.c
 * unit:     yes
 * function: func_021B1498, func_021B14A8, func_021B14F8, func_021B1588, func_021B1634, func_021B1688, func_021B16B4
 * address:  0x021B1498
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021B4BA0 0x021B4BA0 data a4
 *   func_02087988  0x02087988  arm
 *   func_0208799C  0x0208799C  arm
 *   d_021B4B98  0x021B4B98  data  a4
 *   d_021B3C28 0x021B3C28 data a4
 */
typedef unsigned int u32;

typedef struct Node { u32 f0; struct Node *prev; struct Node *next; u32 f0c; unsigned char f10; unsigned char type; } Node;

extern u32 func_02087988(void);
extern void func_0208799C(u32 h);
int func_021B1498(unsigned int i);
Node *func_021B14A8(u32 type);
u32 func_021B14F8(Node *n);
void func_021B1588(unsigned char *dst, const short *src, unsigned int n);
void func_021B1634(unsigned char *src, short *dst, unsigned int n);
void func_021B1688(unsigned char *dst, short *src, unsigned int n);
void func_021B16B4(signed char *src, short *dst, unsigned int n, int fmt);
extern int d_021B4BA0[];
extern Node *d_021B4B98[2];
extern const int d_021B3C28[8];

int func_021B1498(unsigned int i) { return d_021B4BA0[i]; }


Node *func_021B14A8(u32 type)
{
    Node *p = d_021B4B98[0];
    u32 h = func_02087988();

    for (; p; p = p->next) {
        if (p->type == type) {
            func_0208799C(h);
            return p;
        }
    }
    func_0208799C(h);
    return 0;
}


u32 func_021B14F8(Node *n)
{
    u32 h = func_02087988();

    if (n->prev)
        n->prev->next = n->next;
    else {
        d_021B4B98[0] = n->next;
        if (n->next)
            n->next->prev = 0;
    }
    if (n->next)
        n->next->prev = n->prev;
    else {
        d_021B4B98[1] = n->prev;
        if (n->prev)
            n->prev->next = 0;
    }
    d_021B4BA0[n->type]--;
    func_0208799C(h);
    return d_021B4BA0[n->type];
}


/*
 * note: 2026-10-05 tried forms (all DIFF 26/172): an inline encode() with an
 *   inline seg_search() helper, mask types and orders, clamp spellings,
 *   pragmas opt_lifetimes, scheduling, peephole, opt_common_subs,
 *   opt_propagation, opt_dead_assignments, opt_dead_code,
 *   opt_strength_reduction, opt_loop_invariants.
 * note: pass 2 2026-10-06 P2L37: EXACT. The u-law encode is written in the
 *   loop body (no inline helpers). The segment search uses seg as its own
 *   counter, with a goto on a hit and seg = 8 on fall-through, as the helper's
 *   "return size". The code value goes through an int uval and the store is
 *   dst[i] = uval ^ mask. With the inline helpers, the mask and the segment
 *   counter swapped registers (r5/r6).
 */
void func_021B1588(unsigned char *dst, const short *src, unsigned int n)
{
    unsigned int i;

    for (i = 0; i < n; i++) {
        int s, seg, uval;
        unsigned char mask;
        const int *tab;

        s = src[i] >> 2;
        if (s < 0) {
            mask = 0x7f;
            s = -s;
        } else {
            mask = 0xff;
        }
        if (s > 8159)
            s = 8159;
        tab = d_021B3C28;
        for (seg = 0; seg < 8; seg++)
            if (s + 0x21 <= *tab++)
                goto found;
        seg = 8;
    found:
        if (seg >= 8) {
            dst[i] = 0x7f ^ mask;
        } else {
            uval = (seg << 4) | (((s + 0x21) >> (seg + 1)) & 0xf);
            dst[i] = uval ^ mask;
        }
    }
}

void func_021B1634(unsigned char *src, short *dst, unsigned int n)
{
    unsigned int i;

    for (i = 0; i < n; i++) {
        int u = ~src[i];
        int t = (((u & 0xf) << 3) + 0x84) << ((u & 0x70) >> 4);

        dst[i] = (u & 0x80) ? 0x84 - t : t - 0x84;
    }
}

void func_021B1688(unsigned char *dst, short *src, unsigned int n)
{
    unsigned int i;

    for (i = 0; i < n; i++)
        dst[i] = (signed char)(src[i] >> 8);
}

void func_021B16B4(signed char *src, short *dst, unsigned int n, int fmt)
{
    unsigned int i;

    for (i = 0; i < n; i++)
        dst[i] = (short)(src[i] << 8);
}
