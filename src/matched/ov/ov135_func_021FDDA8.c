/*
 * function: func_021FDDA8
 * address:  0x021FDDA8
 * packet:   pkt_021FDDA8
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_SetActorBgPriority  0x0204B84C  arm
 *   func_020355C4  0x020355C4  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 *   tbl_02203D38   0x02203D38  data  a1
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 x;
    u16 y;
    u16 z;
    u8 pri;
    u8 f7;
} ObjPos;

typedef struct {
    u8 page;
    u8 slot;
} Sel;

typedef struct {
    u16 x;
    u16 y;
    u16 anim;
} CurPos;

typedef struct {
    Sel sel[7];
    CurPos cur[1];
} SelTbl;

typedef struct {
    u8 pad0[0xBC0];
    void *res;
    void *set[3];
    u8 padBD0[0xBE8 - 0xBD0];
    void *set2;
    u8 padBEC[4];
    void *set3;
    void *cursor;
    void *mark;
    u8 padBFC[0xD2C - 0xBFC];
    void *btn[2];
} Obj;

extern const SelTbl tbl_02203D38;

extern void func_02082BCC(void *p, int v, int n);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
struct Obj;
extern void func_0204B92C(struct Obj *p, u32 v);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_SetActorBgPriority(void *o, int v);
extern u8 func_020355C4(void);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);

void func_021FDDA8(Obj *p)
{
    ObjPos pos;

    func_02082BCC(&pos, 0, sizeof(pos));
    pos.x = tbl_02203D38.cur[0].x;
    pos.y = tbl_02203D38.cur[0].y;
    p->cursor = CLACT_CreateActor(p->res, (u32)p->set2, (u32)p->set[1], (u32)p->set3, &pos, 0, 0x48);
    func_0204B92C(p->cursor, 1);
    CLACT_SetActorAnimSeq(p->cursor, tbl_02203D38.cur[0].anim);
    CLACT_SetActorBgPriority(p->cursor, 1);
    if (func_020355C4() == 1) {
        func_0204B3DC(p->cursor, 0);
    } else {
        func_0204B3DC(p->cursor, 1);
    }
    pos.x = 0xA0;
    pos.y = 0x20;
    p->mark = CLACT_CreateActor(p->res, (u32)p->set2, (u32)p->set[1], (u32)p->set3, &pos, 0, 0x48);
    CLACT_SetActorAnimSeq(p->mark, 4);
    func_0204B3DC(p->mark, 0);
    pos.x = 0xE4;
    pos.y = 0x75;
    p->btn[0] = CLACT_CreateActor(p->res, (u32)p->set[0], (u32)p->set[1], (u32)p->set[2], &pos, 0, 0x48);
    CLACT_SetActorAnimSeq(p->btn[0], 0x26);
    func_0204B3DC(p->btn[0], 0);
    pos.x = 0x8C;
    p->btn[1] = CLACT_CreateActor(p->res, (u32)p->set[0], (u32)p->set[1], (u32)p->set[2], &pos, 0, 0x48);
    CLACT_SetActorAnimSeq(p->btn[1], 0x27);
    func_0204B3DC(p->btn[1], 0);
    GFL_NET_RestartWithDefaultTimeout(0, 0x48);
}
