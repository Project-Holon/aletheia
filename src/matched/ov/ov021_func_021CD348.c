/*
 * function: EVENT_NAMEIN_Main
 * address:  0x021CD348
 * packet:   pkt_ov021_021CD348
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blocked (MATCH, every concrete byte right): the pooled word 0x000000C2 is a
 * pooled small constant (abs_id_C2, R_ARM_ABS32) passed to FIELD_STATUS_CreateSubProcEvent, not
 * in match.py's OVERLAY_ID_CONSUMERS; no other pool word holds 0x000000C2
 * outside this range (same blocker as pending ov021_func_021C5A54).
 *
 * symbols:
 *   FIELD_STATUS_CreateSubProcEvent  0x020146F8  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   EVENT_NAMEIN_StoreResult  0x021CD3A4  thumb  ov021
 *   STRBUF_Delete  0x02045808  arm
 *   abs_id_C2      0x000000C2  data
 *   d_021F5580     0x021F5580  data  ov194  a4
 */
#include "../include/Obj03150.h"

typedef unsigned char u8;

extern char d_021F5580;
extern unsigned char abs_id_C2[];

struct Evt;
struct U16Vec;
extern void *FIELD_STATUS_CreateSubProcEvent(char *a0, int a1, int a2, int a3, int a4);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern void EVENT_NAMEIN_StoreResult(u8 *a, u8 *b);
extern void STRBUF_Delete(struct U16Vec *vec);

int EVENT_NAMEIN_Main(int a, int *st, u8 *c)
{
    int r;

    switch (*st) {
    case 0:
        r = (int)FIELD_STATUS_CreateSubProcEvent((char *)(((struct Obj03150 *)c)->f0), ((struct Obj03150 *)c)->f10, (int)abs_id_C2, (int)(&d_021F5580), (int)(c + 0x1c));
        GAME_EVENT_CallEvent((struct Evt *)a, (struct Evt **)r);
        (*st)++;
        break;
    case 1:
        EVENT_NAMEIN_StoreResult(c, c + 0x1c);
        STRBUF_Delete((struct U16Vec *)(((struct Obj03150 *)c)->f3C));
        return 1;
    }
    return 0;
}
