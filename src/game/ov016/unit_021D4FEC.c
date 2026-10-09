/*
 * file:     unit_021D4FEC.c
 * function: func_021D4FEC
 * address:  0x021D4FEC
 * packet:   pkt_021D4FE0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021D4FEC   0x021D4FEC  arm
 *
 * Byte at +0x0c of the argument.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021D4FEC.c \
 *       --func func_021D4FEC --addr 0x021D4FEC --region ov016 --cc dsi/1.1p1 --arm
 */
#include "../../matched/include/Obj18403.h"

unsigned char func_021D4FEC(char *p)
{
    return ((struct Obj18403 *)p)->fC;
}
