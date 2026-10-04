/*
 * function: func_021DFC68
 * address:  0x021DFC68
 * packet:   pkt_ov119_021DFC68
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 2026-10-02 lane R1: the register shift (r2/r3 instead of r1/r2) was the incoming r1 kept
 * live: the function takes a second argument and forwards it to func_021DFC28 (p, a1), whose
 * matched definition reads r1. Callers in ov118 pass two arguments.
 *
 * symbols:
 *   func_02015C30    0x02015C30  thumb
 *   func_02015C48    0x02015C48  thumb
 *   func_021DFC28    0x021DFC28  thumb  ov119
 *   func_021DFBF0    0x021DFBF0  thumb  ov119
 *   _s32_to_float    0x0209BDBC  arm
 *   __fdiv           0x0209CE10  arm
 *   __fmul           0x0209C77C  arm
 *   _fmul            0x0209C77C  arm
 *   _f2s             0x0209C494  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef int s32;

extern void func_02015C30(void *p, u32 *out);
extern void func_02015C48(void *p, u32 *src);
extern void func_021DFC28(void *, int);
extern u32 func_021DFBF0(u32, u32, void *, int);
extern float _s32_to_float(s32);
extern float __fdiv(float, float);
extern float __fmul(float, float);
extern s32 _f2s(float);

void func_021DFC68(void *p, int a1)
{
    u32 vec[6];
    s32 k, next, m;

    if (p == 0)
        return;
    k = *(s32 *)((char *)p + 8);
    next = k + 1;
    m = *(s32 *)((char *)p + 4);
    *(s32 *)((char *)p + 8) = next;
    if (m < next)
        return;
    if (m != next) {
        if (*(u32 *)((char *)p + 0x34) != 0) {
            func_021DFC28(p, a1);
            return;
        }
        func_02015C30((void *)(*(u32 *)p), &vec[0]);
        vec[3] = func_021DFBF0(*(u32 *)((char *)p + 0x1c), *(u32 *)((char *)p + 0x28), p, 0);
        if (*(u16 *)((char *)p + 0x16) != 0) {
            float q = 374.0f * __fdiv(_s32_to_float((s32)(vec[0] - vec[3])), 4096.0f);
            *(u16 *)((char *)p + 0x14) -= (u16)_f2s(q);
        }
        vec[4] = func_021DFBF0(*(u32 *)((char *)p + 0x20), *(u32 *)((char *)p + 0x2c), p, 1);
        vec[5] = func_021DFBF0(*(u32 *)((char *)p + 0x24), *(u32 *)((char *)p + 0x30), p, 0);
        func_02015C48((void *)(*(u32 *)p), &vec[3]);
        return;
    }
    func_02015C48((void *)(*(u32 *)p), (u32 *)((char *)p + 0x28));
}
