/*
 * function: func_021EED48
 * address:  0x021EED48
 * packet:   pkt_ov093_021EED48
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021F6398  0x021F6398  data  a4
 *   func_021B9940  0x021B9940  thumb  ov093
 *   func_021D5864  0x021D5864  thumb  ov093
 *   func_0201EE84  0x0201EE84  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 t[8];
} D;

extern D d_021F6398;
extern u8 *func_021B9940(char *p, u8 i);
extern void *func_021D5864(void *m);
extern void func_0201EE84(u32 h, u32 a, void *mon);

void func_021EED48(u8 a, u8 b)
{
    func_0201EE84(d_021F6398.f8, b, func_021D5864(func_021B9940((char *)d_021F6398.f4, a)));
}
