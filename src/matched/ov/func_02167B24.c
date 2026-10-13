/*
 * function: func_02167B24
 * address:  0x02167B24
 * packet:   pkt_02167B24
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   GFL_NET_StartTimingSync  0x0203D594  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Entry;

extern struct Entry *func_020399A8(void);
extern int GFL_NET_StartTimingSync();

int func_02167B24(int a0)
{
    int a1;
    int t4;
    struct Entry *e;

t4 = a0 + 0;
    e = func_020399A8();
loc_02167B2C:
a1 = t4 + 0;
    a0 = GFL_NET_StartTimingSync(e, a1);
loc_02167B32:
    return a0;}
