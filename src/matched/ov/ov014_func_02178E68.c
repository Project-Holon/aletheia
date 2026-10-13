/*
 * function: DWCi_MOV_WH_GetLastError
 * address: 0x02178E68
 * packet: pkt_ov014_02178E68
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gWihWork 0x021797A8 data a4
 */

#include "../include/G_S.h"

typedef unsigned char u8;
extern struct S *gWihWork;
int DWCi_MOV_WH_GetLastError(void) { if (((u8 *)gWihWork) != 0) return *(int *)(((u8 *)gWihWork) + 0x1E98); return 0; }
