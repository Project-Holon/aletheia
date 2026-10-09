/*
 * file:     intrude_subdisp_p03.c
 * unit:     yes
 * function: func_0217D3AC, func_0217D4DC, func_0217D5AC, func_0217D624, func_0217D6C8, func_0217D720, func_0217D870, func_0217D890, func_0217D904, func_0217D918, func_0217DA18, func_0217DA54, func_0217DA90
 * address:  0x0217D3AC
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_020120F8  0x020120F8  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_02013D5C  0x02013D5C  thumb
 *   func_02026454  0x02026454  thumb
 *   func_0202648C  0x0202648C  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_02175DA8  0x02175DA8  thumb  ov011
 *   func_02175B8C  0x02175B8C  thumb  ov011
 *   func_0217EBD8  0x0217EBD8  thumb  ov018
 *   func_0217EEB4  0x0217EEB4  thumb  ov018
 *   func_0217EF44  0x0217EF44  thumb  ov018
 *   func_0217E638  0x0217E638  thumb  ov018
 *   func_0217E714  0x0217E714  thumb  ov018
 *   func_0217DE68  0x0217DE68  thumb  ov018
 *   func_0217E014  0x0217E014  thumb  ov018
 *   func_0217E0F4  0x0217E0F4  thumb  ov018
 *   func_0217E3D0  0x0217E3D0  thumb  ov018
 *   func_0217E4D0  0x0217E4D0  thumb  ov018
 *   func_0217E524  0x0217E524  thumb  ov018
 *   func_0217F194  0x0217F194  thumb  ov018
 *   func_0201210C  0x0201210C  thumb
 *   func_02158378  0x02158378  thumb  ov010
 *   func_020061E4  0x020061E4  thumb
 *   func_0217F174  0x0217F174  thumb  ov018
 *   func_0217F0C4  0x0217F0C4  thumb  ov018
 *   func_0217CEE8  0x0217CEE8  thumb  ov018
 *   func_0217CE08  0x0217CE08  thumb  ov018
 *   func_0217CE6C  0x0217CE6C  thumb  ov018
 *   func_020862F0  0x020862F0  arm
 *   func_0207E5D0  0x0207E5D0  arm
 *   func_0207E804  0x0207E804  arm
 *   func_0204B100  0x0204B100  arm
 *   func_0204B034  0x0204B034  arm
 *   func_0204B258  0x0204B258  arm
 *   func_02025538  0x02025538  thumb
 *   func_0203101C  0x0203101C  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0201EC64  0x0201EC64  thumb
 *   func_0201C440  0x0201C440  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_020457B0  0x020457B0  arm
 *   d_021836B4     0x021836B4  data   a4
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   func_0201D83C  0x0201D83C  thumb
 *   func_02031140  0x02031140  arm
 *   func_02025588  0x02025588  thumb
 *   func_0204B084  0x0204B084  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0203FCA0            0x0203FCA0  arm
 *   MIi_CpuClear32           0x02082A7C  arm
 *   G2x_SetBlendBrightness_  0x0207D658  arm
 *   func_02049658            0x02049658  arm
 *   func_020498F4            0x020498F4  arm
 *   func_02049EF4            0x02049EF4  arm
 *   MIi_CpuCopy16            0x02082A60  arm
 *   func_020307B0            0x020307B0  arm
 *   func_02049B68            0x02049B68  arm
 *   func_02049B40            0x02049B40  arm
 *   func_02040588            0x02040588  arm
 *   func_0217EF70            0x0217EF70  thumb  ov018
 *   func_0217F1E8            0x0217F1E8  thumb  ov018
 *   func_0217F240            0x0217F240  thumb  ov018
 *   d_0218370C               0x0218370C  data  a4
 *   d_0218372C               0x0218372C  data  a4
 *   func_020403F4 0x020403F4 arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_020452E8 0x020452E8 arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_020490F4  0x020490F4  arm
 *   func_0204ACEC  0x0204ACEC  arm
 *   func_02049238  0x02049238  arm
 *   func_02049DF4  0x02049DF4  arm
 *   func_0204ABBC  0x0204ABBC  arm
 *   func_02030734  0x02030734  arm
 *   func_02082A60  0x02082A60  arm
 *   d_02183B14     0x02183B14  data   a1
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0217DAA8 0x0217DAA8 thumb ov018
 *   func_0217DB4C 0x0217DB4C thumb ov018
 *   func_0217DBAC 0x0217DBAC thumb ov018
 *   func_0217DC14 0x0217DC14 thumb ov018
 *   func_0217DC9C 0x0217DC9C thumb ov018
 *   func_0217DCFC 0x0217DCFC thumb ov018
 *   func_0217DD48 0x0217DD48 thumb ov018
 *   func_0204B3B4 0x0204B3B4 arm
 */
#include "../../matched/include/Obj03091.h"
#include "../../matched/include/Obj00703.h"
#include "../../matched/include/Obj02676.h"

#define REG_DB_DISPCNT_SUB (*(volatile u32 *)0x04001000)
#define REG_DB_BLDCNT_SUB  (*(volatile u16 *)0x04001050)
struct Ctx;
struct BigObj;
struct Rec44;
struct GfFont;
struct Tcbl;
struct WordSet;
struct MsgBank;
struct U16Vec;
struct Obj;
struct Bank;
struct PrintSys;
struct Rec;
struct S02031140;
struct Descriptor;
struct Cfg;
typedef struct {
    void *f0;
    unsigned char pad004[0xDC];
    int fE0;
    unsigned char pad0E4[0x88];
    unsigned char f16C;
} Ov018Menu_0217D3AC;

typedef struct { unsigned char a : 7; unsigned char b : 1; } FlagsF8;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef struct {
    void *f0;
    unsigned char pad004[0x10C];
    unsigned short f110;
    unsigned char f112;
    unsigned char pad113[0x55];
    unsigned char f168;
} Ov018Menu_0217D4DC;

typedef unsigned short u16;

struct State {
    u8 pad00[0x1C];
    struct GfFont *font;      /* 0x1C */
    struct Tcbl *tcbl;        /* 0x20 */
    struct WordSet *words;    /* 0x24 */
    int unk28;                /* 0x28 */
    struct MsgBank *msg2C;    /* 0x2C */
    struct MsgBank *msg30;    /* 0x30 */
    u8 pad34[4];
    struct U16Vec *str38;     /* 0x38 */
    struct U16Vec *str3C;     /* 0x3C */
    struct U16Vec *str40;     /* 0x40 */
    u8 pad44[0x10];
    struct Bank *bank;        /* 0x54 */
    struct Obj *obj;          /* 0x58 */
    u8 pad5C[0x54];
    void *unkB0;              /* 0xB0 */
};

struct BgTemplate {
    u32 unk_00;
    u32 unk_04;
    u32 bufSize;
    u32 unk_0c;
    u8  unk_10;
    u8  unk_11;
    u8  unk_12;
    u8  unk_13;
    u32 unk_14;
    u8  unk_18;
    u8  unk_19;
    u8  unk_1a;
    u8  unk_1b;
    u32 unk_1c;
};

typedef struct {
    char pad[0x44];
    int a;
    char b;
    char pad2[3];
    int c;
    char d;
} S;

typedef signed int     s32;

unsigned int func_02012138(const struct Ctx *);
void *func_020120F4(const struct Ctx *p);
u8 *func_020120F8(const struct Ctx *p);
unsigned short func_02012AC8(const struct Rec44 *);
int func_02012B70(const struct BigObj *p);
u32 func_02013D5C(u32 id);
u32 func_02026454(void *obj);
u32 func_0202648C(void *obj);
int func_02158344(int a0);
int func_02175DA8(u8 *p);
int func_02175B8C(u8 *p);
void *func_0217EBD8(u8 *p);
void func_0217EEB4(int *p);
void func_0217EF44(Ov018Menu_0217D3AC *, unsigned char *);
void func_0217E638(Ov018Menu_0217D3AC *, int);
void func_0217E714(Ov018Menu_0217D3AC *, unsigned char *, int);
void func_0217DE68(Ov018Menu_0217D3AC *, int);
void func_0217E014(u8 *p, int a1);
void func_0217E0F4(Ov018Menu_0217D3AC *, unsigned char *, int);
void func_0217E3D0(Ov018Menu_0217D3AC *, int, int);
void func_0217E4D0(int *p, int a1);
void func_0217E524(Ov018Menu_0217D3AC *, int);
void func_0217F194(Ov018Menu_0217D3AC *);
void *func_0201210C(const struct Ctx *p);
int func_02158378(void *);
void func_020061E4(u32 a);
void func_0217F174(u8 *p);
void func_0217F0C4(u8 *p);
void *func_0217CEE8(void *p, int a, int b);
void *func_0217CE08(void *, void *, int, int);
void *func_0217CE6C(void *, void *, int);
extern void func_020862F0();
extern void func_0207E5D0();
extern void func_0207E804();
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern struct Obj *func_0204B034(unsigned char *a0, unsigned int a1, unsigned int heap);
extern void func_0204B258(struct Bank *bank, void *p);
extern void *func_02025538(unsigned int a0, void *a1);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern u32 func_0201C440(void *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045808(struct U16Vec *vec);
extern unsigned int func_02045C04(struct Rec *rec);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern unsigned int func_0201ED04(struct WordSet *p);
extern u32 func_0201D83C(void *ptr);
extern void func_02031140(struct S02031140 *p);
extern void func_02025588(void *p);
extern void func_0204B084(int);
extern u32 func_0204B1CC(struct Bank *bank);
void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
void MIi_CpuClear32(u32 data, void *dest, u32 size);
void G2x_SetBlendBrightness_(volatile u16 *reg, int plane, int brightness);
u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
void *func_02049EF4(void *p, u32 a, u32 b, void **out, u16 d);
void MIi_CpuCopy16(const void *src, void *dest, u32 size);
u32 func_020307B0(void *p);
void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
void func_02040588(unsigned char which, unsigned char enable);
void func_0217EF70(int *p, int x);
int func_0217F1E8(u8 *w);
void func_0217F240(u8 *w, int x);
extern void func_020403F4(unsigned int);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(unsigned int);
extern u32 func_020452E8(struct Descriptor *d);
extern s32 func_0204AC18(void *a, unsigned int b, unsigned int c, unsigned int d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, unsigned int b, unsigned int c, unsigned int a3, u16 flags);
extern s32 func_0204AF28(void *owner, unsigned int first, unsigned int second, unsigned int mode);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int func_0204ACEC(void *a0, unsigned int a1, unsigned int a2, unsigned int a3, u16 a4);
extern void func_02049238(void *);
extern void *func_02049DF4(void *a0, unsigned int a1, unsigned int a2, unsigned int a3, u16 a4);
extern int func_0204ABBC(unsigned int idx, unsigned int flag);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082A60(const void *, void *, int);
extern void func_0204ADA4(u32);
extern void func_0204A8D4(u32);
extern void func_0204AFD8(u32);
extern void func_0217DAA8(int *p, void *a1);
extern void func_0217DB4C(int *p, void *a1);
extern void func_0217DBAC(int *p, void *a1);
extern void func_0217DC14(int *p, void *a1);
extern void func_0217DC9C(int *p, void *a1);
extern void func_0217DCFC(int *p, void *a1);
extern void func_0217DD48(void *, void *);
extern void func_0204B3B4(struct Obj *p);
void func_0217D3AC(Ov018Menu_0217D3AC *w);
void *func_0217D4DC(Ov018Menu_0217D4DC *w, int b, int c);
void func_0217D5AC(int a0, u8 *p);
void func_0217D624(struct State *o);
void func_0217D6C8(int *p);
void func_0217D720(u8 *w, void *bg);
void func_0217D870(void);
void func_0217D890(S *p);
void func_0217D904(char *p);
void func_0217D918(u8 *p, void *bg);
void func_0217DA18(u32 *p);
void func_0217DA54(void *p, void *bg);
void func_0217DA90(void **p);
extern unsigned char d_021836B4[];
extern const struct BgTemplate d_0218370C;
extern const struct BgTemplate d_0218372C;
extern const char d_02183B14[];



void func_0217D3AC(Ov018Menu_0217D3AC *w)
{
    void *s1;
    void *s2;
    unsigned char *p;
    int q;
    int flag;
    int k;

    s1 = (void *)func_02012138(w->f0);
    s2 = func_020120F4(w->f0);
    p = (unsigned char *)func_02158344((int)s1);
    q = func_02012AC8((const struct Rec44 *)func_020120F8(w->f0));
    flag = 0;
    k = (int)func_0217EBD8((u8 *)w);
    if (p != 0 && func_02175DA8(p + 0x1AC) == 0) {
        flag = 1;
    } else if (p == 0 && func_02012B70(s2) == 1 && func_02026454(s1) != 2
               && func_0202648C(s1) == 0 && func_02013D5C(q) == 1) {
        flag = 1;
    }
    if (p != 0 && ((FlagsF8 *)(p + 0x8F8))->b == 1) {
        flag = 0;
    }
    if (flag == 1) {
        func_0217EEB4((int *)w);
        func_0217EF44(w, p);
        func_0217E638(w, q);
        func_0217E714(w, p, q);
        func_0217DE68(w, k);
        func_0217E014((u8 *)w, k);
        func_0217E0F4(w, p, k);
        func_0217E3D0(w, k, q);
        func_0217E4D0((int *)w, k);
        func_0217E524(w, k);
        func_0217F194(w);
        return;
    }
    if (p != 0 && func_02175DA8(p + 0x1AC) == 1 && func_02175B8C(p + 0x1AC) == 1
        && w->f16C == 0 && w->fE0 == 0) {
        func_0217E524(w, k);
        w->f16C = 1;
    }
}



void *func_0217D4DC(Ov018Menu_0217D4DC *w, int b, int c)
{
    void *s1;
    void *s2;
    void *r;
    void *ret;

    s1 = (void *)func_02012138(w->f0);
    s2 = func_020120F4(w->f0);
    r = func_0201210C(w->f0);
    ret = 0;
    if (b == 0 || r == 0) {
        return 0;
    }
    if (w->f168 == 1 || (func_02012B70(s2) == 0 && func_02158344((int)s1) == 0)) {
        func_020061E4(0x551);
        func_0217F174((u8 *)w);
        return func_0217CEE8(w->f0, (int)r, c);
    }
    switch (w->f112) {
    case 1:
        func_020061E4(0x737);
        func_0217F0C4((u8 *)w);
        ret = func_0217CE08(w->f0, r, w->f110, 0);
        break;
    case 2:
        func_020061E4(0x737);
        ret = func_0217CE6C(w->f0, r, func_02158378(s1));
        break;
    }
    if (ret != 0) {
        w->f112 = 0;
        return ret;
    }
    return 0;
}



void func_0217D5AC(int a0, u8 *p)
{
    p[0x11D] ^= 1;
    if (p[0x11D] != 0) {
        if (p[0x11C] != 0) {
            func_020862F0(p + 0x130, 8);
            func_0207E5D0(p + 0x130, 0x102, 8);
            p[0x11C] = 0;
        }
        if (p[0x10F] != 0) {
            func_020862F0(((struct Obj03091 *)p)->fD0, 0x200);
            func_0207E804(((struct Obj03091 *)p)->fD0, ((struct Obj03091 *)p)->fD4, 0x200);
            p[0x10F] = 0;
        }
    }
}



void func_0217D624(struct State *o)
{
    struct Obj *t;

    o->bank = func_0204B100(0x29, 5, 0x70);
    t = func_0204B034(d_021836B4, 1, 0x70);
    o->obj = t;
    func_0204B258(o->bank, t);
    o->unkB0 = func_02025538(0x70, o->bank);
    o->tcbl = func_0203101C(0x70, 0x70, 4, 0x20);
    o->font = func_0201D7EC(0x17, 0, 0, 0, 0x70);
    o->words = func_0201EC64(0x70);
    o->unk28 = func_0201C440((void *)0x70);
    o->msg2C = func_02045B38(0, 2, 0x2D, 0x70);
    o->msg30 = func_02045B38(0, 2, 0x42, 0x70);
    o->str38 = func_020457B0(0x80, 0x70);
    o->str3C = func_020457B0(0x80, 0x70);
    o->str40 = func_020457B0(0x80, 0x70);
}



void func_0217D6C8(int *p)
{
    func_02045808((struct U16Vec *)p[0x38 / 4]);
    func_02045808((struct U16Vec *)p[0x3c / 4]);
    func_02045808((struct U16Vec *)p[0x40 / 4]);
    func_02045C04((struct Rec *)p[0x2c / 4]);
    func_02045C04((struct Rec *)p[0x30 / 4]);
    func_0201C6EC((struct PrintSys *)p[0x28 / 4]);
    func_0201C4C0((struct PrintSys *)p[0x28 / 4]);
    func_0201ED04((struct WordSet *)p[0x24 / 4]);
    func_0201D83C((void *)p[0x1c / 4]);
    func_02031140((struct S02031140 *)p[0x20 / 4]);
    func_02025588((void *)p[0xb0 / 4]);
    func_0204B084(p[0x58 / 4]);
    func_0204B1CC((struct Bank *)p[0x54 / 4]);
}



void func_0217D720(u8 *w, void *bg)
{
    int layer;
    u8 *pal;
    void *res;

    layer = 6;
    func_0203FCA0(6, &d_0218370C, 0);
    func_0203FCA0(7, &d_0218372C, 0);
    MIi_CpuClear32(0, (void *)0x06200000, 0x20000);
    REG_DB_DISPCNT_SUB &= 0xFFFF1FFF;
    REG_DB_BLDCNT_SUB = 0;
    G2x_SetBlendBrightness_(&REG_DB_BLDCNT_SUB, 0x3F, -8);
    func_02049658(bg, 4, 7, 0, 0, 1, 0x15);
    func_020498F4(bg, 5, 7, 0, 0x800, 1, 0x15);
    if (w[0xDA] <= 1) {
        w[0x11F] = 0;
    } else {
        layer = 7;
        w[0x11F] = 1;
    }
    func_020498F4(bg, layer, 6, 0, 0x800, 1, 0x15);
    func_0217EF70((int *)w, w[0xD8]);
    res = func_02049EF4(bg, 8, 1, (void **)&pal, 0x15);
    MIi_CpuCopy16(pal + 0xC, w + 0x138, 0x30);
    func_020307B0(res);
    if (func_0217F1E8(w) == 1) {
        func_0217F240(w, 0);
    }
    func_02049B68(bg, 9, 4, 0, 0x140, 0x15);
    func_02049B40(0x17, 5, 4, 0x1C0, 0x20, 0x15);
    func_02040588(4, 0);
    func_02040588(5, 0);
    func_02040588(6, 1);
    func_02040588(7, 1);
}


void func_0217D870(void)
{
    func_02040588(6, 0);
    func_02040588(7, 0);
    func_020403F4(6);
    func_020403F4(7);
}



void func_0217D890(S *p)
{
    int r;
    int r2;
    char z;

    z = 0;
    r = func_020450F0(6, 0, 0, 0x20, 2, 14, 1);
    p->a = r;
    p->b = z;
    func_02045334((struct Descriptor *)r);
    func_02045374((struct Cfg *)r);
    func_020409B4(func_02045730((struct Descriptor *)r));
    r2 = func_020450F0(6, 1, 0x12, 0x1e, 4, 14, 1);
    p->c = r2;
    p->d = z;
    func_02045334((struct Descriptor *)r2);
    func_02045374((struct Cfg *)r2);
    func_020409B4(func_02045730((struct Descriptor *)r2));
}


void func_0217D904(char *p)
{
    func_020452E8(*(struct Descriptor * *)&((struct Obj00703 *)p)->f44);
    func_020452E8(*(struct Descriptor * *)&((struct Obj00703 *)p)->f4C);
}



void func_0217D918(u8 *p, void *bg)
{
    void *t;

    ((struct Obj02676 *)p)->f8 = (void *)func_0204AC18(bg, 3, 1, 0, 0, 9, 0x15);
    ((struct Obj02676 *)p)->f4 = (void *)func_0204A6C8(bg, 0, 1, 1, 0x15);
    ((struct Obj02676 *)p)->f10 = (void *)func_0204AF28(bg, 1, 2, 0x70);
    t = func_020490F4(0x17, 0x15);
    ((struct Obj02676 *)p)->fC = (void *)func_0204ACEC(t, 5, 1, 0x1a0, 0x15);
    func_02049238(t);
    ((struct Obj02676 *)p)->f14 = (void *)func_0204A6C8(bg, 10, 1, 1, 0x15);
    ((struct Obj02676 *)p)->f18 = (void *)func_0204AF28(bg, 12, 13, 0x70);
    ((struct Obj02676 *)p)->fC8 = func_02049DF4(bg, 10, 1, (unsigned int)(p + 0xcc), 0x70);
    ((struct Obj02676 *)p)->fD4 = (void *)func_0204ABBC((unsigned int)(((struct Obj02676 *)p)->f14), 2);
    ((struct Obj02676 *)p)->fD0 = func_02030734(0x70, 0x200, 1, d_02183B14, 0x495);
    func_02082A60((void *)0x050006E2, p + 0x120, 8);
    func_02082A60(p + 0x120, p + 0x130, 8);
    func_02082A60((void *)0x05000702, p + 0x128, 8);
}


void func_0217DA18(u32 *p)
{
    func_020307B0((void *)p[0xd0 / 4]);
    func_020307B0((void *)p[0xc8 / 4]);
    func_0204ADA4(p[3]);
    func_0204ADA4(p[2]);
    func_0204A8D4(p[1]);
    func_0204A8D4(p[5]);
    func_0204AFD8(p[4]);
    func_0204AFD8(p[6]);
}


/*
 * interface: r1 is visibly restored before every call; preserve incoming bg.
 * Callees' matched definitions omit this unused input; no callee edits.
 */
void func_0217DA54(void *p, void *bg)
{
    func_0217DAA8(p, bg);
    func_0217DB4C(p, bg);
    func_0217DBAC(p, bg);
    func_0217DC14(p, bg);
    func_0217DC9C(p, bg);
    func_0217DCFC(p, bg);
    func_0217DD48(p, bg);
}


void func_0217DA90(void **p)
{
    int i;
    for (i = 0; i < 21; i++) func_0204B3B4(p[23 + i]);
}
