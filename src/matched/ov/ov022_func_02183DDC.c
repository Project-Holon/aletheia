/*
 * function: UNION_APP_ConfirmJoins
 * address:  0x02183DDC
 * packet:   pkt_ov022_02183DDC
 * region:   ov022
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00660.h"

typedef unsigned char u8;
typedef unsigned int u32;

typedef void (*Cb)(int idx, u8 *ent, u32 arg);

void UNION_APP_ConfirmJoins(u8 *s)
{
    int i;
    u32 m;
    u8 *ents;
    Cb cb;

    if (s[7] != 0) {
        i = 0;
        ents = s + 0x2c;
        for (; i < 5; i++) {
            m = 1 << i;
            if (s[7] & m) {
                if ((s[0xe] & m) && (s[4] & m)) {
                    s[4] ^= (u8)m;
                    s[1] |= (u8)m;
                    cb = *(Cb *)&((struct Obj00660 *)s)->fF4;
                    if (cb != 0) {
                        cb((u8)i, ents + i * 0x28, ((struct Obj00660 *)s)->fFC);
                    }
                    s[0x10] = 0xff;
                }
                s[7] = s[7] ^ (u8)m;
            }
        }
    }
}
