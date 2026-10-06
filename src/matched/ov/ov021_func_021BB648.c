/*
 * function: func_021BB648
 * address:  0x021BB648
 * packet:   pkt_ov021_021BB648
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216E1C4  0x0216E1C4  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 *   func_021BB808  0x021BB808  thumb  ov021
 */

int func_0216E1C4(int a, int b);
struct Actor;
struct VecFx32;
void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
void func_021AC154(int a);
void func_021AC1CC(int a, int *b);
struct Vec;
void func_021BB808(int *o, struct Vec *out);

void func_021BB648(int a, int *b)
{
    int v[3];

    if (b[9] == 1 || func_0216E1C4(b[3], (int)(b + 4)) == 0) {
        func_021AC154(a);
        return;
    }
    func_0216D88C((const struct Actor *)b[3], (struct VecFx32 *)v);
    func_021BB808(b, (struct Vec *)v);
    func_021AC1CC(a, v);
}
