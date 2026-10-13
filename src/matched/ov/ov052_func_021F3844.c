/*
 * function: FIELD_GIMMICK_BSUBWAY_InitTrain
 * address:  0x021F3844
 * packet:   pkt_ov052_021F3844
 * region:   ov052
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   FIELD_EFFECT_LoadResources  0x021ABE30  thumb  ov021
 *   sFieldGimmickBsubwayFileName     0x021F3AC0  data  ov052  a4
 */
#include "../include/Obj13111.h"

typedef unsigned char  u8;
extern unsigned int FIELDMAP_GetEffect(u8 *p);
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void FIELD_EFFECT_LoadResources(int, int *, int);
extern char sFieldGimmickBsubwayFileName[];

void FIELD_GIMMICK_BSUBWAY_InitTrain(char *a, u8 *b)
{
    int n;
    int r4 = FIELDMAP_GetEffect(b);

    ((struct Obj13111 *)a)->f24 = func_02030734(((struct Obj13111 *)a)->fC, 4, 1, sFieldGimmickBsubwayFileName, 0x112);
    n = 0xe;
    FIELD_EFFECT_LoadResources(r4, &n, 1);
}
