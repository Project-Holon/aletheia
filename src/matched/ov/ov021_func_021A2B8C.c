/*
 * function: WEATHER_TASK_TickSpawnTimer
 * address:  0x021A2B8C
 * packet:   pkt_ov021_021A2B8C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct {
    u32 arg;
    short x4;
    short timer;
    short reload;
    u8 padA[0xE];
    void (*cb)(u32 arg, int x, int a);
} Obj021A2B8C;

int WEATHER_TASK_TickSpawnTimer(Obj021A2B8C *p, int a)
{
    p->timer--;
    if (p->timer <= 0) {
        p->cb(p->arg, p->x4, a);
        p->timer = p->reload;
        return 1;
    }
    return 0;
}
