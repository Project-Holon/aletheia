/*
 * function: func_021C2F84
 * address:  0x021C2F84
 * packet:   pkt_ov021_021C2F84
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02048A0C  0x02048A0C  arm
 *   func_02045B38  0x02045B38  arm
 *   func_0201EC64  0x0201EC64  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02045808  0x02045808  arm
 *   func_0201ED04  0x0201ED04  thumb
 *   func_0201F4A0  0x0201F4A0  thumb
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0201D304  0x0201D304  thumb
 *   func_0201D83C  0x0201D83C  thumb
 *   func_02049F34  0x02049F34  arm
 *   func_0216FAB4  0x0216FAB4  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 *   func_02045C04  0x02045C04  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct PlttData {
    u8 pad00[0xc];
    u16 *raw;
} PlttData;

typedef struct Obj {
    u8 pad00[0x10];
    u16 heap;
    u16 pad12;
    void *f14;
    u8 pad18[0x8c - 0x18];
    PlttData *pltt;
    void *canvas;
    void *chrRes;
    void *plttRes;
} Obj;

extern void *func_02048A0C(void *p, int i);
extern void *func_02045B38(u32 a, u32 b, u32 c, u32 heap);
extern void *func_0201EC64(u16 heap);
extern void *func_020457B0(u32 size, u16 heap);
extern void *func_02045EC0(void *bank, u32 index);
extern void func_0201F02C(void *a, u32 b, int c);
extern void func_0201F250(void *a, void *b, void *c);
extern void func_02045808(void *p);
extern void func_0201ED04(void *p);
extern void func_0201F4A0(void *dst, void *src);
extern void *func_0201D7EC(u32 a, u32 b, u32 c, u32 d, u32 heap);
extern int func_0201D304(void *a, void *b, u32 c);
extern void func_0201D83C(void *p);
extern void *func_02049F34(u32 arc, u32 file, PlttData **out, u16 heap);
extern void func_0216FAB4(void *h, char *a1, u16 *pl, char *a2, void *str, u16 w, u32 c, u32 d, u16 heap, void *out);
extern void func_020307B0(void *p);
extern void func_02045C04(void *p);

void func_021C2F84(int s, Obj *p, char *a1, char *a2, u32 c, u32 d)
{
    u8 buf[0x14];
    void *x;
    void *z;
    void *y;
    void *m;
    void *h;
    u16 heap;
    void *str;
    int w;
    u16 *pl;

    h = func_02048A0C(p->f14, 0);
    heap = p->heap;
    m = func_02045B38(0, 2, 0xb0, heap);
    if (c == 0) {
        x = func_0201EC64((heap & 0x7FFF) | 0x8000);
        str = func_020457B0(8, (heap & 0x7FFF) | 0x8000);
        y = func_02045EC0(m, c);
        func_0201F02C(x, 0, s);
        func_0201F250(x, str, y);
        func_02045808(y);
        func_0201ED04(x);
    } else {
        y = func_02045EC0(m, c);
        str = func_020457B0(0x10, (heap & 0x7FFF) | 0x8000);
        func_0201F4A0(str, y);
        func_02045808(y);
    }
    w = 0;
    if (d != 0) {
        z = func_0201D7EC(0x17, 0, 0, 0, heap);
        w = func_0201D304(str, z, 0);
        func_0201D83C(z);
        w = 0x3c - w;
        if (w < 0)
            w = 0;
    }
    p->plttRes = func_02049F34(0x17, 5, &p->pltt, heap);
    pl = p->pltt->raw;
    pl[1] = 0x7FFF;
    pl[2] = 0;
    func_0216FAB4(h, a1, pl, a2, str, w, 0, 0x440, heap, buf);
    func_020307B0(p->plttRes);
    func_020307B0(str);
    func_02045C04(m);
}
