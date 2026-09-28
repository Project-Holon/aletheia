/*
 * function: func_0218B630
 * address:  0x0218B630
 * packet:   pkt_ov021_0218B630
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns the index of the first non-egg party member that knows the given
 * move (checks move slots 0x36..0x39), or 6 when none does. Called with 0x39
 * (Surf).
 *
 * symbols:
 *   func_02012934  0x02012934  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern void *func_02012934(void *p);
extern int func_0201AA18(void *party);
extern void *func_0201AB28(void *party, int i);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);

int func_0218B630(void *sys, u32 move)
{
    int n;
    void *party;
    int i;

    party = func_02012934(sys);
    n = func_0201AA18(party);

    for (i = 0; i < n; i++) {
        void *mon = func_0201AB28(party, i);

        if (func_02017E1C(mon, 0x4C, 0) == 0) {
            if (move == func_02017E1C(mon, 0x36, 0) || move == func_02017E1C(mon, 0x37, 0)
                || move == func_02017E1C(mon, 0x38, 0) || move == func_02017E1C(mon, 0x39, 0))
                return i;
        }
    }
    return 6;
}
