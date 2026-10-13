/*
 * function: WEATHER_IsTaskActive
 * address:  0x021A1B50
 * packet:   pkt_ov021_021A1B50
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WEATHER_TASK_GetPhase  0x021A21B0  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct {
    u8 pad[0x20];
    u32 items[2];
} Obj021A1B50;

int WEATHER_TASK_GetPhase(u8 *a0);

int WEATHER_IsTaskActive(Obj021A1B50 *p)
{
    int i;

    if (p != 0) {
        for (i = 0; i < 2; i++) {
            if (WEATHER_TASK_GetPhase((u8 *)p->items[i]) == 1)
                return 1;
        }
    }
    return 0;
}
