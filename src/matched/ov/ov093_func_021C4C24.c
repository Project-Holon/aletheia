/*
 * function: func_021C4C24
 * address: 0x021C4C24
 * packet: pkt_ov093_021C4C24
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * The extent continues into the existing SDK CallbackForJpeg at 021C4C40.
 * DWC_StartUtilityEx takes two full-word payloads; the original passes
 * the callback address and p unchanged in r0/r1.
 * symbols:
 *   func_021EF934 0x021EF934 thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021C4C40 0x021C4C40 thumb ov093
 */
#include "../include/Obj21096.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021EF934(int, int);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021C4C40(int, void *);
void func_021C4C24(u8 *p)
{
    func_021EF934((int)func_021C4C40, (int)p);
    func_021CD4B0(((struct Obj21096 *)p)->fC, 47, 0);
}
