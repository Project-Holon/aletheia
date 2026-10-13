/*
 * function: func_021F3858
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
 *   func_02047A60  0x02047A60  arm
 *   d_021F38C4     0x021F38C4  data
 */
#include "../unit_021F36C0_types.h"

/* Draw the three objects of the scene with the same position, scale and rotation. */
void func_021F3858(void *unused, struct FieldMap *fieldMap, ModelScene *scene)
{
    func_02047A60(scene->object[0], &d_021F38C4);
    func_02047A60(scene->object[1], &d_021F38C4);
    func_02047A60(scene->object[2], &d_021F38C4);
}
