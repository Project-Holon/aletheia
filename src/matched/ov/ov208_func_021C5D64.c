/*
 * function: ov208_func_021C5D64
 * address:  0x021C5D64
 * packet:   pkt_ov208_021C5D64
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BC3B4  0x021BC3B4  thumb
 *   ov208_func_021C6760  0x021C6760  thumb
 *   ov208_func_021C526C  0x021C526C  thumb
 *   ov208_func_021C5B00  0x021C5B00  thumb
 *   ov208_func_021C51D4  0x021C51D4  thumb
 *   ov208_func_021C7448  0x021C7448  thumb
 *   ov208_func_021C5F34  0x021C5F34  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_02035D20  0x02035D20  arm
 *   ov208_func_021C7CE8  0x021C7CE8  thumb
 *   ov208_func_021C7534  0x021C7534  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_020355D8  0x020355D8  arm
 *   ov208_func_021BDC48  0x021BDC48  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ov208Mdl {
    u32 obj;
    u32 f4;
    u8  pos[0x3c];
};

extern int func_021BC3B4(int *p);
extern u32  ov208_func_021C6760(u16 *heap, u8 *p, int key);
extern void ov208_func_021C526C(u16 *heap, u8 *p, int key);
extern void ov208_func_021C5B00(u16 *heap, u8 *p, int key);
extern void ov208_func_021C51D4(struct Ov208Mdl *m);
extern void ov208_func_021C7448(u16 *heap, u8 *p, int key);
extern void ov208_func_021C5F34(u16 *heap, u8 *p, int key, int ev);
extern u32  func_020362DC(void);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern void ov208_func_021C7CE8(u16 *heap, u8 *p, int key);
extern void ov208_func_021C7534(u16 *heap, u8 *p, int key);
extern void func_020061E4(u32 se);
extern void func_020355D8(int v);
extern void ov208_func_021BDC48(void *scene, u32 on);

#define W(o) (*(u32 *)(p + (o)))
#define H(o) (*(u16 *)(p + (o)))
#define MDL(i) ((struct Ov208Mdl *)(p + 0xc) + (i))

void ov208_func_021C5D64(u16 *heap, u8 *p, int key)
{
    u32 x;
    u32 y;
    void *scene;
    int touch;
    int ok;
    u32 r;
    u8 i;

    scene = (void *)func_021BC3B4((int *)key);
    switch (W(0x6b8)) {
    case 0:
        if (W(0x6b4) == 0)
            break;
        r = ov208_func_021C6760(heap, p, key);
        if (r != 5) {
            switch (r) {
            case 0:
                ov208_func_021C526C(heap, p, key);
                return;
            case 1:
                ov208_func_021C5B00(heap, p, key);
                for (i = 0; i < 4; i++)
                    ov208_func_021C51D4(MDL(i));
                return;
            case 2:
                W(0x6c8) = 1;
                ov208_func_021C7448(heap, p, key);
                ov208_func_021C5F34(heap, p, key, 1);
                return;
            case 3:
                W(0x6c8) = 0;
                ov208_func_021C7448(heap, p, key);
                ov208_func_021C5F34(heap, p, key, 1);
                return;
            }
        } else {
            ok = 0;
            if (func_020362DC() & 1) {
                ok = 1;
                touch = 0;
            } else if (func_02035D20(&x, &y) != 0 && y < 0xa8) {
                ok = 1;
                touch = 1;
            }
            if (ok != 0 && H(0x548) >= 2) {
                if ((W(0x124) != 0 && MDL(2)->obj == 0) || (W(0x124) == 0 && MDL(3)->obj == 0)) {
                    ov208_func_021C7CE8(heap, p, key);
                    W(0x6c8) = 1;
                    ov208_func_021C7534(heap, p, key);
                }
                ov208_func_021C5F34(heap, p, key, 2);
                func_020061E4(0x54c);
                func_020355D8(touch);
                ov208_func_021BDC48(scene, 0);
                return;
            }
        }
        break;
    case 4:
        if (W(0x6b4) == 0 || W(0x69c) != 0)
            break;
        r = ov208_func_021C6760(heap, p, key);
        if (r != 5) {
            switch (r) {
            case 0:
                ov208_func_021C526C(heap, p, key);
                return;
            case 1:
                ov208_func_021C5B00(heap, p, key);
                for (i = 0; i < 4; i++)
                    ov208_func_021C51D4(MDL(i));
                break;
            default:
                return;
            }
        }
        break;
    }
}
