/*
 * function: func_02189204
 * address:  0x02189204
 * packet:   pkt_ov021_02189204
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012964  0x02012964  thumb
 *   func_0216CCDC  0x0216CCDC  thumb  ov010
 *   func_0219C554  0x0219C554  thumb
 *   func_0219C680  0x0219C680  thumb
 *   func_02013CC8  0x02013CC8  thumb
 *   func_02013CE0  0x02013CE0  thumb
 *   func_02012138  0x02012138  thumb
 *   func_0217C0A8  0x0217C0A8  thumb  ov018
 *   func_02012944  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   func_021A31A4  0x021A31A4  thumb
 *   func_0219C658  0x0219C658  thumb
 *   func_0219D448  0x0219D448  thumb
 *   func_0218ED50  0x0218ED50  thumb
 *   func_0216CDB8  0x0216CDB8  thumb  ov010
 *   func_0216D2F8  0x0216D2F8  thumb  ov010
 *   func_02189AE8  0x02189AE8  thumb
 *   func_0216D974  0x0216D974  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_020120F4(u32 a);
extern u32 func_02012964(void);
extern void func_0216CCDC(u32 a, u32 b, u32 c, void *d, u32 e, u32 f);
extern void func_0219C554(u32 a, u32 b, u32 c);
extern void func_0219C680(u32 a);
extern u32 func_02013CC8(u32 a);
extern u32 func_02013CE0(u32 a);
extern void *func_02012138(u32 a);
extern u32 func_0217C0A8(void *a0);
extern void func_02012944(u32 a);
extern u32 func_02008550(void);
extern u32 func_021A31A4(u32 a, u32 b);
extern void func_0219C658(u32 a, u32 b);
extern void func_0219D448(u32 a, u32 b);
extern u32 func_0218ED50(u32 a);
extern void func_0216CDB8(u32 a, u32 b);
extern void func_0216D2F8(u32 a);
extern u32 func_02189AE8(u32 a);
extern void func_0216D974(u32 a, u32 b);

void func_02189204(u8 *a)
{
    u32 h;
    u32 x;
    u32 r;
    u32 t;

    h = func_020120F4(*(u32 *)(a + 4));
    r = func_02012964();
    *(u32 *)(a + 0x38) = r;
    func_0216CCDC(r, *(u16 *)a, h, a, *(u32 *)(a + 0x48), *(u32 *)(a + 0x3C));
    func_0219C554(*(u32 *)(a + 0x38), *(u32 *)(a + 0xB0), 0x20);
    func_0219C680(*(u32 *)(a + 0x38));
    x = *(u16 *)(a + 0xD8);
    if (func_02013CC8(x) == 0 && func_02013CE0(x) == 0) {
        t = func_0217C0A8(func_02012138(*(u32 *)(a + 4)));
    } else {
        func_02012944(h);
        t = func_02008550();
    }
    func_0219C658(r, func_021A31A4(t, 0));
    func_0219D448(*(u32 *)(a + 0x38), *(u32 *)(a + 0x130));
    func_0216CDB8(*(u32 *)(a + 0x38), func_0218ED50(*(u32 *)(a + 0x10)));
    func_0216D2F8(*(u32 *)(a + 0x38));
    func_0216D974(r, func_02189AE8(*(u16 *)(a + 0xD0)));
}
