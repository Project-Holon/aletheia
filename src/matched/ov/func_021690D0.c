/*
 * function: func_021690D0
 * address:  0x021690D0
 * packet:   pkt_021690D0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02008B14  0x02008B14  thumb
 */
#include "../include/Obj17736.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;
struct Sub02008AECSession;

extern void *func_02012EBC(struct Big *p);
extern struct Sub02008AECSession *func_02008B14(void *sys);

int func_021690D0(int a0)
{
    void *big;
    struct Sub02008AECSession *s;


    big = func_02012EBC((struct Big *)a0);
loc_021690D6:
    s = func_02008B14(big);
loc_021690DA:
a0 = ((struct Obj17736 *)s)->f8;
    return a0;}
