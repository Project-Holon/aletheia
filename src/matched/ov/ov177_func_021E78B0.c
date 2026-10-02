/*
 * function: func_021E78B0
 * address: 0x021E78B0
 * packet: pkt_ov177_021E78B0
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021E8CEE 0x021E8CEE data a1
 */
typedef unsigned short u16;
typedef struct { unsigned char bg, x, y, w; } WinTemplate;
typedef struct { void *win; unsigned char shown; } Entry;
typedef struct {
    int active;
    void *win[8];
    Entry ent[7];
    char pad5c[0x7c - 0x5c];
    void *list;
    char pad80[0x98 - 0x80];
    int mode;
} Work;
typedef struct { char pad0[0x28]; unsigned score; char pad2c[0x34 - 0x2c]; unsigned count; char name[1]; } Record;
extern const WinTemplate d_021E8CEE[];
extern void *func_020450F0(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);
extern void *func_02045770(void *win);
extern void func_02043B5C(void *bmp, unsigned c);
extern void func_02045334(void *);
extern void func_02045374(void *);
extern unsigned char func_02045730(void *win);
extern void func_020409B4(int v);
extern void *func_020457B0(unsigned capacity, u16 heap);
extern void func_02045808(void *);
extern void *func_020084F4(const void *);
extern void func_02045924(void *, void *);
extern void func_02045CAC(void *, unsigned, void *);
extern void func_0201EFA4(void *, unsigned, unsigned, unsigned, unsigned, unsigned);
extern void func_0201F250(void *, void *, void *);
extern unsigned func_0200856C(const void *);
extern unsigned func_02008570(const void *);
extern void func_0201F048(void *, unsigned, unsigned);
extern void func_0201F094(void *, unsigned, unsigned, unsigned);
extern void func_0202DE64(void *, unsigned);
extern void func_0202DC48(void *, void *, const void *, unsigned);
extern void func_0201C724(unsigned print, void *bmp, short x, short y, void *str, unsigned font, u16 color);
void func_021E78B0(Work *p, const Record *data, unsigned font, unsigned print, void *msg, void *fmt, int alt, u16 heap)
{
    void *str;
    void *buf;
    int j;
    u16 color;
    int draw;
    void *win;
    int i;
    for (i = 0; i < 8; i++) {
        p->win[i] = func_020450F0(1, d_021E8CEE[i].bg, d_021E8CEE[i].x, d_021E8CEE[i].y, d_021E8CEE[i].w, 15, 1);
        func_02043B5C(func_02045770(p->win[i]), 0);
        win = p->win[i];
        func_02045334(win);
        func_02045374(win);
        func_020409B4(func_02045730(win));
        if (i != 7) {
            p->ent[i].win = p->win[i];
            p->ent[i].shown = 0;
        }
    }
    buf = func_020457B0(0x80, heap);
    str = func_020457B0(0x80, heap);
    for (j = 0; j < 8; j++) {
        color = alt == 1 ? 0x3C40 : 0x440;
        draw = 1;
        switch (j) {
        case 0:
            func_02045924(str, func_020084F4(data));
            color = 0x3C40;
            break;
        case 1:
            if (p->mode == 3) {
                func_02045CAC(msg, 12, str);
                color = 0x3C40;
            } else if (p->active != 0) {
                func_02045CAC(msg, 8, str);
                color = 0x3C40;
            } else {
                draw = 0;
            }
            break;
        case 2:
            if (p->mode == 3) {
                func_02045CAC(msg, 13, buf);
                func_0201EFA4(fmt, 0, data->score, 5, 1, 1);
                func_0201F250(fmt, str, buf);
                color = 0x3C40;
            } else if (p->active != 0) {
                func_02045CAC(msg, 9, buf);
                func_0201EFA4(fmt, 0, data->count, 4, 1, 1);
                func_0201F250(fmt, str, buf);
                color = 0x3C40;
            } else {
                draw = 0;
            }
            break;
        case 3:
            func_02045CAC(msg, 20, str);
            color = 0x3C40;
            break;
        case 4:
            func_02045CAC(msg, 22, buf);
            func_0201F048(fmt, 0, func_0200856C(data));
            func_0201F250(fmt, str, buf);
            break;
        case 5:
            func_02045CAC(msg, 23, buf);
            func_0201F094(fmt, 0, func_0200856C(data), func_02008570(data));
            func_0201F250(fmt, str, buf);
            break;
        case 6:
            func_02045CAC(msg, 21, str);
            color = 0x3C40;
            break;
        case 7:
            func_0202DE64(p->list, color);
            func_0202DC48(p->list, p->win[j], data->name, 0);
            draw = 0;
            break;
        }
        if (draw) {
            func_0201C724(print, func_02045770(p->ent[j].win), 0, 0, str, font, color);
            p->ent[j].shown = 1;
        }
    }
    func_02045808(buf);
    func_02045808(str);
}
