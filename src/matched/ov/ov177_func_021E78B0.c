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
 *   PMS_DRAW_Print  0x0202DC48  thumb  arm9
 *   PMS_DRAW_SetPrintColor  0x0202DE64  thumb  arm9
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
extern unsigned int func_020450F0(unsigned int layer, unsigned int a, unsigned int b, unsigned int tiles, unsigned char c, unsigned char d, unsigned char slot);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct PmsDraw;
struct Strbuf;
struct U16Vec;
struct WordSet;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void *func_020457B0(unsigned capacity, u16 heap);
extern void func_02045808(struct U16Vec *vec);
extern const void *func_020084F4(const void *p);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
struct Sub0200852CObj;
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern void func_0201F048(struct WordSet *p, u32 i, u32 n);
extern void func_0201F094(struct WordSet *p, u32 i, u32 a, u32 n);
extern void PMS_DRAW_SetPrintColor(struct PmsDraw *p, u16 v);
extern void PMS_DRAW_Print(void *, void *, const void *, unsigned);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
void func_021E78B0(Work *p, const Record *data, unsigned font, void *print, void *msg, void *fmt, int alt, u16 heap)
{
    void *str;
    void *buf;
    int j;
    u16 color;
    int draw;
    void *win;
    int i;
    for (i = 0; i < 8; i++) {
        p->win[i] = (void *)func_020450F0(1, d_021E8CEE[i].bg, d_021E8CEE[i].x, d_021E8CEE[i].y, d_021E8CEE[i].w, 15, 1);
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
            func_0201F048(fmt, 0, func_0200856C((const struct Sub0200852CObj *)data));
            func_0201F250(fmt, str, buf);
            break;
        case 5:
            func_02045CAC(msg, 23, buf);
            func_0201F094(fmt, 0, func_0200856C((const struct Sub0200852CObj *)data), func_02008570((const struct Sub0200852CObj *)data));
            func_0201F250(fmt, str, buf);
            break;
        case 6:
            func_02045CAC(msg, 21, str);
            color = 0x3C40;
            break;
        case 7:
            PMS_DRAW_SetPrintColor(p->list, color);
            PMS_DRAW_Print(p->list, p->win[j], data->name, 0);
            draw = 0;
            break;
        }
        if (draw) {
            func_0201C724(print, (u32)func_02045770(p->ent[j].win), 0, 0, (u32)str, font, color);
            p->ent[j].shown = 1;
        }
    }
    func_02045808(buf);
    func_02045808(str);
}
