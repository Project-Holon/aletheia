/*
 * function: func_0218B53C
 * address:  0x0218B53C
 * packet:   pkt_ov021_0218B53C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0219E634  0x0219E634  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0219E570  0x0219E570  thumb  ov021
 */

void *func_021A3074(unsigned char *p);
int func_0219E634(void *a, int *buf);
void *func_02188C7C(unsigned char *p);
typedef unsigned int   u32;
u32 func_0219E570(u32 o, u32 k, u32 flag);

int func_0218B53C(unsigned char *p, void *b)
{
    int buf[2];
    if (func_0219E634(func_021A3074(*(void **)(p + 0x18)), buf) != 0)
        return func_0219E570((u32)func_02188C7C(b), (u32)buf, 0);
    return 0;
}
