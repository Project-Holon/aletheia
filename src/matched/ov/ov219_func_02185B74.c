/*
 * function: func_02185B74
 * address:  0x02185B74
 * packet:   pkt_ov219_02185B74
 * region:   ov219
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02047964  0x02047964  arm
 *   func_02047970  0x02047970  arm
 *   func_020479D8  0x020479D8  arm
 *   func_02048C58  0x02048C58  arm
 *   func_02048AD0  0x02048AD0  arm
 *   func_0207ADC4  0x0207ADC4  arm
 *   func_02047A60  0x02047A60  arm
 *   func_0207B388  0x0207B388  arm
 *   func_02185848  0x02185848  thumb  ov219
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int x, y, z; } V3;
typedef struct { V3 a; V3 b; } Pair;
typedef struct { int m[9]; } M33;

extern void func_02047964(void);
extern void func_02047970(void);
extern void func_020479D8(void);
extern void func_02048C58(void *);
extern void func_02048AD0(void *);
extern void func_0207ADC4(M33 *);
extern void func_02047A60(u32, Pair *);
extern void func_0207B388(const void *, const M33 *, M33 *);
extern void func_02185848(M33 *, char *);

void func_02185B74(char *p)
{
    int state = *(int *)(p + 0xC310);

    switch (state) {
    case 0:
        break;
    case 2:
        func_02047964();
        func_02047970();
        *(int *)(p + 0xC310) = 0;
        break;
    case 1: {
        M33 m;
        Pair s;
        M33 m2;
        Pair s2;
        u32 i;

        func_02048C58(*(void **)(p + 0xC370));
        func_02048AD0(*(void **)(p + 0xC36C));
        func_02047964();
        func_020479D8();
        s.a = *(V3 *)(p + 0xC2DC);
        func_0207ADC4(&m);
        s.b = *(V3 *)(p + 0xC300);
        func_02047A60(*(u32 *)(p + 0xC3B8), &s);
        s.b = *(V3 *)(p + 0xC2E8);
        func_02185848(&m, p + 0xC2F4);
        func_02047A60(*(u32 *)(p + 0xC3A4), &s);
        s2.a = *(V3 *)(p + 0xC2DC);
        s2.b = *(V3 *)(p + 0xC300);
        for (i = 0; i < *(u32 *)(p + 0x14); i++) {
            u16 f;
            func_0207B388(p + 0x1c + i * 0x30, &m, &m2);
            f = *(u16 *)(p + i * 0x30 + 0x40);
            if (f != 0)
                func_02047A60(*(u32 *)(p + f * 4 + 0xC3A8), &s2);
        }
        func_02047970();
        break;
    }
    }
}
