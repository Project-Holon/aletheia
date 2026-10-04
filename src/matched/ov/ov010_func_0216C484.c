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

typedef unsigned char  u8;
struct Evt;
extern int func_021BE8D4(void *a, int b, int sel, int d);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_020144DC(int, int);
extern void *func_02014910(char *a0, int a1, int a2, int a3);
extern void *func_020145CC(void *a0);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void func_02082D44(void *, void *, int);
extern void func_020307B0(void *p);

int func_0216C484(int a, int *st, int *o)
{
    int x = o[0];
    switch (*st) {
    case 0:
        func_02012374((struct Evt *)a, (struct Evt **)func_021BE8D4((void *)x, o[1], 0, 0));
        (*st)++;
        break;
    case 1:
        func_02012374((struct Evt *)a, (struct Evt **)func_020144DC(x, o[1]));
        (*st)++;
        break;
    case 2:
        func_02012374((struct Evt *)a, func_02014910((char *)x, o[1], (int)((char *)o + 0x30), (int)((char *)o + 8)));
        (*st)++;
        break;
    case 3:
        func_02012374((struct Evt *)a, func_020145CC((void *)x));
        (*st)++;
        break;
    case 4:
        func_02012374((struct Evt *)a, (struct Evt **)func_021BE92C((void *)x, o[1], 0, 0, 1, 0, 0));
        func_02082D44((char *)o + 0x79, *(void **)((char *)o + 0xd0), 6);
        **(short **)((char *)o + 0xcc) = o[0x6c / 4];
        **(short **)((char *)o + 0xc8) = o[0x70 / 4];
        func_020307B0((void *)o[0x44 / 4]);
        (*st)++;
        break;
    case 5:
        return 1;
    }
    return 0;
}
