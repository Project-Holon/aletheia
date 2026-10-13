/*
 * function: WIFICLUB_ToggleOwnSeat
 * address:  0x021C1968
 * packet:   pkt_ov099_021BF2C4
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WIFICLUB_PublishOwnStatus  0x021BE6E4  thumb  ov099
 *   WIFICLUB_GetStatusSeatFlag  0x021C27E0  thumb  ov099
 *   WIFICLUB_SetStatusSeatFlag  0x021C27E8  thumb  ov099
 *   WIFICLUB_SetStatusModeFlag  0x021C2864  thumb  ov099
 */
typedef unsigned char u8;

typedef struct {
    char pad[0x46];
    u8 f46;                 /* 0x46 */
} Sub;

typedef struct {
    char pad[8];
    void *f8;               /* 0x008 */
    char pad0c[0x23c];
    Sub *f248;              /* 0x248 */
} Work;

extern void WIFICLUB_SetStatusSeatFlag(void *a, int v);
extern void WIFICLUB_SetStatusModeFlag(void *a, int v);
extern void WIFICLUB_PublishOwnStatus(char *s);
extern void WIFICLUB_GetStatusSeatFlag(void *a);

void WIFICLUB_ToggleOwnSeat(Work *w)
{
    w->f248->f46 = 1 - w->f248->f46;
    WIFICLUB_SetStatusSeatFlag(w->f8, w->f248->f46);
    WIFICLUB_SetStatusModeFlag(w->f8, w->f248->f46);
    WIFICLUB_PublishOwnStatus((char *)w);
    WIFICLUB_GetStatusSeatFlag(w->f8);
}
