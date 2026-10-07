/*
 * file:     field_palace_sys_p11.c
 * unit:     yes
 * function: func_021D2F6C, func_021D3018, func_021D3068, func_021D3090, func_021D30B8, func_021D310C
 * address:  0x021D2F6C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021F3970  0x021F3970  thumb  ov064
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_021F3A44  0x021F3A44  thumb  ov064
 *   func_021F3ADC  0x021F3ADC  thumb
 *   func_021F3AC0  0x021F3AC0  thumb  ov064
 *   func_020120F4  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02030734  0x02030734  arm
 *   d_021DE698     0x021DE698  data  ov021  a4
 *   func_020146F8  0x020146F8  thumb
 *   func_02012374  0x02012374  thumb
 *   func_021D3164  0x021D3164  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   abs_id_e1      0x000000E1  data
 *   d_021BBDE4    0x021BBDE4  data  ov225  a4
 */
struct Ctx;
struct Actor;
struct VecFx32;
struct Desc;
struct Obj;
struct Evt;
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct W {
    void *a;
    void *b;
    void **c;
    u16 *d;
} W;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_0201210C(const struct Ctx *p);
extern unsigned int func_02159B10(void *a, void *b);
extern void *func_02188C7C(unsigned char *p);
extern void *func_0216DE94(void *map, u32 id);
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern void *func_021F3970(void *a, int *v, int *w, int c, int d);
extern void func_0215897C(void *a, void *b);
extern void func_021F3A44(void *a, int *v);
extern void *func_021F3ADC(void *a);
extern void *func_021F3AC0(void *a);
extern void *func_020120F4(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020146F8(char *a0, int a1, int a2, int a3, int a4);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void func_021D3164(u32 *p);
extern u32 func_020307B0(void *p);
u32 func_021D2F6C(u32 a, u32 b);
u32 func_021D3018(u32 a, u32 b);
int func_021D3068(u32 a, u32 b);
int func_021D3090(u32 a, u32 b);
void *func_021D30B8(void *a, u16 *b);
u32 func_021D310C(u32 a, u32 *st, u32 *p);
extern char d_021DE698[];
extern unsigned char abs_id_e1[];
extern char d_021BBDE4[];


/*
 * Addresses are Black-image addresses.
 */
u32 func_021D2F6C(u32 a, u32 b)
{
    int v[3];
    int w[3];
    void *s10;
    void *sc;
    void *s14;
    int s18;
    int s8;
    int s4;
    int r7;
    int r6;
    int r4;
    void *r;

    s10 = func_0215A5F4((void *)b);
    sc = func_0215A5DC((void *)b);
    s14 = func_0201210C(sc);
    s18 = (int)func_02159B10((void *)a, (void *)b);
    s8 = (int)func_02159B10((void *)a, (void *)b);
    s4 = (int)func_02159B10((void *)a, (void *)b);
    r7 = (int)func_02159B10((void *)a, (void *)b);
    r6 = (int)func_02159B10((void *)a, (void *)b);
    r4 = (int)func_02159B10((void *)a, (void *)b);
    r = func_0216DE94(func_02188C7C((void *)s14), s18);
    if (r != 0) {
        func_0216D88C(r, (struct VecFx32 *)v);
    }
    w[0] = (s8 << 16) + 0x8000;
    w[1] = s4 << 15;
    w[2] = (r7 << 16) + 0x8000;
    r = func_021F3970(sc, v, w, r6 << 15, r4);
    if (r == 0) {
        return 1;
    }
    func_0215897C(s10, r);
    return 1;
}


u32 func_021D3018(u32 a, u32 b)
{
    int v[3];
    void *s0;
    int r6;
    int r7;
    int z;

    s0 = func_0215A5DC((void *)b);
    r6 = (int)func_02159B10((void *)a, (void *)b);
    r7 = (int)func_02159B10((void *)a, (void *)b);
    z = (int)func_02159B10((void *)a, (void *)b);
    v[0] = (r6 << 16) + 0x8000;
    v[1] = r7 << 15;
    v[2] = (z << 16) + 0x8000;
    func_021F3A44(s0, v);
    return 0;
}


int func_021D3068(u32 a, u32 b)
{
    void *x = func_0215A5F4((void *)b);
    void *t = func_021F3ADC(func_0215A5DC((void *)b));

    if (t == 0) {
        return 1;
    }
    func_0215897C(x, t);
    return 1;
}


/*
 * func_021F3AC0 resolves in ov064: the only Thumb function starting there
 * that takes one argument (ov043's takes two), and the neighbouring ov021
 * functions func_021D2F6C and func_021D3018 already call ov064 code.
 */
int func_021D3090(u32 a, u32 b)
{
    void *x = func_0215A5F4((void *)b);
    void *t = func_021F3AC0(func_0215A5DC((void *)b));

    if (t == 0) {
        return 1;
    }
    func_0215897C(x, t);
    return 1;
}


void *func_021D30B8(void *a, u16 *b)
{
    void *r7;
    void *s4;
    void *s8;
    W *w;

    r7 = func_020120F4(a);
    s4 = func_0201210C(a);
    s8 = func_020122C0(a, 0, func_021D310C, 0x10);
    w = func_020124E8(s8);
    w->a = a;
    w->b = s4;
    w->d = b;
    w->c = func_02030734(4, 8, 0, d_021DE698, 0x4a);
    *w->c = r7;
    return s8;
}


/*
 * abs_id_e1 is FS_OVERLAY_ID(ov225) (overlay_id).  d_021BBDE4 is ov225's
 * proc table (Thumb entries 0x021B95A1, 0x021B96BD, 0x021B9661), handed
 * to the proc loader with ov225's id; it resolves as sole-ref/data in
 * ov225 through the loaded-overlay exception to the own-window rule
 * (attest_xwin_loaded(), 2026-10-02).  No overlay listing labels
 * 0x021BBDE4 as a function; ov114 has ARM code there.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021D310C(u32 a, u32 *st, u32 *p)
{
    switch (st[0]) {
    case 0:
        func_02012374((struct Evt *)a, func_020146F8((char *)p[0], p[1], (int)abs_id_e1, (int)d_021BBDE4, p[2]));
        st[0]++;
        break;
    case 1:
        func_021D3164(p);
        func_020307B0((void *)p[2]);
        return 1;
    }
    return 0;
}
