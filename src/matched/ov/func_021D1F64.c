/*
 * function: EVENT_PERAP_RECORD_ResumeMmdls
 * address:  0x021D1F64
 * packet:   pkt_021D1F64
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FLDMMDL_SysResumeMove  0x0216D9E4  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18378.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern u32 *FLDMMDL_SysResumeMove(void *c);
extern void *FIELDMAP_GetMmdlSys(unsigned char *p);

int EVENT_PERAP_RECORD_ResumeMmdls(u32 a)
{
return (int)FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(GAMESYSTEM_GetFieldMap((const struct Ctx *)((struct Obj18378 *)((u8 *)(a)))->f4)));
}

