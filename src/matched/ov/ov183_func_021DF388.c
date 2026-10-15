/*
 * function: func_021DF388
 * address: 0x021DF388
 * packet: pkt_ov183_021DF388
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two zero alignment bytes at 0x021DF3DA
 * symbols:
 *   func_021DF5B8 0x021DF5B8 thumb ov183
 *   BR_UTIL_GetListMenuField 0x021FCE0C thumb ov186
 *   BR_UTIL_GetListItemBitmap 0x021FCDE8 thumb ov186
 *   BMP_Delete 0x020437AC arm
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   BR_UTIL_DeleteListMenu 0x021FCC80 thumb ov186
 *   BMP_MENUWORK_Delete 0x0201F868 thumb
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj02522.h"
typedef unsigned short u16;
extern void func_021DF5B8(char *);
struct Obj020437AC;
struct WordSet;
extern int BR_UTIL_GetListMenuField(char *p, unsigned field);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 BR_UTIL_GetListItemBitmap(u8 *p, u16 i);
extern void BMP_Delete(struct Obj020437AC *p);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern void BR_UTIL_DeleteListMenu(char *p);
extern u32 BMP_MENUWORK_Delete(void *p);
extern void MI_CpuFill8(void *, int, unsigned int);
void func_021DF388(char *p)
{
    unsigned int i;
    func_021DF5B8(p);
    for (i = 0; i < BR_UTIL_GetListMenuField(((struct Obj02522 *)p)->f4, 3); i++) {
        BMP_Delete((struct Obj020437AC *)BR_UTIL_GetListItemBitmap(((struct Obj02522 *)p)->f4, i));
    }
    WORDSET_DeleteStrbufED04(((struct Obj02522 *)p)->f8);
    BR_UTIL_DeleteListMenu(((struct Obj02522 *)p)->f4);
    BMP_MENUWORK_Delete(((struct Obj02522 *)p)->f0);
    MI_CpuFill8(p, 0, 0xD4);
}
