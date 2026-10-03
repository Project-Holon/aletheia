/*
 * function: func_0218AB50
 * address:  0x0218AB50
 * packet:   pkt_ov021_0218AB50
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Step hook: updates func_021C3378, advances the party step counter
 * (func_0218AAD0) and, when an egg is ready (func_0218AB0C), shows message
 * 0x8CA.
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb
 *   func_02012934  0x02012934  thumb
 *   func_02188D50  0x02188D50  thumb
 *   func_021C3378  0x021C3378  thumb
 *   func_0218AAD0  0x0218AAD0  thumb
 *   func_0218AB0C  0x0218AB0C  thumb
 *   func_02158768  0x02158768  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern u16 func_02188C84(u8 *p);
struct BigObj;
extern void *func_02012934(const struct BigObj *p);
extern void *func_02188D50(u8 *p);
extern int func_021C3378(void **p);
extern void func_0218AAD0(void *sys, void *party);
extern int func_0218AB0C(void *party);
extern int func_02158768(void *a0, u32 a1, int a2, u16 a3);

int func_0218AB50(void *p, u8 *pos, void *msg, void *sys)
{
    u16 v = func_02188C84(pos);
    void *party = func_02012934(sys);

    func_021C3378(func_02188D50(pos));
    func_0218AAD0(sys, party);
    if (func_0218AB0C(party))
        return func_02158768(msg, 0x8CA, 0, v);
    return 0;
}
