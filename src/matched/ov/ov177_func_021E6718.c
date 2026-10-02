/*
 * function: func_021E6718
 * address: 0x021E6718
 * packet: pkt_ov177_021E6718
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021E8D36 0x021E8D36 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef struct { void *win; u8 shown; u8 pad[3]; } Slot;
typedef struct {
    unsigned count;      /* 0x00 */
    void *wins[30];      /* 0x04 */
    Slot slots[11];      /* 0x7c */
} Work;
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
extern const WinDef d_021E8D36[];
extern void *func_020450F0(int, int, int, int, int, int, int);
extern void *func_02045770(void *);
extern void func_02043B5C(void *, int);
extern void func_02045334(void *);
extern void func_02045374(void *);
extern int func_02045730(void *);
extern void func_020409B4(int);
extern void *func_020457B0(unsigned, u16);
extern void func_02045CAC(void *, unsigned, void *);
extern void func_0201F02C(void *, int, void *);
extern void func_0201EFA4(void *, int, unsigned, int, int, int);
extern void func_0201F250(void *, void *, void *);
extern void func_0201C724(void *, void *, s16, s16, void *, int, int);
extern void func_02045808(void *);
void func_021E6718(Work *w, unsigned a1, const Info *info, void *a3, int a4, void *a5, void *a6, void *a7, int a8, HeapArg h)
{
    unsigned i;
    void *s1, *s2;
    int j;
    int draw;
    u16 color;
    w->count = 11;
    for (i = 0; i < w->count; i++) {
        void *win;
        w->wins[i] = func_020450F0(5, d_021E8D36[i].a, d_021E8D36[i].b, d_021E8D36[i].c, d_021E8D36[i].d, 0xf, 1);
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
