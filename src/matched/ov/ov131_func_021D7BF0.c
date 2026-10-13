/*
 * function: P_STA_INFO_FreeResources
 * address: 0x021D7BF0
 * packet: pkt_ov131_021D7BF0
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   P_STA_INFO_DeleteWindows 0x021D7E84 thumb ov131
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj02844.h"

extern void P_STA_INFO_DeleteWindows(void *p, void **q);
struct Rec;
extern unsigned int MSGDATA_Delete(struct Rec *rec);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void P_STA_INFO_FreeResources(void *a, unsigned char *p)
{
    if (((struct Obj02844 *)p)->f4 == 1) P_STA_INFO_DeleteWindows(a, (void **)p);
    MSGDATA_Delete(((struct Obj02844 *)p)->f38);
    MSGDATA_Delete(((struct Obj02844 *)p)->f3C);
    MSGDATA_Delete(((struct Obj02844 *)p)->f40);
    MSGDATA_Delete(((struct Obj02844 *)p)->f44);
    MSGDATA_Delete(((struct Obj02844 *)p)->f48);
    func_020307B0(((struct Obj02844 *)p)->f50);
    func_020307B0(((struct Obj02844 *)p)->f58);
    func_020307B0(((struct Obj02844 *)p)->f60);
    func_020307B0(((struct Obj02844 *)p)->f68);
}
