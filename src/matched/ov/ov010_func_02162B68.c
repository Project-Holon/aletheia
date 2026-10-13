/*
 * function: EVENTDATA_SYSTEM_CalcConnectGridExitOffset
 * address:  0x02162B68
 * packet:   pkt_ov010_02162B68
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   EVENTDATA_SYSTEM_ConnectExitDirToDir  0x02162C54  thumb  ov010
 */

typedef unsigned short u16;
typedef short s16;

struct Sub {
    s16 f0;
    s16 f2;
    s16 f4;
    u16 f6;
    u16 f8;
};

struct Box {
    u16 pad0[4];
    struct Sub s;
};

typedef unsigned char  u8;
extern int EVENTDATA_SYSTEM_ConnectExitDirToDir(u8 *p);

u16 EVENTDATA_SYSTEM_CalcConnectGridExitOffset(struct Box *b, int *pos)
{
    struct Sub *s;
    int m = EVENTDATA_SYSTEM_ConnectExitDirToDir((u8 *)b);
    s = &b->s;
    if (s->f6 > 1)
        return (s->f6 << 4) | (((pos[0] >> 12) - s->f0) / 16) | (m << 8);
    if (s->f8 > 1)
        return (s->f8 << 4) | (((pos[2] >> 12) - s->f4) / 16) | (m << 8);
    return (m << 8) | 0x10;
}
