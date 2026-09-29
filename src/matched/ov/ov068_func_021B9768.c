/*
 * function: func_021B9768
 * address:  0x021B9768
 * packet:   pkt_ov068_021B9768
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BADFC  0x021BADFC  thumb
 *   func_021BA254  0x021BA254  thumb
 *   func_021BA030  0x021BA030  thumb
 *   func_021BA7B4  0x021BA7B4  thumb
 *   func_021BA410  0x021BA410  thumb
 *   func_021BB114  0x021BB114  thumb
 *   func_021BAF9C  0x021BAF9C  thumb
 *   func_021B98E0  0x021B98E0  thumb
 *   func_02031140  0x02031140  arm
 *   func_02045C04  0x02045C04  arm
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_02027FD8  0x02027FD8  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_0201D83C  0x0201D83C  thumb
 *   ov067_id       0x00000043  data
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_021BADFC(void *p);
extern void func_021BA254(void *p);
extern void func_021BA030(void *p);
extern void func_021BA7B4(void *p);
extern void func_021BA410(void *p);
extern void func_021BB114(void *p);
extern void func_021BAF9C(void *p);
extern void func_021B98E0(void *p);
extern void func_02031140(void *p);
extern void func_02045C04(void *p);
extern void func_020315D4(void *p);
extern void func_020306F0(int a);
extern void func_02034A5C(int a);
extern void func_02027FD8(void *p);
extern void func_0201C4C0(void *p);
extern void func_0201D83C(void *p);
extern u8 ov067_id[];

int func_021B9768(void *a, u32 b, u32 c, u8 *w)
{
    func_021BADFC(w + 0x1d8);
    func_021BA254(w + 0x1a0);
    func_021BA030(w + 0xe4);
    func_021BA7B4(w + 0x148);
    func_021BA410(w + 0x104);
    func_021BB114(w + 0xd4);
    func_021BAF9C(w + 0x248);
    func_02031140(*(void **)(w + 0x268));
    func_02045C04(*(void **)(w + 0x25c));
    func_02027FD8(*(void **)(w + 0x264));
    func_02027FD8(*(void **)(w + 0x260));
    func_0201C4C0(*(void **)(w + 0x258));
    func_0201D83C(*(void **)(w + 0x254));
    func_021B98E0(w);
    func_020315D4(a);
    func_020306F0(0x1c);
    func_02034A5C((int)ov067_id);
    return 1;
}
