/*
 * function: func_021C6C7C
 * address:  0x021C6C7C
 * packet:   pkt_ov111_021C6C7C
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_0201C7D0  0x0201C7D0  thumb
 *   func_0200864C  0x0200864C  thumb
 *   func_02008650  0x02008650  thumb
 *   func_021C6BD4  0x021C6BD4  thumb  ov111
 *   d_021C8768     0x021C8768  data  a2
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

extern void *func_02045770(void *p);
extern void func_0201C7D0(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern u32 func_0200864C(void *p);
extern u32 func_02008650(void *p);
extern void func_021C6BD4(void *p, void *a, int x, int dx, int y, void *s, int n, u8 kind, u32 mode, int w0, int h0, int idx);
extern const u16 d_021C8768[];

typedef struct {
    u8 pad0[0x1C];
    void *f1C;
    u8 pad20[0x2A - 0x20];
    u16 h2A;
    u8 pad2C[2];
    u8 b2E;
} Info;

typedef struct {
    u8 pad0[0x31FC];
    void *f31FC;
    u8 pad3200[0x320C - 0x3200];
    void *f320C;
} Work;

void func_021C6C7C(Work *p, void *a, int y, const Info *info, void *s, int idx)
{
    int v;

    if (info->f1C == 0) {
        func_021C6BD4(p, a, 0xD8, 0, y, s, info->b2E, 2, 2, 0xD0, 0x10, idx);
        func_021C6BD4(p, a, 0xD8, 0x13, y, s, info->h2A, 3, 1, 0xAD, 0x1B, idx);
        func_0201C7D0(func_02045770(a), 0xC6, y, p->f320C, p->f31FC, d_021C8768[idx]);
    } else {
        v = func_0200864C(info->f1C);
        if (v > 999) {
            v = 999;
        }
        func_021C6BD4(p, a, 0xD8, 0, y, s, func_02008650(info->f1C), 2, 2, 0xD0, 0x10, idx);
        func_021C6BD4(p, a, 0xD8, 0x13, y, s, v, 3, 1, 0xAD, 0x1B, idx);
        func_0201C7D0(func_02045770(a), 0xC6, y, p->f320C, p->f31FC, d_021C8768[idx]);
    }
}
