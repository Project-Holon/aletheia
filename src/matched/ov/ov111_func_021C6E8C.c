/*
 * function: func_021C6E8C
 * address:  0x021C6E8C
 * packet:   pkt_ov111_021C6E8C
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_CreateActor  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   CLACT_SetActorAutoAnimSpeed  0x0204B954  arm
 *   func_0204B92C  0x0204B92C  arm
 *   d_021C87A4     0x021C87A4  data  a4
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 x;
    u16 y;
    u8 chr;
    u8 cell;
    u8 anm;
    u8 pri;
    u32 z;
} ObjTemplate;

typedef struct {
    ObjTemplate t[8];
} ObjTemplateTable;

typedef struct {
    u16 x;
    u16 y;
    u16 z;
    u8 pad6;
    u8 pri;
} ObjPos;

typedef struct {
    u32 a;
    u32 b;
    u32 c;
} ResSet;

typedef struct {
    u16 heap;
    u8 pad2[2];
    u32 f4;
    u8 pad8[0x98 - 8];
    void *obj[8];
    ResSet res[2];
} Anim;

struct Obj;
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
struct Actor;
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void CLACT_SetActorAutoAnimSpeed(struct Actor *a, u32 v);
extern void func_0204B92C(struct Obj *p, u32 v);
extern const ObjTemplateTable d_021C87A4;

void func_021C6E8C(Anim *a)
{
    ObjTemplateTable tbl = d_021C87A4;
    ObjPos pos;
    int i;

    for (i = 0; i < 8; i++) {
        pos.x = tbl.t[i].x;
        pos.y = tbl.t[i].y;
        pos.z = tbl.t[i].z;
        pos.pri = tbl.t[i].pri;
        a->obj[i] = CLACT_CreateActor((void *)a->f4, a->res[tbl.t[i].cell].a, a->res[tbl.t[i].chr].b, a->res[tbl.t[i].anm].c, &pos, 1, a->heap);
        func_0204B3DC(a->obj[i], 1);
        CLACT_SetActorAutoAnimSpeed(a->obj[i], 0x1000);
        func_0204B92C(a->obj[i], 1);
        if (i == 3) {
            func_0204B3DC(a->obj[i], 0);
        }
    }
    func_0204B3DC(a->obj[5], 0);
}
