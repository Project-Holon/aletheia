/*
 * function: func_02184D38
 * address:  0x02184D38
 * packet:   pkt_ov020_02184D38
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * blocker:  byte-correct (88/88); the bl at +0040 to 0x02014184 is
 * unresolved: 0x02014184 is an unlabelled Thumb leaf in the ARM9 image
 * (push {r3,r4}, no lr, so disasm.py traces no func_ label; overlay
 * callers such as 0x0215A05C and 0x02184E76 exist, but with no label at the
 * target label / sole-ref/code refuse it). evidence
 * class: label / sole-ref/code (target not a traced function start).
 * Seeding 0x02014184 as a function start (integrator) and filing the leaf
 * below would resolve it as `matched`.
 *
 * Leaf C, verified EXACT at 0x02014184 (arm9, thumb) by lane R2:
 *
 *   struct r { u32 a; u16 b; s16 c; u16 d; u16 e; u32 f; int x, y, z; };
 *   void func_02014184(struct r *p, u16 b, u16 d, int x, int y, int z)
 *   {
 *       p->a = 1; p->b = b; p->c = -1; p->d = d; p->e = 0; p->f = 0;
 *       p->x = x; p->y = y; p->z = z;
 *   }
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
