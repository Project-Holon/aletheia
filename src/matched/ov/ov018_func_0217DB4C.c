/*
 * function: INTRUDE_SUBDISP_CreatePlayerMarkActors
 * address:  0x0217DB4C
 * packet:   pkt_ov018_0217DB4C
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_CreateActor  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_0204B92C  0x0204B92C  arm
 *   d_021836E4  0x021836E4  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct { u16 a, b, c, d; } Rect;

struct Obj;
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B3DC(struct Obj *, unsigned int);
extern void func_0204B6F4(struct Obj *o, unsigned int v, unsigned int flag);
typedef unsigned int   u32;
struct Obj;
extern void func_0204B92C(struct Obj *p, u32 v);
extern const Rect d_021836E4;

void INTRUDE_SUBDISP_CreatePlayerMarkActors(int *p, void *a1)
{
    Rect r;
    int i;

    r = d_021836E4;
    for (i = 9; i <= 11; i++) {
        p[0x5c / 4 + i] = (int)CLACT_CreateActor((void *)p[0x54 / 4], p[1], p[2], p[4], &r, 0, 0x70);
        func_0204B6F4((struct Obj *)p[0x5c / 4 + i], (u8)(i - 8), 1);
        func_0204B3DC((struct Obj *)p[0x5c / 4 + i], 0);
    }
}
