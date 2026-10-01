/*
 * function: func_021B64B0
 * address:  0x021B64B0
 * packet:   pkt_ov179_021B64B0
 * region:   ov179
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B66DC  0x021B66DC  thumb  ov179
 */
typedef unsigned int u32;

extern int func_021B66DC(char *p);

u32 func_021B64B0(char *p)
{
    do {
        if (**(int **)(p + 0x601C) == 20) {
            (*(unsigned char **)p)[3] = 0;
            return 1;
        }
    } while (func_021B66DC(p) == 1);
    return *(u32 *)(p + 0x6050);
}
