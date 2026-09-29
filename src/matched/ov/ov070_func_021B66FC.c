/*
 * function: func_021B66FC
 * address:  0x021B66FC
 * packet:   pkt_ov070_021B66FC
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202EA40  0x0202EA40  thumb
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_021B61B8  0x021B61B8  thumb  ov070
 *   func_021B63F8  0x021B63F8  thumb  ov070
 *   func_021B624C  0x021B624C  thumb  ov070
 *   func_021B6138  0x021B6138  thumb  ov070
 *   func_02035C38  0x02035C38  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_02007CC8  0x02007CC8  thumb
 *   func_0204B878  0x0204B878  arm
 *   func_021BB5DC  0x021BB5DC  thumb  ov070
 *   func_021B80C4  0x021B80C4  thumb  ov070
 *   func_021B8AF4  0x021B8AF4  thumb  ov070
 *   func_020362DC  0x020362DC  arm
 *   func_021B8C1C  0x021B8C1C  thumb  ov070
 *   func_021B66E8  0x021B66E8  thumb  ov070
 *   func_021B66B8  0x021B66B8  thumb  ov070
 *   func_021B65E8  0x021B65E8  thumb  ov070
 *   func_021BA6A4  0x021BA6A4  thumb  ov070
 *   func_021B64A0  0x021B64A0  thumb  ov070
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_0202EA40(u32 a);
extern int  func_0201C6B4(u32 a);
extern int  func_021B61B8(void *o);
extern u32  func_021B63F8(u8 *p);
extern void func_021B624C(void *o, int a, int b);
extern void func_021B6138(void *o);
extern int  func_02035C38(void);
extern void func_020061E4(u32 se);
extern void func_02007CC8(void *a, void *dst, u32 id, int dir);
extern void func_0204B878(u32 a, u32 b);
extern void func_021BB5DC(void *p, int mode);
extern void func_021B80C4(void *o, int v);
extern void func_021B8AF4(void *o);
extern u32  func_020362DC(void);
extern void func_021B8C1C(void *o, int a, void *fn);
extern void func_021B66E8(void);
extern int  func_021B66B8(void);
extern int  func_021B65E8(u8 *p);
extern void func_021BA6A4(void *o);
extern int  func_021B64A0(void *o);

void func_021B66FC(u8 *p)
{
    int a;

    func_0202EA40(*(u32 *)(p + 0x850));
    if (func_0201C6B4(*(u32 *)(p + 0x50C)) == 0)
        return;
    a = func_021B61B8(p);
    if (func_021B63F8(p)) {
        func_021B624C(p, a, func_021B61B8(p));
        *(u32 *)(p + 0x818) = 0xFFFF;
        func_021B6138(p);
        return;
    }
    if (func_02035C38() == 0) {
        *(u32 *)(p + 0x85C) = 0;
        if (*(u32 *)(p + 0x860) == 1) {
            func_020061E4(0x54C);
            *(u32 *)(p + 0x860) = 0;
            func_02007CC8(*(void **)(p + 0x18), p + 0x20, *(u32 *)(p + 0x80C), 0);
            func_0204B878(*(u32 *)(p + 0x6A4), 1);
            func_021BB5DC(p, 1);
            *(u32 *)(p + 0x81C) = 0;
            func_021B80C4(p, 0);
            func_021B8AF4(p);
            return;
        }
    }
    if (*(u32 *)(p + 0x85C) == 1)
        return;
    if (func_020362DC() & 5) {
        func_020061E4(0x54C);
        func_02007CC8(*(void **)(p + 0x18), p + 0x20, *(u32 *)(p + 0x80C), 0);
        func_0204B878(*(u32 *)(p + 0x6A4), 1);
        func_021BB5DC(p, 1);
        *(u32 *)(p + 0x81C) = 0;
        func_021B80C4(p, 1);
        func_021B8AF4(p);
        return;
    }
    if (func_020362DC() & 2) {
        func_020061E4(0x551);
        func_0204B878(*(u32 *)(p + 0x6A4), 1);
        *(u32 *)(p + 0x81C) = 0;
        func_021B80C4(p, 1);
        *(u32 *)(p + 0x818) = 0xFFFF;
        func_021B6138(p);
        func_021B8C1C(p, 4, (void *)func_021B66E8);
        return;
    }
    if (func_021B66B8() == 1) {
        func_020061E4(0x551);
        func_0204B878(*(u32 *)(p + 0x6A4), 1);
        *(u32 *)(p + 0x81C) = 0;
        func_021B80C4(p, 0);
        *(u32 *)(p + 0x818) = 0xFFFF;
        func_021B6138(p);
        func_021B8C1C(p, 4, (void *)func_021B66E8);
        return;
    }
    if (func_021B65E8(p)) {
        *(u32 *)(p + 0x860) = 1;
        func_021BA6A4(p);
        func_020061E4(0x548);
        *(u32 *)(p + 0x818) = 0xFFFF;
        func_021B6138(p);
        return;
    }
    if (func_021B64A0(p)) {
        func_021BA6A4(p);
        func_020061E4(0x548);
        *(u32 *)(p + 0x818) = 0xFFFF;
        func_021B6138(p);
    }
}
