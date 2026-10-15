/*
 * function: GAME_BEACON_AddLog
 * address:  0x0202685C
 * packet:   pkt_0202685C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The ring insert: advance hi with a wrap at 30 (pushing lo along when the
 * ring is full), grant the record's items through the bag (0x0200E394
 * family), mark matching entries in the 0x0200C0F0 table, then clear the
 * slot, struct-copy the 92-byte payload in, zero +0x5c, set the live bit
 * and bump the +0xBAE fill count.
 *
 * BLOCKER: label.  Every concrete byte reproduces (516/516).  The four
 * `bl 0x02167394` sites are the only references to that address in the
 * whole image, all inside this range, and no overlay listing labels a
 * function there (ov009 and ov010 both cover the address, interior to
 * code), so no class attests it and no cut helps (--suggest-split).
 *
 * Two spellings the bytes need: the item-amount helper takes an INT id
 * (the `cmp r,#0x1d` is on the untruncated value; the callees' u8
 * parameters produce the lsls/lsrs at each call), and the slot is one
 * pointer `&slots[hi]` which the compiler keeps as base+0x64 and
 * hi*0x60 in two stack slots.
 *
 * symbols:
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   SYMBOL_SAVE_GetBitBlock  0x0200E394  thumb
 *   MISC_SAVEDATA_GetStatusByte  0x0200E44C  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   func_02167394  0x02167394  thumb
 *   SYMBOL_SAVE_GetQuestionnaireAnswer  0x0200E3A4  thumb
 *   MISC_SAVEDATA_IsTallyFull  0x0200E49C  thumb
 *   MISC_SAVEDATA_AddHalfwordClamped  0x0200E460  thumb
 *   MISC_SAVEDATA_AddTallyValue  0x0200E4CC  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_0200C33C  0x0200C33C  thumb
 *   func_0200C364  0x0200C364  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 */
#include "../include/Obj00747.h"
typedef signed char    s8;
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Payload { u32 w[23]; };
struct Rec { struct Payload p; u16 f5c; u8 pad5e[2]; };

struct Req {
    u8   pad00[0x0C];
    u32  f0clo : 16;
    u32  trainer : 10;
    u32  f0chi : 6;
    u8   pad10[0x50 - 0x10];
    u8   f50[0x10];
};

struct Big;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *SYMBOL_SAVE_GetBitBlock(void *p);
extern int   MISC_SAVEDATA_GetStatusByte(void *p, int i);
extern u32   func_02167394(u8 id);
extern u32   SYMBOL_SAVE_GetQuestionnaireAnswer(void *p, u8 id);
extern u32 MISC_SAVEDATA_IsTallyFull(u8 *p, u32 a, u32 count);
extern void MISC_SAVEDATA_AddHalfwordClamped(char *p, int idx, int v);
extern void MISC_SAVEDATA_AddTallyValue(u8 *a0, u32 a1, u32 a2, int a3);
extern void *func_0200C0F0(void *p);
struct Blk34;
extern int func_0200C33C(struct Blk34 *p, u32 i);
extern void func_0200C364(struct Blk34 *p, u8 i, int v);
extern void  MI_CpuFill8(void *d, int v, u32 n);

static inline u32 calc(struct Req *r, int id)
{
    u32 v;
    if (id == 0x1d) {
        v = r->trainer / 10 + 1;
        if (v > func_02167394(id))
            v = func_02167394(id);
    } else {
        v = SYMBOL_SAVE_GetQuestionnaireAnswer(r->f50, id);
    }
    return v;
}

void GAME_BEACON_AddLog(u8 *base, struct Req *r)
{
    void *bag;
    void *sys;
    void *bag2;
    void *tbl;
    int i;
    int j;
    int id;
    u32 v;
    struct Rec *rec;

    (((struct Obj00747 *)base)->fBAD)++;
    if (((struct Obj00747 *)base)->fBAD >= 30)
        ((struct Obj00747 *)base)->fBAD = 0;

    rec = (struct Rec *)(base + 0x64) + ((struct Obj00747 *)base)->fBAD;
    if (((struct Obj00747 *)base)->fBAE > 0 && ((struct Obj00747 *)base)->fBAD == ((struct Obj00747 *)base)->fBAC) {
        (((struct Obj00747 *)base)->fBAC)++;
        if (((struct Obj00747 *)base)->fBAC >= 30)
            ((struct Obj00747 *)base)->fBAC = 0;
    }

    bag = SYMBOL_SAVE_GetBitBlock(GAME_DATA_GetSaveControl(((struct Obj00747 *)base)->f0));
    for (i = 0; i < 3; i++) {
        id = MISC_SAVEDATA_GetStatusByte(bag, i);
        if (id != 0xff) {
            v = calc(r, id);
            if (v != 0 && MISC_SAVEDATA_IsTallyFull(bag, id, v) == 0) {
                MISC_SAVEDATA_AddHalfwordClamped(bag, id, 1);
                MISC_SAVEDATA_AddTallyValue(bag, id, v, 1);
                ((struct Obj00747 *)base)->fBAF = 1;
            }
        }
    }

    sys = GAME_DATA_GetSaveControl(((struct Obj00747 *)base)->f0);
    bag2 = SYMBOL_SAVE_GetBitBlock(sys);
    tbl = func_0200C0F0(sys);
    for (i = 0; i < 3; i++) {
        id = func_0200C33C(tbl, (u8)i);
        if (id != 0xff) {
            for (j = 0; j < 3; j++) {
                if (id == MISC_SAVEDATA_GetStatusByte(bag2, j)) {
                    if (calc(r, id) != 0)
                        func_0200C364(tbl, i, 1);
                }
            }
        }
    }

    MI_CpuFill8(rec, 0, 0x60);
    rec->p = *(struct Payload *)r;
    rec->f5c = 0;
    ((struct Obj00747 *)base)->fBA4 |= 1 << ((struct Obj00747 *)base)->fBAD;
    if (((struct Obj00747 *)base)->fBAE < 30)
        (((struct Obj00747 *)base)->fBAE)++;
}
