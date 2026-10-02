/*
 * function: func_0215F52C
 * address:  0x0215F52C
 * packet:   pkt_ov010_0215F52C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Draws six distinct values from 0..0x33 (random pick among the ones not
 * yet taken) and writes each plus 0x37 to six script-variable slots.
 *
 * Keys: the work locals live in a nested block opened after the six
 * func_02159AE8 calls, so `u16 buf[6] = {0}` is emitted there (at function
 * scope the initializer lands above the calls) and its stores go through
 * the same `add r4, sp, #0x18` the search loops index. `u16 n = 0x34`
 * declared before buf schedules `movs r7, #0x34` ahead of the zero stores.
 * EXACT* only for the 2-byte pad after the function (218 of 220).
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_020056EC  0x020056EC  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern u16 *func_02159AE8(void *c, void *vm);
extern u32 func_020056EC(u32 n);

int func_0215F52C(void *c, void *vm)
{
    u16 *p0, *p1, *p2, *p3, *p4, *p5;

    func_0215A5F4(vm);
    p0 = func_02159AE8(c, vm);
    p1 = func_02159AE8(c, vm);
    p2 = func_02159AE8(c, vm);
    p3 = func_02159AE8(c, vm);
    p4 = func_02159AE8(c, vm);
    p5 = func_02159AE8(c, vm);
    {
        u16 n = 0x34;
        u16 buf[6] = {0};
        int i, v, j;
        s16 r;

        for (i = 0; i < 6; i++) {
            r = func_020056EC(n);
            for (v = 0; v < 0x34; v++) {
                for (j = 0; j < i; j++) {
                    if (buf[j] == v)
                        break;
                }
                if (j == i) {
                    if (--r < 0) {
                        buf[i] = v;
                        break;
                    }
                }
            }
            n--;
        }
        *p0 = buf[0] + 0x37;
        *p1 = buf[1] + 0x37;
        *p2 = buf[2] + 0x37;
        *p3 = buf[3] + 0x37;
        *p4 = buf[4] + 0x37;
        *p5 = buf[5] + 0x37;
    }
    return 0;
}
