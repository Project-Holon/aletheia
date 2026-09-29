/*
 * function: func_021BB328
 * address:  0x021BB328
 * packet:   pkt_ov088_021BB328
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204A5AC  0x0204A5AC  arm
 */

extern void func_0204B3B4(void *);
extern void func_0204B1CC(void *);
extern void func_0204A8D4(void *);
extern void func_0204ADA4(void *);
extern void func_0204AFD8(void *);
extern void func_0204A5AC(void);

void func_021BB328(char *p)
{
    unsigned i;
    for (i = 0; i < 6; i++)
        func_0204B3B4(*(void **)(p + 0x1c + i * 4));
    func_0204B1CC(*(void **)(p + 0x18));
    for (i = 0; i < 3; i++)
        func_0204A8D4(*(void **)(p + 0x34 + i * 4));
    for (i = 0; i < 3; i++)
        func_0204ADA4(*(void **)(p + 0x40 + i * 4));
    for (i = 0; i < 3; i++)
        func_0204AFD8(*(void **)(p + 0x4c + i * 4));
    func_0204A5AC();
}
