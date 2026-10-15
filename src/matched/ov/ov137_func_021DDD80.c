/*
 * function: GURU2_RECEIPT_StateQuitMenu
 * address: 0x021DDD80
 * packet: pkt_ov137_021DDD80
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
 *   GURU2_COMM_Send 0x021DCBC4 thumb ov137
 *   UNION_APP_GetMemberEntry 0x02184180 thumb ov022
 *   WORDSET_SetSlotMyStatus 0x0201F02C thumb
 */
#include "../include/Obj04538.h"
#include "../include/Obj14215.h"
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct WordSet;
extern int GURU2_RECEIPT_GetMemberCount(void *p);
extern unsigned GURU2_RECEIPT_GetKeyTrg(void);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void GURU2_RECEIPT_Noop(char *);
extern u32 BMP_MENU_ProcessYesNo(u8 *p);
extern void *GURU2_RECEIPT_GetUnionApp(u8 *p);
extern void UNION_APP_Open(u8 *p);
extern void GURU2_COMM_Send(void *p, u32 a, const void *b, u32 c);
extern char *UNION_APP_GetMemberEntry(unsigned char *p, int i);
extern void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);
int GURU2_RECEIPT_StateQuitMenu(char *p, int state) {
    char *q = *(char * *)&((struct Obj04538 *)p)->f10;
    unsigned result;
    if (((struct Obj14215 *)q)->f2C != GURU2_RECEIPT_GetMemberCount(p) || ((struct Obj14215 *)q)->f30 != 0) {
        if (GURU2_RECEIPT_GetKeyTrg() & 0xc3) GFL_USE_PlaySeDefaultVolume(0x54c);
        GURU2_RECEIPT_Noop(p);
        return state;
    }
    result = BMP_MENU_ProcessYesNo(((struct Obj04538 *)p)->fE8);
    if (result != -1) {
        if (result == -2) {
            ((struct Obj04538 *)p)->f118 = 0;
            UNION_APP_Open(GURU2_RECEIPT_GetUnionApp((u8 *)p));
        } else {
            ((struct Obj04538 *)p)->f118 = 0xd;
            GURU2_COMM_Send(((struct Obj04538 *)p)->f10, 0x2802, 0, 0);
            WORDSET_SetSlotMyStatus(((struct Obj04538 *)p)->f3C, 0, UNION_APP_GetMemberEntry(GURU2_RECEIPT_GetUnionApp((u8 *)p), 0));
        }
        ((struct Obj04538 *)p)->fE8 = 0;
    }
    GURU2_RECEIPT_Noop(p);
    return state;
}
