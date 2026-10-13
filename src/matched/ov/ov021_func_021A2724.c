/*
 * function: WEATHER_TASK_CallStageFunc
 * address:  0x021A2724
 * packet:   pkt_ov021_021A2724
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;

typedef struct {
    u8 pad[0x24];
    u8 lo : 4;
    u8 hi : 4;
} Obj021A2724;

int WEATHER_TASK_CallStageFunc(Obj021A2724 *p, int (*cb)(Obj021A2724 *, int, int), int x)
{
    if (cb != 0)
        return cb(p, p->lo, x);
    return 1;
}
