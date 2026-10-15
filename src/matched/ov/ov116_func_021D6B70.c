/*
 * function: WIFI_BSUBWAY_StatusDelete
 * address: 0x021D6B70
 * packet: pkt_ov116_021D6B70
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj10338.h"
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void WIFI_BSUBWAY_StatusDelete(unsigned char *a) { if(((struct Obj10338 *)a)->f218) { func_020307B0(((struct Obj10338 *)a)->f218); ((struct Obj10338 *)a)->f218=0; } }
