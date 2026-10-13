/*
 * function: INTRUDE_SUBDISP_CreateTownMarkActors
 * address:  0x0217DBAC
 * packet:   pkt_ov018_0217DBAC
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
 *   d_021836DC  0x021836DC  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct { u16 a, b, c, d; } Rect;

struct Obj;
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B3DC(struct Obj *, unsigned int);
typedef unsigned int   u32;
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_0204B92C(struct Obj *, unsigned int);
extern const Rect d_021836DC;

void INTRUDE_SUBDISP_CreateTownMarkActors(int *p, void *a1)
{
    Rect r;
    int i;

    r = d_021836DC;
    for (i = 12; i <= 14; i++) {
        p[0x5c / 4 + i] = (int)CLACT_CreateActor((void *)p[0x54 / 4], p[1], p[2], p[4], &r, 0, 0x70);
        func_0204B6F4((struct Obj *)p[0x5c / 4 + i], (u8)(i - 11), 1);
        func_0204B3DC((struct Obj *)p[0x5c / 4 + i], 0);
        func_0204B92C((struct Obj *)p[0x5c / 4 + i], 1);
    }
}
