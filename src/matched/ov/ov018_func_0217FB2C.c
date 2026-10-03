/*
 * function: func_0217FB2C
 * address: 0x0217FB2C
 * packet: pkt_ov018_0217FB2C
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02159AE8 0x02159AE8 thumb ov010
 *   func_0215A5DC 0x0215A5DC thumb ov010
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200BE48 0x0200BE48 thumb
 *   func_0200BF10 0x0200BF10 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u16 *func_02159AE8(void *, void *);
extern void *func_0215A5DC(void *);
struct Big;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern u16 *func_0200BE48(void *);
extern u8 func_0200BF10(void *);
int func_0217FB2C(void *a, void *vm)
{
    u16 *out;
    int v;
    out = func_02159AE8(a, vm);
    if (func_0200BF10(func_0200BE48(func_02012EBC(func_020120F4(func_0215A5DC(vm))))) != 0x30) {
        v = 1;
    } else {
        v = 0;
    }
    *out = v;
    return 0;
}
