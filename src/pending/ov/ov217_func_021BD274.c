/*
 * function: func_021BD274
 * address: 0x021BD274
 * packet: pkt_ov217_021BD274
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 *
 * Note 2026-10-04 (wD2 lane12): same residue as 021BD178 (uncached base pool loads, 236 vs 252 bytes). aligned(32) extern tried on the twin: no help.
 *
 * DIFF 2026-10-02 (wC1 lane02): body order/slots/calls match; 8 extra pool loads missing. The original reloads the
 * d_021C34C8 base from the (single) pool word for every field access (compiled 236 bytes vs 252); mine keeps it in a register.
 * Tried non-const, volatile, literal-address macro: no change. Twin of func_021BD178 (field 0x52, tables d_021C32D8 and d_021C34C8).
 *
 * symbols:
 *   _s32_div_f 0x0209C0A4 arm
 *   func_0204384C 0x0204384C arm
 *   func_020439A0 0x020439A0 arm
 *   func_020437AC 0x020437AC arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201C7D0 0x0201C7D0 thumb
 *   d_021C32D8 0x021C32D8 data a4
 *   d_021C34C8 0x021C34C8 data a4
 *   func_020307B0 0x020307B0 arm
 *
 * Note 2026-10-04 (wD1 lane06): Same residue as 021BD178: base address pool word is reloaded per field access in the original; not reproduced.
 */
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef unsigned int u32;
struct Tab { int v[3][10]; };
struct G {
    char pad0[0xc];
    u32 f0c;
    u32 f10;
    int f14;
    int f18;
    u8 f1c;
    u8 f1d;
    u8 f1e;
    u8 pad1f;
    u32 f20;
    u32 f24;
};
extern int func_020307B0(void *p);
struct S { char pad0[8]; u16 h8; char pad1[2]; u32 f0c; u32 arr[0x148 / 4 - 4]; void *f148; };
extern int _s32_div_f(int, int);
extern const struct Tab d_021C32D8;
extern const struct G d_021C34C8;
extern void *func_0204384C(u32 a, u32 b, u32 c, u32 d);
extern void func_020439A0(void *dst, void *src, u32 sx, u32 sy, u32 dx, u32 dy, u32 w, u32 h, u32 z);
extern void func_020437AC(void *p);
extern void *func_02045EC0(void *h, u32 idx);
extern void func_0201C7D0(void *a, u32 b, u32 c, void *d, u32 e, u32 f);

void func_021BD274(struct S *p)
{
    struct Tab tab = d_021C32D8;
    int i;
    int j;
    void *heap;
    void *res;
    u16 color;
    heap = func_0204384C(d_021C34C8.f20, d_021C34C8.f24, 0, p->h8);
    for (i = 0; i < 3; i++) {
        int y = i * 8;
        for (j = 0; j < 10; j++) {
            func_020439A0(heap, p->f148, (tab.v[i][j] % 3) * 8, (tab.v[i][j] / 3) * 8, j * 8, y, 8, 8, 0);
        }
    }
    func_020437AC(heap);
    color = (d_021C34C8.f1e & 0x1f) | ((d_021C34C8.f1c & 0x1f) << 10) | ((d_021C34C8.f1d & 0x1f) << 5);
    res = func_02045EC0((void *)p->arr[d_021C34C8.f0c], d_021C34C8.f10);
    func_0201C7D0(p->f148, (s16)d_021C34C8.f14, (s16)d_021C34C8.f18, res, p->f0c, color);
    func_020307B0(res);
}
