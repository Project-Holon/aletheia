/*
 * function: func_02200218
 * address:  0x02200218
 * packet:   pkt_ov094_02200218
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_022019F4  0x022019F4  thumb  ov094
 *   func_021F8754  0x021F8754  thumb  ov094
 *   func_021B994C  0x021B994C  thumb
 *   func_02006984  0x02006984  thumb
 *   func_02006A8C  0x02006A8C  thumb
 *   func_02006AEC  0x02006AEC  thumb
 *   d_02209FC0  0x02209FC0  data  ov094
 *   d_02209FE0  0x02209FE0  data  ov094
 *   d_02209FF0  0x02209FF0  data  ov094
 *   d_0220A068  0x0220A068  data  ov094
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x28];
    u32 k2c;                /* 0x2c */
    u32 k30;                /* 0x30 */
    char pad34[0x06];
    u16 k3a;                /* 0x3a */
    char pad3c[0x20];
} Entry;

typedef struct {
    unsigned int b0 : 1;
    unsigned int b1 : 1;
} Flags;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
    Flags flags;            /* 0x510 */
} Work;

extern u32 d_02209FC0[];
extern u32 d_02209FE0[];
extern u32 d_02209FF0[];
extern u32 d_0220A068[];

extern int func_022019F4(Work *w, int key);
extern int func_021F8754(void);
extern int func_021B994C(void *p, int key, u32 *out);
extern u32 func_02006984(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
extern void func_02006A8C(u32 idx, int delta);
extern void func_02006AEC(u32 idx, u32 delta);

u32 func_02200218(Work *w, int key, int pitch, int pan, u32 a4, u32 a5, u32 a6)
{
    int idx = func_022019F4(w, key);
    u32 id;
    u32 buf;
    u32 *out;
    int flag;
    void *p;
    u32 r;

    if (idx == -1)
        return 0;
    if (w->e[idx].h == 0)
        return 0;
    switch (key) {
    case 0:
    case 1:
        id = d_02209FC0[key];
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        if (w->flags.b1)
            id = d_02209FF0[key - 2];
        else if (w->flags.b0)
            id = d_0220A068[key - 2];
        else
            id = d_02209FE0[key - 2];
        break;
    case 6:
    case 7:
        if (w->flags.b1)
            id = d_02209FF0[key - 2];
        else
            id = d_0220A068[key - 2];
        break;
    }
    p = (void *)func_021F8754();
    out = &buf;
    flag = 0;
    if (p != 0) {
        if (func_021B994C(p, key, out) == 0)
            out = 0;
    } else {
        out = 0;
    }
    if (a4 != 0 || a5 != 0)
        flag = 1;
    if (pitch == (int)0x80000000) {
        if (w->e[idx].k3a == 1)
            pitch = -0xa00;
        else
            pitch = 0;
    }
    r = func_02006984(w->e[idx].k2c, w->e[idx].k30, (u8)id, flag, a4, a5, a6, (u32)out);
    func_02006A8C(r, (signed char)pan);
    func_02006AEC(r, pitch);
    return r;
}
