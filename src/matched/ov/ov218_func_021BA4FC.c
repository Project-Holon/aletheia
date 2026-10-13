/*
 * function: func_021BA4FC
 * address: 0x021BA4FC
 * packet: pkt_ov218_021BA4FC
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
#include "../include/Obj14773.h"
typedef unsigned int   u32;
struct Obj;
extern u32 CLACT_GetActorDrawEnable(struct Obj *p);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
void func_021BA4FC(char *ctx)
{
    int i;
    void *item;
    if (((struct Obj14773 *)ctx)->f32C != 0) {
        ((struct Obj14773 *)ctx)->f32C = 0;
        for (i = 0; i < 7; i++) {
            item = *(void **)(ctx + 0x294 + i * 4);
            if (CLACT_GetActorDrawEnable(item) != 0)
                CLACT_SetActorDrawEnable(item, 0);
        }
        for (i = 0; i < 7; i++) {
            item = *(void **)(ctx + 0x2b0 + i * 4);
            if (CLACT_GetActorDrawEnable(item) != 0)
                CLACT_SetActorDrawEnable(item, 0);
        }
    }
}
