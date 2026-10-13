/*
 * function: EVENTDATA_SYSTEM_FieldLinkEnterEvent
 * address:  0x021645E0
 * packet:   pkt_ov010_021645E0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Three-step wait state machine on *st; step 0 also counts frames in w[1].
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_COMM_IsSessionEndPending  0x0215870C  thumb ov010
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb ov021
 *   FIELDMAP_CheckPlayerRequest  0x02188BF8  thumb ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb ov021
 *   FIELD_PLAYER_StepFormChange  0x021A2F54  thumb ov021
 *   FIELD_PLAYER_WaitModelReady  0x021A34F8  thumb ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern int INTRUDE_COMM_IsSessionEndPending(void *p, int b);
extern void *FIELDMAP_GetMmdlSys(u8 *p);
extern u32 FIELDMAP_CheckPlayerRequest(u8 *a);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern int   FIELD_PLAYER_StepFormChange(u8 *p);
extern int   FIELD_PLAYER_WaitModelReady(u8 *p);

int EVENTDATA_SYSTEM_FieldLinkEnterEvent(void *unused, int *st, int *w)
{
    int r;
    u8 *h = GAMESYSTEM_GetFieldMap((void *)w[0]);
    FIELDMAP_GetMmdlSys(h);
    switch (*st) {
    case 0:
        r = GAMESYSTEM_GetGameComm((const struct Ctx *)w[0]);
        w[1]++;
        if (INTRUDE_COMM_IsSessionEndPending((void *)r, w[1]) == 1 && (u32)w[1] < 0x1e) {
            break;
        }
        FIELDMAP_CheckPlayerRequest(h);
        (*st)++;
        /* fall through */
    case 1:
        if (FIELD_PLAYER_StepFormChange((u8 *)FIELDMAP_GetFieldPlayer((struct Obj00020 *)h)) == 1) {
            (*st)++;
        }
        break;
    case 2:
        if (FIELD_PLAYER_WaitModelReady((u8 *)FIELDMAP_GetFieldPlayer((struct Obj00020 *)h)) == 1) {
            return 1;
        }
        break;
    }
    return 0;
}
