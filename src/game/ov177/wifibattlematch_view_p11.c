/*
 * file:     wifibattlematch_view_p11.c
 * unit:     yes
 * function: func_021E65FC, func_021E6718
 * address:  0x021E65FC
 * region:   ov177
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021E8D36 0x021E8D36 data a1
 */
struct Actor;
struct PtS;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
typedef struct { short x, y; } Pt;

typedef struct {
    char pad0[0x16c];
    void *objs[22];      /* 0x16c */
    char pad1c4[0x200 - 0x1c4];
    unsigned count;      /* 0x200 */
    short baseX[22];     /* 0x204 */
    unsigned char bg;    /* 0x230 */
    char pad231[3];
    unsigned layer;      /* 0x234 */
} Work_021E65FC;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char u8;

typedef short s16;

typedef struct { void *win; u8 shown; u8 pad[3]; } Slot;

typedef struct {
    unsigned count;      /* 0x00 */
    void *wins[30];      /* 0x04 */
    Slot slots[11];      /* 0x7c */
} Work_021E6718;

typedef struct {
    unsigned f0;
    u16 h4;
    u16 pad6;
    unsigned f8;
    unsigned fC;
    u16 h10;
    u16 h12;
} Info;

typedef struct { u8 a, b, c, d; } WinDef;

typedef struct { u16 heap; } HeapArg;

extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B404(void *, const Pt *, unsigned short);
extern void func_020061E4(unsigned);
extern unsigned func_0209C2B0(unsigned, unsigned);
extern void func_02041EE4(u32 index, u32 a, u32 b);
extern unsigned int func_020450F0(unsigned int layer, unsigned int a, unsigned int b, unsigned int tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void *func_020457B0(unsigned, u16);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201C724(void *, void *, s16, s16, void *, int, int);
extern void func_02045808(struct U16Vec *vec);
int func_021E65FC(Work_021E65FC *w);
void func_021E6718(Work_021E6718 *w, unsigned a1, const Info *info, void *a3, int a4, void *a5, void *a6, void *a7, int a8, HeapArg h);
extern const WinDef d_021E8D36[];

int func_021E65FC(Work_021E65FC *w)
{
    int ret = 0;
    int level;
    int i;
    Pt cur, pos;
    if (w->count == 0) {
        for (i = 0; i < 22; i++) {
            if (w->objs[i] != 0) {
                func_0204B454(w->objs[i], (struct PtS *)&cur, (unsigned short)w->layer);
                w->baseX[i] = cur.x;
            }
        }
        func_020061E4(0x63b);
    }
    level = func_0209C2B0(w->count << 8, 20);
    for (i = 0; i < 22; i++) {
        if (w->objs[i] != 0) {
            func_0204B454(w->objs[i], (struct PtS *)&pos, (unsigned short)w->layer);
            pos.x = w->baseX[i] - func_0209C2B0(w->count << 8, 20);
            func_0204B404(w->objs[i], &pos, w->layer);
        }
    }
    if (w->count++ >= 20) {
        level = 0x100;
        w->count = 0;
        ret = 1;
    }
    func_02041EE4((unsigned char)(w->bg + 1), (int)0, (int)level);
    func_02041EE4((unsigned char)w->bg, (int)0, (int)level);
    return ret;
}

void func_021E6718(Work_021E6718 *w, unsigned a1, const Info *info, void *a3, int a4, void *a5, void *a6, void *a7, int a8, HeapArg h)
{
    unsigned i;
    void *s1, *s2;
    int j;
    int draw;
    u16 color;
    w->count = 11;
    for (i = 0; i < w->count; i++) {
        void *win;
        w->wins[i] = (void *)func_020450F0(5, d_021E8D36[i].a, d_021E8D36[i].b, d_021E8D36[i].c, d_021E8D36[i].d, 0xf, 1);
        func_02043B5C(func_02045770(w->wins[i]), 0);
        win = w->wins[i];
        func_02045334(win);
        func_02045374(win);
        func_020409B4(func_02045730(win));
        if (w->wins[i] != 0) {
            w->slots[i].win = w->wins[i];
            w->slots[i].shown = 0;
        }
    }
    s1 = func_020457B0(0x80, h.heap);
    s2 = func_020457B0(0x80, h.heap);
    for (j = 0; j < 11; j++) {
        color = (a8 == 1) ? 0x3c40 : 0x440;
        draw = 1;
        switch (j) {
        case 0:
            func_02045CAC(a6, a1, s2);
            color = 0x3c40;
            break;
        case 1:
            func_02045CAC(a6, info->f0 + 2, s2);
            color = 0x3c40;
            break;
        case 2:
            func_02045CAC(a6, 7, s1);
            func_0201F02C(a7, 0, a3);
            func_0201F250(a7, s2, s1);
            color = 0x3c40;
            break;
        case 3:
            if (a1)
                func_02045CAC(a6, 8, s2);
            else
                draw = 0;
            break;
        case 4:
            if (a1) {
                func_02045CAC(a6, 9, s1);
                func_0201EFA4(a7, 0, info->h4, 4, 1, 1);
                func_0201F250(a7, s2, s1);
            } else {
                draw = 0;
            }
            break;
        case 5:
            func_02045CAC(a6, 10, s2);
            break;
        case 6:
            func_02045CAC(a6, 11, s1);
            func_0201EFA4(a7, 0, info->fC, 6, 1, 1);
            func_0201F250(a7, s2, s1);
            break;
        case 7:
            func_02045CAC(a6, 12, s2);
            break;
        case 8:
            func_02045CAC(a6, 13, s1);
            func_0201EFA4(a7, 0, info->h10, 5, 1, 1);
            func_0201F250(a7, s2, s1);
            break;
        case 9:
            func_02045CAC(a6, 14, s2);
            break;
        case 10:
            func_02045CAC(a6, 15, s1);
            func_0201EFA4(a7, 0, info->h12, 5, 1, 1);
            func_0201F250(a7, s2, s1);
            break;
        }
        if (draw) {
            func_0201C724(a5, func_02045770(w->slots[j].win), 0, 0, s2, a4, color);
            w->slots[j].shown = 1;
        }
    }
    func_02045808(s1);
    func_02045808(s2);
}
