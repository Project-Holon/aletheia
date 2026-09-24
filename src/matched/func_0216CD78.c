/*
 * function: func_0216CD78
 * address:  0x0216CD78
 * packet:   pkt_0216CD78
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0219C624  0x0219C624  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0219C624();

int func_0216CD78(int a0, int a1)
{

a1 = *(int *)((char *)a0 + 0x24);
    if (a1 == 0) goto loc_0216CD84;
loc_0216CD80:
    a0 = func_0219C624();
loc_0216CD84:
    return a0;}
