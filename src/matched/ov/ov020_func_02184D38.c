/*
 * function: func_02184D38
 * address:  0x02184D38
 * packet:   pkt_ov020_02184D38
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The ARM9 leaf 0x02014184 is resolved by its matched shard.
 *
 * What made it byte-correct: `const int *q` (see the EXACT twins
 * ov020_func_02184D90.c / ov020_func_02184DE8.c).
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020142A4  0x020142A4  thumb
 *   func_02014184  0x02014184  thumb
 *   func_02184CEC  0x02184CEC  thumb  ov020
 *   func_02184388  0x02184388  thumb  ov020
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;
typedef unsigned int   u32;

void *func_020122C0(void *p, int a, void (*cb)(void), int n);
void *func_020124E8(void *p);
void func_02184CEC(void *obj, void *p);
u16 func_020142A4(u16 s);
void func_02184388(void);
void func_02014184(void *o, int a, int s, int x, int y, int z);

void *func_02184D38(void *p, int unused, int a, const int *q, u16 s, int t)
{
    void *r0v = func_020122C0(p, 0, func_02184388, 0x9c);
    char *r4 = func_020124E8(r0v);

    func_02184CEC(r4, p);
    s = func_020142A4(s);
    func_02014184(r4 + 0x10, a, (s16)s, q[0], q[1], q[2]);
    *(int *)(r4 + 0x2c) = 0;
    *(int *)(r4 + 0x40) = t;
    return r0v;
}
