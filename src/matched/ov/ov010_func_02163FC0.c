/*
 * function: func_02163FC0
 * address:  0x02163FC0
 * packet:   pkt_ov010_02163FC0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D88C  0x0216D88C  thumb
 *   func_0216D89C  0x0216D89C  thumb
 */

struct Actor;
struct VecFx32;
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *p);
extern void func_0216D89C(int a, int *p);

void func_02163FC0(int a, int dir, int amt)
{
    int buf[3];

    func_0216D88C((const struct Actor *)a, (struct VecFx32 *)buf);
    switch (dir) {
    case 0:
        buf[2] -= amt;
        break;
    case 1:
        buf[2] += amt;
        break;
    case 2:
        buf[0] -= amt;
        break;
    case 3:
        buf[0] += amt;
        break;
    }
    func_0216D89C(a, buf);
}
