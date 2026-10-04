/*
 * function: func_021B9858
 * address:  0x021B9858
 * packet:   pkt_ov072_021B9858
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030EAC  0x02030EAC  arm
 *   func_021BB5E0  0x021BB5E0  thumb  ov072
 *   func_021BB204  0x021BB204  thumb  ov072
 *   func_021BAF9C  0x021BAF9C  thumb  ov072
 *   func_021BA570  0x021BA570  thumb  ov072
 *   func_021BA0D8  0x021BA0D8  thumb  ov072
 *   func_021BB534  0x021BB534  thumb  ov072
 *   func_021BB42C  0x021BB42C  thumb  ov072
 *   func_021B9F20  0x021B9F20  thumb  ov072
 *   func_021B9938  0x021B9938  thumb  ov072
 *   func_021BBB34  0x021BBB34  thumb  ov072
 *   func_021BB738  0x021BB738  thumb  ov072
 *   func_02045C04  0x02045C04  arm
 *   func_0201D83C  0x0201D83C  thumb
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   func_02034A5C  0x02034A5C  arm
 *   ov067_id       0x00000043  data
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef signed int     s32;
struct Node;
struct Rec;
struct S020315D4;
extern void func_02030EAC(struct Node *n);
extern void func_021BB5E0(void *a);
extern void func_021BB204(void *a);
extern void func_021BAF9C(void *a);
extern void func_021BA570(void *a);
extern void func_021BA0D8(void *a);
extern void func_021BB534(void *a);
extern void func_021BB42C(void *a);
extern void func_021B9F20(void *a);
extern void func_021B9938(void *a);
extern void func_021BBB34(void *a);
extern void func_021BB738(u32 *p);
extern void func_02045C04(struct Rec *rec);
extern void func_0201D83C(void *a);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(u32 heap);
extern void func_02034A5C(s32 handle);
extern char ov067_id[];

int func_021B9858(void *a, int b, int c, u8 *o)
{
    func_02030EAC(*(void **)(o + 0x13c));
    func_021BB5E0(o + 0xf4);
    func_021BB204(o + 0xb0);
    func_021BAF9C(o + 0x78);
    func_021BA570(o + 0x50);
    func_021BA0D8(o + 0x38);
    func_021BB534(o + 0xd4);
    if (**(int **)(o + 0x130) != 1) {
        func_021BB42C(o + 0xc4);
    }
    func_021B9F20(o + 0x14);
    func_021B9938(o + 4);
    func_021BBB34(*(void **)(o + 0x34));
    func_021BB738(*(void **)o);
    func_02045C04(*(void **)(o + 0x12c));
    func_02045C04(*(void **)(o + 0x128));
    func_0201D83C(*(void **)(o + 0x124));
    func_020315D4(a);
    func_020306F0(0x44);
    func_02034A5C((u32)ov067_id);
    return 1;
}
