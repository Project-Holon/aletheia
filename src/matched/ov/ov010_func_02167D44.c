/*
 * function: BSUBWAY_COMM_RecvPlayerData
 * address:  0x02167D44
 * packet:   pkt_ov010_02167D44
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * lever: Const source halfwords restores c[0]/c[1] load scheduling.
 * symbols:
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    u8 pad0[0xb];
    u8 f0b;
    u16 lo : 5;
    u16 hi : 3;
    u16 rest : 8;
    u8 pad1[0xa];
    u16 f18;
    u16 f1a;
    u16 f1c;
    u8 pad2[4];
    u16 f22;
    u16 f24;
    u8 pad3[0x724 - 0x26];
    u8 f724;
    u8 pad4[3];
    u16 f728;
} D;

extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);

void BSUBWAY_COMM_RecvPlayerData(int a, int b, const u16 *c, D *d)
{
    u16 n = 0;
    u16 w;
    u16 v;
    d->f724++;
    if (a != GFL_NET_SYSTEM_GetCurrentAid()) {
        w = c[0];
        v = c[1];
        d->f0b = w;
        d->f1a = v;
        d->f1c = c[2];
        d->f18 = c[3];
        d->hi = d->f0b + 5;
        if (d->f22 == v || d->f22 == d->f1c)
            n += 1;
        if (d->f24 == v || d->f24 == d->f1c)
            n += 2;
        d->f728 = n;
    }
}
