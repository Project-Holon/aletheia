/*
 * function: func_02186304
 * address: 0x02186304
 * packet: pkt_ov023_02186304
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes follow the return at 0x02186320.
 * symbols:
 *   func_02039338 0x02039338 arm
 *   func_0218654C 0x0218654C thumb ov023
 *   func_02184560 0x02184560 thumb ov023
 * Caller explicitly sets r1 for func_02184560, retained despite its legacy one-argument definition.
 */
extern unsigned short func_02039338(void);
extern int func_0218654C(char *p);
extern void func_02184560(char *, int);
void func_02186304(char *p, int a)
{
    if (func_02039338() == 0) {
        func_0218654C(p);
        func_02184560(p, a);
    }
}
