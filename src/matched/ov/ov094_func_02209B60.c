/*
 * function: BTLV_FINGER_CURSOR_Start
 * address:  0x02209B60
 * packet:   pkt_ov094_02209B60
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The f24 store is written out in both arms (the cross-jumped-tail idiom):
 * then-arm `str` is cross-jumped onto the else-arm copy, giving beq/b/movs.
 *
 * symbols:
 *   d_0220AC10     0x0220AC10  data   ov094  a4
 *   BTLV_FINGER_CURSOR_DeleteActor  0x02209C18  thumb  ov094
 *   BTLV_FINGER_CURSOR_AnimCallback  0x02209C30  thumb  ov094
 *   CLACT_CreateAffineActor  0x0204B324  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_SetActorAnimFrame  0x0204B8C4  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_ApplyActorAnimCommand  0x0204BA00  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 f0;
    void *h;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u16 f2c;
} P;

typedef struct {
    u16 x;
    u16 y;
    u32 rest[5];
} Cfg;

typedef struct {
    u16 a;
    u16 b;
    void *p;
    void *cb;
} Msg;

extern Cfg d_0220AC10;
struct Actor;
struct Cmd;
extern void BTLV_FINGER_CURSOR_DeleteActor(char *p);
extern void BTLV_FINGER_CURSOR_AnimCallback(void *p);
struct Obj;
extern struct Obj *CLACT_CreateAffineActor(u32 owner, u32 i, u32 j, u32 k, u32 e, u16 f, u16 g);
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_SetActorAnimFrame(struct Obj *p, u32 value);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_ApplyActorAnimCommand(struct Actor *a, const struct Cmd *cmd);

int BTLV_FINGER_CURSOR_Start(P *p, u16 a, u16 b, u32 c, u32 e, u32 f)
{
    Cfg cfg = d_0220AC10;
    Msg msg;

    if (p->f28 != 0)
        return 0;
    if (p->h != 0) {
        BTLV_FINGER_CURSOR_DeleteActor((char *)p);
        p->h = 0;
    }
    cfg.x = a;
    cfg.y = b;
    p->h = CLACT_CreateAffineActor(p->f0, p->fc, p->f10, p->f14, (u32)(&cfg), 1, p->f2c);
    CLACT_SetActorAnimSeq(p->h, 0);
    CLACT_SetActorAnimFrame(p->h, 0);
    CLACT_SetActorAutoAnim(p->h, 1);
    CLACT_SetActorDrawEnable(p->h, 1);
    if (c != 0)
        p->f1c = c;
    else
        p->f1c = 1;
    if (f != 0)
        p->f24 = f;
    else
        p->f24 = 1;
    p->f18 = 0;
    p->f20 = e;
    p->f28 = 0;
    msg.p = p;
    msg.a = 0;
    msg.b = 0;
    msg.cb = (void *)BTLV_FINGER_CURSOR_AnimCallback;
    CLACT_ApplyActorAnimCommand(p->h, (const struct Cmd *)(&msg));
    return 1;
}
