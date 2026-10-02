/*
 * function: func_02169138
 * address:  0x02169138
 * packet:   pkt_02169138
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02008B14  0x02008B14  thumb
 *   func_02008BD0  0x02008BD0  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;
struct Sub02008AECSession;

extern void *func_02012EBC(struct Big *p);
extern struct Sub02008AECSession *func_02008B14(void *sys);
extern int func_02008BD0();

int func_02169138(int a0)
{
    void *big;
    struct Sub02008AECSession *s;


    big = func_02012EBC((struct Big *)a0);
loc_0216913E:
    s = func_02008B14(big);
loc_02169142:
    a0 = func_02008BD0(s);
loc_02169146:
    return a0;}
