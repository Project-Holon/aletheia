/*
 * function: func_021E06DC
 * address:  0x021E06DC
 * packet:   pkt_ov093_021E06DC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021E899C  0x021E899C  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
extern int func_021D775C(int key);
extern void *func_021C88A4(void *a, int k, int b);
typedef struct { unsigned v; } Word;
extern Word func_021E899C(int a);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C88C8(void *a, void *b);

void func_021E06DC(int a, void *b, int c)
{
    int *p;

    if (c == func_021D775C(3)) {
        p = func_021C88A4(b, 0x1b, c);
        p[1] = 5;
        *(Word *)(p + 2) = func_021E899C(c);
        func_021C8838(p + 4, 1, 0x73);
        func_021C88C8(b, p);
    }
}
