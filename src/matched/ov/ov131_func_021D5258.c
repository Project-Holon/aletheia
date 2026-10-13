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
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 */
#include "../include/Obj08144.h"
struct PrintSys;
struct Rec;
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
typedef unsigned int   u32;
extern u32 GF_FONT_Delete(void *ptr);
void P_STATUS_ExitMessage(char *p)
{
    PRINTSYS_QUE_Clear(((struct Obj08144 *)p)->f84);
    PRINTSYS_QUE_Delete(((struct Obj08144 *)p)->f84);
    MSGDATA_Delete(((struct Obj08144 *)p)->f7C);
    GF_FONT_Delete(((struct Obj08144 *)p)->f80);
}
