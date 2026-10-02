/*
 * function: ov208_func_021BC844
 * address:  0x021BC844
 * packet:   pkt_ov208_021BC844
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02049BDC  0x02049BDC  arm
 *   func_02049740  0x02049740  arm
 *   func_02049990  0x02049990  arm
 *   func_020413B0  0x020413B0  arm
 *   func_02049238  0x02049238  arm
 *   func_02041B6C  0x02041B6C  arm
 *   data_021C8D98  0x021C8D98  data
 *   data_021C80E0  0x021C80E0  data
 *   data_021C80E8  0x021C80E8  data
 *   data_021C80F0  0x021C80F0  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ov208BgArc {
    u32 chr;
    u32 scr;
    u32 size;
};

struct Ov208Win {
    u32 chrOfs;
    u8  layer;
    u8  kind;
};

extern void *func_02030734(u32 heap, u32 size, u32 clear, const char *file, u32 line);
extern void *func_020490F4(unsigned int id, u16 heap);
extern void func_02049BDC(void *h, u32 id, u32 type, u32 ofs, u32 src, u32 size, u16 heap);
extern u32  func_02049740(void *h, u32 id, u32 layer, u32 ofs, u32 size, u32 heap);
extern void func_02049990(void *h, u32 id, u32 layer, u32 ofs, u32 chrOfs, u32 a5, u32 a6,
                          u32 heap);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02049238(void *h);
extern void func_02041B6C(int layer);
extern const char data_021C8D98[];
extern const u8 data_021C80E0[2][4];
extern const u8 data_021C80E8[2][4];
extern const struct Ov208BgArc data_021C80F0[2];

struct Ov208Win *ov208_func_021BC844(u16 heap, u32 kind, u8 layer, u8 pal, u8 objPal)
{
    struct Ov208Win *w;
    void *h;
    u32 sub;
    u32 type;
    u32 scr;

    w = func_02030734(heap, sizeof(*w), 1, data_021C8D98, 0x323);
    if (layer < 4) {
        sub = 0;
        type = 0;
    } else {
        sub = 1;
        type = 4;
    }
    h = func_020490F4(0x9f, heap);
    func_02049BDC(h, data_021C80F0[sub].chr, type, data_021C80E8[sub][kind] << 5, pal << 5,
                  0x20, heap);
    func_02049BDC(h, data_021C80F0[sub].chr, type, data_021C80E0[sub][kind] << 5,
                  objPal << 5, 0x20, heap);
    w->chrOfs = func_02049740(h, data_021C80F0[sub].scr, layer, 0, 0, heap);
    scr = data_021C80F0[sub].size;
    if (kind == 3 && sub == 0)
        scr = 0x20;
    func_02049990(h, scr, layer, 0, (u16)w->chrOfs, 0, 0, heap);
    func_020413B0(layer, 0, 0x15, 0x20, 3, pal);
    func_020413B0(layer, 0, 0, 0x20, 0x15, objPal);
    func_02049238(h);
    func_02041B6C(layer);
    w->layer = layer;
    w->kind = 4;
    return w;
}
