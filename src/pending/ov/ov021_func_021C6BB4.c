/*
 * function: func_021C6BB4
 * address:  0x021C6BB4
 * packet:   pkt_ov021_021C6BB4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Byte-correct; the single wildcarded site is _d2f (0x0209B64C, the
 * double-to-float runtime helper): no func_ label there (its prologue saves
 * nothing), no row in layout/runtime_arm9.txt, so no witness outside the
 * range under test. Blocker: evidence class runtime (needs a
 * layout/runtime_arm9.txt row for 0x0209B64C _d2f) - integrator's file.
 * Lever: `t = 1.0f; t *= a / b;` keeps the fmul by 1.0f; a plain `1.0f * x`
 * or `x * 1.0f` folds away. The FX32 round (x > 0 ? x*4096+0.5 : x*4096-0.5)
 * must go through one float temp so the _ffix and the call are shared.
 *
 * symbols:
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218ED58  0x0218ED58  thumb  ov021
 *   _ffltu         0x0209BE04  arm
 *   _fdiv          0x0209CE10  arm
 *   _fmul          0x0209C77C  arm
 *   _fsub          0x0209CB8C  arm
 *   _fadd          0x0209C95C  arm
 *   _ffix          0x0209C494  arm
 *   _fflt          0x0209BDBC  arm
 *   _f2d           0x0209BD38  arm
 *   _d2f           0x0209B64C  arm
 *   _dsqrt         0x0209C5E0  arm
 *   _fgr           0x0209BBB0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_02188C58(u32 a);
extern void func_0218ED58(u32 a, int v);
extern double _dsqrt(double x);

void func_021C6BB4(u8 *p)
{
    u32 h = func_02188C58(*(u32 *)p);
    u32 n = *(u16 *)(p + 6);
    float t, a, b, v;

    if (*(u16 *)(p + 4) <= n) {
        t = 1.0f;
        t *= (float)(u32)*(u16 *)(p + 4) / (float)n;
        t = (float)_dsqrt((double)t);
        a = (float)*(int *)(p + 8) / 4096.0f;
        b = (float)*(int *)(p + 12) / 4096.0f;
        v = (1.0f - t) * a + t * b;
        if (v > 0.0f)
            v = 4096.0f * v + 0.5f;
        else
            v = 4096.0f * v - 0.5f;
        func_0218ED58(h, (int)v);
    }
}
