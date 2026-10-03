/*
 * function: func_021C2918
 * address:  0x021C2918
 * packet:   pkt_ov021_021C2918
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_02043678  0x02043678  arm
 *   func_02048A0C  0x02048A0C  arm
 *   func_02047388  0x02047388  arm
 *   func_020473B8  0x020473B8  arm
 *   func_0202D060  0x0202D060  thumb
 *   func_0202D064  0x0202D064  thumb
 *   func_0202D0D4  0x0202D0D4  thumb
 *   func_02049E34  0x02049E34  arm
 *   func_02049F34  0x02049F34  arm
 *   func_020437D4  0x020437D4  arm
 *   func_02082A7C  0x02082A7C  arm
 *   func_02082A90  0x02082A90  arm
 *   func_02044F64  0x02044F64  arm
 *   func_02061CA4  0x02061CA4  arm
 *   func_02030830  0x02030830  arm
 * Twin of ov195 func_0220685C (same tile-copy body). The far argument block
 * at +0x9C needs a local pointer (`a = p->args`), and the two size calls
 * must land in int locals before the (u16) << 3 conversions.
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

typedef struct Obj {
    u8 pad00[0x10];
    u16 heap;
    u16 pad12;
    void *f14;
    u8 pad18[0x88 - 0x18];
    CharData *chr;
    PlttData *pltt;
    void *canvas;
    void *chrRes;
    void *plttRes;
    u32 args[5];
} Obj;

typedef signed int     s32;
struct Bmp;
struct Layer;
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u32 heap);
extern void *func_02048A0C(void *p, int i);
extern u32 func_02047388(struct Layer *layer);
extern u32 func_020473B8(struct Layer *layer);
extern int func_0202D060(void);
extern s32 func_0202D064(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
extern s32 func_0202D0D4(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
extern void *func_02049E34(u32 ctx, u32 file, u32 a2, CharData **out, u16 heap);
extern void *func_02049F34(u32 ctx, u32 file, PlttData **out, u16 heap);
extern void *func_020437D4(const struct Bmp *bmp);
extern void func_02082A7C(u32 fill, void *dst, u32 size);
extern void func_02082A90(const void *src, void *dst, u32 size);
extern void func_02044F64(void *canvas, u32 v, u16 heap);
extern void func_02061CA4(int type, u32 addr, void *data, u32 size);
extern void *func_02030830(u32 heapId);

void func_021C2918(Obj *p)
{
    u16 heap;
    u8 *buf;
    int j;
    u32 tex;
    u32 pltt;
    u8 *src;
    u32 chrFile;
    u32 plttFile;
    void *h;
    u32 *a;
    int t1;
    int t2;
    int i;
    int k;

    heap = p->heap;
    p->canvas = func_02043678(16, 16, 32, heap);
    k = 0;
    h = func_02048A0C(p->f14, 0);
    t1 = func_02047388(h);
    t2 = func_020473B8(h);
    tex = (u16)t1 << 3;
    pltt = (u16)t2 << 3;
    a = p->args;
    chrFile = func_0202D064(func_0202D060(), a[0], a[1], a[2], a[3], 0, a[4]);
    plttFile = func_0202D0D4(func_0202D060(), a[0], a[1], a[2], a[3], 0, a[4]);
    p->chr = 0;
    p->pltt = 0;
    p->chrRes = func_02049E34(func_0202D060(), chrFile, 1, &p->chr, heap);
    p->plttRes = func_02049F34(func_0202D060(), plttFile, &p->pltt, heap);
    src = p->chr->raw;
    buf = func_020437D4(p->canvas);
    func_02082A7C(0, buf, 0x2000);
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
    func_02044F64(p->canvas, 0, heap);
    func_02061CA4(0, tex, func_020437D4(p->canvas), 0x2000);
    func_02061CA4(1, pltt, p->pltt->raw, 0x20);
    func_02030830(p->heap);
}
