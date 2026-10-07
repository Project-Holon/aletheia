/*
 * file:     worldtrade_box_p07.c
 * unit:     yes
 * function: func_021F59E8, func_021F5A18, func_021F5A7C, func_021F5B8C, func_021F5CA4
 * address:  0x021F59E8
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_02045808 0x02045808 arm
 *   func_021F663C 0x021F663C thumb ov135
 *   func_021F4E98 0x021F4E98 thumb ov135
 *   func_020355C4 0x020355C4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021F6C48  0x021F6C48  thumb
 *   func_021F6BA4  0x021F6BA4  thumb
 *   func_021F6B40  0x021F6B40  thumb
 *   func_022025E4  0x022025E4  thumb
 *   func_021F6CDC  0x021F6CDC  thumb
 *   tbl_02202E24  0x02202E24  data  a1
 */
#include "../../matched/include/Obj00287.h"
#include "../../matched/include/Obj00018.h"

struct U16Vec;
struct Obj;
struct Actor;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct {
    u8 pad0[8];
    void *party;
    void *save;
} Ctx;

typedef struct {
    Ctx *ctx;
    u8 pad4[0x28 - 4];
    u32 state;
    u8 pad2C[0xC4 - 0x2C];
    u16 box;
    u16 slot;
    u8 padC8[0xB68 - 0xC8];
    void *msg;
    u8 padB6C[0xBFC - 0xB6C];
    u32 cursor;
} Work_021F5A7C;

typedef struct {
    u8 pad0[0xF0];
    u8 want[0x128 - 0xF0];
} Entry;

typedef struct {
    Ctx *ctx;
    u8 pad4[0x28 - 4];
    u32 state;
    u8 pad2C[0xC4 - 0x2C];
    u16 box;
    u16 slot;
    u8 padC8[0xD4 - 0xC8];
    int sel;
    u8 padD8[0x20C - 0xD8];
    Entry list[1];
    u8 pad334[0xB68 - 0x334];
    void *msg;
    u8 padB6C[0xBFC - 0xB6C];
    u32 cursor;
} Work_021F5B8C;

typedef struct {
    u8 pad0[0xBF4];
    u32 cursor;
} Work_021F5CA4;

extern u32 func_020307B0(void *p);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_020221A4(void);
extern void func_021F663C(u8 *, u32, u32, u32, u32, u32);
extern void func_021F4E98(u8 *, u32, u32);
extern u8 func_020355C4(void);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0204B9A0(struct Actor *a);
extern void func_020061E4(u32 se);
extern int func_021F6C48(void *party, void *save, int box, int slot);
extern int func_021F6BA4(void *party, void *save, int box, int slot);
extern void *func_021F6B40(void *party, void *save, int box, int slot);
extern void func_022025E4(u32 a, u32 b, u32 c);
extern int func_021F6CDC(void *mon, void *want);
extern int func_02035C08(const void *key);
extern void func_020355D8(u8 v);
void func_021F59E8(char *p);
int func_021F5A18(u8 *p);
void func_021F5A7C(Work_021F5A7C *p);
void func_021F5B8C(Work_021F5B8C *p);
int func_021F5CA4(Work_021F5CA4 *p);
extern const u8 tbl_02202E24[];

void func_021F59E8(char *p) { func_020307B0(((struct Obj00287 *)p)->fEAC); func_02045808(((struct Obj00287 *)p)->fB80); func_02045808(((struct Obj00287 *)p)->fB88); func_02045808(((struct Obj00287 *)p)->fB84); }

/*
 * precondition: entry mode at offset 0x20 must be 5 or 6; original
 *   leaves r4 unchanged for other modes at 021F5A32..021F5A38.
 */
int func_021F5A18(u8 *p)
{
    int index;
    if (func_020221A4()) {
        if (((struct Obj00018 *)p)->f20 == 5) {
            index = 0x15;
        } else if (((struct Obj00018 *)p)->f20 == 6) {
            index = 0x11;
        }
        func_021F663C(p, index, 1, 0, 0xf0f, 0);
        func_021F4E98(p, 3, 1);
        if (func_020355C4() == 1) {
            func_0204B3DC((struct Obj *)((struct Obj00018 *)p)->fBF4, 0);
        } else {
            func_0204B3DC((struct Obj *)((struct Obj00018 *)p)->fBF4, 1);
        }
    }
    return 2;
}


void func_021F5A7C(Work_021F5A7C *p)
{
    if (p->slot == 0x1E) {
        func_0204B3DC((struct Obj *)p->cursor, 1);
        func_0204B9A0((struct Actor *)p->cursor);
        p->state = 0x11;
        func_020061E4(0x551);
        return;
    }
    if (p->slot == 0x1F) {
        return;
    }
    switch (func_021F6C48(p->ctx->party, p->ctx->save, p->box, p->slot)) {
    case 1:
        func_020061E4(0x54C);
        if (func_021F6BA4(p->ctx->party, p->ctx->save, p->box, p->slot) != 0) {
            func_022025E4((u32)p->msg, 0, (u32)func_021F6B40(p->ctx->party, p->ctx->save, p->box, p->slot));
            func_021F663C((u8 *)p, 0x16, 1, 0, 0xF0F, 0);
            func_021F4E98((u8 *)p, 3, 7);
        } else {
            func_021F663C((u8 *)p, 0x1A, 1, 0, 0xF0F, 1);
            func_021F4E98((u8 *)p, 4, 1);
        }
        break;
    case 2:
        func_020061E4(0x54C);
        func_021F663C((u8 *)p, 0x21, 1, 0, 0xF0F, 1);
        func_021F4E98((u8 *)p, 4, 1);
        break;
    }
}


void func_021F5B8C(Work_021F5B8C *p)
{
    void *mon;

    if (p->slot == 0x1E) {
        func_0204B3DC((struct Obj *)p->cursor, 1);
        func_0204B9A0((struct Actor *)p->cursor);
        p->state = 0x11;
        return;
    }
    if (p->slot == 0x1F) {
        return;
    }
    switch (func_021F6C48(p->ctx->party, p->ctx->save, p->box, p->slot)) {
    case 1:
        mon = func_021F6B40(p->ctx->party, p->ctx->save, p->box, p->slot);
        if (func_021F6CDC(mon, p->list[p->sel].want) != 0) {
            if (func_021F6BA4(p->ctx->party, p->ctx->save, p->box, p->slot) != 0) {
                func_022025E4((u32)p->msg, 0, (u32)mon);
                func_021F663C((u8 *)p, 0x12, 1, 0, 0xF0F, 0);
                func_021F4E98((u8 *)p, 3, 9);
                func_020061E4(0x54C);
            } else {
                func_021F663C((u8 *)p, 0x1A, 1, 0, 0xF0F, 1);
                func_021F4E98((u8 *)p, 4, 1);
            }
        } else {
            func_020061E4(0x551);
        }
        break;
    case 0:
    case 2:
        func_020061E4(0x551);
        break;
    }
}


int func_021F5CA4(Work_021F5CA4 *p)
{
    int r = func_02035C08(tbl_02202E24);

    if (r != -1) {
        func_0204B3DC((struct Obj *)p->cursor, 0);
        func_020355D8(1);
    }
    return r;
}
