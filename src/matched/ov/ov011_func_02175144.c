/*
 * function: INTRUDE_COMM_LookupZonePair
 * address:  0x02175144
 * packet:   pkt_ov011_02175144
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gIntrudeCommZonePairs  0x02176AA0  data ov011 a2
 */
#include "../include/Obj02670.h"

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Ent {
    u16 a;
    u16 b;
    u16 c;
} Ent;

extern Ent gIntrudeCommZonePairs[8];

int INTRUDE_COMM_LookupZonePair(u16 v, u8 *out)
{
    int i;
    u8 k;

    ((struct Obj02670 *)out)->f0 = v;
    for (i = 0; i < 8; i++) {
        if (v == gIntrudeCommZonePairs[i].a) {
            k = 0;
        } else if (v == gIntrudeCommZonePairs[i].b) {
            k = 1;
        } else {
            continue;
        }
        out[2] = k;
        out[3] = i;
        return 1;
    }
    out[3] = 0xff;
    return 0;
}
