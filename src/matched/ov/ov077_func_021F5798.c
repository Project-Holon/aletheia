/*
 * function: func_021F5798
 * address:  0x021F5798
 * packet:   pkt_ov077_021F5798
 * region:   ov077
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;

int func_021F5798(u8 *p)
{
    int i;
    int n;
    int cnt;

    (*(void (**)(u8 *))(p + 0x3070))(p);
    n = *(u16 *)(p + 0x3008) * *(u16 *)(p + 0x300A);
    cnt = 0;
    for (i = 0; i < n; i++) {
        u8 *e = p + i * 64;
        int ok = 0;

        if (*(int *)(e + 0x38) == 0) {
            if (*(int *)(e + 0x34) != 0) {
                int (*fn)(u8 *) = *(int (**)(u8 *))(e + 0x3c);

                if (fn == 0)
                    *(int *)(e + 0x38) = 1;
                else
                    ok = fn(e);
            }
        } else {
            ok = 1;
        }
        if (ok)
            cnt++;
    }
    return cnt >= n;
}
