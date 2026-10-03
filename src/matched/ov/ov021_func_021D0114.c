/*
 * function: func_021D0114
 * address:  0x021D0114
 * packet:   pkt_ov021_021D0114
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0200856C  0x0200856C  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5DC(void *a0);
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012944(void *p);
extern int func_0200856C(void *p);
extern u16 *func_02159AE8(void *a0, void *a1);

int func_021D0114(u32 a, u32 b)
{
    u16 *q = func_02159AE8((void *)a, (void *)b);

    *q = func_0200856C(func_02012944(func_020120F4((void *)func_0215A5DC((void *)b)))) != 0 ? 1 : 0;
    return 0;
}
