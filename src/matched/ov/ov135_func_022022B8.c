/*
 * function: func_022022B8
 * address:  0x022022B8
 * packet:   pkt_022022B8
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0200CDE0  0x0200CDE0  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_02017F50  0x02017F50  thumb
 *   func_0220246C  0x0220246C  thumb
 *   func_0201A98C  0x0201A98C  thumb
 *   func_020076D0  0x020076D0  thumb
 *   func_022026BC  0x022026BC  thumb
 *   func_0200752C  0x0200752C  thumb
 *   func_0200AD94  0x0200AD94  thumb
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *sys;
    u8 pad4[4];
    void *party;
    u32 box;
    void *dex;
} Ctx;

typedef struct {
    Ctx *ctx;
    u8 pad4[0xDC - 4];
    u32 boxId;
    u32 pos;
} Work;

extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern void func_0200CDE0(void *dex, void *mon);
extern int func_0201AA18(void *party);
extern void func_02017E40(void *mon, u32 id, u32 v);
extern u8 func_02017F50(u32 species, u16 form, u32 pid);
extern void func_0220246C(void *p, int which);
extern u32 func_0201A98C(void *party, void *mon);
extern int func_020076D0(u32 s, u32 *a, u32 *b);
extern u32 func_022026BC(void *mon);
extern void func_0200752C(u32 s, u32 a, u32 e);
extern void func_0200AD94(void *p, u16 v);

void func_022022B8(Work *p, void *mon, u32 box, int hatch)
{
    u32 pos;
    u32 species;
    u32 form;
    u32 slot;

    func_02017E1C(mon, 6, 0);
    func_0200CDE0(p->ctx->dex, mon);
    box = 0xFF;
    if (func_0201AA18(p->ctx->party) == 6) {
        box = 0;
    }
    if (hatch != 0) {
        func_02017E40(mon, 9, 0x46);
        species = func_02017E1C(mon, 5, 0);
        form = func_02017E1C(mon, 0x6F, 0);
        func_02017E40(mon, 0x6E, func_02017F50((u16)species, form, func_02017E1C(mon, 0, 0)));
        func_0220246C(p->ctx->sys, 0);
    }
    if (box == 0xFF) {
        func_0201A98C(p->ctx->party, mon);
        slot = func_0201AA18(p->ctx->party);
        p->boxId = 0xFF;
        slot -= 1;
    } else {
        pos = 0;
        func_020076D0(p->ctx->box, &box, &pos);
        func_0200752C(p->ctx->box, box, func_022026BC(mon));
        p->boxId = box;
        slot = pos;
    }
    p->pos = slot;
    func_0200AD94(p->ctx->sys, 0);
}
