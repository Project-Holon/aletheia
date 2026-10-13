/*
 * function: FIELD_GIMMICK_D06_CheckPushStone
 * address:  0x021F38A4
 * packet:   pkt_ov051_021F38A4
 * region:   ov051
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_GIMMICK_D06_GetWork  0x021F3D6C  thumb  ov051
 *   FIELD_GIMMICK_D06_GetPanelCount  0x021F3724  thumb  ov051
 *   FIELD_GIMMICK_D06_GetPanelPositions  0x021F3718  thumb  ov051
 *   FIELD_GIMMICK_D06_TriggerPanelPulse  0x021F3D04  thumb  ov051
 *   FIELD_GIMMICK_D06_CreateSlideEvent  0x021F3958  thumb  ov051
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb
 *   FLDMMDL_MOVE_AddDirVector  0x02164208  thumb
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb
 *   FLDMMDL_SysSearchGridPos  0x0216DDC0  thumb
 *   FLDMMDL_GetObjId  0x0216D588  thumb
 */

extern void *FIELD_GIMMICK_D06_GetWork(int a);
extern int FIELD_GIMMICK_D06_GetPanelCount(int a);
extern int FIELD_GIMMICK_D06_GetPanelPositions(int a);
extern void FIELD_GIMMICK_D06_TriggerPanelPulse(int a, int b);
extern int FIELD_GIMMICK_D06_CreateSlideEvent(int a, int b, int c);
extern void *FIELDMAP_GetFieldPlayer(unsigned char *p);
struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *a, struct VecFx32 *b);
extern void FLDMMDL_MOVE_AddDirVector(int a, int *b, int c);
extern void *FIELDMAP_GetMmdlSys(unsigned char *p);
extern int FLDMMDL_SysSearchGridPos(void *a, int b, int c, int d);
extern int FLDMMDL_GetObjId(int a);

int FIELD_GIMMICK_D06_CheckPushStone(int a, int b)
{
    int v[3];
    int res;
    int x;
    int y;
    int h;
    unsigned int i;
    int *p;
    unsigned int n;
    int *r4;

    res = 0;
    r4 = FIELD_GIMMICK_D06_GetWork(a);
    FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer((void *)a), (struct VecFx32 *)v);
    FLDMMDL_MOVE_AddDirVector(b, v, 1 << 16);
    x = (short)(((v[0] >> 4) / 4096));
    y = (short)(((v[2] >> 4) / 4096));
    n = FIELD_GIMMICK_D06_GetPanelCount(*r4);
    p = (int *)FIELD_GIMMICK_D06_GetPanelPositions(*r4);
    i = 0;
    if (i < n)
        for (; i < n; i++) {
            if (p[0] == x && p[2] == y)
                FIELD_GIMMICK_D06_TriggerPanelPulse(a, i);
            p += 3;
        }
    h = FLDMMDL_SysSearchGridPos(FIELDMAP_GetMmdlSys((void *)a), x, y, 0);
    if (h != 0 && FLDMMDL_GetObjId(h) == 0xfd)
        res = FIELD_GIMMICK_D06_CreateSlideEvent(a, h, b);
    return res;
}
