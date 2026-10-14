/*
 * function: WORLDTRADE_SEARCH_SelectButton
 * address:  0x021FEAE0
 * packet:   pkt_021FEAE0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORLDTRADE_SEARCH_GetSelectedButton  0x021FE9B0  thumb
 *   WORLDTRADE_SetActorPos  0x021F4FF4  thumb
 *   tbl_02203D38   0x02203D38  data  a1
 *   tbl_02203D46   0x02203D46  data  a2
 *
 * Select cursor entry i from the {page, slot} byte table: page 0 stores
 * the slot at +0x28 of the state block, any other page sets the +0x24
 * flag and stores it at +0x2C. Then redraw the cursor sprite at +0xBF4
 * from the 8-byte position table.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 page;
    u8 slot;
} Sel;

typedef struct {
    u16 x;
    u16 y;
    u16 pad[2];
} CurPos;

typedef struct {
    u8 pad0[0x24];
    int f24;
    int f28;
    int f2C;
} State;

typedef struct {
    u8 pad0[0xBF4];
    u32 cursor;
    u8 padBF8[0xE00 - 0xBF8];
    State *st;
} Work;

extern const Sel tbl_02203D38[];
extern const CurPos tbl_02203D46[];

extern int WORLDTRADE_SEARCH_GetSelectedButton(Work *p);
extern void WORLDTRADE_SetActorPos(u32 a, u32 b, u32 c);

void WORLDTRADE_SEARCH_SelectButton(Work *p, int i)
{
    int a;
    int b;

    if (tbl_02203D38[i].page == 0) {
        p->st->f24 = 0;
        p->st->f28 = tbl_02203D38[i].slot;
    } else {
        p->st->f24 = 1;
        p->st->f2C = tbl_02203D38[i].slot;
    }
    a = WORLDTRADE_SEARCH_GetSelectedButton(p);
    b = WORLDTRADE_SEARCH_GetSelectedButton(p);
    WORLDTRADE_SetActorPos(p->cursor, tbl_02203D46[a].x, tbl_02203D46[b].y);
}
