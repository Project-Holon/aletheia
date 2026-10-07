/*
 * file:     btlv_effvm_p96.c
 * unit:     yes
 * function: func_02204A70, func_02204A88, func_02204AEC, func_02204B0C, func_02204BAC, func_02204BCC, func_02204C48
 * address:  0x02204A70
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B454  0x0204B454  arm
 *   func_0204B404  0x0204B404  arm
 *   func_0220687C  0x0220687C  thumb  ov094
 *   d_0220AEB0     0x0220AEB0  data   ov094  a1
 *   d_0220A38C     0x0220A38C  data   ov094  a1
 *   d_0220A3E4     0x0220A3E4  data   ov094  a4
 *   func_02030734  0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   func_022042E4  0x022042E4  thumb  ov094
 *   func_022043AC  0x022043AC  thumb  ov094
 *   func_0220684C  0x0220684C  thumb  ov094
 *   func_021F8AC0  0x021F8AC0  thumb  ov094
 *   func_021F7998  0x021F7998  thumb  ov094
 *   func_021F8678 0x021F8678 thumb ov094
 *   func_021F8884 0x021F8884 thumb ov094
 *   func_0207D658  0x0207D658  arm
 */
#define reg_GXS_DB_DISPCNT (*(volatile u32 *)0x04001000)
#define reg_G2S_DB_WININ   (*(volatile u16 *)0x04001048)
#define reg_G2S_DB_WINOUT  (*(volatile u16 *)0x0400104A)
#define reg_G2S_DB_BLDCNT  (*(volatile u16 *)0x04001050)
struct S02030EE8;
struct Actor;
struct PtS;
struct Obj;
struct Vec2;
typedef struct Bits_02204A70 { unsigned lo:15; unsigned mode:2; unsigned hi:15; } Bits_02204A70;

typedef unsigned int   u32;

typedef short s16;

typedef struct Main_02204A88 {
    unsigned char pad00[0x210];
    void *o210;
    void *o214;
} Main_02204A88;

typedef struct Ctx {
    Main_02204A88 *main;
} Ctx;

typedef unsigned short u16;

typedef struct Bits_02204AEC { unsigned a:1; unsigned n:3; unsigned rest:28; } Bits_02204AEC;

typedef unsigned char u8;

typedef struct Main_02204B0C {
    void *owner;
    unsigned char pad04[0x68 - 4];
    u32 b0 : 1;
    u32 lo : 18;
    u32 mode : 2;
    u32 hi : 11;
    unsigned char pad6c[0x240 - 0x6c];
    u16 h240;
} Main_02204B0C;

typedef struct Obj {
    Main_02204B0C *main;
} Obj;

typedef int BOOL;

extern u32 func_02030EE8(struct S02030EE8 *p);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0220687C(char *p, void *q);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02030DA8(void *owner, void (*fn)(void *, void *), void *p, u32 a3);
extern void func_022042E4(void *a, void *b);
extern void func_022043AC(void *h);
extern void func_0220684C(char *p, int a, int b);
extern void func_021F8AC0(int a);
extern void func_021F7998(u32 a);
extern void *func_021F8678(void);
extern void func_021F8884(int a);
extern void func_0207D658(u32 addr, int plane, int brightness);
void func_02204A70(void *h);
void func_02204A88(int a0, Ctx *c);
void func_02204AEC(void *h);
void func_02204B0C(Main_02204B0C *m, int c);
void func_02204BAC(int a, int *b);
void func_02204BCC(void *a0, int *c);
void func_02204C48(void *a0, int *c);
extern const char d_0220AEB0[];
extern const u8 d_0220A38C[][2];
extern const int d_0220A3E4[][2];


void func_02204A70(void *h)
{
    char *p = *((char **)func_02030EE8(h));
    ((Bits_02204A70 *)(p + 0x68))->mode = 0;
}


void func_02204A88(int a0, Ctx *c)
{
    s16 v[2];

    func_0204B454(c->main->o210, (struct PtS *)v, 1);
    v[0] -= 8;
    func_0204B404(c->main->o210, (const struct Vec2 *)v, 1);
    func_0204B454(c->main->o214, (struct PtS *)v, 1);
    v[0] -= 8;
    func_0204B404(c->main->o214, (const struct Vec2 *)v, 1);
    if (v[0] == 0xe0) {
        func_0220687C((char *)c->main, (void *)a0);
    }
}


void func_02204AEC(void *h)
{
    char *p = *((char **)func_02030EE8(h));
    ((Bits_02204AEC *)(p + 0x68))->n--;
}


void func_02204B0C(Main_02204B0C *m, int c)
{
    Obj *o;
    int k;

    o = func_02030734((u16)((m->h240 & 0x7fff) | 0x8000), 0x24, 1, d_0220AEB0, 0xd8c);
    k = m->mode;
    m->mode = d_0220A38C[k][c - 5];
    m->b0 = 1;
    o->main = m;
    func_0220684C((char *)m, (int)func_02030DA8(m->owner, func_022042E4, o, 1), (int)((void *)func_022043AC));
    func_021F8AC0(2);
    func_021F7998(d_0220A3E4[k][c - 5]);
}


/*
 * lane O10 candidate
 */
void func_02204BAC(int a, int *b)
{
    if (func_021F8678() != 0) {
        func_021F8884(b[1]);
        func_0220687C((char *)b[0], (void *)a);
    }
}


static inline void GXS_SetVisibleWnd(int mask)
{
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0xe000) | ((u32)mask << 13);
}


static inline void G2S_SetWnd0InsidePlane(int wnd, BOOL effect)
{
    u32 tmp;
    tmp = ((reg_G2S_DB_WININ & ~0x3f) | ((u32)wnd << 0));
    if (effect) {
        tmp |= (0x20 << 0);
    }
    reg_G2S_DB_WININ = (u16)tmp;
}


static inline void G2S_SetWnd1InsidePlane(int wnd, BOOL effect)
{
    u32 tmp;
    tmp = ((reg_G2S_DB_WININ & ~0x3f00) | ((u32)wnd << 8));
    if (effect) {
        tmp |= (0x20 << 8);
    }
    reg_G2S_DB_WININ = (u16)tmp;
}


static inline void G2S_SetWndOutsidePlane(int wnd, BOOL effect)
{
    u32 tmp;
    tmp = ((reg_G2S_DB_WINOUT & ~0x3f) | ((u32)wnd << 0));
    if (effect) {
        tmp |= (0x20 << 0);
    }
    reg_G2S_DB_WINOUT = (u16)tmp;
}


static inline void G2S_SetBlendBrightness(int plane, int brightness)
{
    func_0207D658((u32)&reg_G2S_DB_BLDCNT, plane, brightness);
}


/*
 * volatile: sub-engine DISPCNT 0x04001000, WININ 0x04001048, WINOUT 0x0400104A read-modify-written by the SDK inlines (0x02204BD4..0x02204C20)
 */
void func_02204BCC(void *a0, int *c)
{
    GXS_SetVisibleWnd(3);
    G2S_SetWnd0InsidePlane(0x1f, c[1] > 1);
    G2S_SetWnd1InsidePlane(0x1f, c[1] == 3);
    G2S_SetWndOutsidePlane(0x1f, 0);
    G2S_SetBlendBrightness(0x10, -8);
    func_0220687C((void *)c[0], a0);
}


static inline void G2S_BlendNone(void)
{
    func_0207D658((u32)&reg_G2S_DB_BLDCNT, 0, 0);
}


/*
 * volatile: sub-engine DISPCNT 0x04001000, WININ 0x04001048, WINOUT 0x0400104A read-modify-written by the SDK inlines (0x02204C4C..0x02204C76)
 */
void func_02204C48(void *a0, int *c)
{
    GXS_SetVisibleWnd(0);
    G2S_SetWnd0InsidePlane(0, 0);
    G2S_SetWnd1InsidePlane(0, 0);
    G2S_SetWndOutsidePlane(0, 0);
    G2S_BlendNone();
    func_0220687C((void *)c[0], a0);
}
