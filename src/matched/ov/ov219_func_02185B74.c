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
 *   G3D_SYSTEM_DrawEnd  0x02047970  arm
 *   G3D_SYSTEM_ApplyLookAt  0x020479D8  arm
 *   func_02048C58  0x02048C58  arm
 *   func_02048AD0  0x02048AD0  arm
 *   MTX_Identity33_  0x0207ADC4  arm
 *   G3D_SYSTEM_DrawObject  0x02047A60  arm
 *   func_0207B388  0x0207B388  arm
 *   BEACON_DETAIL_SetupCalc  0x02185848  thumb  ov219
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int x, y, z; } V3;
typedef struct { V3 a; V3 b; } Pair;
typedef struct { int m[9]; } M33;

extern void func_02047964(void);
extern void G3D_SYSTEM_DrawEnd(void);
extern void G3D_SYSTEM_ApplyLookAt(void);
struct Arg;
struct Light;
struct LightSlot;
extern void func_02048C58(struct LightSlot *slots);
extern void func_02048AD0(struct Light *l);
extern void MTX_Identity33_(M33 *);
extern void G3D_SYSTEM_DrawObject(void *a0, struct Arg *a1);
extern void func_0207B388(const void *, const M33 *, M33 *);
extern void BEACON_DETAIL_SetupCalc(M33 *, char *);

void func_02185B74(char *p)
{
    int state = *(int *)(p + 0xC310);

    switch (state) {
    case 0:
        break;
    case 2:
        func_02047964();
        G3D_SYSTEM_DrawEnd();
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
        G3D_SYSTEM_ApplyLookAt();
        s.a = *(V3 *)(p + 0xC2DC);
        MTX_Identity33_(&m);
        s.b = *(V3 *)(p + 0xC300);
        G3D_SYSTEM_DrawObject((void *)(*(u32 *)(p + 0xC3B8)), (struct Arg *)(&s));
        s.b = *(V3 *)(p + 0xC2E8);
        BEACON_DETAIL_SetupCalc(&m, p + 0xC2F4);
        G3D_SYSTEM_DrawObject((void *)(*(u32 *)(p + 0xC3A4)), (struct Arg *)(&s));
        s2.a = *(V3 *)(p + 0xC2DC);
        s2.b = *(V3 *)(p + 0xC300);
        for (i = 0; i < *(u32 *)(p + 0x14); i++) {
            u16 f;
            func_0207B388(p + 0x1c + i * 0x30, &m, &m2);
            f = *(u16 *)(p + i * 0x30 + 0x40);
            if (f != 0)
                G3D_SYSTEM_DrawObject((void *)(*(u32 *)(p + f * 4 + 0xC3A8)), (struct Arg *)(&s2));
        }
        G3D_SYSTEM_DrawEnd();
        break;
    }
    }
}
