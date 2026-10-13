/*
 * function: BTL_MAIN_InitFirstTwoTrainerSlots
 * address:  0x021B69FC
 * packet:   pkt_ov093_021B69FC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_TRAINER_SLOT_InitPlayer  0x021B9E38  thumb  ov093
 *   BTL_TRAINER_SLOT_InitFromData  0x021B9E7C  thumb  ov093
 *   BTL_MAIN_InitTrainerSlot  0x021B6954  thumb  ov093
 */
#include "../include/Obj00661.h"
#include "../include/Obj06216.h"

struct A;
struct B;
extern void BTL_TRAINER_SLOT_InitPlayer(char *p, int a, int b);
extern void BTL_TRAINER_SLOT_InitFromData(struct A *p, struct B *src);
extern void BTL_MAIN_InitTrainerSlot(int, int);

void BTL_MAIN_InitFirstTwoTrainerSlots(int a, char *b)
{
    if (((struct Obj00661 *)b)->f23 == 0) {
        BTL_TRAINER_SLOT_InitPlayer((char *)(a + 0x20), ((struct Obj06216 *)a)->f468, ((struct Obj06216 *)a)->fC0);
        BTL_TRAINER_SLOT_InitFromData((struct A *)(a + 0x48), (struct B *)(((struct Obj00661 *)b)->f4C));
    } else {
        BTL_MAIN_InitTrainerSlot(a, 0);
        BTL_MAIN_InitTrainerSlot(a, 1);
    }
}
