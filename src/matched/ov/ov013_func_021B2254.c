/*
 * function: VCT_SESSION_RemovePeer
 * address:  0x021B2254
 * packet:   pkt_ov013_021B2254
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gVctSession  0x021B60D8  data  ov013  a4
 *   gVctGroup  0x021B4BD0  data  ov013  a4
 *   VCT_SESSION_FindPeer  0x021B2A20  arm  ov013
 */

typedef struct Ctx {
    int f0;
    int (*cb)(int, int, int, int);
    int arg;
    int fC;
    int state;
} Ctx;

extern Ctx gVctSession;
extern int gVctGroup;
struct N;
extern struct N *VCT_SESSION_FindPeer(int id);

int VCT_SESSION_RemovePeer(int a)
{
    int r;

    if (gVctSession.state != 3)
        return -2;
    r = (int)VCT_SESSION_FindPeer(a);
    if (r == 0)
        return -1;
    gVctSession.cb(a, 9, r, gVctSession.arg);
    gVctGroup--;
    return 0;
}
