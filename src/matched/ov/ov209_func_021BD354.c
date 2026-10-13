/*
 * function: func_021BD354
 * address: 0x021BD354
 * packet: pkt_ov209_021BD354
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 021BD396 two-byte alignment padding before 021BD398.
 * symbols:
 *   GAME_DATA_CheckSaveFlag 0x02012BF8 thumb
 *   GAME_DATA_SetSaveFlag 0x02012BE0 thumb
 *   func_021BD890 0x021BD890 thumb ov209
 */
#include "../include/Obj10912.h"
extern int GAME_DATA_CheckSaveFlag(int, int);
extern void GAME_DATA_SetSaveFlag(void *, unsigned, unsigned);
extern void func_021BD890(char *, int, int);
void func_021BD354(char *p)
{
    if (GAME_DATA_CheckSaveFlag(**(int * *)&((struct Obj10912 *)p)->f0, 15) == 1) {
        GAME_DATA_SetSaveFlag(**(void ** *)&((struct Obj10912 *)p)->f0, 15, 0);
        func_021BD890(p, 5, 6);
    } else {
        GAME_DATA_SetSaveFlag(**(void ** *)&((struct Obj10912 *)p)->f0, 15, 1);
        func_021BD890(p, 5, 7);
    }
}
