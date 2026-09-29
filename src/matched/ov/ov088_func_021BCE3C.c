/*
 * function: func_021BCE3C
 * address:  0x021BCE3C
 * packet:   pkt_ov088_021BCE3C
 * region:   ov088
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * EXACT*: the extent runs 20 bytes long; the follower at 0x021BCE70 is an
 * unlabelled tail-call stub (ldr r0,[pc]; ldr r3,[pc]; ldr r0,[r0]; bx r3).
 * The switch value is unsigned so that case 0xFFFFFFFE sorts after case 0.
 *
 * symbols:
 *   func_0201FEBC  0x0201FEBC  thumb
 *   func_021BD118  0x021BD118  thumb  ov088
 *   func_021BD23C  0x021BD23C  thumb  ov088
 */

extern unsigned func_0201FEBC(char *);
extern void func_021BD118(char *, int);
extern void func_021BD23C(void);

void func_021BCE3C(char *p, int *out)
{
    unsigned r = func_0201FEBC(*(char **)(p + 0x20));
    switch (r) {
    case 0:
        func_021BD118(p, 2);
        *out = 6;
        break;
    case 0xFFFFFFFE:
        func_021BD23C();
        *out = 7;
        break;
    }
}
