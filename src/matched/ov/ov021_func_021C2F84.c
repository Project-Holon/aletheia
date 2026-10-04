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

struct StrObj;
struct TexKey;
struct WordSet;
extern u32 func_02048A0C(u8 *a0, int i);
struct GfFont;
struct MsgBank;
struct Rec;
struct U16Vec;
struct WordSet;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_0201EC64(u16 heap);
extern void *func_020457B0(u32 size, u16 heap);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201ED04(struct WordSet *p);
extern void func_0201F4A0(void *dst, void *src);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_0201D83C(void *p);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern int func_0216FAB4(void *file, const char *texName, void *extra, const char *plttName, u32 a4, u16 a5, u16 a6, u16 a7, u16 heap, struct TexKey *out);
extern void func_020307B0(void *p);
extern void func_02045C04(struct Rec *rec);

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

    h = (void *)func_02048A0C(p->f14, 0);
    heap = p->heap;
    m = func_02045B38(0, 2, 0xb0, heap);
    if (c == 0) {
        x = func_0201EC64((heap & 0x7FFF) | 0x8000);
        str = func_020457B0(8, (heap & 0x7FFF) | 0x8000);
        y = func_02045EC0(m, c);
        func_0201F02C(x, 0, (void *)s);
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
        w = func_0201D304(str, (u32)z, 0);
        func_0201D83C(z);
        w = 0x3c - w;
        if (w < 0)
            w = 0;
    }
    p->plttRes = func_02049F34(0x17, 5, (u32)(&p->pltt), heap);
    pl = p->pltt->raw;
    pl[1] = 0x7FFF;
    pl[2] = 0;
    func_0216FAB4(h, a1, pl, a2, (u32)str, w, 0, 0x440, heap, (struct TexKey *)buf);
    func_020307B0(p->plttRes);
    func_020307B0(str);
    func_02045C04(m);
}
