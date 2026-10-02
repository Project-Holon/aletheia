/*
 * function: func_021AB9FC
 * address:  0x021AB9FC
 * packet:   pkt_ov021_021AB9FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021AB760  0x021AB760  thumb
 *   func_0218E124  0x0218E124  thumb
 *   func_0218EC90  0x0218EC90  thumb
 *   func_0218ECF4  0x0218ECF4  thumb
 *
 * Lever: `const S *` together with the inline set3 helper gives the y, x, z
 * load order of the two 12-byte vector fills (as in ov021_func_021AB890.c).
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


static inline void set3(V *d, int x, int y, int z)
{
    d->x = x;
    d->y = y;
    d->z = z;
}

void func_021AB9FC(int a, const S *s)
{
    int h = func_021AB760(a);
    V v1;
    V v0;

    func_0218E124(h, 2);
    set3(&v1, s->f24.x, s->f24.y, s->f24.z);
    set3(&v0, s->f30.x, s->f30.y, s->f30.z);
    func_0218EC90(h, &v1);
    func_0218ECF4(h, &v0);
}
