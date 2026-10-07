/*
 * function: func_0218A528
 * address:  0x0218A528
 * packet:   pkt_0218A528
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   D_0218A7C0     0x0218A7C0  data
 */

#include "../../../matched/include/G_Slot.h"

typedef unsigned char u8;

typedef struct {
    u8 id[4];
    u8 ref[4];
    void *obj[4];
} Slot;

extern struct Slot *D_0218A7C0;
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void func_0218A528(u8 *a)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (D_0218A7C0->id[i] == a[0x45]) {
            D_0218A7C0->ref[i]--;
            if (D_0218A7C0->ref[i] == 0) {
                D_0218A7C0->id[i] = 0xff;
                func_020307B0(D_0218A7C0->obj[i]);
                D_0218A7C0->obj[i] = 0;
            }
            return;
        }
    }
}
