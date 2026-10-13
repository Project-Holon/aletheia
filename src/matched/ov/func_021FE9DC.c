/*
 * function: func_021FE9DC
 * address:  0x021FE9DC
 * packet:   pkt_021FE9DC
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   KEY_GetTrg  0x020362DC  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   func_021FE9B0  0x021FE9B0  thumb
 *   func_021F4FF4  0x021F4FF4  thumb
 *   tbl_02203D46   0x02203D46  data  a2
 *
 * Move the menu cursor by the pressed d-pad key: up and down step the
 * +0x28 row (page 0, rows 0..3) or the +0x2C row (page 1, rows 0..2),
 * right and left switch the +0x24 page. A real move plays sound 0x548
 * and sets the cursor sprite's animation from the position table; the
 * cursor is then placed at the table position of the current slot.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 x;
    u16 y;
    u16 anim;
    u16 pad;
} CurPos;

typedef struct {
    u8 pad0[0x24];
    int page;
    int row0;
    int row1;
} State;

typedef struct {
    u8 pad0[0xBF4];
    u32 cursor;
    u8 padBF8[0xE00 - 0xBF8];
    State *st;
} Work;

extern const CurPos tbl_02203D46[];

extern u32 KEY_GetTrg(void);
extern void GFL_USE_PlaySeDefaultVolume(u32 se);
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern int func_021FE9B0(Work *p);
extern void func_021F4FF4(u32 a, u32 b, u32 c);

void func_021FE9DC(Work *p)
{
    int a;
    int b;

    if (KEY_GetTrg() & 0x40) {
        if (p->st->page == 0) {
            if (p->st->row0 > 0) {
                p->st->row0--;
                GFL_USE_PlaySeDefaultVolume(0x548);
                CLACT_SetActorAnimSeq((struct Obj *)p->cursor, tbl_02203D46[func_021FE9B0(p)].anim);
            }
        } else {
            if (p->st->row1 > 0) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                p->st->row1--;
                CLACT_SetActorAnimSeq((struct Obj *)p->cursor, tbl_02203D46[func_021FE9B0(p)].anim);
            }
        }
    } else if (KEY_GetTrg() & 0x80) {
        if (p->st->page == 0) {
            if (p->st->row0 < 3) {
                p->st->row0++;
                GFL_USE_PlaySeDefaultVolume(0x548);
                CLACT_SetActorAnimSeq((struct Obj *)p->cursor, tbl_02203D46[func_021FE9B0(p)].anim);
            }
        } else {
            if (p->st->row1 < 2) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                p->st->row1++;
                CLACT_SetActorAnimSeq((struct Obj *)p->cursor, tbl_02203D46[func_021FE9B0(p)].anim);
            }
        }
    } else if (KEY_GetTrg() & 0x10) {
        if (p->st->page != 1) {
            p->st->page = 1;
            GFL_USE_PlaySeDefaultVolume(0x548);
            CLACT_SetActorAnimSeq((struct Obj *)p->cursor, tbl_02203D46[func_021FE9B0(p)].anim);
        } else {
            p->st->page = 1;
        }
    } else if (KEY_GetTrg() & 0x20) {
        if (p->st->page != 0) {
            p->st->page = 0;
            GFL_USE_PlaySeDefaultVolume(0x548);
            CLACT_SetActorAnimSeq((struct Obj *)p->cursor, tbl_02203D46[func_021FE9B0(p)].anim);
        } else {
            p->st->page = 0;
        }
    }
    a = func_021FE9B0(p);
    b = func_021FE9B0(p);
    func_021F4FF4(p->cursor, tbl_02203D46[a].x, tbl_02203D46[b].y);
}
