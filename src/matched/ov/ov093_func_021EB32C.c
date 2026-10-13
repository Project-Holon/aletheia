/*
 * function: BTLV_SCU_StartEntryScene
 * address: 0x021EB32C
 * packet: pkt_ov093_021EB32C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_MAIN_GetCompetitor 0x021B86B8 thumb ov093
 *   BTL_MAIN_GetRule 0x021B8588 thumb ov093
 *   BTL_MAIN_IsMultiMode 0x021B86C8 thumb ov093
 *   BTLV_SCU_ProcEntrySingleWild 0x021EB690 thumb ov093
 *   BTLV_SCU_ProcEntrySingleTrainer 0x021EB870 thumb ov093
 *   BTLV_SCU_ProcEntrySingleLink 0x021EBAC0 thumb ov093
 *   BTLV_SCU_ProcEntryDoubleWild 0x021EBB20 thumb ov093
 *   BTLV_SCU_ProcEntryDoubleLinkLocal 0x021EBE28 thumb ov093
 *   BTLV_SCU_ProcEntryDoubleLinkComm 0x021EBE88 thumb ov093
 *   BTLV_SCU_ProcEntryDoubleTrainerLocal 0x021EBD90 thumb ov093
 *   BTLV_SCU_ProcEntryDoubleTrainerComm 0x021EBDDC thumb ov093
 *   func_021EBED4 0x021EBED4 thumb ov093
 *   func_021EBF20 0x021EBF20 thumb ov093
 */
#include "../include/Obj05227.h"
#include "../include/Obj07850.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef int (*Cb)(int *, u8 *);
extern void *BTL_MAIN_GetCompetitor(void ***);
extern u32 BTL_MAIN_GetRule(void **p);
extern int BTL_MAIN_IsMultiMode(unsigned char **p);
extern int BTLV_SCU_ProcEntrySingleWild(int *, u8 *);
extern int BTLV_SCU_ProcEntrySingleTrainer(int *, u8 *);
extern int BTLV_SCU_ProcEntrySingleLink(int *, u8 *);
extern int BTLV_SCU_ProcEntryDoubleWild(int *, u8 *);
extern int BTLV_SCU_ProcEntryDoubleLinkLocal(int *, u8 *);
extern int BTLV_SCU_ProcEntryDoubleLinkComm(int *, u8 *);
extern int BTLV_SCU_ProcEntryDoubleTrainerLocal(int *, u8 *);
extern int BTLV_SCU_ProcEntryDoubleTrainerComm(int *, u8 *);
extern int func_021EBED4(int *, u8 *);
extern int func_021EBF20(int *, u8 *);
static inline void set(u8 *p, Cb cb)
{
    ((struct Obj07850 *)p)->fE0 = 0;
    *(Cb *)&((struct Obj07850 *)p)->fE4 = cb;
    *(u8 * *)&((struct Obj07850 *)p)->fE8 = p;
    ((struct Obj07850 *)p)->fEC = 0;
}
void BTLV_SCU_StartEntryScene(u8 *p, u32 flag)
{
    int type = (int)BTL_MAIN_GetCompetitor(*(void *** *)&((struct Obj05227 *)p)->f134);
    p[0x14f] = 0;
    p[0x150] = flag;
    switch (BTL_MAIN_GetRule(((struct Obj05227 *)p)->f134)) {
    case 0:
        switch (type) {
        default: case 0: case 4: set(p, BTLV_SCU_ProcEntrySingleWild); return;
        case 1: case 2: set(p, BTLV_SCU_ProcEntrySingleTrainer); return;
        case 3: set(p, BTLV_SCU_ProcEntrySingleLink); return;
        }
    case 1:
        switch (type) {
        case 0: set(p, BTLV_SCU_ProcEntryDoubleWild); return;
        case 3:
            if (!BTL_MAIN_IsMultiMode((unsigned char **)(*(u8 * *)&((struct Obj05227 *)p)->f134))) set(p, BTLV_SCU_ProcEntryDoubleLinkLocal);
            else set(p, BTLV_SCU_ProcEntryDoubleLinkComm);
            return;
        case 1: case 2:
            if (!BTL_MAIN_IsMultiMode((unsigned char **)(*(u8 * *)&((struct Obj05227 *)p)->f134))) set(p, BTLV_SCU_ProcEntryDoubleTrainerLocal);
            else set(p, BTLV_SCU_ProcEntryDoubleTrainerComm);
            return;
        }
        break;
    case 2:
        if (type != 3) set(p, func_021EBED4);
        else set(p, func_021EBF20);
        return;
    case 3:
        if (type != 3) set(p, func_021EBED4);
        else set(p, func_021EBF20);
        return;
    }
}
