/*
 * function: GIMMICK_OBJ_ELBOARD_AddMessage
 * address:  0x021F3D38
 * packet:   pkt_ov048_021F3D38
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GIMMICK_OBJ_ELBOARD_AddLine  0x021F472C  thumb
 *   FIELD_GIMMICK_GATE_LogMessage  0x021F3A50  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   ZONEDATA_ResetEventFlag  0x0201433C  thumb
 */

typedef unsigned int   u32;
struct BigObj;
extern void GIMMICK_OBJ_ELBOARD_AddLine(unsigned char *p, const void *q);
extern void FIELD_GIMMICK_GATE_LogMessage(char *p, int a, int b);
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern void ZONEDATA_ResetEventFlag(char *a0, int a1);

void GIMMICK_OBJ_ELBOARD_AddMessage(int *p, int a, int b, int *c)
{
    GIMMICK_OBJ_ELBOARD_AddLine((unsigned char *)p[5], (const void *)a);
    if (b == 8)
        FIELD_GIMMICK_GATE_LogMessage((char *)p, b, c[1]);
    else
        FIELD_GIMMICK_GATE_LogMessage((char *)p, b, 0);
    if (b == 8 && c[2] == 1) {
        ZONEDATA_ResetEventFlag((char *)GAME_DATA_GetEventWork((const struct BigObj *)p[2]), (unsigned short)c[1]);
    }
}
