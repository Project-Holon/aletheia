/*
 * function: func_021F3958
 * address:  0x021F3958
 * packet:   pkt_ov051_021F3958
 * region:   ov051
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F3D6C  0x021F3D6C  thumb  ov051
 *   func_021F3C98  0x021F3C98  thumb  ov051
 *   func_021F3C84  0x021F3C84  thumb  ov051
 *   func_021F39F8  0x021F39F8  thumb  ov051
 *   func_021F3AB4  0x021F3AB4  thumb  ov051
 *   func_02188C80  0x02188C80  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082C60  0x02082C60  arm
 */

extern char *func_021F3D6C(int a);
extern int func_021F3C98(char *a, char *b);
extern int func_021F3C84(char *a, char *b, int c);
extern int func_021F39F8(int a, int *s, int *t);
extern int func_021F3AB4(int a, int *s, int *t);
extern int func_02188C80(int a);
extern int func_020122C0(int a, int b, void *c, int d);
extern unsigned short *func_020124E8(int a);
extern void func_02082C60(void *a, int b, int c);

int func_021F3958(int a, int id, int arg)
{
    int sp3;
    int sp8;
    int sp1;
    unsigned short i;
    int v;
    char *r5;
    char *r7;
    unsigned short *r6;

    r5 = func_021F3D6C(a);
    sp8 = func_02188C80(a);
    for (i = 0; i < 12; i++) {
        v = *(int *)(r5 + 12 + i * 8);
        if (v == id)
            break;
    }
    if (i >= 12)
        i = 0;
    r7 = r5 + 12 + i * 8;
    if (func_021F3C98(r5, r7) == 1)
        return 0;
    sp3 = func_021F3C84(r5, r7, arg);
    if (sp3 == 0)
        sp1 = func_020122C0(sp8, 0, func_021F3AB4, 0x10);
    else
        sp1 = func_020122C0(sp8, 0, func_021F39F8, 0x10);
    r6 = func_020124E8(sp1);
    func_02082C60(r6, 0, 0x10);
    r6[0] = arg;
    *(char **)(r6 + 6) = r5;
    r6[1] = i;
    *(char **)(r6 + 4) = r7;
    *(int *)(r6 + 2) = sp3;
    return sp1;
}
