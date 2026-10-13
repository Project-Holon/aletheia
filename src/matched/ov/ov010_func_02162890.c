/*
 * function: EVENTDATA_SYSTEM_SearchAutoPosEvent
 * address:  0x02162890
 * packet:   pkt_ov010_02162890
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   EVENTDATA_SYSTEM_IsPosEventGridHit  0x02162F0C  thumb  ov010
 *   func_020143CC  0x020143CC  thumb
 */

typedef unsigned short u16;

struct Rec {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    u16 pad[7];
};

struct Ctx {
    u16 pad0[12];
    u16 f18;
    u16 pad1a[7];
    struct Rec *f28;
};

typedef unsigned int   u32;
extern int EVENTDATA_SYSTEM_IsPosEventGridHit(char *p, int *v);
extern u32 func_020143CC(u32 a, u32 b);

struct Rec *EVENTDATA_SYSTEM_SearchAutoPosEvent(struct Ctx *c, void *a, int key)
{
    struct Rec *r = c->f28;
    u16 i;
    u16 n;
    u16 v;
    if (r != 0) {
        n = c->f18;
        for (i = 0; i < n; i++, r++) {
            if (EVENTDATA_SYSTEM_IsPosEventGridHit((char *)r, (int *)key) != 0 && r->f6 == 6) {
                if (r->f4 == 0)
                    return r;
                v = *((u16 *)func_020143CC((u32)a, r->f4));
                if (v == r->f2)
                    return r;
            }
        }
    }
    return 0;
}
