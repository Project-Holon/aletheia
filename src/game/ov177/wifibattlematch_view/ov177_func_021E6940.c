/*
 * function: func_021E6940
 * address: 0x021E6940
 * packet: pkt_ov177_021E6940
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021E8CCE 0x021E8CCE data a1
 *   func_021E5ADC 0x021E5ADC thumb ov177
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef struct { void *win; u8 shown; u8 pad[3]; } Slot;
typedef struct {
    unsigned count;      /* 0x000 */
    void *wins[30];      /* 0x004 */
    Slot slots[30];      /* 0x07c */
    char pad16c[0x230 - 0x16c];
    u8 bg;               /* 0x230 */
    u8 palette;          /* 0x231 */
} Work;
typedef struct {
    char pad0[0x94];
    unsigned date1;      /* 0x94 */
    unsigned date2;      /* 0x98 */
    unsigned pad9c;
    u16 hA0;             /* 0xa0 */
    u16 padA2;
    unsigned uA4;        /* 0xa4 */
    u16 hA8;             /* 0xa8 */
} Info;
typedef struct { u8 a, b, c, d; } WinDef;
extern const WinDef d_021E8CCE[];
extern unsigned int func_020450F0(unsigned int layer, unsigned int a, unsigned int b, unsigned int tiles, u8 c, u8 d, u8 slot);
typedef unsigned int   u32;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
struct Strbuf;
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern void func_02008500(void *, void *);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F230(struct WordSet *p, u32 i, u32 v);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201C724(void *, void *, s16, s16, void *, int, int);
struct PrintSys;
extern void func_021E5ADC(u32 *p, struct PrintSys *win, u32 str, u32 c2, u32 c1, u16 heap);
extern void func_02045808(struct U16Vec *vec);
void func_021E6940(Work *w, unsigned a1, const Info *info, void *a3, int a4, void *a5, void *a6, void *a7, u16 heap)
{
    unsigned i;
    void *s1, *s2;
    int j;
    int draw;
    u16 color;
    w->count = 8;
    for (i = 0; i < w->count; i++) {
        void *win;
        w->wins[i] = (void *)func_020450F0(w->bg, d_021E8CCE[i].a, d_021E8CCE[i].b, d_021E8CCE[i].c, d_021E8CCE[i].d, w->palette, 1);
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
    s1 = func_020457B0(0x80, heap);
    s2 = func_020457B0(0x80, heap);
    for (j = 0; j < 8; j++) {
        unsigned d1, d2;
        draw = 1;
        color = 0x440;
        switch (j) {
        case 0:
            func_02045924(s2, (const u16 *)info);
            color = 0x3c40;
            break;
        case 1:
            d1 = info->date1;
            d2 = info->date2;
            func_02045CAC(a6, 0x10, s1);
            func_0201EFA4(a7, 0, (u16)((u8)(d1 >> 24) + 2000), 4, 0, 1);
            func_0201F230(a7, 1, (u8)(d1 >> 16));
            func_0201EFA4(a7, 2, (u8)(d1 >> 8), 2, 0, 1);
            func_0201EFA4(a7, 3, (u16)((u8)(d2 >> 24) + 2000), 4, 0, 1);
            func_0201F230(a7, 4, (u8)(d2 >> 16));
            func_0201EFA4(a7, 5, (u8)(d2 >> 8), 2, 0, 1);
            func_0201F250(a7, s2, s1);
            color = 0x3c40;
            break;
        case 2:
            func_02008500(a3, s2);
            color = 0x3c40;
            break;
        case 3:
            func_02045CAC(a6, 8, s2);
            break;
        case 4:
            func_02045CAC(a6, 9, s1);
            func_0201EFA4(a7, 0, info->hA0, 4, 1, 1);
            func_0201F250(a7, s2, s1);
            break;
        case 5:
            func_02045CAC(a6, 10, s2);
            break;
        case 6:
            if (a1) {
                func_021E5ADC((u32 *)(&w->slots[j]), a5, a4, info->uA4, info->hA8, heap);
                draw = 0;
            } else {
                func_02045CAC(a6, 11, s1);
                func_0201EFA4(a7, 0, info->uA4, 6, 1, 1);
                func_0201F250(a7, s2, s1);
            }
            break;
        case 7:
            func_02045CAC(a6, 0x11, s2);
            color = 0x3c40;
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
