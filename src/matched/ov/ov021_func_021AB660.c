/*
 * function: FLD_SCENEAREA_Update
 * address:  0x021AB660
 * packet:   pkt_ov021_021AB660
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The loop's id load is spelled as byte-base + i * sizeof + 0x40: with
 * o->recs[i].f40, (o->recs + i)->f40, a Rec * local, a recs local, a
 * u16 ids[4] member or a cast through &o->recs[i], the records base and the
 * i * 0x48 product swap r3/r6 (7 bytes); int i and declaration order do
 * not move it.
 *
 * symbols:
 *   FLD_SCENEAREA_RunCheck  0x021AB798  thumb  ov021
 *   FLD_SCENEAREA_RunAction  0x021AB7C0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Rec {
    u8 pad00[0x40];
    u16 f40;
    u16 f42;
    u16 f44;
    u16 f46;
};

struct Obj {
    u8 pad00[8];
    struct Rec *recs;
    void *f0C;
    u32 count;
    int cur;
    int f18;
    u32 f1C;
};

extern int FLD_SCENEAREA_RunCheck(void *tbl, u16 id, struct Obj *o, struct Rec *r, void *arg);
extern void FLD_SCENEAREA_RunAction(void *tbl, u16 id, struct Obj *o, struct Rec *r, void *arg);

int FLD_SCENEAREA_Update(struct Obj *o, void *arg)
{
    u32 i;
    int sel;

    if (o->f18 == 0)
        return -1;
    o->f1C = 0xFFFF;
    sel = -1;
    for (i = 0; i < o->count; i++) {
        if (FLD_SCENEAREA_RunCheck(o->f0C, *(u16 *)((u8 *)o->recs + i * sizeof(struct Rec) + 0x40), o, &o->recs[i], arg))
            sel = i;
    }
    if (sel != o->cur) {
        if (o->cur != -1) {
            FLD_SCENEAREA_RunAction(o->f0C, o->recs[o->cur].f46, o, &o->recs[o->cur], arg);
            o->f1C = o->recs[o->cur].f46;
        }
        if (sel != -1) {
            FLD_SCENEAREA_RunAction(o->f0C, o->recs[sel].f44, o, &o->recs[sel], arg);
            o->f1C = o->recs[sel].f44;
        }
        o->cur = sel;
    } else if (o->cur != -1) {
        FLD_SCENEAREA_RunAction(o->f0C, o->recs[o->cur].f42, o, &o->recs[o->cur], arg);
        o->f1C = o->recs[o->cur].f42;
    }
    return o->cur;
}
