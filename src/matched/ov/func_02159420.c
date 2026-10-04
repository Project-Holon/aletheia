/*
 * function: func_02159420
 * address:  0x02159420
 * packet:   pkt_02159420
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02011398  0x02011398  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ring;
extern u32 func_02011398(struct Ring *r);

int func_02159420(int a0)
{

    a0 = func_02011398((struct Ring *)a0);
loc_02159426:
a0 = 0;
    return a0;}
