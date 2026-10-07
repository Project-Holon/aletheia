/*
 * function: func_0272FD7C
 * address:  0x0272FD7C
 * packet:   twl_audio
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   data_02732EFC 0x02732EFC data twl
 */

#include "../include/G_twl_data_02732EFC.h"

struct Entry {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
};

extern struct G_twl_data_02732EFC data_02732EFC[];

void func_0272FD7C(void) {
    register struct Entry *e = ((struct Entry *)data_02732EFC);
    register int i = 0;
    do {
        e->unk0 = 1;
        e->unk4 = 0;
        e->unk8 = 0x40000;
        i++;
        e->unkC = -1;
        e++;
    } while (i <= 3);
}
