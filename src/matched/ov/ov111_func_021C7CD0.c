/*
 * function: VIEWER_ACTOR_HandleDrag
 * address:  0x021C7CD0
 * packet:   pkt_ov111_021C7CD0
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VIEWER_ACTOR_WrapAngle  0x021C7C78  thumb
 *   VIEWER_ACTOR_StepBounce  0x021C7C94  thumb
 *   d_021C88B4  0x021C88B4  data
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;

typedef struct {
    u8 pad0[0xC];
    void *fC;
} Res;

typedef struct {
    u8 pad0[4];
    void *f4;
    u8 pad8[4];
    int fC;
    int f10;
} Parent;

typedef struct {
    void *f0;
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x20 - 0x18];
    void *f20;
    void *f24;
    void *f28;
    void *f2C[7];
    void *f48;
    void *f4C;
    void *f50;
    void *f54;
    void *f58;
    void *f5C[8];
    void *f7C[24];
    void *fDC;
    void *fE0;
    void *fE4;
    void *fE8;
    void *fEC;
    void *fF0;
    void *fF4;
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    Parent *f108;
    int state;
    int f110;
    u16 f114;
    u16 f116;
    int f118;
    int f11C;
    u8 pad120[2];
    u16 f122;
    u8 pad124[4];
    int f128;
    int f12C;
    int f130;
    u8 pad134[4];
    int f138;
    int f13C;
    int f140;
    int f144;
    int f148;
    void *f14C[3];
    Res *f158[3];
    void *f164[3];
    Res *f170[3];
    u8 f17C[8];
    void *f184;
    int f188[8];
    u8 f1A8[8];
    u8 f1B0[8];
} Work;

extern int VIEWER_ACTOR_WrapAngle(int v, int range);
extern void VIEWER_ACTOR_StepBounce(Work *p);
extern const int d_021C88B4[8];

void VIEWER_ACTOR_HandleDrag(Work *p, int unused, int touch, int x)
{
    int i;
    int v;
    int d;

    if (p->f122 == 0 && touch != 0) {
        p->f138 = p->f13C;
        p->f130 = x;
    } else if (p->f122 == 1 && touch == 1) {
        p->f13C = p->f138 + ((x - p->f130) << 10);
        p->f13C = VIEWER_ACTOR_WrapAngle(p->f13C, 0x100000);
    } else if (p->f122 == 1 && touch == 0) {
        if (p->f12C != 0) {
            p->f140 = (p->f128 - p->f12C) << 11;
        }
        if (p->f140 > 40000) {
            p->f140 = 40000;
        } else if (p->f140 < -40000) {
            p->f140 = -40000;
        }
    }
    if (p->f122 == 0 && touch == 0) {
        p->f13C = p->f13C + p->f140;
        p->f13C = VIEWER_ACTOR_WrapAngle(p->f13C, 0x100000);
        if (p->f144 >= 0) {
            if (p->f148 > p->f13C - 50000 && p->f148 < p->f13C + 50000) {
                p->f140 = 0;
                p->f13C = p->f148;
                p->f144 = -1;
            }
        } else {
            VIEWER_ACTOR_StepBounce(p);
            for (i = 0; i < 8; i++) {
                v = d_021C88B4[i];
                if (v > p->f13C - 10000 && v < p->f13C + 10000) {
                    d = p->f140;
                    if (d < 0) {
                        d = -d;
                    }
                    if (d < 10000) {
                        p->f13C = v;
                        p->f140 = 0;
                    }
                }
            }
        }
    }
    p->f12C = p->f128;
    p->f128 = x;
    p->f122 = touch;
}
