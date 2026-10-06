/*
 * function: func_02156F24
 * address:  0x02156F24
 * packet:   pkt_ov010_02156F24
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F8480  0x021F8480  thumb ov132
 *   func_021F879C  0x021F879C  thumb
 *   func_021F8640  0x021F8640  thumb
 */

typedef unsigned char  u8;
extern u8 *func_021F8480(u8 *input, int heap);
extern int func_021F879C(int);
extern void func_021F8640(int);

int func_02156F24(int a, int *state, int c, int *d)
{
    switch (*state) {
    case 0:
        d[1] = (int)func_021F8480((u8 *)d[0], 0x2e);
        *state = 1;
        break;
    case 1:
        if (func_021F879C(d[1]) == 1)
            *state = 2;
        break;
    case 2:
        func_021F8640(d[1]);
        return 1;
    }
    return 0;
}
