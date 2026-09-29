/*
 * unit:     yes
 * function: func_021BA4C8, func_021BA520
 * address:  0x021BA4C8
 * packet:   pkt_ov099_021BA4C8
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Lever: the second get-call result is a named local (b == a) so cmp keeps
 * the call result in the left slot.
 *
 * func_021BA520 is the unlabelled 22-byte leaf after the lead function
 * (seed function_starts 0x021BA520).
 *
 * symbols:
 *   func_021C57F4  0x021C57F4  thumb  ov127
 *   func_021C57D8  0x021C57D8  thumb  ov127
 *   func_021C49A4  0x021C49A4  thumb  ov127
 *   func_021BA228  0x021BA228  thumb  ov099
 *   func_021BA5F0  0x021BA5F0  thumb  ov099
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;

typedef struct {
    char pad00[0x570];
    void **f570;
} W;

typedef struct {
    void *f0;
    void *f4;
    s16 f8;
    u8 fa;
    u8 fb;
} S;

extern void func_021C57F4(void *p);
extern void func_021C57D8(void *p, int v);
extern int func_021C49A4(void *p, int i);
extern void func_021BA228(W *w, S *s);
extern void func_021BA5F0(W *w, S *s, u8 c);

int func_021BA4C8(W *w, S *s)
{
    int a;
    int b;

    s->f8 = s->f8 - 1;
    if (s->f8 <= 0) {
        func_021C57F4(s->f4);
        func_021C57D8(s->f4, 1);
        a = func_021C49A4(*w->f570, 4);
        b = func_021C49A4(s->f0, 4);
        if (b == a) {
            func_021BA228(w, s);
        } else {
            func_021BA5F0(w, s, s->fb);
        }
    }
    return 0;
}

int func_021BA520(W *w, S *s)
{
    s->f8 = s->f8 + 1;
    if (s->f8 > 0x2d) {
        return 1;
    }
    return 0;
}
