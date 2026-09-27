/*
 * function: func_021B9F98
 * address:  0x021B9F98
 * packet:   pkt_ov218_021B9F98
 * region:   ov218
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * blocker:  mode-0 arm register allocation, ~14 concrete bytes. Original
 *           loads q into r1 then does `subs r2, r1, r3` with the 0x83
 *           constant in r1, and reuses the same q for both the strb and the
 *           strh/str; the natural C always materialises q once into a fresh
 *           register (r2). Closest shape: a switch with case 0 first gives
 *           the correct block order and entry/exit jumps but a different
 *           scratch assignment for the offset computation.
 *
 * symbols:
 *   g_021BAC80     0x021BAC80  data  ov218  a4
 */

extern int g_021BAC80[];

void func_021B9F98(int *p, int mode)
{
    char *q;

    switch (mode) {
    case 0:
        q = *(char **)((char *)p + 0x20);
        q[1] = 0x83 - *(int *)((char *)p + 0x30);
        *(short *)(q + 2) = g_021BAC80[0];
        *(int *)(q + 4) = 1;
        break;
    case 1:
        q = *(char **)((char *)p + 0x20);
        q[1] = 0;
        *(short *)(q + 2) = 0;
        *(int *)(q + 4) = 0;
        break;
    }
}