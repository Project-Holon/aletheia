/*
 * function: GURU2_RECEIPT_SetStateFromChild
 * address: 0x021DE17C
 * packet: pkt_ov137_021DE17C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_RECEIPT_GetUnionApp 0x021DCF50 thumb ov137
 *   UNION_APP_GetMemberEntry 0x02184180 thumb ov022
 *   WORDSET_SetSlotMyStatus 0x0201F02C thumb
 *   UNION_APP_GetMemberCount 0x021841A4 thumb ov022
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 */
#include "../include/Obj02868.h"
#include "../include/Obj23729.h"
#include "../include/Obj23730.h"
#include "../include/Obj23731.h"
#include "../include/Obj23732.h"
#include "../include/Obj23733.h"
typedef unsigned char  u8;
extern void *GURU2_RECEIPT_GetUnionApp(u8 *p);
typedef unsigned short u16;
typedef unsigned int   u32;
struct WordSet;
extern char *UNION_APP_GetMemberEntry(unsigned char *p, int i);
extern void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);
extern int UNION_APP_GetMemberCount(unsigned char *p);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
void GURU2_RECEIPT_SetStateFromChild(char *p, int command, int player) {
    void *target;
    if (((struct Obj02868 *)p)->f118 == 3) {
        switch (command) {
        case 1:
            target = UNION_APP_GetMemberEntry(GURU2_RECEIPT_GetUnionApp((u8 *)p), player);
            if (target != 0)
                WORDSET_SetSlotMyStatus(((struct Obj02868 *)p)->f3C, 0, target);
            ((struct Obj02868 *)p)->f118 = command;
            ((struct Obj23729 *)(*(char * *)&((struct Obj02868 *)p)->f10))->f2C = UNION_APP_GetMemberCount(GURU2_RECEIPT_GetUnionApp((u8 *)p));
            ((struct Obj23730 *)(*(char * *)&((struct Obj02868 *)p)->f10))->f30 = 0;
            return;
        case 19:
            WORDSET_SetSlotMyStatus(((struct Obj02868 *)p)->f3C, 0, UNION_APP_GetMemberEntry(GURU2_RECEIPT_GetUnionApp((u8 *)p), player));
            if (player != GFL_NET_SYSTEM_GetCurrentAid()) {
                if (GFL_NET_SYSTEM_GetCurrentAid() == 0)
                    ((struct Obj23731 *)(*(char * *)&((struct Obj02868 *)p)->f10))->f30 &= player ^ 0xffff;
                ((struct Obj02868 *)p)->f118 = command;
            }
            break;
        }
    } else {
        if (command == 1) {
            ((struct Obj23732 *)(*(char * *)&((struct Obj02868 *)p)->f10))->f30 = 0;
            ((struct Obj23733 *)(*(char * *)&((struct Obj02868 *)p)->f10))->f2C = UNION_APP_GetMemberCount(GURU2_RECEIPT_GetUnionApp((u8 *)p));
        }
    }
}
