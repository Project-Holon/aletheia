/*
 * function: func_0216C9F4
 * address:  0x0216C9F4
 * packet:   pkt_ov010_0216C9F4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02161824  0x02161824  thumb  ov010
 *   func_02012374  0x02012374  thumb
 *   func_02029BCC  0x02029BCC  thumb
 *   func_02188CE8  0x02188CE8  thumb  ov021
 *   func_021AAABC  0x021AAABC  thumb  ov021
 *   func_02189A08  0x02189A08  thumb  ov021
 *   func_021CF498  0x021CF498  thumb  ov021
 *   func_020144DC  0x020144DC  thumb
 *   func_0216C9CC  0x0216C9CC  thumb  ov010
 *   func_02029C00  0x02029C00  thumb
 *   func_020145CC  0x020145CC  thumb
 *   func_02029CC0  0x02029CC0  thumb
 *   func_021BE92C  0x021BE92C  thumb  ov021
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Ctx;
struct Evt;
extern void *func_02161824(void *a, void *b);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void *func_02029BCC(void *a, u32 b);
extern u32 func_02188CE8(u8 *p);
extern void func_021AAABC(int);
extern int func_02189A08(unsigned char *p);
extern void func_021CF498(struct Ctx *c, u32 x, int idx);
extern int func_020144DC(int, int);
extern void *func_0216C9CC(void *a, void *b, void *c);
extern void *func_02029C00(void *a);
extern void *func_020145CC(void *a0);
extern void *func_02029CC0(void *a);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);

int func_0216C9F4(int a, int *st, int *o)
{
    int x = o[0];
    int y = o[1];
    switch (*st) {
    case 0:
        func_02012374((struct Evt *)a, func_02161824((void *)x, (void *)y));
        (*st)++;
        break;
    case 1:
        func_02012374((struct Evt *)a, func_02029BCC((void *)x, *(unsigned short *)(o[2] + 0x18)));
        (*st)++;
        break;
    case 2:
        func_021AAABC(func_02188CE8((u8 *)y));
        func_021CF498((struct Ctx *)func_02189A08((unsigned char *)o[1]), a, 9);
        (*st)++;
        break;
    case 3:
        func_02012374((struct Evt *)a, (struct Evt **)func_020144DC(x, y));
        (*st)++;
        break;
    case 4:
        func_02012374((struct Evt *)a, func_0216C9CC((void *)x, (void *)o[2], (void *)o[3]));
        (*st)++;
        break;
    case 5:
        func_02012374((struct Evt *)a, func_02029C00((void *)x));
        (*st)++;
        break;
    case 6:
        func_02012374((struct Evt *)a, func_020145CC((void *)x));
        (*st)++;
        break;
    case 7:
        func_02012374((struct Evt *)a, func_02029CC0((void *)x));
        (*st)++;
        break;
    case 8:
        func_02012374((struct Evt *)a, (struct Evt **)func_021BE92C((void *)x, y, 0, 0, 1, 0, 0));
        (*st)++;
        break;
    case 9:
        return 1;
    default:
        return 1;
    }
    return 0;
}
