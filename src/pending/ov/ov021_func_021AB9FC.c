/*
 * function: func_021AB9FC
 * address:  0x021AB9FC
 * packet:   pkt_ov021_021AB9FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * symbols:
 *   func_021AB760  0x021AB760  thumb
 *   func_0218E124  0x0218E124  thumb
 *   func_0218EC90  0x0218EC90  thumb
 *   func_0218ECF4  0x0218ECF4  thumb
 */

typedef struct {
    int x;
    int y;
    int z;
} V;

typedef struct {
    int pad[9];
    V f24;
    V f30;
} S;

extern int func_021AB760(int a);
extern void func_0218E124(int h, int b);
extern void func_0218EC90(int h, V *v);
extern void func_0218ECF4(int h, V *v);

/*
 * 2026-10-01: DIFF in the copy schedule only: the original loads y, x, z of
 * f24 and interleaves the f30 loads with the v1 stores (no alias assumed);
 * struct assignment gives ldm/stm, braced init and field-by-field copies keep
 * the stores in order.
 */
void func_021AB9FC(int a, S *s)
{
    int h = func_021AB760(a);
    V v1;
    V v0;
    int x;
    int y;
    int z;
    func_0218E124(h, 2);
    x = s->f24.x;
    y = s->f24.y;
    z = s->f24.z;
    v1.x = x;
    v1.y = y;
    v1.z = z;
    x = s->f30.x;
    y = s->f30.y;
    z = s->f30.z;
    v0.x = x;
    v0.y = y;
    v0.z = z;
    func_0218EC90(h, &v1);
    func_0218ECF4(h, &v0);
}
