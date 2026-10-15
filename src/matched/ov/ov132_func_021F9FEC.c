/*
 * function: STA_ACT_AUDIENCE_Create
 * address: 0x021F9FEC
 * packet: pkt_ov132_021F9FEC
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   STA_ACT_AUDIENCE_Noop 0x021FA0D0 thumb ov132
 *   STA_ACT_AUDIENCE_SetupRecords 0x021FA0D8 thumb ov132
 *   d_021FDCC4 0x021FDCC4 data a4
 */
#include "../include/Obj08156.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void *func_02030734(unsigned, unsigned, int, const char *, u16);
extern void STA_ACT_AUDIENCE_Noop(char *);
extern void STA_ACT_AUDIENCE_SetupRecords(char *p, char *q);
extern const char d_021FDCC4[];
char *STA_ACT_AUDIENCE_Create(unsigned heap, void *a, unsigned b)
{
    u8 i = 0;
    char *p = func_02030734(heap, 0x3e4, 0, d_021FDCC4, 115);
    ((struct Obj08156 *)p)->f0 = heap;
    STA_ACT_AUDIENCE_Noop(p);
    STA_ACT_AUDIENCE_SetupRecords(p, (char *)b);
    ((struct Obj08156 *)p)->f1E8 = a;
    ((struct Obj08156 *)p)->f200 = 0;
    for (; i < 4; i++) *(int *)(p + i * 4 + 0x1ec) = 0;
    ((struct Obj08156 *)p)->f1FC = 255;
    return p;
}
