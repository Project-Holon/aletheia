/*
 * function: func_021C2BE4
 * address:  0x021C2BE4
 * packet:   pkt_ov021_021C2BE4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02048A0C  0x02048A0C  arm
 *   func_02047388  0x02047388  arm
 *   func_020473B8  0x020473B8  arm
 *   func_02046F48  0x02046F48  arm
 *   func_0206E964  0x0206E964  arm
 *   func_021C2EDC  0x021C2EDC  thumb  ov021
 *   func_021C2F14  0x021C2F14  thumb  ov021
 *   func_02049DB4  0x02049DB4  arm
 *   func_02049F34  0x02049F34  arm
 *   func_020437D4  0x020437D4  arm
 *   func_02082A7C  0x02082A7C  arm
 *   func_02082A90  0x02082A90  arm
 *   func_02044F64  0x02044F64  arm
 *   func_02061CA4  0x02061CA4  arm
 *   func_02030830  0x02030830  arm
 * Sibling of func_021C2918 (same object layout at +0x88..+0x98), 16x16
 * tile copy with archive 0xB4 and file ids passed in.
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
} Obj;

extern void *func_02048A0C(void *p, int i);
extern int func_02047388(void *p);
extern int func_020473B8(void *p);
extern void *func_02046F48(void *p);
extern void *func_0206E964(void *p);
extern u32 func_021C2EDC(void *tex, u32 a);
extern u32 func_021C2F14(void *tex, u32 a);
extern void *func_02049DB4(u32 arc, u32 file, u32 comp, CharData **out, u16 heap);
extern void *func_02049F34(u32 arc, u32 file, PlttData **out, u16 heap);
extern u8 *func_020437D4(void *canvas);
extern void func_02082A7C(u32 fill, void *dst, u32 size);
extern void func_02082A90(const void *src, void *dst, u32 size);
extern void func_02044F64(void *canvas, u32 v, u16 heap);
extern void func_02061CA4(int type, u32 addr, void *data, u32 size);
extern void func_02030830(u16 heap);

void func_021C2BE4(Obj *p, u32 a1, u32 a2, u32 chrFile, u32 plttFile)
{
    u32 tex;
    u32 pltt;
    u16 heap;
    u8 *buf;
    int j;
    void *h;
    void *t;
    u8 *src;
    int i;
    int k;

    heap = p->heap;
    k = 0;
    h = func_02048A0C(p->f14, 0);
    func_02047388(h);
    func_020473B8(h);
    t = func_0206E964(func_02046F48(h));
    tex = func_021C2EDC(t, a1);
    pltt = func_021C2F14(t, a2);
    p->chr = 0;
    p->pltt = 0;
    p->chrRes = func_02049DB4(0xb4, chrFile, 1, &p->chr, heap);
    p->plttRes = func_02049F34(0xb4, plttFile, &p->pltt, heap);
    src = p->chr->raw;
    buf = func_020437D4(p->canvas);
    func_02082A7C(0, buf, 0x2000);
    for (j = 0; j < 16; j++) {
        for (i = 0; i < 16; i++) {
            func_02082A90(src + k * 32, buf + (i + j * 16) * 32, 32);
            k++;
        }
    }
    func_02044F64(p->canvas, 0, heap);
    func_02061CA4(0, tex, func_020437D4(p->canvas), 0x2000);
    func_02061CA4(1, pltt, p->pltt->raw, 0x20);
    func_02030830(p->heap);
}
