/*
 * function: FLDMMDL_MOVE_AddDirVectorPos
 * address:  0x02163FC0
 * packet:   pkt_ov010_02163FC0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_GetPos  0x0216D88C  thumb
 *   FLDMMDL_SetPos  0x0216D89C  thumb
 */

struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *a, struct VecFx32 *p);
extern void FLDMMDL_SetPos(int a, int *p);

void FLDMMDL_MOVE_AddDirVectorPos(int a, int dir, int amt)
{
    int buf[3];

    FLDMMDL_GetPos((const struct Actor *)a, (struct VecFx32 *)buf);
    switch (dir) {
    case 0:
        buf[2] -= amt;
        break;
    case 1:
        buf[2] += amt;
        break;
    case 2:
        buf[0] -= amt;
        break;
    case 3:
        buf[0] += amt;
        break;
    }
    FLDMMDL_SetPos(a, buf);
}
