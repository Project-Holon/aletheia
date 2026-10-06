/*
 * function: func_021BABDC
 * address:  0x021BABDC
 * packet:   pkt_ov021_021BABDC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B8220  0x021B8220  thumb  ov021
 *   func_021B82F0  0x021B82F0  thumb  ov021
 *   func_021B834C  0x021B834C  thumb  ov021
 *   func_021BB014  0x021BB014  thumb  ov021
 */

extern unsigned int func_021B8220(unsigned char *p);
typedef unsigned short u16;
typedef unsigned char  u8;
extern u16 func_021B82F0(u8 *p);
extern int func_021B834C(void *a);
typedef unsigned int   u32;
extern void func_021BB014(u32 a, u32 b, u32 c);

void func_021BABDC(void *p)
{
    void *a = (void *)func_021B8220(p);
    int b = func_021B82F0(a);
    int c = func_021B834C(a);

    if (b == 1) {
        func_021BB014((u32)p, (u32)a, c);
    }
}
