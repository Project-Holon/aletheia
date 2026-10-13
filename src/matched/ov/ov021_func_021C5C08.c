/*
 * function: SCRCMD_SubProcEventMain
 * address:  0x021C5C08
 * packet:   pkt_ov021_021C5C08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  pooled 0x000000AB is an overlay-id-like absolute symbol passed to
 *           FIELD_STATUS_CreateSubProcEvent (0x020146F8), which is not in match.py
 *           OVERLAY_ID_CONSUMERS, so the ABS32 has no witness (literal class
 *           refuses the range's own pool word).  Every concrete byte matches.
 *
 * symbols:
 *   FIELD_STATUS_CreateSubProcEvent  0x020146F8  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   ov171_id       0x000000AB  data  a1
 *   gSubProcTable    0x021DEA44  data  ov021  a1
 */

typedef unsigned short u16;

typedef struct {
    int f0;
    int f4;
    u16 f8[3];
    u16 fE;
    u16 *f10;
} Arg;

extern void *FIELD_STATUS_CreateSubProcEvent(char *a0, int a1, int a2, int a3, int a4);
struct Evt;
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern char gSubProcTable[];
extern char ov171_id[];

int SCRCMD_SubProcEventMain(void *a, int *st, Arg *p)
{
    int v;

    switch (*st) {
    case 0:
        GAME_EVENT_CallEvent(a, FIELD_STATUS_CreateSubProcEvent((char *)p->f0, p->f4, (int)ov171_id, (int)gSubProcTable, (int)p->f8));
        *st = *st + 1;
        break;
    case 1:
        switch (p->fE) {
        case 0:
            v = 0;
            *p->f10 = v;
            break;
        case 1:
            v = 1;
            *p->f10 = v;
            break;
        }
        return 1;
    }
    return 0;
}
