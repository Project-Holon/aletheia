/*
 * function: GIMMICK57_DrawModelScene
 * address:  0x021F3858
 * packet:   pkt_021F3858
 * region:   ov057
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3D_SYSTEM_DrawObject  0x02047A60  arm
 *   d_021F38C4     0x021F38C4  data
 */
#include "../unit_021F36C0_types.h"

/* Draw the three objects of the scene with the same position, scale and rotation. */
void GIMMICK57_DrawModelScene(void *unused, struct FieldMap *fieldMap, ModelScene *scene)
{
    G3D_SYSTEM_DrawObject(scene->object[0], &d_021F38C4);
    G3D_SYSTEM_DrawObject(scene->object[1], &d_021F38C4);
    G3D_SYSTEM_DrawObject(scene->object[2], &d_021F38C4);
}
