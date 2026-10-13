/*
 * function: BTLV_FINGER_CURSOR_AnimCallback
 * address:  0x02209C30
 * packet:   pkt_ov094_02209C30
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * f18 and f28 are volatile: the original reloads f18 after each f28
 * store and keeps the store order.
 *
 * symbols:
 *   CLACT_SetActorAnimSeq  0x0204B878  arm  arm9
 *   CLACT_ApplyActorAnimCommand  0x0204BA00  arm  arm9
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm  arm9
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 f0;
    void *h;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    volatile u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    volatile u32 f28;
    u16 f2c;
} P;

typedef struct {
    u16 a;
    u16 b;
    void *p;
    void *cb;
} Msg;

struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
struct Actor;
struct Cmd;
extern void CLACT_ApplyActorAnimCommand(struct Actor *a, const struct Cmd *cmd);

void BTLV_FINGER_CURSOR_AnimCallback(P *p)
{
    Msg m0;
    Msg m1;

    switch (p->f18) {
    case 0:
        if (--p->f1c == 0) {
            CLACT_SetActorAnimSeq(p->h, 1);
            p->f18++;
            m0.p = p;
            m0.a = 1;
            m0.b = p->f20;
            m0.cb = (void *)BTLV_FINGER_CURSOR_AnimCallback;
            CLACT_ApplyActorAnimCommand(p->h, (const struct Cmd *)(&m0));
            return;
        }
        break;
    case 1:
        p->f28 = 1;
        p->f18++;
        m1.p = p;
        m1.a = 2;
        m1.b = 0;
        m1.cb = (void *)BTLV_FINGER_CURSOR_AnimCallback;
        CLACT_ApplyActorAnimCommand(p->h, (const struct Cmd *)(&m1));
        return;
    case 2:
        CLACT_SetActorDrawEnable(p->h, 0);
        p->f28 = 0;
        p->f18++;
        break;
    case 3:
        break;
    }
}
