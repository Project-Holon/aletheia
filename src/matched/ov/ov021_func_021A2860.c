/*
 * function: WEATHER_TASK_InitBillboards
 * address:  0x021A2860
 * packet:   pkt_ov021_021A2860
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WEATHER_TASK_InitBillboard  0x021A2A18  thumb  ov021
 */

typedef struct {
    char pad0[4];
    unsigned short count;
} Hdr;

typedef struct {
    char pad0[0x18];
    int *arr;
    int pad1c;
    Hdr *hdr;
    char pad24[4];
    char sub[4];
} Obj;

void WEATHER_TASK_InitBillboard(void *a, int i, int v, void *p, int x);

void WEATHER_TASK_InitBillboards(Obj *o, int x)
{
    int i;

    for (i = 0; i < o->hdr->count; i++) {
        WEATHER_TASK_InitBillboard(o->sub, i, o->arr[i], (char *)o->hdr + 0xe + i * 12, x);
    }
}
