/*
 * unit: yes
 * function: MOVE_POKEMON_IsSkill8Unusable, MOVE_POKEMON_CreateDiveEvent
 * address: 0x0215EC2C
 * packet: pkt_ov010_0215EC2C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MOVE_POKEMON_IsSkillUsable 0x0215F104 thumb ov010
 *   SWEET_SCENT_CreateEvent 0x021C6078 thumb ov021
 */
#include "../include/Obj12315.h"
extern int MOVE_POKEMON_IsSkillUsable(int a0, int a1);
typedef enum { B_FALSE, B_TRUE } Bool;
int MOVE_POKEMON_IsSkill8Unusable(void *p)
{
    return MOVE_POKEMON_IsSkillUsable((int)p, 8) != 0 ? B_FALSE : B_TRUE;
}
typedef unsigned char u8;
typedef unsigned short u16;
extern void *SWEET_SCENT_CreateEvent(void *, void *, u8);
void *MOVE_POKEMON_CreateDiveEvent(u16 *a, void *b)
{
    return SWEET_SCENT_CreateEvent(((struct Obj12315 *)b)->f8, ((struct Obj12315 *)b)->f10, *a);
}
