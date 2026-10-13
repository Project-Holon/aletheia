/*
 * function: FIELD_GIMMICK_GATE_RestoreLoggedFlags
 * address:  0x021F3830
 * packet:   pkt_ov048_021F3830
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   ZONEDATA_SetEventFlag  0x02014314  thumb
 *   FIELD_GIMMICK_GATE_GetSave  0x021F37A4  thumb  ov048
 */

typedef unsigned char u8;
typedef unsigned short u16;

struct BigObj;
extern unsigned int GAME_DATA_GetEventWork(const struct BigObj *p);
extern void ZONEDATA_SetEventFlag(char *a0, int a1);
typedef unsigned int   u32;
extern u8 *FIELD_GIMMICK_GATE_GetSave(u32 a);

void FIELD_GIMMICK_GATE_RestoreLoggedFlags(int *p)
{
    int r6;
    int i;
    u8 *q;

    r6 = (int)GAME_DATA_GetEventWork((const struct BigObj *)p[2]);
    q = FIELD_GIMMICK_GATE_GetSave(p[1]) + 0xc;
    for (i = 0; i < q[0]; i++) {
        if (*(int *)(q + i * 4 + 4) == 8) {
            ZONEDATA_SetEventFlag((char *)r6, (u16)(*(int *)(q + i * 4 + 0x20)));
        }
    }
}
