/*
 * function: ZONEDATA_SetDirectRailLocation
 * address:  0x020141A8
 * packet:   pkt_020141A8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The explicit-parameter initialiser of the 0x18-byte record that
 * ZONEDATA_SetZoneStartLocation fills from a table id: a = 1, b, c = -1, d, e = 0, f = 1,
 * the 0x12 byte = 1, then g/h/i from the three trailing parameters (two on
 * the stack) and the 0x13 byte from ZONEDATA_DirToRailKey(ZONEDATA_ExitDirToDir(d)).
 *
 * What closed it (wave 17, from 47 out): nothing new in the source; the
 * s16 field written -1 is the image's `subs r0, r5, #2` off the constant 1
 * kept in r5.  The earlier 47 was measured against a 92-byte extent that
 * ran over the unlabelled leaves at 0x020141DC; once 0x020141DC was seeded
 * (seed round 9) the extent is the real 52 bytes and this source is exact.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ZONEDATA_SetDirectRailLocation.c \
 *       --func ZONEDATA_SetDirectRailLocation --addr 0x020141A8 --cc 1.1p1 --thumb
 *
 * symbols:
 *   ZONEDATA_ExitDirToDir  0x02014274  thumb
 *   ZONEDATA_DirToRailKey  0x0201441C  thumb
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
    u8  on;     /* 0x12 */
    u8  kind;   /* 0x13 */
    s16 h;      /* 0x14 */
    u16 i;      /* 0x16 */
};

extern u32 ZONEDATA_ExitDirToDir(u32 a);
extern u8 ZONEDATA_DirToRailKey(int i);

void ZONEDATA_SetDirectRailLocation(struct t *p, int b, int d, u16 g, u16 i, s16 h)
{
    p->a = 1;
    p->b = b;
    p->c = -1;
    p->d = d;
    p->e = 0;
    p->f = 1;
    p->on = 1;
    p->g = g;
    p->i = i;
    p->h = h;
    p->kind = ZONEDATA_DirToRailKey(ZONEDATA_ExitDirToDir(d));
}
