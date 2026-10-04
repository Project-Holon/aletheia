/*
 * function: func_021A2254
 * address:  0x021A2254
 * packet:   pkt_ov021_021A2254
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A2BC4  0x021A2BC4  thumb  ov021
 *   _s32_div_f     0x0209C0A4  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_021A2BC4(u32 a);

void func_021A2254(u8 *p, void (*fn)(u8 *, int, u32), int n, int m, int k, u16 w)
{
    int j;
    u8 *cur;
    int cnt;
    int i;
    u8 *next;

    fn(p, n, w);
    cnt = 0;
    cur = *(u8 **)(p + 0x774);
    if (cur == 0) {
        return;
    }
    next = *(u8 **)(cur + 0x34);
    i = 0;
    if (n <= 0) {
        return;
    }
    do {
        j = 0;
        if (cnt > 0) {
            do {
                ((void (*)(u8 *))(*(u32 *)(*(u32 *)(p + 0x20) + 0x48)))(cur);
                if (func_021A2BC4((u32)cur) == 0) {
                    break;
                }
                j++;
            } while (j < cnt);
        }
        cur = next;
        next = *(u8 **)(cur + 0x34);
        if (i >= m) {
            if (i % m == 0) {
                cnt += k;
            }
        }
        if (cur == *(u8 **)(p + 0x774)) {
            break;
        }
        i++;
    } while (i < n);
}
