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
#include "../include/Obj07712.h"
#include "../include/Obj13217.h"

typedef unsigned char u8;
typedef unsigned short u16;

int func_021F5798(u8 *p)
{
    int i;
    int n;
    int cnt;

    (*(void (**)(u8 *))(p + 0x3070))(p);
    n = ((struct Obj13217 *)p)->f3008 * ((struct Obj13217 *)p)->f300A;
    cnt = 0;
    for (i = 0; i < n; i++) {
        u8 *e = p + i * 64;
        int ok = 0;

        if (((struct Obj07712 *)e)->f38 == 0) {
            if (((struct Obj07712 *)e)->f34 != 0) {
                int (*fn)(u8 *) = *(int (**)(u8 *))(e + 0x3c);

                if (fn == 0)
                    ((struct Obj07712 *)e)->f38 = 1;
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
