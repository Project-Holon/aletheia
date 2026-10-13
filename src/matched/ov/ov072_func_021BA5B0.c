/*
 * function: TOWNMAP_MapSetZoom
 * address:  0x021BA5B0
 * packet:   pkt_ov072_021BA5B0
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TOWNMAP_MapSetScroll  0x021BA638  thumb  ov072
 *   TOWNMAP_TownSetScale  0x021BAD10  thumb  ov072
 *   TOWNMAP_TownSetScroll  0x021BAD84  thumb  ov072
 *   TOWNMAP_UpdateMarkerPosition  0x021BAF3C  thumb  ov072
 *   d_021BBB78     0x021BBB78  data  ov072
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 f0;
    int f4;
    char *f8;
    u32 fC;
    int f10;
    int f14;
    short f18;
    short f1A;
    u16 f1C;
    u16 f1E;
} W;

extern char d_021BBB78[];
extern void TOWNMAP_MapSetScroll(W *p, int *v);
extern void TOWNMAP_TownSetScale(char *p, int s, char *r);
extern void TOWNMAP_TownSetScroll(int *p, int *b);
extern void TOWNMAP_UpdateMarkerPosition(u32 *p, const u32 *v);

void TOWNMAP_MapSetZoom(W *p, u32 s, const int *v)
{
    u32 i;
    int t[2];

    if (s == 0x1000) {
        p->f18 = 0;
        p->f1A = 0;
        p->f1C = 0;
        p->f1E = 0;
    } else {
        p->f18 = -0x48;
        p->f1A = -0x80;
        p->f1C = 0x80;
        p->f1E = 0x60;
    }
    t[0] = -v[0];
    t[1] = -v[1];
    TOWNMAP_MapSetScroll(p, t);
    for (i = 0; i < p->fC; i++) {
        TOWNMAP_TownSetScale(p->f8 + i * 0x44, s, d_021BBB78);
        TOWNMAP_TownSetScroll((int *)(p->f8 + i * 0x44), &p->f10);
    }
    TOWNMAP_UpdateMarkerPosition((u32 *)((char *)p + 0x20), (const u32 *)((int *)&p->f10));
}
