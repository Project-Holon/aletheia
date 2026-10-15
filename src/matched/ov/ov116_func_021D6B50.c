/*
 * function: WIFI_BSUBWAY_StatusInit
 * address: 0x021D6B50
 * packet: pkt_ov116_021D6B50
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Two bytes zero alignment padding follow the compiled function.
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   MYSTATUS_Create 0x0200846C thumb
 */
#include "../include/Obj22619.h"
extern void MI_CpuFill8(void *,int,unsigned int);
extern void *MYSTATUS_Create(int);
void WIFI_BSUBWAY_StatusInit(unsigned char *a,int b) { MI_CpuFill8(a,0,0x21c); ((struct Obj22619 *)a)->f218=MYSTATUS_Create(b); }
