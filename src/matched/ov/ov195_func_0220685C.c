/*
 * function: func_0220685C
 * address:  0x0220685C
 * packet:   pkt_0220685C
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_02208F68 0x02208F68 data
 *   func_02030734 0x02030734 arm
 *   func_02043678 0x02043678 arm
 *   func_0202D060 0x0202D060 thumb
 *   func_0202D064 0x0202D064 thumb
 *   func_0202D0D4 0x0202D0D4 thumb
 *   func_02049E34 0x02049E34 arm
 *   func_02049F34 0x02049F34 arm
 *   func_020437D4 0x020437D4 arm
 *   func_02082A7C 0x02082A7C arm
 *   func_02082A90 0x02082A90 arm
 *   func_02044F64 0x02044F64 arm
 *   func_02061CA4 0x02061CA4 arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct CharData {
    u8 pad00[0x14];
    u8 *raw;
} CharData;

typedef struct PlttData {
    u8 pad00[0xc];
    void *raw;
} PlttData;

typedef struct Grid {
    CharData *chr;
    PlttData *pltt;
    void *chrRes;
    void *plttRes;
    void *canvas;
    u32 tex;
    u32 plttAddr;
    u8 rest[0xA278 - 0x1c];
} Grid;

extern char d_02208F68[];
extern void *func_02030734(u16 heap, u32 size, int flags, void *file, u32 line);
extern void *func_02043678(u8 w, u8 h, u32 tileSize, u16 heap);
extern u32 func_0202D060(void);
extern u32 func_0202D064(u32 ctx, u32 a1, u32 a2, u32 a3, u32 s0, u32 s1, u32 s2);
extern u32 func_0202D0D4(u32 ctx, u32 a1, u32 a2, u32 a3, u32 s0, u32 s1, u32 s2);
extern void *func_02049E34(u32 ctx, u32 file, u32 a2, CharData **out, u16 heap);
extern void *func_02049F34(u32 ctx, u32 file, PlttData **out, u16 heap);
extern u8 *func_020437D4(void *canvas);
extern void func_02082A7C(u32 fill, void *dst, u32 size);
extern void func_02082A90(const void *src, void *dst, u32 size);
extern void func_02044F64(void *canvas, u32 v, u16 heap);
extern void func_02061CA4(int type, u32 addr, void *data, u32 size);

Grid *func_0220685C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 tex, u32 pltt, u16 heap)
{
    Grid *g = func_02030734(heap, sizeof(Grid), 1, d_02208F68, 0x720);
    u32 chrFile;
    u32 plttFile;
    u8 *src;
    u8 *buf;
    int i, j;
    int k;

    g->canvas = func_02043678(16, 16, 32, heap);
    g->tex = tex;
    g->plttAddr = pltt;
    chrFile = func_0202D064(func_0202D060(), a0, a1, a2, a3, a4, a5);
    plttFile = func_0202D0D4(func_0202D060(), a0, a1, a2, a3, a4, a5);
    g->chr = 0;
    g->pltt = 0;
    g->chrRes = func_02049E34(func_0202D060(), chrFile, 1, &g->chr, heap);
    g->plttRes = func_02049F34(func_0202D060(), plttFile, &g->pltt, heap);
    src = g->chr->raw;
    buf = func_020437D4(g->canvas);
    func_02082A7C(0, buf, 0x2000);
    k = 0;
    for (j = 0; j < 8; j++) {
        for (i = 0; i < 8; i++) {
            func_02082A90(src + k * 32, buf + 0x440 + (i + j * 16) * 32, 32);
            k++;
        }
    }
    for (j = 0; j < 8; j++) {
        for (i = 8; i < 12; i++) {
            func_02082A90(src + k * 32, buf + 0x440 + (i + j * 16) * 32, 32);
            k++;
        }
    }
    for (j = 8; j < 12; j++) {
        for (i = 0; i < 8; i++) {
            func_02082A90(src + k * 32, buf + 0x440 + (i + j * 16) * 32, 32);
            k++;
        }
    }
    for (j = 8; j < 12; j++) {
        for (i = 8; i < 12; i++) {
            func_02082A90(src + k * 32, buf + 0x440 + (i + j * 16) * 32, 32);
            k++;
        }
    }
    func_02044F64(g->canvas, 0, heap);
    func_02061CA4(0, tex, func_020437D4(g->canvas), 0x2000);
    func_02061CA4(1, pltt, g->pltt->raw, 0x20);
    return g;
}
