/*
 * function: P_STA_RIBBON_Main
 * address: 0x021D8830
 * packet: pkt_ov131_021D8830
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   P_STA_RIBBON_UpdateInput 0x021D8A2C thumb ov131
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   P_STA_RIBBON_HideDetail 0x021D9670 thumb ov131
 *   P_STA_RIBBON_ShowDetail 0x021D9568 thumb ov131
 *   P_STA_RIBBON_UpdateRows 0x021D92B0 thumb ov131
 */
#include "../include/Obj00091.h"
#include "../include/Obj03816.h"

extern void P_STA_RIBBON_UpdateInput(unsigned char *, unsigned char *);
typedef unsigned int   u32;
struct PrintSys;
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);
extern void P_STA_RIBBON_HideDetail(unsigned char *, unsigned char *);
extern void P_STA_RIBBON_ShowDetail(unsigned char *, unsigned char *);
extern void P_STA_RIBBON_UpdateRows(unsigned char *, unsigned char *);
void P_STA_RIBBON_Main(unsigned char *a, unsigned char *p)
{
    P_STA_RIBBON_UpdateInput(a,p);
    if (((struct Obj00091 *)p)->f8 == 1) {
        if (PRINTSYS_QUE_IsFinished(((struct Obj03816 *)a)->f84) == 1) {
            P_STA_RIBBON_HideDetail(a,p);
            P_STA_RIBBON_ShowDetail(a,p);
            ((struct Obj00091 *)p)->f8=0;
        }
    } else P_STA_RIBBON_UpdateRows(a,p);
    if (p[0x60]) p[0x60]--;
}
