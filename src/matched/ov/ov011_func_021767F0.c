/*
 * function: INTRUDE_COMM_GetMarkerPosForPartner
 * address:  0x021767F0
 * packet:   pkt_ov011_021767F0
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   GAME_DATA_GetOwnNetId  0x02012B58  thumb
 *   sLinkMarkerPosTemplate     0x02176FD8  data  ov011  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8  pad[0x86];
    u16 v : 3;
    u8  pad2[0x902 - 0x88];
    u8  f902;
} Rec;

typedef struct {
    u32 w0;
    u32 w4;
    u32 w8;
} Cs;

extern Cs   sLinkMarkerPosTemplate;
extern int INTRUDE_COMM_GetWorkIfRunning(int a0);
struct BigObj;
extern u8 GAME_DATA_GetOwnNetId(const struct BigObj *p);

void INTRUDE_COMM_GetMarkerPosForPartner(void *a, void *b, Cs *c)
{
    Rec *r;
    int d;

    r = (Rec *)INTRUDE_COMM_GetWorkIfRunning((int)a);
    if (r == 0 || r->v == GAME_DATA_GetOwnNetId(b)) {
        d = 0;
    } else {
        d = r->v - GAME_DATA_GetOwnNetId(b);
        if (d < 0) {
            d += r->f902;
        }
    }
    *c = sLinkMarkerPosTemplate;
    c->w0 += d << 22;
}
