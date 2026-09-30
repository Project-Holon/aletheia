/*
 * function: func_0217A7AC
 * address:  0x0217A7AC
 * packet:   pkt_ov015_0217A7AC
 * region:   ov015
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * Lane 04 (2026-09-30): 320/320 bytes, 18 concrete bytes.  Four source fixes
 *   read off the image and verified by compile:
 *   - the two loops are `for (; (i < size) ? 1 : 0; i++)`; the plain relational
 *     form rotates the loop (a dead pre-test plus a fall-through body) whereas
 *     the ternary keeps the image's `b <bottom-test>` entry.  This alone took
 *     the file from 177 concrete bytes to 29.
 *   - `size` is `int` (the image compares signed: `blt`) but the clamp is
 *     unsigned: `if ((unsigned int)size > 0xB5)` gives the image's `movhi`.
 *   - the address 0x0217AC90 is named through TWO externs (g_0217AC90 and
 *     g_0217AC90b at the same address); the image's pool carries the word
 *     twice.  One name CSE'd both uses into a callee-saved register and left
 *     the function 4 bytes short.
 *   Residue (register allocation only): the image keeps the early `&g` in r4
 *   (so the +0x70 reload lands in r0) and the second loop's counter in r5;
 *   dsi/1.1p1 keeps `&g` in r7 across the calls and colours the second loop's
 *   counter r1.  Declaration order, the loop spelling, moving `i = 0`, and a
 *   literal cast for the call argument were all measured inert.
 *
 * sdk:      IRCi_Read (libirc.a irc_internal.o)
 *
 * symbols:
 *   func_02075E9C  0x02075E9C  arm
 *   func_02084DF4  0x02084DF4  arm
 *   func_0217A674  0x0217A674  arm    ov015
 *   func_0217A5B4  0x0217A5B4  arm    ov015
 *   func_0217A718  0x0217A718  arm    ov015
 *   func_02084E2C  0x02084E2C  arm
 *   func_02075EAC  0x02075EAC  arm
 *   g_0217ACA0     0x0217ACA0  data
 *   g_0217AC90     0x0217AC90  data
 *   g_0217AC90b    0x0217AC90  data
 *   g_0217AAB4     0x0217AAB4  data
 */

typedef unsigned char u8;
typedef unsigned short u16;

struct irc_param {
    int f0;
    u8 *send;
    u8 *recv;
};

extern u8 g_0217ACA0[181];
extern struct irc_param g_0217AC90;
extern struct irc_param g_0217AC90b;
extern u16 g_0217AAB4;

extern void func_02075E9C(u16 id);
extern long func_02084DF4(u16 id);
extern u8 func_0217A674(struct irc_param *p);
extern void func_0217A5B4(void);
extern void func_0217A718(struct irc_param *p);
extern void func_02084E2C();
extern void func_02075EAC(u16 id);

int func_0217A7AC(u8 *buf)
{
    int size;
    int i;

    g_0217AC90.send = g_0217ACA0;
    g_0217AC90.recv = buf;
    g_0217ACA0[0] = 1;
    buf[0] = 0;
    func_02075E9C(g_0217AAB4);
    func_02084DF4(g_0217AAB4);
    while (*(volatile u16 *)0x040001A0 & 0x80)
        ;
    *(volatile u16 *)0x040001A0 = 0xA042;
    func_0217A674(&g_0217AC90b);
    func_0217A5B4();
    func_0217A718(&g_0217AC90b);
    func_0217A5B4();
    size = buf[0];
    i = 0;
    g_0217AC90b.send = 0;
    g_0217AC90b.recv = buf;
    if ((unsigned int)size > 0xB5)
        size = 0;
    buf[0] = 0;
    if (size != 0) {
        for (; (i < size) ? 1 : 0; i++) {
            if (i == size - 1)
                *(volatile u16 *)0x040001A0 = 0xA002;
            func_0217A718(&g_0217AC90b);
        }
    } else {
        *(volatile u16 *)0x040001A0 = 0xA002;
        func_0217A718(&g_0217AC90b);
    }
    for (i = 0; (i < size) ? 1 : 0; i++) {
        buf[i] ^= 0xAA;
    }
    while (*(volatile u16 *)0x040001A0 & 0x80)
        ;
    func_02084E2C(g_0217AAB4);
    func_02075EAC(g_0217AAB4);
    return size;
}
