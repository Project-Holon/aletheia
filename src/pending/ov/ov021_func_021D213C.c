/*
 * function: func_021D213C
 * address:  0x021D213C
 * packet:   pkt_ov021_021D213C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Byte-correct; the only wildcards are the two calls to func_020249B0, an
 * unlabelled arm9 Thumb leaf (0x020249B0, 104 bytes incl. pool, table search
 * over 13 {u16 *p; int n} rows at 0x0209F7C8) with no witness outside this
 * range. The leaf is Ilias's (arm9); best C so far is NOT verified (DIFF, same
 * size, loop bodies right, the k-loop re-reads row->p/row->n each iteration in
 * the original and guard uses pool word 0x0209F7CC = base+4):
 *   int func_020249B0(int a, int b) { int i,j,k; E *e;
 *     if (a == b) return 1;
 *     for (i = 0; i < 13; i++) { e = &d[i];
 *       for (j = 0; j < e->n; j++) if (a == e->p[j]) {
 *         for (k = 0; k < *(int *)((char *)d2 + i*8); k++) if (b == e->p[k]) return 1;
 *         return 0; } }
 *     return 0; }
 *   with E {u16 *p; int n;} d[] at 0x0209F7C8, d2 at 0x0209F7CC.
 *
 * symbols:
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_020249B0  0x020249B0  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_02159B10(u32 a, u32 b);
extern u16 *func_02159AE8(u32 a, u32 b);
extern int func_020249B0(u32 a, u16 b);

int func_021D213C(u32 a, u32 b)
{
    u32 base, s, r7, r4;
    u16 *p;

    r4 = func_02159B10(a, b);
    s = func_02159B10(a, b);
    r7 = func_02159B10(a, b);
    p = func_02159AE8(a, b);
    switch (r4) {
    case 1:
        base = 0x5C0;
        r4 = base + 0xBB;
        break;
    case 2:
        base = 0x664;
        r4 = base + 0x53;
        break;
    default:
        *p = 0;
        return 0;
    }
    if (func_020249B0(base, s & 0x7FF) && func_020249B0(r4, r7 & 0x7FF)) {
        *p = 1;
    } else {
        *p = 0;
    }
    return 0;
}
