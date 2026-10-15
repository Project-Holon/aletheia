/*
 * function: FIELD_CAMERA_CalcAngles
 * address:  0x0218E610
 * packet:   pkt_ov021_0218E610
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Converts a vector to two 16-bit angles plus its length.
 *
 * symbols:
 *   VEC_Mag  0x0207CBD0  arm
 *   VEC_Normalize  0x0207CCA4  arm
 *   func_0207CFB8  0x0207CFB8  arm
 *   FIELD_CAMERA_RefineAngles  0x0218E7DC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef struct { int x, y, z; } V;

extern int VEC_Mag(void *a);
extern void VEC_Normalize(void *a, V *b);
extern int func_0207CFB8(int a, int b);
extern void FIELD_CAMERA_RefineAngles(V *v, u16 h0, u16 h1, u16 *p0, u16 *p1);

void FIELD_CAMERA_CalcAngles(void *a, u16 *b, u16 *c, int *d)
{
    V v;
    V w;
    u16 h[2];
    int len;

    len = VEC_Mag(a);
    VEC_Normalize(a, &v);
    w.x = v.x;
    w.y = 0;
    w.z = v.z;
    h[1] = func_0207CFB8(v.y, VEC_Mag(&w));
    h[0] = func_0207CFB8(v.x, v.z);
    FIELD_CAMERA_RefineAngles(&v, h[0], h[1], h, &h[1]);
    *b = h[1];
    *c = h[0];
    *d = len;
}
