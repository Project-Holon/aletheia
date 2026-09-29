/*
 * function: func_021EFAD8
 * address:  0x021EFAD8
 * packet:   pkt_ov093_021EFAD8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Lever: the append store is written `((u32 *)(a + b * 0x18 + 0x68))[n] = c`;
 * the flat `*(u32 *)(a + b * 0x18 + n * 4 + 0x68)` schedules the scaled index
 * before the row base (two instructions swapped).  A single `!= 0` guard with
 * one trailing `return 0` shares the exit.
 *
 * symbols:
 *   func_021EFCE4  0x021EFCE4  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

void *func_021EFCE4(char *arg0, int arg1);

int func_021EFAD8(char *a, u32 b, u32 c)
{
    u32 n;
    u32 i;

    if (func_021EFCE4(a, b) != 0) {
        n = *(u32 *)(a + 0x128 + b * 4);
        if (n < 6) {
            for (i = 0; i < n; i++) {
                if (c == *(u32 *)(a + b * 0x18 + i * 4 + 0x68))
                    return 0;
            }
            ((u32 *)(a + b * 0x18 + 0x68))[n] = c;
            *(u32 *)(a + 0x128 + b * 4) = n + 1;
            return 1;
        }
    }
    return 0;
}
