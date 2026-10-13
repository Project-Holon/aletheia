/*
 * function: FIELD_G3D_MAP_CmdFindEventMonInParty
 * address:  0x0216BD54
 * packet:   pkt_ov010_0216BD54
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: reads a species and a flag value and two result
 * variables, maps the event species (243-245, 251, 492, 647-649) to a kind
 * and, for 647/648, a signature move (548/547, dropped when the flag is 0),
 * and stores FIELD_G3D_MAP_FindEventMonInParty's answer in the second variable; any other
 * species stores 0.
 *
 * symbols:
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   FIELD_G3D_MAP_FindEventMonInParty  0x0216BE20  thumb  ov010
 */

typedef unsigned short u16;

extern void *SCRCMD_WORK_GetGameData(void *work);
struct BigObj;
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *ctx, void *work);
extern int FIELD_G3D_MAP_FindEventMonInParty(int a, int b, int e, int d, u16 *out);

int FIELD_G3D_MAP_CmdFindEventMonInParty(void *ctx, void *work)
{
    void *s = GAME_DATA_GetMyParty(SCRCMD_WORK_GetGameData(work));
    int species = SCRIPT_WORK_ReadWorkValue(ctx, work);
    unsigned int flag = SCRIPT_WORK_ReadWorkValue(ctx, work);
    u16 *out = SCRIPT_WORK_ReadWorkPointer(ctx, work);
    u16 *res = SCRIPT_WORK_ReadWorkPointer(ctx, work);
    int kind;
    int move;

    switch (species) {
    case 647:
        kind = 4;
        move = 548;
        break;
    case 648:
        kind = 5;
        move = 547;
        break;
    case 251:
        kind = 0;
        move = 0;
        break;
    case 243:
    case 244:
    case 245:
        kind = 2;
        move = 0;
        break;
    case 649:
        kind = 6;
        move = 0;
        break;
    case 492:
        kind = 7;
        move = 0;
        break;
    default:
        *res = 0;
        return 0;
    }
    if (flag == 0) {
        move = 0;
    }
    *res = FIELD_G3D_MAP_FindEventMonInParty((int)s, species, move, kind, out);
    return 0;
}
