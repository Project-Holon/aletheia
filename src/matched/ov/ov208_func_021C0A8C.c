/*
 * function: ov208_func_021C0A8C
 * address:  0x021C0A8C
 * packet:   pkt_ov208_021C0A8C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ov208_func_021BC3B4  0x021BC3B4  thumb  ov208
 *   func_0204B98C  0x0204B98C  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B92C  0x0204B92C  arm
 *   ov208_func_021BDC48  0x021BDC48  thumb  ov208
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;
typedef int            s32;

extern void *ov208_func_021BC3B4(int key);
extern int  func_0204B98C(u32 obj);
extern void func_0204B878(u32 obj, u32 anim);
struct Obj;
extern void func_0204B92C(struct Obj *obj, u32 v);
extern void ov208_func_021BDC48(void *s, u32 on);

#define OBJ(i) (((u32 *)(p + 0xbc))[i])

void ov208_func_021C0A8C(u16 *heap, u8 *p, int key)
{
    void *scene;
    u8 sel;
    u32 anim;
    u32 next;
    u32 nextAnim;

    scene = ov208_func_021BC3B4(key);
    sel = p[0xd8];
    if (sel == 2) {
        anim = 2;
        next = 1;
        nextAnim = 4;
    } else if (sel == 1) {
        anim = 4;
        next = 2;
        nextAnim = 2;
    }
    if (sel != 7 && func_0204B98C(OBJ(sel)) == 0) {
        func_0204B878(OBJ(p[0xd8]), anim);
        func_0204B92C((struct Obj *)OBJ(next), 1);
        func_0204B878(OBJ(next), nextAnim);
        p[0xd8] = 7;
        if (*(u32 *)(p + 0x6c) == 0 || *(u32 *)(p + 0x6c) == 5)
            ov208_func_021BDC48(scene, 1);
    }
}
