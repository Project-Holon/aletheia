/*
 * function: func_021BD30C
 * address:  0x021BD30C
 * packet:   pkt_ov021_021BD30C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BD2C0  0x021BD2C0  thumb  ov021
 *   func_021BD2C8  0x021BD2C8  thumb  ov021
 *   func_021BD2B8  0x021BD2B8  thumb  ov021
 *   func_021BD604  0x021BD604  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_021BD2C0(u8 *p);
extern u16 func_021BD2C8(u8 *p);
extern u16 func_021BD2B8(u8 *p);
extern void func_021BD604(void *a, void *b, void *c, void *d, void *e);

void func_021BD30C(char *p)
{
    void *a;
    void *b;

    a = (void *)func_021BD2C0((u8 *)p);
    b = (void *)func_021BD2C8((u8 *)p);
    func_021BD604(a, b, (void *)func_021BD2B8((u8 *)p), p + 0x40, p + 0x41);
}
