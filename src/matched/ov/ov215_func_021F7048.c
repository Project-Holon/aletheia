/*
 * function: func_021F7048
 * address:  0x021F7048
 * packet:   pkt_021F7048
 * region:   ov215
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Flushes a 0x44-byte-stride descriptor table: one pass over the count at
 * p+0x50 submitting every entry at level 0, then the selected entry at
 * p+0x4e twice (level 1 then 2) whose result advances the p+0x5c state.
 *
 * symbols:
 *   func_02048A18    0x02048A18  arm
 *   func_02047910    0x02047910  arm
 *   func_020478B8    0x020478B8  arm
 */

typedef unsigned short u16;

extern void *func_02048A18(void *p, int v);
extern int func_020478B8(void *p, int a, int b);

void func_021F7048(char *p)
{
    u16 i;
    void *q;
    int a, b;

    for (i = 0; i < *(u16 *)(p + 0x50); i++) {
        func_02047910(func_02048A18(*(void **)(p + 0x48),
                        *(u16 *)(*(char **)(p + 0x54) + i * 0x44)), 0, 0x1000);
    }
    *(int *)(p + 0x58) = *(int *)(p + 0x58) + 1;
    q = func_02048A18(*(void **)(p + 0x48),
                      *(u16 *)(*(char **)(p + 0x54) + *(u16 *)(p + 0x4e) * 0x44));
    if (*(int *)(p + 0x5c) == 1) {
        a = func_020478B8(q, 1, 0x5000);
        b = func_020478B8(q, 2, 0x5000);
        if (a == 0 && b == 0)
            *(int *)(p + 0x5c) = 2;
    } else if (*(int *)(p + 0x5c) == 3) {
        a = func_020478B8(q, 1, -0x2000);
        b = func_020478B8(q, 2, -0x2000);
        if (a == 0 && b == 0)
            *(int *)(p + 0x5c) = 0;
    }
}
