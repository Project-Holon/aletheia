/*
 * function: FLDMMDL_AddMmdlHeaderList
 * address: 0x0216CEAC
 * packet: pkt_ov010_0216CEAC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: zero alignment halfword at 0x0216CEE2, then labelled 0x0216CEE4.
 * interface: E42C forwards r0/r1 unchanged; caller reads r0, so extern returns int.
 * symbols:
 *   FLDMMDL_HeaderIsEventIdNone 0x0216E418 thumb ov010
 *   FLDMMDL_CheckEventFlagBit 0x0216E42C thumb ov010
 *   FLDMMDL_AddMmdlCore 0x0216CDC4 thumb ov010
 */
#include "../include/Obj19117.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int FLDMMDL_HeaderIsEventIdNone(void *a);
extern unsigned int FLDMMDL_CheckEventFlagBit(void *bitmap, int id);
extern u8 *FLDMMDL_AddMmdlCore(u32,u8 *,u32,u32);
void FLDMMDL_AddMmdlHeaderList(u32 a,u8 *p,u32 b,u32 n,u32 c) {
    do {
        if(FLDMMDL_HeaderIsEventIdNone(p)==1 || FLDMMDL_CheckEventFlagBit((void *)c,((struct Obj19117 *)p)->f8)==0)
            FLDMMDL_AddMmdlCore(a,p,b,c);
        p+=0x24;
    } while(--n);
}
