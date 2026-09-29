/*
 * function: func_021F55A0
 * address:  0x021F55A0
 * packet:   pkt_ov082_021F55A0
 * region:   ov082
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02189A60  0x02189A60  thumb  ov021
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_021F5648  0x021F5648  thumb  ov082
 */

typedef unsigned int u32;

extern int  func_020124E4(void);
extern int  func_0201210C(int a);
extern u32 *func_02189A60(int a);
extern void func_0204E720(int a, int b, int c, int d);
extern int  func_0204E804(void);
extern void func_02030EAC(int a);
extern void func_021F5648(int a, void *p);

int func_021F55A0(int a0, int *st)
{
    int obj;
    char *w;
    int t;

    obj = func_0201210C(func_020124E4());
    w = *(char **)func_02189A60(obj);
    switch (*st) {
    case 0:
        if (*(int *)(w + 0x70) != 0)
            func_0204E720(3, 0, 0x10, -8);
        else
            func_0204E720(1, 0, 0x10, 0);
        (*st)++;
        break;
    case 1:
        if (func_0204E804() != 0)
            break;
        func_02030EAC(*(int *)(w + 0x14));
        (*st)++;
        break;
    case 2:
        if (*(int *)(w + 0x2C) != 0)
            break;
        if (*(int *)(w + 0x50) != 0)
            break;
        func_02030EAC(*(int *)(w + 0x18));
        t = *(int *)(w + 0x70);
        func_021F5648(obj, w);
        if (t != 0)
            return 1;
        func_0204E720(1, 0x10, 0, 0);
        (*st)++;
        break;
    case 3:
        if (func_0204E804() == 0)
            return 1;
        break;
    }
    return 0;
}
