/*
 * function: P_STATUS_ExitMessage
 * address: 0x021D5258
 * packet: pkt_ov131_021D5258
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 */
#include "../include/Obj08144.h"
struct PrintSys;
struct Rec;
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
typedef unsigned int   u32;
extern u32 GF_FONT_Delete(void *ptr);
void P_STATUS_ExitMessage(char *p)
{
    func_0201C6EC(((struct Obj08144 *)p)->f84);
    func_0201C4C0(((struct Obj08144 *)p)->f84);
    MSGDATA_Delete(((struct Obj08144 *)p)->f7C);
    GF_FONT_Delete(((struct Obj08144 *)p)->f80);
}
