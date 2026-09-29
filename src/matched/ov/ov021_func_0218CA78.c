/*
 * function: func_0218CA78
 * address:  0x0218CA78
 * packet:   pkt_ov021_0218CA78
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0218DD70  0x0218DD70  thumb ov021
 *   func_0218D1D0  0x0218D1D0  thumb ov021
 *   func_0218D304  0x0218D304  thumb ov021
 *   func_0218D444  0x0218D444  thumb ov021
 *   func_0218D570  0x0218D570  thumb ov021
 *   func_0218D7A8  0x0218D7A8  thumb ov021
 *   func_0216932C  0x0216932C  thumb ov010
 *   sub_0207C768   0x0207C768  arm
 */

typedef unsigned short u16;

extern void func_0218DD70(void *p);
extern void func_0218D1D0(void *p, void *q, void *r);
extern void func_0218D304(void *p, void *q, void *r);
extern void func_0218D444(void *p, void *q, void *r);
extern void func_0218D570(void *p, void *q, void *r);
extern void func_0218D7A8(void *p, void *q);
extern void func_0216932C(int a);
extern int sub_0207C768(int a, int b);

void func_0218CA78(char *p)
{
    int i;
    int a;
    int b;

    if (*(int *)(p + 0x1c) == 0)
        return;
    for (i = 0; i < *(u16 *)(p + 0x2e); i++)
        func_0218DD70(*(char **)(p + 0x28) + i * 16);
    switch (*(unsigned int *)(p + 0xc)) {
    case 0:
        func_0218D1D0(p, p + 0x34, *(void **)(p + 0x28));
        break;
    case 1:
    default:
        func_0218D304(p, p + 0x34, *(void **)(p + 0x28));
        break;
    case 2:
        func_0218D444(p, p + 0x34, *(void **)(p + 0x28));
        break;
    case 3:
        func_0218D570(p, p + 0x34, *(void **)(p + 0x28));
        break;
    }
    func_0218D7A8(p, *(void **)(p + 0x28));
    for (i = 0; i < *(u16 *)(p + 0x2e); i++)
        func_0216932C(*(int *)(*(char **)(p + 0x24) + i * 0x28));
    a = sub_0207C768(*(int *)(p + 0x34), *(int *)(p + 4));
    b = sub_0207C768(*(int *)(p + 0x3c), *(int *)(p + 4));
    *(int *)(p + 0x30) = (a >> 12) + (b >> 12) * *(u16 *)(p + 0x14);
}
