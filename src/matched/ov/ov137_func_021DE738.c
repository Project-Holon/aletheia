/*
 * function: GURU2_RECEIPT_UpdateMemberChange
 * address: 0x021DE738
 * packet: pkt_ov137_021DE738
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: previous state at +0x4804 is read at 0x021DE764 and 0x021DE7CA.
 * symbols:
 *   GURU2_RECEIPT_GetMemberCount 0x021DE354 thumb ov137
 *   GURU2_RECEIPT_GetUnionApp 0x021DCF50 thumb ov137
 *   UNION_APP_Close 0x02184114 thumb ov022
 *   UNION_APP_GetMemberCount 0x021841A4 thumb ov022
 *   UNION_APP_GetJoinedBits 0x021841A0 thumb ov022
 *   BMP_MENU_DeleteYesNo  0x0201FEF4  thumb  arm9
 */
#include "../include/Obj00170.h"
#include "../include/Obj23737.h"
#include "../include/Obj23738.h"
typedef unsigned char u8;
typedef struct { u8 pad[0x4804]; volatile int previous; } Obj;
extern int GURU2_RECEIPT_GetMemberCount(void *);
extern void *GURU2_RECEIPT_GetUnionApp(u8 *p);
extern int UNION_APP_Close(unsigned char *p);
extern int UNION_APP_GetMemberCount(unsigned char *p);
extern unsigned char UNION_APP_GetJoinedBits(unsigned char *p);
extern void BMP_MENU_DeleteYesNo(u8 *o);
int GURU2_RECEIPT_UpdateMemberChange(Obj *obj)
{
    u8 *p = (u8 *)obj;
    int state;
    state = GURU2_RECEIPT_GetMemberCount(p);
    if (state > ((struct Obj23737 *)(*(u8 * *)&((struct Obj00170 *)p)->f10))->f2C) {
        if (UNION_APP_Close(GURU2_RECEIPT_GetUnionApp(p))) ((struct Obj00170 *)p)->f4808 = 1;
    } else ((struct Obj00170 *)p)->f4808 = 0;
    if (state == obj->previous) return 1;
    switch (state) {
    case 0: break;
    case 1:
        if ((unsigned)UNION_APP_GetMemberCount(GURU2_RECEIPT_GetUnionApp(p)) > 1 || UNION_APP_GetJoinedBits(GURU2_RECEIPT_GetUnionApp(p)) > 1) return 1;
        *(int *)&((struct Obj00170 *)p)->f118 = 17;
        if (((struct Obj00170 *)p)->fE8) {
            BMP_MENU_DeleteYesNo(((struct Obj00170 *)p)->fE8);
            ((struct Obj00170 *)p)->fE8 = 0;
        }
        return 2;
    case 2: case 3: case 4:
        if (state < obj->previous)
            ((struct Obj23738 *)(*(u8 * *)&((struct Obj00170 *)p)->f10))->f2C = (unsigned)UNION_APP_GetMemberCount(GURU2_RECEIPT_GetUnionApp(p));
        break;
    case 5: break;
    }
    obj->previous = GURU2_RECEIPT_GetMemberCount(p);
    return 1;
}
