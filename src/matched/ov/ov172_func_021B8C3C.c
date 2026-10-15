/*
 * function: CTVT_TALK_Create
 * address: 0x021B8C3C
 * packet: pkt_ov172_021B8C3C
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   CTVT_MIC_Create 0x021B9F9C thumb ov172
 *   MIi_CpuCopy16 0x02082A60 arm
 *   d_021C7200 0x021C7200 data a4
 */
#include "../include/Obj04552.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const char d_021C7200[];
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void *CTVT_MIC_Create(u32);
extern void MIi_CpuCopy16(const void *, void *, u32);
char *CTVT_TALK_Create(char *unused, u16 heap)
{
    char *q;
    u8 i;
    q = func_02030734(heap, 0xac, 1, d_021C7200, 0xd7);
    ((struct Obj04552 *)q)->f10 = CTVT_MIC_Create(heap);
    ((struct Obj04552 *)q)->f1C = func_02030734(heap, 0x808, 1, d_021C7200, 0xda);
    ((struct Obj04552 *)q)->f20 = ((struct Obj04552 *)q)->f1C;
    *(char * *)&((struct Obj04552 *)q)->f24 = *(char * *)&((struct Obj04552 *)q)->f1C + 8;
    ((struct Obj04552 *)q)->fD = 4;
    MIi_CpuCopy16((void *)0x05000420, q + 0x5a, 32);
    for (i = 0; i < 16; i++) *(u16 *)(q + i * 2 + 0x3a) = 32767;
    return q;
}
