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
 * notes: DIFF, loops: image keeps both loops unguarded (b to the bottom test) with size in r4 and i in r5; ours emits the redundant size-nonzero guard (ble) and swaps the two registers. Tried while/for/while(1)+break/size int/i=0 hoisted/size>i/declaration order.
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
extern u16 g_0217AAB4;

extern void func_02075E9C(u16 id);
extern long func_02084DF4(u16 id);
extern u8 func_0217A674(struct irc_param *p);
extern void func_0217A5B4(void);
extern void func_0217A718(struct irc_param *p);
extern void func_02084E2C();
extern void func_02075EAC(u16 id);

u8 func_0217A7AC(u8 *buf)
{
    u8 size;
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
    func_0217A674((struct irc_param *)0x0217AC90);
    func_0217A5B4();
    func_0217A718((struct irc_param *)0x0217AC90);
    func_0217A5B4();
    size = buf[0];
    i = 0;
    g_0217AC90.send = 0;
    g_0217AC90.recv = buf;
    if (size > 0xB5)
        size = 0;
    buf[0] = 0;
    if (size != 0) {
        while (i < size) {
            if (i == size - 1)
                *(volatile u16 *)0x040001A0 = 0xA002;
            func_0217A718(&g_0217AC90);
            i++;
        }
    } else {
        *(volatile u16 *)0x040001A0 = 0xA002;
        func_0217A718((struct irc_param *)0x0217AC90);
    }
    i = 0;
    while (i < size) {
        buf[i] ^= 0xAA;
        i++;
    }
    while (*(volatile u16 *)0x040001A0 & 0x80)
        ;
    func_02084E2C(g_0217AAB4);
    func_02075EAC(g_0217AAB4);
    return size;
}
