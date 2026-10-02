/*
 * function: func_021690F0
 * address:  0x021690F0
 * packet:   pkt_021690F0
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

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;
struct Sub02008AECSession;

extern void *func_02012EBC(struct Big *p);
extern struct Sub02008AECSession *func_02008B14(void *sys);

int func_021690F0(int a0)
{
    void *big;
    struct Sub02008AECSession *s;


    big = func_02012EBC((struct Big *)a0);
loc_021690F6:
    s = func_02008B14(big);
loc_021690FA:
a0 = *(int *)((char *)s + 0x10);
    return a0;}
