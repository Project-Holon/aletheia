/*
 * function: func_021B6934
 * address:  0x021B6934
 * packet:   pkt_ov070_021B6934
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B68E8  0x021B68E8  thumb  ov070
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200D418  0x0200D418  thumb
 *   func_0200D58C  0x0200D58C  thumb
 *   func_02020FE4  0x02020FE4  thumb
 *   func_0200D55C  0x0200D55C  thumb
 *   func_021B7D20  0x021B7D20  thumb  ov070
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F02C  0x0201F02C  thumb
 *   func_021B61F4  0x021B61F4  thumb  ov070
 *   func_0201F250  0x0201F250  thumb
 *   func_021BACF0  0x021BACF0  thumb  ov070
 *   func_020061E4  0x020061E4  thumb
 *   func_021B6100  0x021B6100  thumb  ov070
 *   func_021B6A14  0x021B6A14  thumb  ov070
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int   func_021B68E8(u16 id);
extern void *func_02012EBC(void *sys);
extern void *func_0200D418(void *sys);
extern u32   func_0200D58C(void *blk);
extern u32   func_02020FE4(u16 a, u32 sel, u32 id);
extern void  func_0200D55C(void *blk, u8 v);
extern void  func_021B7D20(void *o, int x);
extern void  func_02045CAC(u32 a0, u32 a1, u32 a2);
extern void  func_0201F02C(u32 a0, u32 a1, u32 a2);
extern void  func_021B61F4(void *o, int a, u32 b);
extern void  func_0201F250(u32 a0, u32 a1, u32 a2);
extern void  func_021BACF0(void *o, int v);
extern void  func_020061E4(u32 se);
extern void  func_021B6100(void *obj, void *fn);
extern void  func_021B6A14(u8 *p);

void func_021B6934(u8 *p)
{
    void *blk;
    u8 v;

    if (func_021B68E8(*(u32 *)(p + 0x84C))) {
        blk = func_0200D418(func_02012EBC(*(void **)p));
        if (func_0200D58C(blk)) {
            v = func_02020FE4(*(u32 *)(p + 0x84C), 2, *(u16 *)(p + 0x544));
            func_0200D55C(blk, v);
            func_021B7D20(p, 1);
            func_02045CAC(*(u32 *)(p + 0x51C), 0x3F, *(u32 *)(p + 0x524));
            func_0201F02C(*(u32 *)(p + 0x520), 0, *(u32 *)(p + 8));
            func_021B61F4(p, 1, *(u32 *)(p + 0x84C));
            func_0201F250(*(u32 *)(p + 0x520), *(u32 *)(p + 0x528), *(u32 *)(p + 0x524));
            func_021BACF0(p, 1);
            func_020061E4(0x7CD);
        } else {
            func_02045CAC(*(u32 *)(p + 0x51C), 0x40, *(u32 *)(p + 0x524));
            func_0201F250(*(u32 *)(p + 0x520), *(u32 *)(p + 0x528), *(u32 *)(p + 0x524));
            func_021BACF0(p, 1);
        }
        func_021B6100(p, (void *)func_021B6A14);
    }
}
