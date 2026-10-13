/*
 * function: ZONEDATA_SetZoneStartLocation
 * address:  0x02014204
 * packet:   pkt_020141A8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocker:  matched - 0x02013C70's only call site image-wide is the one
 *           inside this function, and src/pending/ZONEDATA_IsRailMap.c is itself
 *           only MATCH (its pool word for _RailMapZoneTable has no outside
 *           witness), so no `matched` entry can attest the site.  Every
 *           concrete byte here is correct; --suggest-split reports no
 *           viable cut.
 * symbols:
 *   ZONEDATA_GetStartRailPos   0x02013B90  thumb
 *   ZONEDATA_GetStartPos   0x02013B74  thumb
 *   ZONEDATA_IsRailMap  0x02013C70  thumb
 *   ZONEDATA_InitLocation  0x020140F8  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

struct t {
    u32 a;      /* 0x00 */
    u16 b;      /* 0x04 */
    s16 c;      /* 0x06 */
    u16 d;      /* 0x08 */
    u16 e;      /* 0x0a */
    u32 f;      /* 0x0c */
    u16 g;      /* 0x10 */
    u8  pad[2];
    u16 h;      /* 0x14 */
    u16 i;      /* 0x16 */
};

struct v3 { u32 x, y, z; };

extern void ZONEDATA_InitLocation(int p0);
extern int ZONEDATA_IsRailMap(u32 a);
extern void ZONEDATA_GetStartRailPos(u32 id, u32 *out);
extern void ZONEDATA_GetStartPos(u32 id, u32 *out);

void ZONEDATA_SetZoneStartLocation(struct t *p, int id)
{
    struct v3 v;

    ZONEDATA_InitLocation((int)p);
    p->a = 1;
    p->b = id;
    p->c = -1;
    p->d = 2;
    p->e = 0;
    if (ZONEDATA_IsRailMap(id) != 0) {
        ZONEDATA_GetStartRailPos(id, (u32 *)(&v));
        p->f = 1;
        *((u8 *)p + 0x12) = 1;
        p->g = v.x;
        p->i = v.y;
        p->h = v.z;
    } else {
        ZONEDATA_GetStartPos(id, (u32 *)(&v));
        p->f = 0;
        *(struct v3 *)((u8 *)p + 0x10) = v;
    }
}
