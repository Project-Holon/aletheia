/*
 * function: func_0217BA6C
 * address: 0x0217BA6C
 * packet: pkt_ov019_0217BA6C
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0217B9CC 0x0217B9CC thumb ov019
 *   func_0217B9F4 0x0217B9F4 thumb ov019
 *   func_0201A090 0x0201A090 thumb
 */
#include "../include/Obj09409.h"
extern void *func_0217B9CC(char *);
extern void func_0217B9F4(void *);
extern int func_0201A090(void *, void *, unsigned int *);
int func_0217BA6C(char *p, unsigned int *mask)
{
    void *party;
    int result;
    party = func_0217B9CC(p);
    *mask = 0;
    if (party != 0) {
        result = func_0201A090(((struct Obj09409 *)p)->f352C, party, mask);
        func_0217B9F4(party);
    } else {
        *mask = -1;
        result = 5;
    }
    return result;
}
