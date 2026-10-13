/*
 * function: FIELD_NOGRID_MAPPER_Main
 * address:  0x021BB36C
 * packet:   pkt_ov021_021BB36C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_RAIL_Update  0x021B79E4  thumb  ov021
 *   FIELD_RAIL_UpdateCamera  0x021B79F0  thumb  ov021
 */

typedef struct {
    void *f0;
    char pad[0x10];
    int f14;
} Obj;

struct Obj;
extern void FIELD_RAIL_Update(unsigned short *p);
extern int FIELD_RAIL_UpdateCamera(struct Obj *o, int flag);

void FIELD_NOGRID_MAPPER_Main(Obj *p)
{
    FIELD_RAIL_Update(p->f0);
    if (p->f14 == 0) {
        FIELD_RAIL_UpdateCamera(p->f0, 0);
    }
}
