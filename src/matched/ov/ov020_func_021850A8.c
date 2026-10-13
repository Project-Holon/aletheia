/*
 * function: EVENT_MAPCHANGE_CreateFixedZoneEvent
 * address:  0x021850A8
 * packet:   pkt_ov020_021850A8
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * blocker: byte-correct; the bl to 0x02014184 has no witness (unlabelled ARM9
 * Thumb leaf, sole caller in range). Evidence class: label / sole-ref/code.
 * Leaf 0x02014184 (arm9, Thumb, EXACT with match.py one, the integrator's to file):
 *   typedef short s16;
 *   typedef struct { int f0; s16 h4, h6, h8, ha; int fc, f10, f14, f18; } Obj;
 *   void ZONEDATA_SetDirectLocation(Obj *o, s16 a, s16 b, int c, int d, int e)
 *   { o->f0 = 1; o->h4 = a; o->h6 = -1; o->h8 = b; o->ha = 0; o->fc = 0;
 *     o->f10 = c; o->f14 = d; o->f18 = e; }
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   ZONEDATA_SetDirectLocation  0x02014184  thumb
 *   ZONEDATA_DirToExitDir  0x020142A4  thumb
 *   EVENT_MAPCHANGE_RunFixedZoneEvent  0x02184C78  thumb  ov020
 *   EVENT_MAPCHANGE_InitWork  0x02184CEC  thumb  ov020
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short s16;

struct Desc;
struct Obj;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
void ZONEDATA_SetDirectLocation(void *d, int a, s16 b, int c, int e, int f);
u32 ZONEDATA_DirToExitDir(u32 idx);
int EVENT_MAPCHANGE_RunFixedZoneEvent(void *ctx, int *st, int *p);
void EVENT_MAPCHANGE_InitWork(void **o, void *p);

void *EVENT_MAPCHANGE_CreateFixedZoneEvent(void *p)
{
    void *r0v = func_020122C0(p, 0, EVENT_MAPCHANGE_RunFixedZoneEvent, 0x9c);
    char *r4 = func_020124E8(r0v);

    EVENT_MAPCHANGE_InitWork((void **)r4, p);
    ZONEDATA_SetDirectLocation(r4 + 0x10, 0x1A6, ZONEDATA_DirToExitDir(0), 0x2E << 14, 0, 0x3E << 14);
    *(int *)(r4 + 0x2c) = 0;
    return r0v;
}
