/*
 * function: func_021F732C
 * address: 0x021F732C
 * packet: pkt_ov112_021F732C
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05 (wD7 lane15): closed. The else arm of func_021F4B24 writes the whole v3.z store in
 *   each arm of the k - 7 test (q+0x20 plus 0xA000 or 0x5000, minus EA[4] << 11). The zz local that
 *   merged at the join was what swapped off (r4) and t (r6); tail merging rebuilds the shared add.
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
                        if (k - 7 <= 1u) {
                            v3.z = *(int *)(q + 0x20) + 0xA000 - (*(u8 *)(EA + 4) << 11);
                        } else {
                            v3.z = *(int *)(q + 0x20) + 0x5000 - (*(u8 *)(EA + 4) << 11);
                        }
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
