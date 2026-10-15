/*
 * function: WIFI_2DCHAR_ReleaseCells
 * address: 0x021C4010
 * packet: pkt_ov127_021C4010
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFI_2DCHAR_ReleaseBmpCells 0x021C4080 thumb ov127
 *   WIFI_2DCHAR_IsCellUsed 0x021C447C thumb ov127
 *   WIFI_2DCHAR_ReleaseCell 0x021C4424 thumb ov127
 */
#include "../include/Obj23013.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void WIFI_2DCHAR_ReleaseBmpCells(u8 *);
extern int WIFI_2DCHAR_IsCellUsed(char *, int);
extern void WIFI_2DCHAR_ReleaseCell(char *, int);
void WIFI_2DCHAR_ReleaseCells(u8 *p)
{
    int i;
    if (((struct Obj23013 *)p)->f2F4 != (u32)-1) WIFI_2DCHAR_ReleaseBmpCells(p);
    for(i=0;i<18;i++) if(WIFI_2DCHAR_IsCellUsed((char *)p,i)==1)WIFI_2DCHAR_ReleaseCell((char *)p,i);
}
