/*
 * function: ZKNSEARCH_MAIN_UpdateListInput
 * address: 0x021BD4AC
 * packet: pkt_ov210_021BD4AC
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ZKNSEARCH_MAIN_WaitConfirmInput 0x021C00FC thumb ov210
 *   ZKNSEARCH_MAIN_HideResultLayout 0x021BCCA8 thumb ov210
 *   ZKNSEARCH_MAIN_PrintLabel1 0x021BE7E4 thumb ov210
 *   func_020355C4 0x020355C4 arm
 *   CURSOR_MOVE_SetState 0x020260F4 thumb
 *   ZKNSEARCH_MAIN_NormalizeRecordByte 0x021BCF0C thumb ov210
 */
#include "../include/Obj03936.h"
#include "../include/Obj14677.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int ZKNSEARCH_MAIN_WaitConfirmInput(u8 *);
extern void ZKNSEARCH_MAIN_HideResultLayout(char *);
extern void ZKNSEARCH_MAIN_PrintLabel1(u8 *);
extern u8 func_020355C4(void);
typedef unsigned int   u32;
struct Struct_02025CD0;
extern void CURSOR_MOVE_SetState(struct Struct_02025CD0 *obj, u32 state);
extern void ZKNSEARCH_MAIN_NormalizeRecordByte(u8 *);
int ZKNSEARCH_MAIN_UpdateListInput(u8 *p)
{
    if (ZKNSEARCH_MAIN_WaitConfirmInput(p) == 1) {
        u8 *head = *(u8 * *)&((struct Obj03936 *)p)->f0;
        if (((struct Obj14677 *)head)->f14 != 0) {
            ((struct Obj14677 *)head)->fC = 0;
            return 26;
        }
        ZKNSEARCH_MAIN_HideResultLayout((char *)p);
        ZKNSEARCH_MAIN_PrintLabel1(p);
        if (func_020355C4() == 1)
            CURSOR_MOVE_SetState(((struct Obj03936 *)p)->f2B0, 0);
        else
            CURSOR_MOVE_SetState(((struct Obj03936 *)p)->f2B0, 1);
        ZKNSEARCH_MAIN_NormalizeRecordByte(p);
        return 4;
    }
    return 8;
}
