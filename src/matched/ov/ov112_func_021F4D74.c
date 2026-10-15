/*
 * function: MUSICAL_MCSS_FreeElemImage
 * address: 0x021F4D74
 * packet: pkt_ov112_021F4D74
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MUSICAL_MCSS_GetArcFileCount 0x021F4AA8 thumb ov112
 *   MUSICAL_MCSS_GetElemPtr 0x021F4F54 thumb ov112
 *   BILLBOARD_SetElemId 0x0204F604 arm
 *   BILLBOARD_ReleaseImageVramIfUsed 0x0204F1A0 arm
 */
#include "../include/Obj02168.h"
#include "../include/Obj10298.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u16 low:3; u16 bit3:1; u16 bit4:1; u16 rest:11; } Bits;
extern u16 MUSICAL_MCSS_GetArcFileCount(int);
extern u8 *MUSICAL_MCSS_GetElemPtr(u8 *,int);
extern void BILLBOARD_SetElemId(void *,u32,u16 *);
struct Obj0204F1A0;
extern void BILLBOARD_ReleaseImageVramIfUsed(struct Obj0204F1A0 *a0, u32 a1);
void MUSICAL_MCSS_FreeElemImage(u8 *p, u8 *e, int type, u16 id)
{
    ((struct Obj02168 *)e)->fC = MUSICAL_MCSS_GetArcFileCount(type);
    *(u8 * *)&((struct Obj02168 *)e)->f20 = MUSICAL_MCSS_GetElemPtr(*(u8 * *)&((struct Obj10298 *)p)->fC,type);
    ((struct Obj02168 *)e)->f0 = ((struct Obj02168 *)e)->f0 & ~8;
    BILLBOARD_SetElemId(((struct Obj10298 *)p)->f4,((struct Obj02168 *)e)->f8,&id);
    if (((Bits *)e)->bit4 == 1) BILLBOARD_ReleaseImageVramIfUsed(((struct Obj10298 *)p)->f4,((struct Obj02168 *)e)->f4);
    ((struct Obj02168 *)e)->f0 = ((struct Obj02168 *)e)->f0 & ~16;
    ((struct Obj02168 *)e)->f4 = id;
    ((struct Obj02168 *)e)->f0 = (((struct Obj02168 *)e)->f0 & ~1) | 1;
    ((struct Obj02168 *)e)->f0 |= 2;
}
