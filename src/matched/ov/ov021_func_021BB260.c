/*
 * function: FIELD_NOGRID_MAPPER_SetActive
 * address:  0x021BB260
 * packet:   pkt_ov021_021BB260
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLD_SCENEAREA_SetEnabled  0x021AB75C  thumb  ov021
 */

typedef struct {
    char pad[0xC];
    void *fC;
    int pad10;
    int f14;
} Obj;

typedef unsigned int   u32;
typedef unsigned char  u8;
extern void FLD_SCENEAREA_SetEnabled(u8 *p, u32 v);

void FIELD_NOGRID_MAPPER_SetActive(Obj *p, int b)
{
    if (b != 0) {
        p->f14 = 0;
    } else {
        p->f14 = 1;
    }
    FLD_SCENEAREA_SetEnabled(p->fC, b);
}
