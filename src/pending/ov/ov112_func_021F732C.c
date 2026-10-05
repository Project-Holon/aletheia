/*
 * function: func_021F732C
 * address: 0x021F732C
 * packet: pkt_ov112_021F732C
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * 2026-10-05 (wave D6 lane 19): still DIFF, 36 bytes, r4/r6 swap (off vs t). Callees checked: 5450, 545C,
 *   4B24/4B30 read r0 (and pass r1/r2 through, but the image sets none); 4E6C is variadic (push {r0-r3}),
 *   a `...` prototype changes nothing. Tried: a real struct for the arrays at 0x84/0xA8/0xCC with
 *   q->e[i] (no off local; same 36); off/t declared inside the loop body (same); the else arm of
 *   func_021F4B24 as one ternary (worse: constant slots swap).
 * 2026-10-04 wave D3 lane 18: DIFF, same size (628 bytes), frame 0x6c and all slot offsets match.
 * Residue 1: t (call result of func_021F5450) is in r4 and i*4 in r6; original has t in r6 and i*4 in r4 (whole-body r4/r6 swap).
 * Residue 2: hoisted constants 0x80000, 0xA000, 0x14000 land in slots 0x20, 0x1c, ? instead of original 0x18, 0x20, 0x1c (original store order 0x80000, 0xA000, 0x14000).
 * Residue 3: else arm of func_021F4B24: original loads k, then q+0x20, then selects 0xA000 or 0x5000, adds r0=r1+r0; compiled loads q+0x20 after the select and adds reversed.
 * Tried: E/EA as macros re-read per use (matches the original), hide call in else arm (matches layout), declaration order of Vec/Mtx/ints (matches slots), explicit off local, t declared first, z0 temp (worse).
 * FX round macro (x>0 ? x*4096+0.5f : x*4096-0.5f) with x = u16 at self+0x434 matches.
 * 2026-10-05 wD4 lane09: DIFF, 36 bytes (was 54). Residues 2 and 3 closed: the else arm of func_021F4B24 is `zz = q+0x20; if (k - 7 <= 1u) zz += 0xA000; else zz += 0x5000; v3.z = zz - (EA[4] << 11);` (tail merge of the two adds gives the shared `adds r0,r1,r0`, and the constant slots now match). Residue: only the whole-body r4/r6 swap (off=i*4 in r6, t in r4; original off r4, t r6). Tried: i*4 in the E/EA macros with no off local, t declared before off, off declared last, t as a block-scoped initialised local: no change.
 * 2026-10-05 wD5 lane16: DIFF, 36 bytes, same r4/r6 swap (original off=i*4 in r4, t in r6). Tried: t assigned inside the
 *   `if (*(int *)(t = ...) == 1)` test, off assigned before the k chain (worse, 46), `off = i << 2`, `off = i; off *= 4;`,
 *   u32 off, u32 i (37), E/EA/0xCC as `((u8 **)(q + 0x84))[i]` array reads (572) and as `q + i * 4 + K` (36),
 *   t through a static inline getter. None moves the colours.
 * symbols:
 *   func_021F5450 0x021F5450 thumb ov112
 *   func_021F545C 0x021F545C thumb ov112
 *   func_021F4B30 0x021F4B30 thumb ov112
 *   func_021F4B24 0x021F4B24 thumb ov112
 *   func_021F4E8C 0x021F4E8C thumb ov112
 *   func_021F4ED4 0x021F4ED4 thumb ov112
 *   func_021F4EB4 0x021F4EB4 thumb ov112
 *   func_021F4E6C 0x021F4E6C thumb ov112
 *   func_0207AF38 0x0207AF38 thumb
 *   func_0207B51C 0x0207B51C arm
 *   func_0207CA00 0x0207CA00 arm
 *   func_0204F638 0x0204F638 arm
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   table 0x020A1B38 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct { int x, y, z; } Vec;
typedef struct { int m[9]; } Mtx;
extern s16 table[];
extern u8 *func_021F5450(u8 *, int);
extern u8 *func_021F545C(u8 *);
extern int func_021F4B30(u8 *);
extern int func_021F4B24(u8 *);
extern void func_021F4E8C(u32, u8 *, const Vec *);
extern void func_021F4ED4(u32, u8 *, u16);
extern void func_021F4EB4(u32, u8 *, s16, s16);
extern void func_021F4E6C(u8 *, u8 *, u32);
extern void func_0207AF38(Mtx *, int, int);
extern void func_0207B51C(const Vec *, const Mtx *, Vec *);
extern void func_0207CA00(const Vec *, const Vec *, Vec *);
extern void func_0204F638(void *, u32, Vec *);

#define E (*(u8 **)(q + off + 0x84))
#define EA (*(u8 **)(q + off + 0xA8))
#define FXR(x) ((int)(((x) > 0) ? (x) * 4096 + 0.5f : (x) * 4096 - 0.5f))

void func_021F732C(u8 *self, u8 *q)
{
    Vec v3;
    Mtx mtx;
    Vec v2;
    Vec v1;
    int i;
    int off;
    int k;
    int ang2;
    int z;
    int ang0;
    int neg;
    u8 *t;
    u16 h;
    int zz;

    for (i = 0; i < 9; i++) {
        k = i;
        if (*(int *)(q + 0x54) == 1) {
            if (i == 7) {
                k = 8;
            } else if (i == 8) {
                k = 7;
            } else if (i == 0) {
                k = 1;
            } else if (i == 1) {
                k = 0;
            }
        }
        off = i * 4;
        if (E != 0 && *(int *)(q + off + 0xCC) == 1) {
            if (*(int *)(q + 0xC) == 1 && *(int *)(q + 8) == 1) {
                t = func_021F5450(*(u8 **)(q + 0x58), k);
                if (*(int *)t == 1) {
                    neg = (*(int *)(t + 0x1C) < 0) ? 1 : 0;
                    ang0 = (u16)(0x10000 - *(u16 *)(t + 0x34));
                    ang2 = (u16)((0x10000 + *(u16 *)(t + 0x36) + *(s16 *)(EA + 2)) % 0x10000);
                    func_021F545C(*(u8 **)(q + 0x58));
                    z = *(int *)(t + 0x1C);
                    func_0207AF38(&mtx, -table[(ang0 >> 4) * 2], table[(ang0 >> 4) * 2 + 1]);
                    func_0207B51C((Vec *)(t + 0x10), &mtx, &v1);
                    if (neg == 1) {
                        ang2 = (u16)(0x10000 - ang2);
                    }
                    if (func_021F4B30(E) == 0 && neg == 1) {
                        z = -z;
                    }
                    func_0207B51C((Vec *)(t + 0x28), &mtx, &v2);
                    func_0207CA00((Vec *)(t + 0x28), &v2, &v2);
                    h = *(u16 *)(self + 0x434);
                    v3.x = *(int *)(t + 4) + v1.x + 0x80000 + FXR(h);
                    v3.y = *(int *)(t + 8) + v1.y + 0x60000;
                    if (func_021F4B24(E) == 1) {
                        v3.z = *(int *)(q + 0x20) - 0x14000;
                    } else {
                        zz = *(int *)(q + 0x20);
                        if (k - 7 <= 1u) {
                            zz += 0xA000;
                        } else {
                            zz += 0x5000;
                        }
                        v3.z = zz - (*(u8 *)(EA + 4) << 11);
                    }
                    func_021F4E8C(*(u32 *)(self + 0x10), E, &v3);
                    func_021F4ED4(*(u32 *)(self + 0x10), E, (u16)(ang2 - ang0));
                    func_021F4EB4(*(u32 *)(self + 0x10), E, (s16)(z / 16 / 4), (s16)(*(int *)(t + 0x20) / 16 / 4));
                    func_021F4E6C(*(u8 **)(self + 0x10), E, 1);
                }
            } else {
                func_021F4E6C(*(u8 **)(self + 0x10), E, 0);
            }
        }
    }
    func_021F545C(*(u8 **)(q + 0x58));
    v3.x = *(int *)(q + 0x18) / 16;
    v3.y = (0xC0000 - *(int *)(q + 0x1C)) / 16;
    v3.z = 0x32;
    func_0204F638(*(void **)(self + 8), *(u32 *)(q + 0x5C), &v3);
}
