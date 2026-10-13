/*
 * function: EVENTDATA_SYSTEM_GetConnectExitRailLocation
 * address: 0x02162D90
 * packet: pkt_ov010_02162D90
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * lever: const source pointer schedules fa between the signed load and output store.
 * following: two-byte alignment padding at 0x02162DFE.
 * symbols:
 *   EVENTDATA_SYSTEM_ConnectExitDirToDir 0x02162C54 thumb ov010
 *   EVENTDATA_SYSTEM_CalcExitOffset 0x02162AA4 thumb ov010
 *   ZONEDATA_DirToRailKey 0x0201441C thumb
 */
typedef unsigned short u16;
typedef unsigned char u8;
typedef short s16;
struct Sub { u16 f0; u16 f2; s16 f4; u16 f6; u16 f8; u16 fa; };
struct Box { u16 pad0[4]; struct Sub s; };
struct Out { u16 f0; u8 f2; u8 f3; s16 f4; u16 f6; };
extern int EVENTDATA_SYSTEM_ConnectExitDirToDir(u8 *p);
extern u16 EVENTDATA_SYSTEM_CalcExitOffset(int q, int m, int a, int b, u16 n);
extern u8 ZONEDATA_DirToRailKey(int m);
void EVENTDATA_SYSTEM_GetConnectExitRailLocation(const struct Box *b, int q, struct Out *o)
{
    const struct Sub *s = &b->s;
    int m = EVENTDATA_SYSTEM_ConnectExitDirToDir((u8 *)b);
    u16 fa;
    o->f0 = b->s.f0;
    o->f2 = 1;
    o->f3 = ZONEDATA_DirToRailKey(m);
    o->f4 = s->f4;
    fa = s->fa;
    o->f6 = s->f2;
    if (s->f8 > 1) {
        o->f4 = o->f4 + (s16)EVENTDATA_SYSTEM_CalcExitOffset(q, m, 1, fa, s->f8);
    } else if (s->f6 > 1) {
        o->f6 = o->f6 + EVENTDATA_SYSTEM_CalcExitOffset(q, m, 1, fa, s->f6);
    }
}
