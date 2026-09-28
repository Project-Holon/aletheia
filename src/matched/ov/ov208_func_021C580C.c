/*
 * function: ov208_func_021C580C
 * address:  0x021C580C
 * packet:   pkt_ov208_021C580C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C51A0  0x021C51A0  thumb
 *   func_021C51C8  0x021C51C8  thumb
 *   ov208_func_021C5664  0x021C5664  thumb
 *   ov208_func_021C569C  0x021C569C  thumb
 *   ov208_func_021C5CF0  0x021C5CF0  thumb
 *   ov208_func_021C4BB4  0x021C4BB4  thumb
 *   ov208_func_021C4F30  0x021C4F30  thumb
 *   ov208_func_021C4E54  0x021C4E54  thumb
 *   ov208_func_021C4EAC  0x021C4EAC  thumb
 *   ov208_func_021C6A10  0x021C6A10  thumb
 *   ov208_func_021C6AFC  0x021C6AFC  thumb
 *   ov208_func_021C68D4  0x021C68D4  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ov208Mdl {
    u32 obj;
    u32 f4;
    u8  pos[0x3c];
};

extern void func_021C51A0(struct Ov208Mdl *m, u32 sys);
extern void func_021C51C8(u32 obj, int side, u8 *p);
extern void ov208_func_021C5664(u16 *heap, u8 *p, int key);
extern void ov208_func_021C569C(u16 *heap, u8 *p, int key, int a, int b, int pose, u16 idx);
extern void ov208_func_021C5CF0(u16 *heap, u8 *p, int key);
extern void ov208_func_021C4BB4(u16 *heap, u8 *p, int key);
extern void ov208_func_021C4F30(u16 *heap, u8 *p, int key);
extern void ov208_func_021C4E54(u16 *heap, u8 *p, int key);
extern void ov208_func_021C4EAC(u16 *heap, u8 *p, int key);
extern void ov208_func_021C6A10(u16 *heap, u8 *p, int key);
extern void ov208_func_021C6AFC(u16 *heap, u8 *p, int key);
extern void ov208_func_021C68D4(u16 *heap, u8 *p, int key);

#define W(o) (*(u32 *)(p + (o)))
#define H(o) (*(u16 *)(p + (o)))
#define MDL(i) ((struct Ov208Mdl *)(p + 0xc) + (i))

void ov208_func_021C580C(u16 *heap, u8 *p, int key)
{
    u8 i;
    int a;
    int b;
    int pose;

    for (i = 0; i < 4; i++)
        func_021C51A0(MDL(i), W(8));
    ov208_func_021C5664(heap, p, key);
    pose = 0;
    if (W(0x6b8) == 4 && H(0x548) >= 2)
        pose = 1;
    a = W(0x124) != 0 ? 0 : 4;
    b = W(0x124) != 0 ? 4 : 1;
    ov208_func_021C569C(heap, p, key, a, b, pose, H(0x54e));
    if (a != 4)
        func_021C51C8(MDL(0)->f4, 0, p);
    if (b != 4)
        func_021C51C8(MDL(1)->f4, 1, p);
    if (W(0x6b8) == 4 && H(0x548) >= 2) {
        a = W(0x124) != 0 ? 2 : 4;
        b = W(0x124) != 0 ? 4 : 3;
        ov208_func_021C569C(heap, p, key, a, b, 2, H(0x550));
        if (a != 4)
            func_021C51C8(MDL(2)->f4, 2, p);
        if (b != 4)
            func_021C51C8(MDL(3)->f4, 3, p);
    }
    ov208_func_021C5CF0(heap, p, key);
    ov208_func_021C4BB4(heap, p, key);
    ov208_func_021C4F30(heap, p, key);
    ov208_func_021C4E54(heap, p, key);
    ov208_func_021C4EAC(heap, p, key);
    ov208_func_021C6A10(heap, p, key);
    ov208_func_021C6AFC(heap, p, key);
    ov208_func_021C68D4(heap, p, key);
}
