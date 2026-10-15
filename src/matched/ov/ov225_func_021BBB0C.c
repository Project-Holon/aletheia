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
 *   func_021B9FBC 0x021B9FBC thumb ov225
 *   func_021BA158 0x021BA158 thumb ov225
 *   MANUAL_CATEGORY_DrawOption 0x021BBD74 thumb ov225
 *   func_021BA154 0x021BA154 thumb ov225
 *   func_021BA0F0 0x021BA0F0 thumb ov225
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
extern void func_021B9FBC(char *);
extern unsigned func_021BA158(char *p);
extern unsigned func_021BA154(char *p);
extern void MANUAL_CATEGORY_DrawOption(char *);
extern void func_021BA0F0(char *,unsigned,unsigned);
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
        func_021B9FBC(*(char * *)&((struct Obj26309 *)(*(char * *)&((struct Obj00602 *)p)->f4))->f34);
        if (((struct Obj00602 *)p)->f38 == 0) {
            choice = func_021BA158(*(char * *)&((struct Obj26310 *)(*(char * *)&((struct Obj00602 *)p)->f4))->f34);
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
            choice = func_021BA154(*(char * *)&((struct Obj26312 *)(*(char * *)&((struct Obj00602 *)p)->f4))->f34);
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
                    func_021BA0F0(*(char * *)&((struct Obj26314 *)(*(char * *)&((struct Obj00602 *)p)->f4))->f34, *(u8 *)*(char * *)&((struct Obj00602 *)p)->f0, ((struct Obj00602 *)p)->f8);
                    ((struct Obj00602 *)p)->fC = 0;
                }
                break;
            }
        }
    }
done:
    return result;
}
