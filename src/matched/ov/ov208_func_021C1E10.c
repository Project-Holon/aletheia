/*
 * function: func_021C1E10
 * address:  0x021C1E10
 * packet:   pkt_ov208_021C1E10
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BC3B4  0x021BC3B4  thumb  ov208
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_021C1F50  0x021C1F50  thumb  ov208
 *   func_0204B878  0x0204B878  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B8C4  0x0204B8C4  arm
 *   func_021BDC48  0x021BDC48  thumb  ov208
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_021C0CCC  0x021C0CCC  thumb  ov208
 *   func_021C1D30  0x021C1D30  thumb  ov208
 *   func_021C1FC4  0x021C1FC4  thumb  ov208
 *   func_021C2238  0x021C2238  thumb  ov208
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 f0;
    u8 f1;
    u8 rest[0x3c];
} Entry;

extern void *func_021BC3B4(int key);
extern void func_0201C6EC(u32 a);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
struct CharBuf;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_021C1F50(u16 *heap, u8 *p, int key);
extern void func_0204B878(u32 obj, u32 anim);
struct Obj;
extern void func_0204B92C(struct Obj *obj, u32 v);
extern void func_0204B8C4(u32 obj, int v);
extern void func_021BDC48(void *s, u32 on);
extern void func_0204B3DC(u32 obj, int on);
extern void func_021C0CCC(u16 *heap, u8 *p, int key);
extern void func_021C1D30(u16 *heap, u8 *p, int key);
extern void func_021C1FC4(u16 *heap, u8 *p, int key);
extern void func_021C2238(u16 *heap, u8 *p, int key);

#define W(o) (*(u32 *)(p + (o)))
#define OBJ(i) (((u32 *)(p + 0xbc))[i])

void func_021C1E10(u16 *heap, u8 *p, int key, int dir, int touch)
{
    void *s;
    int other;
    u32 anim;

    s = func_021BC3B4(key);
    if (W(0x8c) == 0)
        W(0x90) = ((Entry *)W(0x94))[0].f1 == 0;
    else
        W(0x90) = ((Entry *)W(0x94))[p[0x78]].f1 == 0;
    W(0x2c) = 0;
    func_0201C6EC(W(0x3c));
    func_02043B5C(func_02045770((struct Descriptor *)W(0x1c)), 0);
    func_021C1F50(heap, p, key);
    if (dir) {
        p[0xd8] = 2;
        anim = 3;
        other = 1;
    } else {
        p[0xd8] = 1;
        anim = 5;
        other = 2;
    }
    func_0204B878(OBJ(p[0xd8]), anim);
    func_0204B92C((struct Obj *)OBJ(other), 0);
    func_0204B8C4(OBJ(other), 0);
    func_021BDC48(s, 0);
    if (touch == 1) {
        func_0204B3DC(W(0xcc), 0);
    } else if (W(0x6c) == 5 && W(0x90) == 1) {
        func_021C0CCC(heap, p, key);
        func_021C1D30(heap, p, key);
    }
    func_021C1FC4(heap, p, key);
    func_021C2238(heap, p, key);
}
