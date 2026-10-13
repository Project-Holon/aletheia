/*
 * function: ENCEFF_Start
 * address:  0x021CF498
 * packet:   pkt_ov021_021CF498
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Picks a row of the 0x25-entry table at 0x021DB4FC (0x14 bytes each) and calls its
 * builder.
 *
 * symbols:
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GFL_HEAP_GetAllocatableSize  0x0203038C  arm
 *   ENCEFF_LoadOverlay  0x021CF564  thumb  ov021
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   func_020124E8  0x020124E8  thumb
 *   d_021DB4FC     0x021DB4FC  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Ent {
    u32 (*fn)(u32, void *, u32);   /* 0x00 */
    u32 f04;                       /* 0x04 */
    int f08;                       /* 0x08 */
    u32 f0c;                       /* 0x0C */
    u32 f10;                       /* 0x10 */
} Ent;

typedef struct Ctx {
    u32 f00;
    u32 f04;
    void *f08;
} Ctx;

extern Ent d_021DB4FC[];

struct Evt;
struct Obj;
extern void *FIELDMAP_GetGameSystem(void *p);
extern u32  GFL_HEAP_GetAllocatableSize(u32 a);
extern void ENCEFF_LoadOverlay(Ctx *c);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern void *func_020124E8(struct Obj *p);

void ENCEFF_Start(Ctx *c, u32 x, int idx)
{
    u32 r;
    u32 y;
    void *p = c->f08;

    y = (u32)FIELDMAP_GetGameSystem(p);

    if (idx >= 0x25) {
        idx = 0;
    }
    if (GFL_HEAP_GetAllocatableSize(0x15) < d_021DB4FC[idx].f10) {
        idx = 7;
    }
    if (d_021DB4FC[idx].f08 != -1) {
        ENCEFF_LoadOverlay(c);
    }
    r = d_021DB4FC[idx].fn(y, p, d_021DB4FC[idx].f0c);
    GAME_EVENT_CallEvent((struct Evt *)x, (struct Evt **)r);
    c->f00 = (u32)func_020124E8((struct Obj *)r);
    c->f04 = d_021DB4FC[idx].f04;
}
