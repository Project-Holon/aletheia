/*
 * function: func_021C05B0
 * address:  0x021C05B0
 * packet:   pkt_ov217_021C05B0
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Same lever as 021BD178: u32 base local cast per use, loop shape as the twins (i outer, y = i*8).
 *
 * symbols:
 *   d_021C3C54  0x021C3C54  data  a4
 *   d_021C37D0  0x021C37D0  data  a4
 *   func_0204384C  0x0204384C  arm
 *   func_020439A0  0x020439A0  arm
 *   func_020437AC  0x020437AC  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201C7D0  0x0201C7D0  thumb
 *   func_020307B0  0x020307B0  arm
 *   _u32_div_f  0x0209C0A4  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

struct Entry {
    int x, y, pad, bank, index, px, py;
    u8 r, g, b, pad2;
    u32 arc, member, enabled;
};
struct Row {
    u32 w[20];
};
struct Tab {
    struct Row r[3];
};
struct Bmp;
struct MsgBank;
struct Obj020437AC;

extern const struct Tab d_021C3C54;
extern const struct Entry d_021C37D0;
extern struct Bmp *func_0204384C(u32, u32, u32, u32);
extern void func_020439A0(struct Bmp *, struct Bmp *, u32, u32, int, int, u32, u32, u32);
extern void *func_02045EC0(struct MsgBank *, u32);
extern void func_0201C7D0(void *, s16, s16, void *, void *, u16);
extern void func_020307B0(void *);
extern void func_020437AC(struct Obj020437AC *);

#define E ((const struct Entry *)gb)
void func_021C05B0(u8 *p)
{
    struct Tab tab = d_021C3C54;
    int i;
    int j;
    struct Bmp *bmp;
    void *text;
    u16 color;
    u32 gb = (u32)&d_021C37D0;
    bmp = func_0204384C(E->arc, E->member, 0, *(u16 *)(p + 4));
    for (i = 0; i < 3; i++) {
        int y = i * 8;
        for (j = 0; j < 20; j++) {
            func_020439A0(bmp, *(struct Bmp **)(p + 0x3B4), (tab.r[i].w[j] % 3) * 8, (tab.r[i].w[j] / 3) * 8, j * 8, y, 8, 8, 0);
        }
    }
    func_020437AC((struct Obj020437AC *)bmp);
    color = ((E->r & 31) << 10) | ((E->g & 31) << 5) | (E->b & 31);
    text = func_02045EC0(*(struct MsgBank **)(p + 12 + E->bank * 4), E->index);
    func_0201C7D0(*(void **)(p + 0x3B4), E->px, E->py, text, *(void **)(p + 8), color);
    func_020307B0(text);
}
