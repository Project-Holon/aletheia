/*
 * function: WIFICLUB_SetOwnStatusAndPublish
 * address: 0x021C18C8
 * packet: pkt_ov099_021C18C8
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFICLUB_CopyZeroToDeviceAddr 0x021C282C thumb ov099
 *   DWC_RAP_GetTargetFriendIndex 0x02156A3C thumb ov009
 *   func_02009B80 0x02009B80 thumb
 *   WIFICLUB_SetOwnStatusKindPhase 0x021C1908 thumb ov099
 *   WIFICLUB_PublishOwnStatus 0x021BE6E4 thumb ov099
 */
#include "../include/Obj00008.h"
typedef unsigned char u8;
extern int WIFICLUB_CopyZeroToDeviceAddr(u8 *);
extern int DWC_RAP_GetTargetFriendIndex(void);
struct Sub020097BCObj;
extern void func_02009B80(struct Sub020097BCObj *obj, int i);
extern void WIFICLUB_SetOwnStatusKindPhase(char *, int, int);
extern void WIFICLUB_PublishOwnStatus(char *);
void WIFICLUB_SetOwnStatusAndPublish(char *p, int kind, int value)
{
    if (*(u8 * *)&((struct Obj00008 *)p)->f8 != 0) {
        if (kind == 1 && value == 2) WIFICLUB_CopyZeroToDeviceAddr(*(u8 * *)&((struct Obj00008 *)p)->f8);
        if (kind == 4 && value < 3) func_02009B80(((struct Obj00008 *)p)->f4, DWC_RAP_GetTargetFriendIndex());
        WIFICLUB_SetOwnStatusKindPhase(p, kind, value);
        WIFICLUB_PublishOwnStatus(p);
    }
}
