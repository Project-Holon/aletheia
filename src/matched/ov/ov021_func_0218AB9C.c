/*
 * function: func_0218AB9C
 * address:  0x0218AB9C
 * packet:   pkt_ov021_0218AB9C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Bumps a 7-bit counter in the save block; when it wraps, calls func_0201B7EC
 * on every party member with the two coordinates read from the position
 * object.
 *
 * symbols:
 *   func_02008978  0x02008978  thumb
 *   func_02008980  0x02008980  thumb
 *   func_02188C9C  0x02188C9C  thumb
 *   func_02188C84  0x02188C84  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern void *func_02012EBC(void *p);
extern void *func_02008854(void *p);
extern u16 func_02008978(void *p);
extern void func_02008980(void *p, u16 v);
extern void *func_02012934(void *p);
extern u16 func_02188C9C(u8 *p);
extern u16 func_02188C84(u8 *p);
extern int func_0201AA18(void *party);
extern void *func_0201AB28(void *party, int i);
extern void func_0201B7EC(void *mon, int a, int b);

void func_0218AB9C(void *sys, u8 *pos)
{
    void *save = func_02008854(func_02012EBC(sys));
    int wrapped = 0;
    u16 count = func_02008978(save) + 1;

    if (count >= 0x80) {
        count = 0;
        wrapped = 1;
    }
    func_02008980(save, count);
    if (wrapped) {
        void *party = func_02012934(sys);
        int a;
        int b;
        int n;
        int i;

        a = func_02188C9C(pos);
        b = func_02188C84(pos);
        n = func_0201AA18(party);
        for (i = 0; i < n; i++)
            func_0201B7EC(func_0201AB28(party, i), a, b);
    }
}
