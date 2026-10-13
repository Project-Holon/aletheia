/*
 * function: FLDEFF_ENCOUNT_Start
 * address:  0x021ADAAC
 * packet:   pkt_ov021_021ADAAC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_EFFECT_GetFieldMap  0x021ABE14  thumb  ov021
 *   FIELDMAP_GetMoveKind  0x02188CFC  thumb  ov021
 *   FIELD_EFFECT_GetResource  0x021ABEA0  thumb  ov021
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   MI_CpuFill8  0x02082BCC  arm
 *   FIELD_EFFECT_AddObject  0x021ABFA8  thumb  ov021
 *   sEncountResourceIndex     0x021D9238  data  a1
 *   sEncountFuncs     0x021D9240  data  a4
 */
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct L {
    int f0;
    int f4;
    void *f8;
    int fc;
    u16 h10;
    u16 h12;
    int f14;
    u8 b18;
    u8 pad19[3];
    int f1c;
    int f20;
    int f24;
} L;

extern u8 sEncountResourceIndex[];
extern int sEncountFuncs[];

extern unsigned int FIELD_EFFECT_GetFieldMap(u8 *p);
extern unsigned int FIELDMAP_GetMoveKind(u8 *p);
typedef unsigned int   u32;
extern int FIELD_EFFECT_GetResource(u32 a, u32 b);
extern void *MI_CpuFill8(void *p, u8 v, unsigned n);
extern void *FIELDMAP_GetMmdlSys(unsigned char *p);
extern u8 FIELD_EFFECT_AddObject(int a, void *b, int c, int d, void *e, int f);

u8 FLDEFF_ENCOUNT_Start(int a, u8 *b, int c, int d, int e, int f)
{
    int t;
    int k;
    int r;
    L l;

    t = FIELD_EFFECT_GetFieldMap(b);
    if (FIELDMAP_GetMoveKind((u8 *)t) != 0) {
        return 0;
    }
    k = sEncountResourceIndex[f];
    r = FIELD_EFFECT_GetResource((u32)b, k + 0x12);
    if (r == 0) {
        return 0;
    }
    MI_CpuFill8(&l, 0, 0x28);
    l.f0 = a;
    l.f4 = r;
    l.f8 = FIELDMAP_GetMmdlSys((void *)t);
    l.h10 = c;
    l.h12 = d;
    l.f14 = k;
    if (k == 0) {
        l.b18 = f;
    } else {
        l.b18 = 0;
    }
    l.f1c = (c << 16) + 0x8000;
    l.f24 = (d << 16) + 0x8000;
    l.f20 = e;
    return FIELD_EFFECT_AddObject((int)b, sEncountFuncs, 0, 1, &l, 0);
}
