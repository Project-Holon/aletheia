/*
 * function: func_0216D0F8
 * address:  0x0216D0F8
 * packet:   pkt_ov010_0216D0F8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * final push 2026-10-05 G4L4: EXACT in c99 and c. The last argument of func_0216D7F4 is
 * a named int local (t) set from the field just before the call, with
 * #pragma opt_propagation off around the function. With propagation on the local is folded
 * into the call and the object copy is born before the argument chain (chain in r1, 13 B);
 * with it off the chain is born first and takes r0, as in the image. s16 local with the
 * pragma gave 9 B; int local without the pragma gave 13 B.
 *
 * symbols:
 *   func_0216E51C  0x0216E51C  thumb  ov010
 *   func_0216E544  0x0216E544  thumb  ov010
 *   func_0216D7F0  0x0216D7F0  thumb  ov010
 *   func_0216D7F4  0x0216D7F4  thumb  ov010
 *   func_0216D800  0x0216D800  thumb  ov010
 *   func_0216D80C  0x0216D80C  thumb  ov010
 *   func_0216D818  0x0216D818  thumb  ov010
 *   func_0216D824  0x0216D824  thumb  ov010
 *   func_0216D844  0x0216D844  thumb  ov010
 *   func_0216D85C  0x0216D85C  thumb  ov010
 *   func_0216D874  0x0216D874  thumb  ov010
 *   func_0216D89C  0x0216D89C  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef int            s32;
typedef s32            fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct Src {
    u16  x;
    u16  y;
    fx32 z;
} Src;

extern int  func_0216E51C(void *obj);
extern void func_0216E544(void *obj, VecFx32 *out);
extern void func_0216D7F0(void *obj, s16 v);
extern void func_0216D7F4(void *obj, s16 v);
extern void func_0216D800(void *obj, s16 v);
extern void func_0216D80C(void *obj, s16 v);
extern void func_0216D818(void *obj, s16 v);
extern void func_0216D824(void *obj, s16 v);
extern void func_0216D844(void *obj, s16 v);
extern void func_0216D85C(void *obj, s16 v);
extern void func_0216D874(void *obj, s16 v);
extern void func_0216D89C(void *obj, const VecFx32 *v);

#pragma opt_propagation off
void func_0216D0F8(void *obj, const u8 *a1)
{
    const Src *p = (const Src *)(a1 + 0x1c);
    VecFx32 v;
    s32 x;
    s32 y;
    fx32 z;

    if (func_0216E51C(obj) == 0) {
        x = p->x;
        y = p->y;
        z = p->z;
    } else {
        func_0216E544(obj, &v);
        x = (v.x >> 4) / 4096;
        y = (v.z >> 4) / 4096;
        z = v.y;
    }
    v.x = (x << 16) + 0x8000;
    func_0216D7F0(obj, p->x);
    func_0216D80C(obj, x);
    func_0216D844(obj, x);
    {
        int t = (p->z >> 4) / 4096;
        func_0216D7F4(obj, t);
    }
    v.y = z;
    x = (z >> 4) / 4096;
    func_0216D818(obj, x);
    func_0216D85C(obj, x);
    v.z = (y << 16) + 0x8000;
    func_0216D800(obj, p->y);
    func_0216D824(obj, y);
    func_0216D874(obj, y);
    func_0216D89C(obj, &v);
}
#pragma opt_propagation reset
