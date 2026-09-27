/*
 * function: func_021E03F8
 * address:  0x021E03F8
 * packet:   pkt_ov175_021E03F8
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Switch on p->0: case 2 bumps channel 0x24/0x38, case 3 bumps 0x26/0x3c and
 *          falls into the shared extra block, case 4 bumps 0x28/0x40 and
 *          falls through into it.  The extra block (the p+8 counter and the
 *          func_021E0504 call) is written out in both arms so the compiler
 *          cross-jumps 3 onto 4's copy; the branch bodies read p->0x124
 *          through the cached `q`, but the extra block and the tail reload it
 *          fresh, which is why one load stays shared and the rest do not.
 *
 * symbols:
 *   func_021E0504  0x021E0504  arm  ov175
 *   func_021E04FC  0x021E04FC  arm  ov175
 */

typedef unsigned short u16;
typedef short s16;

extern void func_021E0504(char *p, s16 x);
extern void func_021E04FC(char *p, int x);

int func_021E03F8(char *p, int a1, int a2)
{
    char *q = *(char **)(p + 0x124);
    int v = *(int *)p;

    if (v == 2) {
        *(u16 *)(q + 0x24) += 1;
        *(int *)(q + 0x38) += 5;
    } else if (v == 3) {
        *(u16 *)(q + 0x26) += 1;
        *(int *)(q + 0x3c) += 5;
        *(u16 *)(p + 8) += 1;
        func_021E0504(*(char **)(p + 0x124) + *(int *)(p + 4), *(s16 *)(p + 8));
    } else if (v == 4) {
        *(u16 *)(q + 0x28) += 1;
        *(int *)(q + 0x40) += 5;
        *(u16 *)(p + 8) += 1;
        func_021E0504(*(char **)(p + 0x124) + *(int *)(p + 4), *(s16 *)(p + 8));
    }
    func_021E0504(*(char **)(p + 0x124) + *(int *)(p + 0x120), (s16)a1);
    *(int *)(p + 0x120) += 2;
    func_021E0504(*(char **)(p + 0x124) + *(int *)(p + 0x120), 2);
    *(int *)(p + 0x120) += 2;
    func_021E04FC(*(char **)(p + 0x124) + *(int *)(p + 0x120), a2);
    *(int *)(p + 0x120) += 1;
    return 0;
}
