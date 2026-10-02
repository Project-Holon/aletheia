/*
 * function: func_021C05B0
 * address:  0x021C05B0
 * packet:   pkt_ov217_021C05B0
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * Note 2026-10-02: DIFF draft. Semantics decoded (240-byte local table copy from d_021C3C54, 3x20 blit loop
 * with v%3 / v/3, tail as func_021C04FC using d_021C37A4[1] = d_021C37D0). Original loads the pool word
 * 021C37D0 twice (no CSE) and keeps j/bmp in stack slots sp+0x20/sp+0x1C; spelling not found.
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
 *
 * Addresses are Black-image addresses.
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

void func_021C05B0(u8 *p)
{
    struct Tab tab;
    struct Bmp *bmp;
    void *text;
    u16 color;
    int j;
    int k;
    u32 v;

    tab = d_021C3C54;
    j = 0;
    bmp = func_0204384C(d_021C37D0.arc, d_021C37D0.member, 0, *(u16 *)(p + 4));
    for (j = 0; j < 3; j++) {
        for (k = 0; k < 20; k++) {
            v = tab.r[j].w[k];
            func_020439A0(bmp, *(struct Bmp **)(p + 0x3B4), (v % 3) << 3, (v / 3) << 3, k << 3, j << 3, 8, 8, 0);
        }
    }
    func_020437AC((struct Obj020437AC *)bmp);
    color = ((d_021C37D0.r & 31) << 10) | ((d_021C37D0.g & 31) << 5) | (d_021C37D0.b & 31);
    text = func_02045EC0(*(struct MsgBank **)(p + 12 + d_021C37D0.bank * 4), d_021C37D0.index);
    func_0201C7D0(*(void **)(p + 0x3B4), d_021C37D0.px, d_021C37D0.py, text, *(void **)(p + 8), color);
    func_020307B0(text);
}
