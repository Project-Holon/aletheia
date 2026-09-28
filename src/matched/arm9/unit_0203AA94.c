/*
 * unit:     yes
 * function: func_0203AA94
 * address:  0x0203AA94
 * packet:   pkt_0203A958
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469D8     0x021469D8  data
 *   g_020A7AF8     0x020A7AF8  data
 *   g_020A7B78     0x020A7B78  data
 *   func_0203D798  0x0203D798  arm
 *   func_02034714  0x02034714  arm
 *   func_020395EC  0x020395EC  arm
 *   func_02038C18  0x02038C18  arm
 *   _u32_div_f     0x0209C2B0  arm
 *
 * The net_command.c command-queue trio, 0x0203AA94..0x0203AD6C, folded into
 * one translation unit: the enqueue (func_0203AA94), the header pump
 * (func_0203ABC0) and the chunk pump (func_0203ACAC).  All three walk the
 * same five 0x18-byte slot table at g_021469D8 and share the 4-bit status
 * nibble pair at record +0x17 / table +0x57.  Filed as a unit because the
 * three are individually EXACT and reproduce the range with its pools.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0203AA94.c \
 *       --addr 0x0203AA94 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8   *g_021469D8;
extern char  g_020A7AF8[];
extern char  g_020A7B78[];
extern u8   *func_0203D798(void);
extern void  func_02034714(char *f, u32 line, char *e);
extern u32   func_020395EC(u32 a);
extern u32   func_02038C18(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);

typedef struct {
    u8 lo : 4;
    u8 hi : 4;
} Status;

u32 func_0203AA94(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4)
{
    u8 *cfg;
    u8 *t;
    u8 *st57;
    u8 *s;
    int i;
    int mtu;
    Status *sc;
    Status *st;

    cfg = func_0203D798();
    t = g_021469D8;
    st57 = t + 0x57;
    for (i = 0; i < 5; i++) {
        sc = (Status *)&st57[i * 0x18];
        if (sc->hi)
            continue;
        if (sc->lo == 0)
            break;
    }
    if (i == 5)
        return 0;

    s = t + 0x40 + i * 0x18;
    *(u32 *)(s + 4) = a3;
    mtu = cfg[0x61] - 0xc;
    if (mtu <= 0)
        func_02034714(g_020A7AF8, 0x22b, g_020A7B78);
    *(u16 *)(s + 0xe) = cfg[0x61] - 0xc;
    *(u16 *)(s + 0x14) = a3 / *(u16 *)(s + 0xe);
    *(u16 *)(s + 0x10) = a3 % *(u16 *)(s + 0xe);
    if (*(u16 *)(s + 0x10) != 0)
        *(u16 *)(s + 0x14) = *(u16 *)(s + 0x14) + 1;
    *(u16 *)(s + 0x12) = 0;
    *(u16 *)(s + 0xc) = a2;
    s[0x16] = a1;
    *(u32 *)(s + 8) = a4;
    *(u32 *)s = func_020395EC(a0);
    st = (Status *)(s + 0x17);
    st->hi = 1;
    return st->hi;
}

u32 func_0203ABC0(void)
{
    u16 hdr[6];
    u8 *s;
    Status *st;
    u8 *t;
    int i;

    t = g_021469D8 + 0x40;
    for (i = 0; i < 5; i++) {
        s = t + i * 0x18;
        st = (Status *)(s + 0x17);
        if (st->hi) {
            hdr[2] = *(u16 *)(s + 0x14);
            *(u32 *)&hdr[0] = *(u32 *)(s + 4);
            hdr[3] = *(u16 *)(s + 0xc);
            hdr[4] = *(u16 *)(s + 0xe);
            hdr[5] = s[0x16];
            st->lo = func_02038C18(0xd, (u32)hdr, 0xc, 1,
                                   *(u32 *)s, s[0x16], 0);
            st->hi = 1 - st->lo;
            return st->lo;
        }
    }
    return 0;
}

void func_0203ACAC(void)
{
    int i;
    u32 n;
    u32 c;
    u32 base;
    u8 *t;
    u8 *s;

    t = g_021469D8;
    for (i = 0; i < 5; i++) {
        if ((u32)(t[i * 0x18 + 0x57] << 0x1c) >> 0x1c) {
            s = t + 0x40 + i * 0x18;
            c = *(u16 *)(s + 0x12);
            n = *(u16 *)(s + 0xe);
            base = *(u32 *)(s + 8) + n * c;
            if (c + 1 == *(u16 *)(s + 0x14))
                n = *(u16 *)(s + 0x10);
            if (func_02038C18(0xc, base, n, 1,
                              *(u32 *)s, s[0x16], 1) != 0)
                *(u16 *)(s + 0x12) = *(u16 *)(s + 0x12) + 1;
            if (*(u16 *)(s + 0x12) == *(u16 *)(s + 0x14))
                s[0x17] = s[0x17] & ~0xf;
            return;
        }
    }
    func_0203ABC0();
}
