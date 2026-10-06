/*
 * function: func_0217C758
 * address:  0x0217C758
 * packet:   pkt_ov018_0217C758
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Initialises a 0x18-byte record (cleared by the fill below) and, when the
 * last argument is set, places its field object. The pool carries
 * 0x02183AF0 twice (stores, then call arguments), so two extern names:
 * see docs/idioms/a-duplicated-pool-word-is-a-second-extern-name-for-the-same-address.md.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02012964  0x02012964  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D8AC  0x0216D8AC  thumb  ov010
 *   func_0216E618  0x0216E618  thumb  ov010
 *   func_0216CE60  0x0216CE60  thumb  ov010
 *   func_0217BCDC  0x0217BCDC  thumb  ov018
 *   func_0216DAC8  0x0216DAC8  thumb  ov010
 *   d_02183AF0     0x02183AF0  data  a4
 *   g_02183AF0     0x02183AF0  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

typedef struct {
    void *f0;
    void *f4;
    s16 f8;
    s16 fA;
    u16 fC;
    u8 fE;
    u8 fF;
    u8 f10;
    u8 f11;
    u8 f12;
    u8 f13;
    void *f14;
} Rec;

typedef struct {
    u16 f0;
    u16 f2;
    u8 pad04[8];
    u16 fC;
} Tmpl;

extern Tmpl d_02183AF0;
extern Tmpl g_02183AF0;

extern void func_02082BCC(void *, int, int);
struct BigObj;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_02012964(const struct BigObj *p);
struct Obj00020;
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(unsigned char *p);
extern u16 func_02188C9C(unsigned char *);
extern u16 func_0216D598(void *);
extern int func_0216D83C(void *);
extern int func_0216D86C(void *);
extern u32 func_0216D8AC(void *p);
extern void func_0216E618(Tmpl *, u16, u16, int);
extern void *func_0216CE60(int, Tmpl *, int);
extern void func_0217BCDC(u8 *p, void *a1, int id, u8 kind, u8 flag);
extern void func_0216DAC8(unsigned int *, unsigned int);

void func_0217C758(Rec *r, void *a1, void *a2, void *a3, u16 id, u8 kind,
                   u8 flag, u16 idx, int place)
{
    int sys;
    void *obj;
    int zone;
    int x;
    int y;

    func_02082BCC(r, 0, 0x18);
    r->f0 = a1;
    r->f4 = a2;
    r->fC = id;
    r->fE = kind;
    r->fF = flag;
    r->fA = 15;
    r->f8 = r->fA;
    r->f13 = idx;
    if (place != 0) {
        sys = func_02012964(func_020120F4(a1));
        obj = func_021A3074(func_02188CB4(a2));
        zone = func_02188C9C(a2);
        d_02183AF0.f2 = func_0216D598(obj);
        d_02183AF0.fC = idx;
        x = func_0216D83C(obj);
        y = func_0216D86C(obj);
        func_0216E618(&g_02183AF0, x, y, func_0216D8AC(obj));
        r->f14 = func_0216CE60(sys, &g_02183AF0, zone);
        func_0217BCDC(a3, r->f0, r->fC, r->fE, r->fF);
        func_0216DAC8(obj, 1);
        func_0216DAC8(r->f14, 0);
    }
}
