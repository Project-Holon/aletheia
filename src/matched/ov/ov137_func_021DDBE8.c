/*
 * function: GURU2_RECEIPT_StateCancelMenu
 * address: 0x021DDBE8
 * packet: pkt_ov137_021DDBE8
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_RECEIPT_GetMemberCount 0x021DE354 thumb ov137
 *   GURU2_RECEIPT_GetKeyTrg 0x021DE7F4 thumb ov137
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   GURU2_RECEIPT_Noop 0x021DD924 thumb ov137
 *   BMP_MENU_ProcessYesNo 0x0201FEBC thumb
 *   GURU2_RECEIPT_GetUnionApp 0x021DCF50 thumb ov137
 *   UNION_APP_Open 0x02184134 thumb ov022
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 */
#include "../include/Obj05426.h"
#include "../include/Obj14212.h"
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern int GURU2_RECEIPT_GetMemberCount(void *p);
extern unsigned GURU2_RECEIPT_GetKeyTrg(void);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void GURU2_RECEIPT_Noop(char *);
extern u32 BMP_MENU_ProcessYesNo(u8 *p);
extern void *GURU2_RECEIPT_GetUnionApp(u8 *p);
extern void UNION_APP_Open(u8 *p);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
int GURU2_RECEIPT_StateCancelMenu(char *p, int state) {
    char *q = *(char * *)&((struct Obj05426 *)p)->f10;
    unsigned result;
    if (((struct Obj14212 *)q)->f2C != GURU2_RECEIPT_GetMemberCount(p) || ((struct Obj14212 *)q)->f30 != 0) {
        if (GURU2_RECEIPT_GetKeyTrg() & 0xc3) GFL_USE_PlaySeDefaultVolume(0x548);
        GURU2_RECEIPT_Noop(p);
        return state;
    }
    result = BMP_MENU_ProcessYesNo(((struct Obj05426 *)p)->fE8);
    if (result != -1) {
        if (result == -2) {
            UNION_APP_Open(GURU2_RECEIPT_GetUnionApp((u8 *)p));
            ((struct Obj05426 *)p)->f118 = 0;
        } else {
            if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
                ((struct Obj05426 *)p)->f118 = 0x18;
                ((struct Obj05426 *)p)->f4812 = GURU2_RECEIPT_GetMemberCount(p);
            }
        }
        ((struct Obj05426 *)p)->fE8 = 0;
    }
    GURU2_RECEIPT_Noop(p);
    return state;
}
