/*
 * function: FLDMMDL_HeaderIsEventIdNone
 * address: 0x0216E418
 * packet: pkt_ov010_0216E418
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj19137.h"

typedef unsigned short u16;
int FLDMMDL_HeaderIsEventIdNone(void *a) { if (((struct Obj19137 *)a)->fA==65535) return 1; return 0; }
