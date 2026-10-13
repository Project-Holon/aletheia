/*
 * function: EVENTDATA_SYSTEM_SetConnectGridPos
 * address:  0x02162708
 * packet:   pkt_ov010_02162708
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 */

typedef unsigned short u16;
typedef unsigned int u32;

struct Ent {
    u16 pad0[3];
    u16 f6;
    u16 f8;
    u16 fa;
    u16 fc;
    u16 pad[3];
};

struct Ctx {
    u16 pad0[11];
    u16 f16;
    u16 pad18[6];
    struct Ent *f24;
};

void EVENTDATA_SYSTEM_SetConnectGridPos(struct Ctx *c, u32 idx, u16 a, u32 b, u16 e)
{
    struct Ent *p;
    if (c->f16 >= idx && c->f24 != 0) {
        p = &c->f24[idx];
        if (p->f6 == 0) {
            u16 *q;
            u16 t = (a << 4) + 8;
            q = (u16 *)p + 4;
            p->f8 = t;
            q[1] = b << 4;
            q[2] = (e << 4) + 8;
        }
    }
}
