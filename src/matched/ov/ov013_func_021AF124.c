/*
 * function: VCT_MAIN_StartStream
 * address: 0x021AF124
 * packet: pkt_ov013_021AF124
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gVctWork 0x021B3C80 data ov013 a4
 *   func_02073A60 0x02073A60 arm
 */

#include "../include/G_Work.h"

typedef unsigned char u8;
extern struct Work *gVctWork;
struct A;
extern void func_02073A60(struct A *);
void VCT_MAIN_StartStream(void) { func_02073A60((struct A *)(((u8 *)gVctWork) + 0x19B8)); }
