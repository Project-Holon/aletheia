/*
 * function: UNION_MSG_SelectMenu
 * address:  0x0217F310
 * packet:   pkt_ov019_0217F310
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02034714  0x02034714  arm
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   FIELD_MSGBG_IsPrintQueFinished  0x0219049C  thumb  ov021
 *   FIELD_MSGBG_MenuFuncMain  0x021909E4  thumb  ov021
 *   d_021807F8     0x021807F8  data   ov019 a4
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12529.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02034714(const char *a, u32 b, const char *c);
struct Handle;
extern u32 FIELDMAP_GetMsgBg(u8 *p);
extern int FIELD_MSGBG_IsPrintQueFinished(u8 *p);
extern int FIELD_MSGBG_MenuFuncMain(struct Handle *h);
extern u32 d_021807F8[];

int UNION_MSG_SelectMenu(char *p, u32 a1)
{
    u32 h = FIELDMAP_GetMsgBg((u8 *)a1);

    if (h == 0) {
        func_02034714((const char *)d_021807F8, 0, (const char *)d_021807F8);
    }
    if (h != 0 && FIELD_MSGBG_IsPrintQueFinished((u8 *)h) == 0) {
        return -1;
    }
    if (((struct Obj12529 *)p)->f2810 == 0) {
        func_02034714((const char *)d_021807F8, 0, (const char *)d_021807F8);
    }
    return FIELD_MSGBG_MenuFuncMain((struct Handle *)(((struct Obj12529 *)p)->f2810));
}
