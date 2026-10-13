/*
 * function: EVENT_GAME_MANUAL_Main
 * address:  0x021D310C
 * packet:   pkt_ov021_021D310C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * abs_id_e1 is FS_OVERLAY_ID(ov225) (overlay_id).  d_021BBDE4 is ov225's
 * proc table (Thumb entries 0x021B95A1, 0x021B96BD, 0x021B9661), handed
 * to the proc loader with ov225's id; it resolves as sole-ref/data in
 * ov225 through the loaded-overlay exception to the own-window rule
 * (attest_xwin_loaded(), 2026-10-02).  No overlay listing labels
 * 0x021BBDE4 as a function; ov114 has ARM code there.
 *
 * symbols:
 *   FIELD_STATUS_CreateSubProcEvent  0x020146F8  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   EVENT_GAME_MANUAL_SetResult  0x021D3164  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   abs_id_e1      0x000000E1  data
 *   d_021BBDE4    0x021BBDE4  data  ov225  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

struct Evt;
extern void *FIELD_STATUS_CreateSubProcEvent(char *a0, int a1, int a2, int a3, int a4);
extern unsigned char abs_id_e1[];
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern void EVENT_GAME_MANUAL_SetResult(u32 *p);
extern u32 func_020307B0(void *p);
extern char d_021BBDE4[];

u32 EVENT_GAME_MANUAL_Main(u32 a, u32 *st, u32 *p)
{
    switch (st[0]) {
    case 0:
        GAME_EVENT_CallEvent((struct Evt *)a, FIELD_STATUS_CreateSubProcEvent((char *)p[0], p[1], (int)abs_id_e1, (int)d_021BBDE4, p[2]));
        st[0]++;
        break;
    case 1:
        EVENT_GAME_MANUAL_SetResult(p);
        func_020307B0((void *)p[2]);
        return 1;
    }
    return 0;
}
