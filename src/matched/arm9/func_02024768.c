/*
 * function: PMSI_PARAM_IsSpecialWord
 * address:  0x02024768
 * packet:   pkt_02024768
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 *
 * Blocked: data_0209F734 (a 12-halfword table) is named by exactly one pool word,
 * 0x020247A4, and that word is inside this function's own range once the
 * body compiles to its full 64 bytes; the `literal` class discards it. Every
 * concrete byte reproduces.
 * status:   EXACT
 * symbols:
 *   data_0209F734  0x0209F734  data
 *
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

struct Tbl {
    u16 f[12];
};

extern const struct Tbl data_0209F734;

s32 PMSI_PARAM_IsSpecialWord(u32 v)
{
    struct Tbl b;
    u8 i;

    b = data_0209F734;
    for (i = 0; i < 12; i++) {
        if (v == b.f[i]) {
            return 1;
        }
    }
    return 0;
}
