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
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   MATH_CalcHMACSHA1  0x020816FC  arm
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

extern void MI_CpuFill8(void *, int, u32);
extern void MI_CpuCopy8(u32, void *, u32);
extern u32  OS_IsRunOnTwl(void);
extern void func_0209125C(u32 a, u32 b, u32 c, u32 d, u32 e);
extern u32  func_0208139C(u32);
extern void MATH_CalcHMACSHA1(void *digest, const void *bin_ptr, u32 bin_len, const void *key_ptr, u32 key_len);

int func_02078F30(u8 *a0, u32 a1, u32 a2, int a3)
{
    u8 buf[0x14];
    u8 tmp[0x40];
    u32 handle;
    u32 v;
    u32 i;

    MI_CpuFill8(buf, 0, 0x14);
    MI_CpuCopy8(g_02150D20.f18, tmp, g_02150D20.f1c);

    if (a3 == 0 && OS_IsRunOnTwl() != 0) {
        v = g_02150D20.f1c;
        func_0209125C((u32)buf, a1, a2, (u32)tmp, v);
    } else {
        handle = 0;
        if (a3 != 0) {
            handle = func_0208139C(1);
        }
        v = g_02150D20.f1c;
        MATH_CalcHMACSHA1(buf, (const void *)a1, a2, tmp, v);
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