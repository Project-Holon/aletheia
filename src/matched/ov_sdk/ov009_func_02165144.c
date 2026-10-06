/*
 * function: func_02165144
 * address:  0x02165144
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Dispatches on whether either argument is missing.
 *
 * symbols:
 *   func_02165204  0x02165204  arm  ov009
 *   func_02165164  0x02165164  arm  ov009
 */

extern long func_02165204(int a, int b);
extern long func_02165164(void *bssid, void *essid, unsigned long option);

void func_02165144(void *a, void *b, unsigned long a2)
{
    if (a == 0 || b == 0) {
        func_02165204((int)a, (int)b);
        return;
    }

    func_02165164(a, b, a2);
}

