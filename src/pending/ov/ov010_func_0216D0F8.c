/*
 * function: func_0216D0F8
 * address:  0x0216D0F8
 * packet:   pkt_ov010_0216D0F8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * DIFF, 13 concrete bytes, 208/208 bytes, all 12 relocations resolved.
 * checks: 1 current E544 body takes2 and returnsint (unused here), setters
 * take2 with observed signed-halfword caller truncations, D89C copies3words;
 * 2 current matched-family search no scheduling twin; 3 raw address and
 * enum-typed source z retain13/208; 4 const/inline argument idioms reread;
 * 5 directory/neighbours refreshed, actual VecFx32 local has correct offsets.
 * The const entry parameter restores the +46 and +A4 store/argument swaps.
 * Remaining +66..72: image loads p->z into r0 and moves obj to r0 last;
 * C moves obj first and loads p->z into r1. Types/struct storage, signed
 * fields, long z, an inline argument helper and enum locals were tested.
 * An inline helper combined with const remains 13. Eight fixed one runs.
 * Prior permuter 300 anneal + 300 random --types was already consumed;
 * its volatile/temp result was invalid. No repeat was run in this pass.
 * Own callee bodies and caller truncations justify signed-short externs.
 * No same-region matched twin fixes this last argument schedule.
 * wave76 final retry: numeric record-address local, named z extraction and
 * enum-typed source z each retain13/208. Three fixed one runs; renewed
 * manual pass exhausted. Historical anneal/random searches never repeated.
 *
 * recoup 2026-10-05 (lane Z9, no source existed in src/): DIFF 13 B of 208 (+66..72).
 * Twin search: grep -l func_0216D7F4 / func_0216E544 / func_0216D800 src/matched/ov
 * hit only their own definitions; func_0216D844/D85C/D874/D89C twin
 * ov010_func_0216E014 (s16 cast of (p[i]>>4)/4096) matches the expression only.
 * Callee types read from matched definitions: all setters are void, u16 param.
 * Residue: the image evaluates the D7F4 argument chain in r0 and copies obj to
 * r0 last (obj not live in r0 across the chain); ours holds obj in r0 first and
 * runs the chain in r1. The matching z reload from [sp] (call 0x7A) has the
 * image shape, only the member load p->z differs.
 * Idioms checked (read in full): a-const-source-pointer-pulls-field-loads-up-next-to-the-call-result
 * (const already kept, 13 B), a-const-parameter-hoists-field-loads-above-a-call-result-store
 * (n/a, 13 B), a-const-record-pointer-moves-the-outgoing-stack-store-below-the-register-copies
 * (n/a, 13 B), a-const-source-pointer-hoists-the-last-load-of-a-struct-copy (n/a, 13 B),
 * a-call-that-sets-no-arguments-takes-the-loaded-locals-in-place (n/a, 13 B).
 * Tried: (s16) cast at call 13; block-local fx32 t / s32 t / s16 w 13; x reused 13;
 * split t = p->z >> 4 13; static inline getz() 13; const Src * const 13; __restrict 13;
 * obj as int in every prototype 13; six per-function pragmas (lifetimes 31, rest 13);
 * p->z / 16 / 4096 107; s16 fields 192.
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
    func_0216D7F4(obj, (p->z >> 4) / 4096);
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
