/*
 * function: EVENT_FIELD_PROCLINK_IsNetConnected
 * address:  0x0216210C
 * packet:   pkt_0216210C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0200FB24  0x0200FB24  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_0200FB24(void);

int EVENT_FIELD_PROCLINK_IsNetConnected(int a0)
{

    a0 = func_0200FB24();
loc_02162112:
    if (a0 == 0) goto loc_0216211A;
loc_02162116:
a0 = 1;
    return a0;
loc_0216211A:
a0 = 0;
    return a0;}
