/*
 * function: func_021C4C0C
 * address:  0x021C4C0C
 * packet:   pkt_ov021_021C4C0C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_0216E1A4  0x0216E1A4  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 */

typedef unsigned short u16;

typedef struct { int a; int b; } S;

typedef unsigned int   u32;
extern int func_021AC1AC(u32 a);
extern int func_0216E1A4(int a0, int a1);
struct Actor;
struct VecFx32;
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
extern void func_021AC1CC(int a, int *v);

void func_021C4C0C(int a, int *b)
{
    int v[3];
    int *p = (int *)func_021AC1AC(a);

    *(S *)b = *(S *)p;
    func_0216E1A4(b[1], (int)(b + 2));
    func_0216D88C((const struct Actor *)b[1], (struct VecFx32 *)v);
    v[2] += 0x8000;
    func_021AC1CC(a, v);
    *(u16 *)(b + 4) = *(u16 *)(b[0] + 6);
}
