/*
 * function: MUSICAL_EVENT_CreateDressupParam
 * address:  0x02155F9C
 * packet:   pkt_02155F9C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MUSICAL_DRESSUP_SYS_Create  0x02156CAC  thumb  ov010
 */
#include "../include/Obj07201.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Obj { int f00; int f04; int f08; } Obj;
extern Obj *MUSICAL_DRESSUP_SYS_Create(int a, int b, int c);

Obj *MUSICAL_EVENT_CreateDressupParam(int a0)
{
    int a1;
    int a2;
    int t4;
    Obj *p;

t4 = a0 + 0;
a1 = ((struct Obj07201 *)t4)->f3C;
a2 = ((struct Obj07201 *)t4)->f1C;
a0 = 4;
    p = MUSICAL_DRESSUP_SYS_Create(a0, a1, a2);
loc_02155FAA:
a1 = ((struct Obj07201 *)t4)->f28;
*(Obj * *)&((struct Obj07201 *)t4)->f2C = p;
p->f00 = a1;
    return p;}
