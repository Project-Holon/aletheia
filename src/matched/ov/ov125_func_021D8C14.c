/*
 * function: GDS_SOCKET_CopySslTemplate
 * address: 0x021D8C14
 * packet: pkt_ov125_021D8C14
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_0208CC78 0x0208CC78 arm
 *   GDS_SOCKET_Alloc 0x021D7C7C arm ov125
 *   STD_CopyString 0x0208CADC arm
 *   gGdsSslTemplatePtr 0x021DAA88 data a4
 */
#include "../include/Obj14013.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *gGdsSslTemplatePtr;
extern void MI_CpuCopy8(const void *, void *, u32);
extern u32 func_0208CC78(const char *);
extern char *GDS_SOCKET_Alloc(u32);
extern char *STD_CopyString(char *destp, const char *srcp);
void GDS_SOCKET_CopySslTemplate(const char *s, u8 *p)
{
    MI_CpuCopy8(gGdsSslTemplatePtr, p, 0x830);
    if (s) {
        *(char * *)&((struct Obj14013 *)p)->f800 = GDS_SOCKET_Alloc(func_0208CC78(s) + 1);
        STD_CopyString(*(char * *)&((struct Obj14013 *)p)->f800, s);
    }
}
