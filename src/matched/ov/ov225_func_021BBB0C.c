/*
 * function: MANUAL_CATEGORY_UpdateOption
 * address: 0x021BBB0C
 * packet: pkt_ov225_021BBB0C
 * status: EXACT*
 * region: ov225
 * isa: thumb
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * trailing: 021BBBF0 callback already owns separate verified shard; BF2 alignment.
 * symbols:
 *   MANUAL_CATEGORY_DeleteOptionSlots 0x021BBCF4 thumb ov225
 *   MANUAL_CATEGORY_OptionNoop 0x021BBC50 thumb ov225
 *   MANUAL_CATEGORY_UpdateOptionSlots 0x021BBD28 thumb ov225
 *   MANUAL_COMMON_UpdateTouchbar 0x021B9FBC thumb ov225
 *   MANUAL_COMMON_GetTouchbarPressed 0x021BA158 thumb ov225
 *   MANUAL_CATEGORY_DrawOption 0x021BBD74 thumb ov225
 *   MANUAL_COMMON_GetTouchbarSelected 0x021BA154 thumb ov225
 *   MANUAL_COMMON_SetTouchbarSelection 0x021BA0F0 thumb ov225
 */
#include "../include/Obj00602.h"
#include "../include/Obj26309.h"
#include "../include/Obj26310.h"
#include "../include/Obj26312.h"
#include "../include/Obj26313.h"
#include "../include/Obj26314.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void MANUAL_CATEGORY_DeleteOptionSlots(char *);
extern void MANUAL_CATEGORY_OptionNoop(char *);
extern void MANUAL_CATEGORY_UpdateOptionSlots(u8 *);
extern void MANUAL_COMMON_UpdateTouchbar(char *);
extern unsigned MANUAL_COMMON_GetTouchbarPressed(char *p);
extern unsigned MANUAL_COMMON_GetTouchbarSelected(char *p);
extern void MANUAL_CATEGORY_DrawOption(char *);
extern void MANUAL_COMMON_SetTouchbarSelection(char *,unsigned,unsigned);
int MANUAL_CATEGORY_UpdateOption(char *p)
{
    int result = 0;
    int timer = ((struct Obj00602 *)p)->f3C;
    int choice;
    if (timer == 0) result = 1;
    else if (timer > 0) {
        if (timer == 1) {
            MANUAL_CATEGORY_DeleteOptionSlots(p);
            MANUAL_CATEGORY_OptionNoop(p);
        }
        ((struct Obj00602 *)p)->f3C -= 1;
    }
    if (((struct Obj00602 *)p)->f38 != 1) MANUAL_CATEGORY_UpdateOptionSlots((u8 *)p);
    if (((struct Obj00602 *)p)->f38 == 0 || ((struct Obj00602 *)p)->f38 == 2) {
        MANUAL_COMMON_UpdateTouchbar(*(char * *)&((struct Obj26309 *)(*(char * *)&((struct Obj00602 *)p)->f4))->f34);
        if (((struct Obj00602 *)p)->f38 == 0) {
            choice = MANUAL_COMMON_GetTouchbarPressed(*(char * *)&((struct Obj26310 *)(*(char * *)&((struct Obj00602 *)p)->f4))->f34);
            if (choice == -1) goto done;
            ((struct Obj00602 *)p)->f38 = 2;
            if (choice == 4) {
                if (((struct Obj00602 *)p)->f8 != 0) {
                    ((struct Obj00602 *)p)->f8 -= 1;
                    ((struct Obj00602 *)p)->fC = 1;
                }
            } else if (choice == 5) {
                if (((struct Obj00602 *)p)->f8 < *(u8 *)*(char * *)&((struct Obj00602 *)p)->f0 - 1) {
                    ((struct Obj00602 *)p)->f8 += 1;
                    ((struct Obj00602 *)p)->fC = 1;
                }
            }
            if (((struct Obj00602 *)p)->fC) MANUAL_CATEGORY_DrawOption(p);
        } else {
            choice = MANUAL_COMMON_GetTouchbarSelected(*(char * *)&((struct Obj26312 *)(*(char * *)&((struct Obj00602 *)p)->f4))->f34);
            if (choice == -1) goto done;
            switch (choice) {
            case 1:
                ((struct Obj26313 *)(*(char * *)&((struct Obj00602 *)p)->f0))->f28 = 0;
                ((struct Obj00602 *)p)->f38 = 1;
                ((struct Obj00602 *)p)->f3C = 1;
                break;
            case 4: case 5:
                ((struct Obj00602 *)p)->f38 = 0;
                if (((struct Obj00602 *)p)->fC) {
                    MANUAL_COMMON_SetTouchbarSelection(*(char * *)&((struct Obj26314 *)(*(char * *)&((struct Obj00602 *)p)->f4))->f34, *(u8 *)*(char * *)&((struct Obj00602 *)p)->f0, ((struct Obj00602 *)p)->f8);
                    ((struct Obj00602 *)p)->fC = 0;
                }
                break;
            }
        }
    }
done:
    return result;
}
