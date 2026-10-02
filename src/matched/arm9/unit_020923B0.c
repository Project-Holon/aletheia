/*
 * unit:     yes
 * function: func_020923B0, func_020923C4, func_020923F0
 * address:  0x020923B0
 * packet:   pkt_020923B0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * String / memory utilities:
 *   func_020923B0 (20 B)  wraps func_02092430 (memset) and returns ptr
 *   func_020923C4 (44 B)  memchr (byte search)
 *   func_020923F0 (64 B)  memcmp (memory comparison)
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020923B0.c \
 *       --addr 0x020923B0
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_02092430(void *p, u32 val, u32 count);

void *func_020923B0(void *p, int c, u32 n)
{
    func_02092430(p, c, n);
    return p;
}

u8 *func_020923C4(u8 *s, u32 c, u32 n)
{
    u8 val = (u8)c;

    if (n != 0) {
        do {
            if (*s++ == val) {
                return s - 1;
            }
        } while (--n != 0);
    }
    return 0;
}

int func_020923F0(const u8 *s1, const u8 *s2, u32 n)
{
    u8 b1;
    u8 b2;

    if (n != 0) {
        do {
            b1 = *s1++;
            b2 = *s2++;
            if (b1 != b2) {
                b1 = *(s1 - 1);
                b2 = *(s2 - 1);
                return (b1 < b2) ? -1 : 1;
            }
        } while (--n != 0);
    }
    return 0;
}
