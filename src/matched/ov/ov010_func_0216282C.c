/*
 * function: EVENTDATA_SYSTEM_SearchPosEventIgnoreHeight
 * address:  0x0216282C
 * packet:   pkt_ov010_0216282C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   EVENTDATA_SYSTEM_DirToPosEventType  0x0216279C  thumb  ov010
 *   EVENTDATA_SYSTEM_IsPosEventGridHitIgnoreHeight  0x02162F74  thumb  ov010
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

extern u16 EVENTDATA_SYSTEM_DirToPosEventType(int mode);
extern int EVENTDATA_SYSTEM_IsPosEventGridHitIgnoreHeight(char *p, int *v);
typedef unsigned int   u32;
extern u32 func_020143CC(u32 a, u32 b);

struct Rec *EVENTDATA_SYSTEM_SearchPosEventIgnoreHeight(struct Ctx *c, void *a, int *key, int mode)
{
    struct Rec *r = c->f28;
    u16 v;
    u16 t;
    u16 i;
    u16 n;
    if (r != 0) {
        t = EVENTDATA_SYSTEM_DirToPosEventType(mode);
        i = 0;
        n = c->f18;
        for (; i < n; i++, r++) {
            if (EVENTDATA_SYSTEM_IsPosEventGridHitIgnoreHeight((char *)r, key) != 0 && r->f6 == t) {
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
