/*
 * function: func_02197EDC
 * address:  0x02197EDC
 * packet:   pkt_ov021_02197EDC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D7C4  0x0216D7C4  thumb  ov010
 *   func_02197EB4  0x02197EB4  thumb  ov021
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   func_0216D570  0x0216D570  thumb  ov010
 *   func_0216D7C0  0x0216D7C0  thumb  ov010
 *   func_0216D7C8  0x0216D7C8  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 func_0216D7C4(u8 *);
extern void func_02197EB4(u32 a);
extern u32 func_0216D57C(void *p, u32 v);
extern void func_0216D570(char *p, u32 v);
extern void func_0216D7C0(void *p, u16 v);
extern void func_0216D7C8(void *p, u16 v);

u32 func_02197EDC(u8 *p, u32 a1, u32 a2, u32 a3)
{
    if (func_0216D7C4(p) != 0xff) {
        func_02197EB4((u32)p);
        if (func_0216D57C(p, 0x400) == 0) {
            return 0;
        }
    }
    func_0216D570((char *)p, 0x400);
    func_0216D7C0(p, 0xff);
    func_0216D7C8(p, 0);
    return 1;
}
