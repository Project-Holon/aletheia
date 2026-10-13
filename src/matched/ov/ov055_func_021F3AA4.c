/*
 * function: CROWD_Update
 * address:  0x021F3AA4
 * packet:   pkt_ov055_021F3AA4
 * region:   ov055
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELDMAP_GetTimeZone  0x02189A38  thumb  ov021
 *   FIELDMAP_IsEventActive  0x02189A2C  thumb  ov021
 *   CROWD_UpdateSpawns  0x021F3F30  thumb  ov055
 *   CROWD_MakePersonSolid  0x021F3D90  thumb  ov055
 *   CROWD_UpdatePerson  0x021F3CF4  thumb  ov055
 *   CROWD_UpdateChatter  0x021F4474  thumb  ov055
 */
#include "../include/Obj13120.h"

extern int FIELDMAP_GetTimeZone(int);
typedef signed short   s16;
extern int FIELDMAP_IsEventActive(int *a);
struct S;
extern void CROWD_UpdateSpawns(struct S *p, char *q, int k);
extern void CROWD_MakePersonSolid(unsigned char *p);
extern void CROWD_UpdatePerson(unsigned char *p, int a, int b);
extern void CROWD_UpdateChatter(s16 *a, s16 *b, int *c);

void CROWD_Update(int a, int b, char *c)
{
    int i;

    CROWD_UpdateSpawns((struct S *)(c + 0x308), c, FIELDMAP_GetTimeZone(b));
    if (FIELDMAP_IsEventActive((int *)b)) {
        for (i = 0; i < 0x20; i++)
            CROWD_MakePersonSolid((unsigned char *)(c + 8 + i * 0x18));
    }
    for (i = 0; i < 0x20; i++)
        CROWD_UpdatePerson((unsigned char *)(c + 8 + i * 0x18), ((struct Obj13120 *)c)->f4, ((struct Obj13120 *)c)->f0);
    CROWD_UpdateChatter((s16 *)(c + 0x348), (s16 *)(c + 0x308), (int *)b);
}
