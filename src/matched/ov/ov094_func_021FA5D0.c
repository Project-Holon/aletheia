/*
 * function: func_021FA5D0
 * address: 0x021FA5D0
 * packet: pkt_ov094_021FA5D0
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * witness: arm9 func_02051788 filed as src/matched/arm9/func_02051788.c.
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02051648 0x02051648 arm
 *   func_02051788 0x02051788 arm
 *   func_021FE38C 0x021FE38C thumb ov094
 *   func_021FD1A8 0x021FD1A8 thumb ov094
 *   func_021FD1C0 0x021FD1C0 thumb ov094
 *   func_021FDD60 0x021FDD60 thumb ov094
 *   d_0220AE68 0x0220AE68 data ov094 a1
 *   d_02209D78 0x02209D78 data a4
 *   d_02209E04 0x02209E04 data a4
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int x, y, z; } Vec;
typedef struct { u32 v[8]; } Desc;
extern char d_0220AE68[];
extern const Vec d_02209D78, d_02209E04;
extern u32 func_0201134C(void *);
extern void *func_02030734(u16, u32, int, const char *, u16);
extern void func_020307B0(void *);
extern void func_02051648(void *, Desc *, u16, Vec *, Vec *, Vec *, u16);
extern int func_02051788(void *);
extern unsigned int func_021FE38C(char *, unsigned int);
extern int func_021FD1A8(char *, unsigned int);
extern int func_021FD1C0(char *, int);
extern void func_021FDD60(char *, int *, int, int);

int func_021FA5D0(void *a, char *s)
{
    Desc desc;
    int *p;
    int slot;
    int count;
    int arg;
    int i;

    p = func_02030734((*(u16 *)(s + 0x238) & 0x7fff) | 0x8000, 0x5c, 1, d_0220AE68, 0x7ff);
    slot = func_021FD1A8(s, func_021FE38C(s, func_0201134C(a)));
    count = func_021FD1C0(s, slot);
    p[0] = (int)a;
    p[1] = func_0201134C(a);
    p[2] = func_0201134C(a);
    p[3] = 0;
    p[4] = func_0201134C(a);
    p[5] = 0;
    p[6] = func_0201134C(a);
    arg = func_0201134C(a);
    p[17] = func_0201134C(a);
    p[18] = func_0201134C(a);
    p[19] = func_0201134C(a);
    p[20] = func_0201134C(a);
    if (slot != 16) {
        if (arg != 0) {
            Vec zero = {0, 0, 0};
            Vec v1;
            Vec v2;
            v1 = d_02209D78;
            v2 = d_02209E04;
            desc.v[0] = 2;
            desc.v[1] = 0x3000;
            desc.v[2] = 0xffffd000;
            desc.v[3] = 0xffffc000;
            desc.v[4] = 0x4000;
            desc.v[5] = 0x1000;
            desc.v[6] = 0x200000;
            desc.v[7] = 0x1000;
            if (func_02051788(*(void **)(s + 12 + slot * 4)) == 0)
                func_02051648(*(void **)(s + 12 + slot * 4), &desc, 0x2000, &zero, &v1, &v2, (u16)((*(u16 *)(s + 0x238) & 0x7fff) | 0x8000));
            p[16] = 2;
        }
        if (p[2] == 8)
            p[2] = p[1];
        for (i = 0; i < count; i++)
            func_021FDD60(s, p, slot, i);
    }
    func_020307B0(p);
    return *(int *)(s + 0x23c);
}
