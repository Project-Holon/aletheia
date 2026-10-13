/*
 * function: BTL_MAIN_InitTrainerSlot
 * address:  0x021B6954
 * packet:   pkt_ov093_021B6954
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MAIN_GetRelativeClientIndex  0x021BA710  thumb  ov093
 *   BTL_TRAINER_SLOT_InitFromData  0x021B9E7C  thumb  ov093
 *   BTL_TRAINER_SLOT_InitPlayer  0x021B9E38  thumb  ov093
 */
#include "../include/Obj06216.h"
#include "../include/Obj13266.h"

typedef unsigned char  u8;
extern u8 BTL_MAIN_GetRelativeClientIndex(int a, int b);
struct A;
struct B;
extern void BTL_TRAINER_SLOT_InitFromData(struct A *p, struct B *src);
extern void BTL_TRAINER_SLOT_InitPlayer(char *p, int a, int b);

void BTL_MAIN_InitTrainerSlot(int a, int b)
{
    char *p = (char *)a;
    int base = ((struct Obj06216 *)p)->f0;
    int idx = BTL_MAIN_GetRelativeClientIndex(((struct Obj06216 *)p)->f46C, b);
    char *q = (char *)(a + 0x20) + b * 0x28;
    char *e = (char *)base + idx * 4;
    int *r = (int *)((struct Obj13266 *)e)->f48;
    if (*r != 0)
        BTL_TRAINER_SLOT_InitFromData((struct A *)((int)q), (struct B *)((int)r));
    else
        BTL_TRAINER_SLOT_InitPlayer((char *)((int)q), ((struct Obj06216 *)p)->f468, ((struct Obj13266 *)e)->f34);
}
