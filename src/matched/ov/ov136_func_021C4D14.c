/*
 * function: func_021C4D14
 * address:  0x021C4D14
 * packet:   pkt_ov136_021C4D14
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C4D14 0x021C4D14 thumb
 *   func_021C4DA8 0x021C4DA8 thumb
 *   func_021C5470 0x021C5470 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   STRBUF_Delete 0x02045808 arm
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   func_021C52F8 0x021C52F8 thumb
 *   func_021C5114 0x021C5114 thumb
 *   func_021C4EC4 0x021C4EC4 thumb
 */
#include "../include/Obj01751.h"
typedef unsigned char u8;
struct Rec;
struct TaskMenuState;
struct U16Vec;
extern void func_021C4DA8(u8 *p);
extern void func_021C5470(u8 *p);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
extern void STRBUF_Delete(struct U16Vec *vec);
typedef unsigned int   u32;
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern void func_021C52F8(u8 *p);
extern void func_021C5114(u8 *p);
extern void func_021C4EC4(void *p);
int func_021C4D14(u8 *p)
{
    func_021C4DA8(p);
    func_021C5470(p);
    if (p + 0x28) MSGDATA_Delete(((struct Obj01751 *)p)->f20);
    STRBUF_Delete(((struct Obj01751 *)p)->f34);
    APP_TASKMENU_RES_Delete(((struct Obj01751 *)p)->f108);
    func_021C52F8(p);
    func_021C5114(p);
    func_021C4EC4(p);
    return 1;
}
