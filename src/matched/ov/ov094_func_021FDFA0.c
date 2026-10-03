/*
 * function: func_021FDFA0
 * address: 0x021FDFA0
 * packet: pkt_ov094_021FDFA0
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0201134C 0x0201134C thumb
 *   func_020515CC 0x020515CC arm
 *   func_02051648 0x02051648 arm
 *   func_02051788 0x02051788 arm
 *   func_021FE38C 0x021FE38C thumb ov094
 *   func_021FD1A8 0x021FD1A8 thumb ov094
 *   func_021FD9F0 0x021FD9F0 thumb ov094
 *   func_021FCF2C 0x021FCF2C thumb ov094
 *   func_021F8694 0x021F8694 thumb ov094
 *   func_021FF3F4 0x021FF3F4 thumb ov094
 *   _s32_div_f 0x0209C0A4 arm
 *   d_0220AE68 0x0220AE68 data
 *   d_02209E10 0x02209E10 data
 *   d_02209DB4 0x02209DB4 data
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int x, y, z; } Vec;
typedef struct { u32 v[8]; } Desc;
extern char d_0220AE68[];
extern const Vec d_02209E10, d_02209DB4;
extern int *func_02030734(u16, u32, int, const char *, u16);
extern void func_020307B0(void *);
extern u32 func_0201134C(void *);
extern int func_020515CC(int *, int, void (*)(void), void *);
extern void func_02051648(void *, Desc *, u16, Vec *, Vec *, Vec *, u16);
extern int func_02051788(char *p);
extern u32 func_021FE38C(char *, u32);
extern int func_021FD1A8(char *, int);
extern void func_021FD9F0(void);
extern int func_021FCF2C(void *, int);
extern void *func_021F8694(void);
extern void func_021FF3F4(void *obj, void *out, int idx);
extern int _s32_div_f(int, int);
int func_021FDFA0(void *a, char *s, int mode)
{
    int *p;
    int idx;
    int x;
    int y;
    int flags;

    idx = func_021FD1A8(s, func_021FE38C(s, func_0201134C(a)));
    x = func_0201134C(a);
    flags = 0;
    *(int **)(s + 0x1f4 + *(int *)(s + 0x234) * 4) = func_02030734((*(u16 *)(s + 0x238) & 0x7fff) | 0x8000, 0x40, 0, d_0220AE68, 0x1c79);
    p = *(int **)(s + 0x1f4 + *(int *)(s + 0x234) * 4);
    *(int *)(s + 0x234) += 1;
    p[0] = func_0201134C(a);
    p[4] = func_0201134C(a);
    p[5] = func_0201134C(a);
    y = func_0201134C(a);
    p[6] = 0;
    p[9] = p[8] = func_0201134C(a);
    p[10] = 0;
    p[11] = func_0201134C(a);
    p[12] = func_0201134C(a);
    p[13] = 0;
    p[14] = func_0201134C(a);
    p[7] = _s32_div_f(0x10000, p[8]);
    p[15] = mode;
    if (idx == 16)
        goto end;
    if (mode == 1) {
        if (func_02051788(*(void **)(s + 0xc + idx * 4)) == 0) {
            Desc desc;
            Vec zero = {0, 0, 0};
            Vec v1;
            Vec v2;
            v1 = d_02209E10;
            v2 = d_02209DB4;
            desc.v[0] = 2;
            desc.v[1] = 0x3000;
            desc.v[2] = 0xffffd000;
            desc.v[3] = 0xffffc000;
            desc.v[4] = 0x4000;
            desc.v[5] = 0x1000;
            desc.v[6] = 0x200000;
            desc.v[7] = 0x1000;
            func_02051648(*(void **)(s + 0xc + idx * 4), &desc, 0x2000, &zero, &v1, &v2, (*(u16 *)(s + 0x238) & 0x7fff) | 0x8000);
        }
    }
    switch (p[0]) {
    case 0:
    case 1:
        flags = func_021FCF2C(a, 14);
        func_021FF3F4(func_021F8694(), &p[1], flags);
        break;
    case 2:
    case 3:
        flags = func_021FCF2C(a, 16);
        func_021FF3F4(func_021F8694(), &p[1], flags);
        break;
    case 4:
    case 5:
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        break;
    }
    if (flags & 1)
        p[6] = 0x8000;
    p[2] += y;
    if (func_020515CC(*(int **)(s + 0xc + idx * 4), x, func_021FD9F0, p) == -1)
        func_020307B0(p);
end:
    return *(int *)(s + 0x23c);
}
