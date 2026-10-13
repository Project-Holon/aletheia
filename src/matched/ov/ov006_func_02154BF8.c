/*
 * function: EVENT_WIFICLUB_Create
 * address:  0x02154BF8
 * packet:   pkt_ov006_02154BF8
 * region:   ov006
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   EVENT_WIFICLUB_InitWork  0x02154B08  thumb  ov006
 *   EVENT_WIFICLUB_Main  0x021544F0  thumb  ov006
 */

typedef unsigned int   u32;
struct Desc;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void EVENT_WIFICLUB_InitWork(void *obj_in, void *p, int a, int b);
int EVENT_WIFICLUB_Main(void *evt, u32 *state, char *obj);

int EVENT_WIFICLUB_Create(int a, int b, int c)
{
    int h;

    h = (int)func_020122C0((void *)a, 0, EVENT_WIFICLUB_Main, 0x174);
    EVENT_WIFICLUB_InitWork((void *)h, (void *)a, b, c);
    return h;
}
