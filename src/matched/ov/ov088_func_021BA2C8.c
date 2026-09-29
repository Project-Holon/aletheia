/*
 * function: func_021BA2C8
 * address:  0x021BA2C8
 * packet:   pkt_ov088_021BA2C8
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     listing extent (112) runs 2 bytes past the compiled function (110);
 *           trailing alignment padding, no byte difference.
 *
 * symbols:
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_021BC0C8  0x021BC0C8  thumb  ov088
 *   func_021BC054  0x021BC054  thumb  ov088
 */

extern int func_0201C4E4(void *p);
extern void *func_02045770(void *p);
extern int func_0201C6C4(void *t, void *p);
extern void func_02045334(void *p);
extern int func_0201C6B4(void *p);
extern int func_021BC0C8(void *p);
extern int func_021BC054(void *p, int k);

int func_021BA2C8(char *p)
{
    unsigned i;
    void *t;
    func_0201C4E4(*(void **)(p + 0x68));
    for (i = 0; i < 14; i++) {
        t = *(void **)(p + 0x68);
        if (*(unsigned char *)(p + i * 8 + 0x84) != 0 && func_0201C6C4(t, func_02045770(*(void **)(p + i * 8 + 0x80))) == 0) {
            func_02045334(*(void **)(p + i * 8 + 0x80));
            *(unsigned char *)(p + i * 8 + 0x84) = 0;
        }
    }
    if (func_0201C6B4(*(void **)(p + 0x68)) == 1) {
        if (func_021BC0C8(p) == 1)
            return 10;
        return func_021BC054(p, 5);
    }
    return 4;
}
