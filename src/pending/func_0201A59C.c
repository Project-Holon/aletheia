/*
 * function: func_0201A59C
 * address:  0x0201A59C
 * packet:   pkt_0201A59C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * note:     re-verified 2026-09-20: MATCH; see verify output
 * blocker:  0201A858 (label), 0209E424 (literal) - every concrete byte is right (0 differing bytes, 96 of 96)
 *
 * symbols:
 *   g_0209E424      0x0209E424  data
 *   func_0201A858   0x0201A858  thumb
 *   func_0201A5FC   0x0201A5FC  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0201A59C.c \
 *       --func func_0201A59C --addr 0x0201A59C --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern const u8 g_0209E424[6];
extern int func_0201A858(char *buf);
extern int func_0201A5FC(void *a0, void *a1, char *buf, void *a2, u32 zero);

int func_0201A59C(void *a0, void *a1, void *a2)
{
    char buf[6];

    buf[0] = g_0209E424[0];
    buf[1] = g_0209E424[1];
    buf[2] = g_0209E424[2];
    buf[3] = g_0209E424[3];
    buf[4] = g_0209E424[4];
    buf[5] = g_0209E424[5];

    if (func_0201A858(buf) != 0) {
        do {
            if (func_0201A5FC(a0, a1, buf, a2, 0) == 1) {
                return 1;
            }
        } while (func_0201A858(buf) != 0);
    }

    return 0;
}
