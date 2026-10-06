/*
 * function: func_0217F8D0
 * address:  0x0217F8D0
 * packet:   pkt_ov018_0217F8D0
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_02175B8C  0x02175B8C  thumb  ov011
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 pad0[0x93F];
    u8 lo93F : 3;
    u8 bit93F : 1;
} Sys;

u16 *func_02159AE8(void *a0, void *a1);
void *func_0215A5DC(void *a0);
typedef unsigned int   u32;
struct Ctx;
u32 func_02012138(const struct Ctx *p);
int func_02158344(int a0);
int func_02175B8C(u8 *p);

int func_0217F8D0(void *a0, int a)
{
    u16 *out;
    Sys *s;
    int v;

    out = func_02159AE8(a0, (void *)a);
    s = (Sys *)func_02158344(func_02012138(func_0215A5DC((void *)a)));
    if (s != 0 && s->bit93F == 0 && func_02175B8C((u8 *)s + 0x1AC) == 1) {
        v = 1;
    } else {
        v = 0;
    }
    *out = v;
    return 0;
}
