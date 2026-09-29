/*
 * function: func_021F1418
 * address:  0x021F1418
 * packet:   pkt_ov032_021F1418
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F1418 0x021F1418 thumb
 *   func_021F0EA4 0x021F0EA4 thumb
 *   func_021F0ED0 0x021F0ED0 thumb
 *   func_021F150C 0x021F150C thumb
 *   func_021F1484 0x021F1484 thumb
 *   func_02031194 0x02031194 arm
 */

typedef unsigned char u8;

extern void func_021F0EA4(void *e, int a);
extern void func_021F0ED0(void *e, int a);
extern void func_021F150C(void *this, void *e, void *p);
extern void func_021F1484(void *this, int a, void *e, void *c, void *p);
extern void func_02031194(void *h);

void func_021F1418(void *h, u8 *t)
{
    void *this;

    this = *(void **)(t + 0xc);
    if (*(int *)(t + 0x10) > 0)
        return;
    if (t[0] == 0) {
        func_021F0EA4(*(void **)(t + 8), 1);
        if (*(int *)(t + 4) == 1) {
            func_021F150C(this, *(void **)(t + 8), t + 0x10);
            func_021F0ED0(*(void **)(t + 8), 1);
        } else {
            func_021F1484(this, t[1], *(void **)(t + 8), 0, t + 0x10);
        }
        t[0] = t[0] + 1;
        return;
    }
    if (*(int **)(t + 0x14) != 0)
        *(*(int **)(t + 0x14)) = *(*(int **)(t + 0x14)) - 1;
    func_02031194(h);
}
