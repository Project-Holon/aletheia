/*
 * function: func_0217BA48
 * address: 0x0217BA48
 * packet: pkt_ov019_0217BA48
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02012934 0x02012934 thumb
 *   func_0201A090 0x0201A090 thumb
 */
#include "../include/Obj09409.h"
#include "../include/Obj19403.h"
struct BigObj;
extern void *func_02012934(const struct BigObj *p);
extern int func_0201A090(void *, void *, unsigned int *);
int func_0217BA48(char *p, unsigned int *mask)
{
    void *party;
    *mask = 0;
    party = func_02012934(((struct Obj19403 *)(*(char * *)&((struct Obj09409 *)p)->f0))->f8);
    return func_0201A090(((struct Obj09409 *)p)->f352C, party, mask);
}
