/*
 * function: GURU2_RECEIPT_HandleKeys
 * address: 0x021DD80C
 * packet: pkt_ov137_021DD80C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_RECEIPT_GetKeyTrg 0x021DE7F4 thumb ov137
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   GURU2_RECEIPT_GetMemberCount 0x021DE354 thumb ov137
 *   GURU2_RECEIPT_GetUnionApp 0x021DCF50 thumb ov137
 *   UNION_APP_Close 0x02184114 thumb ov022
 *   UNION_APP_GetMemberCount 0x021841A4 thumb ov022
 *   UNION_APP_Open 0x02184134 thumb ov022
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   GURU2_RECEIPT_PrintMessage 0x021DE4B4 thumb ov137
 *   GURU2_RECEIPT_SetPendingState 0x021DD93C thumb ov137
 */
#include "../include/Obj06534.h"
#include "../include/Obj08211.h"
#include "../include/Obj23713.h"
#include "../include/Obj23714.h"
extern unsigned GURU2_RECEIPT_GetKeyTrg(void);
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern int GURU2_RECEIPT_GetMemberCount(void *p);
extern void *GURU2_RECEIPT_GetUnionApp(u8 *p);
extern int UNION_APP_Close(unsigned char *p);
extern int UNION_APP_GetMemberCount(unsigned char *p);
extern void UNION_APP_Open(u8 *p);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void GURU2_RECEIPT_PrintMessage(char *,int,int);
extern void GURU2_RECEIPT_SetPendingState(char *,int);
void GURU2_RECEIPT_HandleKeys(char *p) {
    char *q;
    if (GURU2_RECEIPT_GetKeyTrg()&1) {
        if (GFL_NET_SYSTEM_GetCurrentAid()==0) {
            q=*(char * *)&((struct Obj06534 *)p)->f10;
            if (((struct Obj08211 *)q)->f2C==GURU2_RECEIPT_GetMemberCount(p) && ((struct Obj08211 *)q)->f30==0) {
                if (UNION_APP_Close(GURU2_RECEIPT_GetUnionApp((u8 *)p))) {
                    GFL_USE_PlaySeDefaultVolume(0x54c);
                    GURU2_RECEIPT_PrintMessage(p,3,0);
                    GURU2_RECEIPT_SetPendingState(p,22);
                }
            } else GFL_USE_PlaySeDefaultVolume(0x548);
        }
    } else if (GURU2_RECEIPT_GetKeyTrg()&2) {
        if (GFL_NET_SYSTEM_GetCurrentAid()!=0) {
            if (((struct Obj23713 *)(*(char * *)&((struct Obj06534 *)p)->f10))->f28==0) {
                GURU2_RECEIPT_PrintMessage(p,4,0);
                GURU2_RECEIPT_SetPendingState(p,4);
            } else GFL_USE_PlaySeDefaultVolume(0x548);
        } else {
            q=*(char * *)&((struct Obj06534 *)p)->f10;
            if (((struct Obj08211 *)q)->f2C==UNION_APP_GetMemberCount(GURU2_RECEIPT_GetUnionApp((u8 *)p)) && ((struct Obj08211 *)q)->f30==0) {
                if (UNION_APP_Close(GURU2_RECEIPT_GetUnionApp((u8 *)p))) {
                    GURU2_RECEIPT_PrintMessage(p,4,0);
                    GURU2_RECEIPT_SetPendingState(p,4);
                    GFL_USE_PlaySeDefaultVolume(0x551);
                }
            } else GFL_USE_PlaySeDefaultVolume(0x548);
        }
    } else {
        if (((struct Obj06534 *)p)->f4808==0 && GFL_NET_SYSTEM_GetCurrentAid()==0 &&
            ((struct Obj23714 *)(*(char * *)&((struct Obj06534 *)p)->f10))->f2C==UNION_APP_GetMemberCount(GURU2_RECEIPT_GetUnionApp((u8 *)p)))
            UNION_APP_Open(GURU2_RECEIPT_GetUnionApp((u8 *)p));
    }
}
