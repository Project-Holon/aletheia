/*
 * function: SCRCMD_NameInEventMain
 * address:  0x021C5A54
 * packet:   pkt_ov021_021C5A54
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blocked (MATCH, every concrete byte right): the pooled word 0x000000C2 is a
 * pooled small constant (abs_id_C2, R_ARM_ABS32) passed as the third argument
 * to FIELD_STATUS_CreateSubProcEvent / FIELD_STATUS_CreateSubProcNoFadeEvent, neither of which is in match.py's
 * OVERLAY_ID_CONSUMERS, and no other pool word image-wide holds 0x000000C2,
 * so no evidence class attests it.  d_021F5580 resolves with the ov194 token (0xC2 is ov194; its proc table init/main/exit sits at 0x021F5580).
 *
 * symbols:
 *   FIELD_STATUS_CreateSubProcEvent  0x020146F8  thumb
 *   FIELD_STATUS_CreateSubProcNoFadeEvent  0x02014728  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   abs_id_C2      0x000000C2  data
 *   d_021F5580     0x021F5580  data  ov194  a4
 */

extern char d_021F5580;
extern unsigned char abs_id_C2[];

struct Evt;
extern void *FIELD_STATUS_CreateSubProcEvent(char *a0, int a1, int a2, int a3, int a4);
extern void *FIELD_STATUS_CreateSubProcNoFadeEvent(char *a0, int a1, int a2, int a3, int a4);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);

int SCRCMD_NameInEventMain(int a, int *st, int *c)
{
    int r;

    switch (*st) {
    case 0:
        if (c[3] != 0) {
            r = (int)FIELD_STATUS_CreateSubProcEvent((char *)c[0], c[1], (int)abs_id_C2, (int)(&d_021F5580), c[2]);
        } else {
            r = (int)FIELD_STATUS_CreateSubProcNoFadeEvent((char *)c[0], c[1], (int)abs_id_C2, (int)(&d_021F5580), c[2]);
        }
        GAME_EVENT_CallEvent((struct Evt *)a, (struct Evt **)r);
        (*st)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}
