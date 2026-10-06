/*
 * function: func_021A1B50
 * address:  0x021A1B50
 * packet:   pkt_ov021_021A1B50
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A21B0  0x021A21B0  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct {
    u8 pad[0x20];
    u32 items[2];
} Obj021A1B50;

int func_021A21B0(u8 *a0);

int func_021A1B50(Obj021A1B50 *p)
{
    int i;

    if (p != 0) {
        for (i = 0; i < 2; i++) {
            if (func_021A21B0((u8 *)p->items[i]) == 1)
                return 1;
        }
    }
    return 0;
}
