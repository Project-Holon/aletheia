/*
 * function: func_02078F30
 * address:  0x02078F30
 * packet:   pkt_02078F30
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02150D20  0x02150D20  data
 *   func_0209125C  0x0209125C  thumb
 *
 * DRAFT: compiles the whole 252-byte range; verdict pending.
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct S78F30 {
    u8  pad00[0x18];
    u32 f18;
    u32 f1c;
};

extern struct S78F30 g_02150D20;

extern void func_02082BCC(void *, int, u32);
extern void func_02082D44(u32, void *, u32);
extern u32  func_02085D3C(void);
extern void func_0209125C(void *, u32, u32, void *, u32);
extern u32  func_0208139C(u32);
extern void func_020816FC(void *, u32, u32, void *, u32);

int func_02078F30(u8 *a0, u32 a1, u32 a2, int a3)
{
    u8 buf[0x14];
    u8 tmp[0x40];
    u32 handle;
    u32 v;
    u32 i;

    func_02082BCC(buf, 0, 0x14);
    func_02082D44(g_02150D20.f18, tmp, g_02150D20.f1c);

    if (a3 == 0 && func_02085D3C() != 0) {
        v = g_02150D20.f1c;
        func_0209125C(buf, a1, a2, tmp, v);
    } else {
        handle = 0;
        if (a3 != 0) {
            handle = func_0208139C(1);
        }
        v = g_02150D20.f1c;
        func_020816FC(buf, a1, a2, tmp, v);
        if (a3 != 0) {
            func_0208139C(handle);
        }
    }

    i = 0;
    while (i < 0x14) {
        if (*(u32 *)(buf + i) != *(u32 *)(a0 + i)) {
            break;
        }
        i += 4;
    }
    return i == 0x14;
}