/*
 * function: SODATEYA_AddSharedMoves
 * address:  0x021C4160
 * packet:   pkt_ov021_021C4160
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   POKE_PERSONAL_LoadDataDirect  0x0201ADD0  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   SODATEYA_AddMove  0x021C42F4  thumb  ov021
 *   sSodateyaSharedMoveSlotIds     0x021DA8F8  data  ov021  a4
 *
 * Twin of SODATEYA_AddLevelUpMoves (same goto-rotated learnset walk). The call
 * result must be a named local (v == mv gives cmp r0, r5), and end = 0
 * goes after the entry copies, as in the twin.
 */

typedef unsigned int u32;
typedef unsigned short u16;

typedef struct { u16 x, y; } P;
typedef struct { u32 v[4]; } T4;

extern void POKE_PERSONAL_LoadDataDirect(unsigned int a, int b, void *buf);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern void SODATEYA_AddMove(u32 *p, u32 v);
extern const T4 sSodateyaSharedMoveSlotIds;

void SODATEYA_AddSharedMoves(u32 *p, u32 *q)
{
    P buf[26];
    T4 t = sSodateyaSharedMoveSlotIds;
    P d, b, a;
    int i;
    int fa;
    int fb;
    int end;
    int k;
    u32 mv;
    u32 v;

    POKE_PERSONAL_LoadDataDirect((u16)q[0], (u16)q[1], buf);
    i = 0;
    goto test;
body:
    d = a;
    mv = d.x;
    fa = 0;
    fb = 0;
    for (k = 0; k < 4; k++) {
        v = POKE_TOOL_GetPartyValue((void *)p[0], t.v[k], 0);
        if (v == mv) {
            fa = 1;
            break;
        }
    }
    for (k = 0; k < 4; k++) {
        v = POKE_TOOL_GetPartyValue((void *)p[1], t.v[k], 0);
        if (v == mv) {
            fb = 1;
            break;
        }
    }
    if (fa && fb)
        SODATEYA_AddMove(q, mv);
    i++;
test:
    a = buf[i];
    b = a;
    end = 0;
    if (b.x == 0xffff && b.y == 0xffff)
        end = 1;
    if (!end)
        goto body;
}
