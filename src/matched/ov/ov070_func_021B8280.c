/*
 * function: ITEMMENU_BuildActionList
 * address:  0x021B8280
 * packet:   pkt_ov070_021B8280
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ITEMMENU_GetCursorIndex  0x021B61B8  thumb  ov070
 *   ITEMMENU_GetSlot  0x021B616C  thumb  ov070
 *   FILE_UTIL_CreateArcTool0F34  0x02020F34  thumb
 *   ITEMMENU_CheckItemFilter  0x021B822C  thumb  ov070
 *   ITEMMENU_IsCheckModeAllowed  0x021B8F68  thumb  ov070
 *   FILE_UTIL_Get_1014  0x02021014  thumb
 *   PALANM_IsOutsideReservedIdRange  0x020213E0  thumb
 *   ITEMMENU_IsItemRegistered  0x021B83A0  thumb  ov070
 *   func_020307B0  0x020307B0  arm
 */
#include "../include/Obj00002.h"

typedef unsigned char  u8;
extern int ITEMMENU_GetCursorIndex(u8 *p);
extern void *ITEMMENU_GetSlot(u8 *p, int i);
extern void *FILE_UTIL_CreateArcTool0F34(unsigned int item, unsigned int which, unsigned int heap);
struct Obj;
extern void ITEMMENU_CheckItemFilter(struct Obj *o, void *rec, unsigned short *p, u8 *out);
extern int ITEMMENU_IsCheckModeAllowed(char *p, int value);
typedef unsigned short u16;
typedef unsigned int   u32;
struct Rec;
extern u32 FILE_UTIL_Get_1014(struct Rec *p, u32 sel);
extern u32 PALANM_IsOutsideReservedIdRange(u16 v);
extern int ITEMMENU_IsItemRegistered(char *p, int value);
extern u32 func_020307B0(void *p);

void ITEMMENU_BuildActionList(struct Obj *p, unsigned char *q)
{
    unsigned short *e = ITEMMENU_GetSlot((u8 *)p, ITEMMENU_GetCursorIndex((u8 *)p));
    if (e != 0 && *e != 0) {
        void *h = FILE_UTIL_CreateArcTool0F34(*e, 0, ((struct Obj00002 *)p)->f544);
        unsigned char v = ((struct Obj00002 *)p)->f80C;
        ITEMMENU_CheckItemFilter(p, h, e, q);
        if (ITEMMENU_IsCheckModeAllowed((char *)p, v) == 0 && q[0] != 2) {
            q[0] = 0xFF;
        }
        if (FILE_UTIL_Get_1014(h, 3) == 0) {
            if (PALANM_IsOutsideReservedIdRange(*e) == 1) {
                q[1] = 6;
            }
            if (v != 2) {
                q[2] = 3;
            }
        }
        if (FILE_UTIL_Get_1014(h, 4) != 0) {
            if (ITEMMENU_IsItemRegistered((char *)p, *e) == 1) {
                q[2] = 5;
            } else {
                q[2] = 4;
            }
        }
        q[3] = 8;
        func_020307B0(h);
    }
}
