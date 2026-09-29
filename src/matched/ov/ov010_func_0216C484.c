/*
 * function: func_0216C484
 * address:  0x0216C484
 * packet:   pkt_ov010_0216C484
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_020144DC  0x020144DC  thumb
 *   func_02014910  0x02014910  thumb
 *   func_020145CC  0x020145CC  thumb
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_02082D44  0x02082D44  arm
 *   func_020307B0  0x020307B0  arm
 */

extern int func_021BE8D4(int, int, int, int);
extern void func_02012374(int, int);
extern int func_020144DC(int, int);
extern int func_02014910(int, int, char *, char *);
extern int func_020145CC(int);
extern int func_021BE92C(int, int, int, int, int, int, int);
extern void func_02082D44(void *, void *, int);
extern void func_020307B0(int);

int func_0216C484(int a, int *st, int *o)
{
    int x = o[0];
    switch (*st) {
    case 0:
        func_02012374(a, func_021BE8D4(x, o[1], 0, 0));
        (*st)++;
        break;
    case 1:
        func_02012374(a, func_020144DC(x, o[1]));
        (*st)++;
        break;
    case 2:
        func_02012374(a, func_02014910(x, o[1], (char *)o + 0x30, (char *)o + 8));
        (*st)++;
        break;
    case 3:
        func_02012374(a, func_020145CC(x));
        (*st)++;
        break;
    case 4:
        func_02012374(a, func_021BE92C(x, o[1], 0, 0, 1, 0, 0));
        func_02082D44((char *)o + 0x79, *(void **)((char *)o + 0xd0), 6);
        **(short **)((char *)o + 0xcc) = o[0x6c / 4];
        **(short **)((char *)o + 0xc8) = o[0x70 / 4];
        func_020307B0(o[0x44 / 4]);
        (*st)++;
        break;
    case 5:
        return 1;
    }
    return 0;
}
