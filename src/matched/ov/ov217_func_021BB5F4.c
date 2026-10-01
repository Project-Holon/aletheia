/*
 * function: func_021BB5F4
 * address: 0x021BB5F4
 * packet: pkt_ov217_021BB5F4
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * arity: BB910 retains supplied r1=13 through its forwarding chain.
 * symbols:
 *   func_021BB98C 0x021BB98C thumb ov217
 *   func_021BBC50 0x021BBC50 thumb ov217
 *   func_021BBE7C 0x021BBE7C thumb ov217
 *   func_021BBCB0 0x021BBCB0 thumb ov217
 *   func_021BC6E4 0x021BC6E4 thumb ov217
 *   func_021BBDF0 0x021BBDF0 thumb ov217
 *   func_021BC014 0x021BC014 thumb ov217
 *   func_021BC72C 0x021BC72C thumb ov217
 *   func_020061E4 0x020061E4 thumb
 *   func_021BB990 0x021BB990 thumb ov217
 *   func_021BC490 0x021BC490 thumb ov217
 *   func_021BC4A0 0x021BC4A0 thumb ov217
 *   func_021BC50C 0x021BC50C thumb ov217
 *   func_021BC55C 0x021BC55C thumb ov217
 *   func_021BB91C 0x021BB91C thumb ov217
 *   func_021BB910 0x021BB910 thumb ov217
 */
typedef unsigned char u8;
extern unsigned func_021BB98C(void *);
extern u8 func_021BBC50(u8 *);
extern void func_021BBE7C(u8 *, unsigned);
extern void func_021BBCB0(u8 *);
extern unsigned func_021BC6E4(void *);
extern void func_021BBDF0(u8 *, unsigned);
extern void func_021BC014(u8 *);
extern void func_021BC72C(u8 *, unsigned, u8 *);
extern unsigned func_020061E4(unsigned);
extern void func_021BB990(void *);
extern void func_021BC490(void);
extern int func_021BC4A0(void);
extern void func_021BC50C(u8 *);
extern unsigned func_021BC55C(unsigned);
extern void func_021BB91C(void *);
extern void func_021BB910(u8 *, unsigned);
void func_021BB5F4(u8 *p)
{
    switch (func_021BB98C(p)) {
    case 0:
        func_021BBE7C(p, func_021BBC50(p));
        func_021BBCB0(p);
        func_021BBDF0(p, func_021BC6E4(p));
        func_021BC014(p);
        func_021BC72C(p, 3, (u8 *)1);
        func_020061E4(1898);
        func_021BB990(p);
        break;
    case 1:
        if (*(unsigned *)(p + 0x24) >= 60) {
            func_021BC490();
            func_021BB990(p);
        }
        break;
    case 2:
        if (func_021BC4A0()) {
            func_021BC50C(p);
            func_021BB990(p);
        }
        break;
    case 3:
        if (func_021BC55C((unsigned)p)) {
            func_021BB91C(p);
            func_021BB910(p, 13);
        }
        break;
    }
}
