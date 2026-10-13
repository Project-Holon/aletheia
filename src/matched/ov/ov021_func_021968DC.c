/*
 * function: IRCBATTLEMENU_SeqPressTopButton
 * address:  0x021968DC
 * packet:   pkt_ov021_021968DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   IRCBATTLEMENU_HookTopMenuPressed  0x0219686C  thumb  ov021
 *   func_0204B92C  0x0204B92C  arm
 *   CLACT_ApplyActorAnimCommand  0x0204BA00  arm
 *   CLACT_RestartActorAnim  0x0204B9A0  arm
 *   IRCBATTLEMENU_SetSeq  0x02196034  thumb  ov021
 *   IRCBATTLEMENU_SeqIdleTop  0x021968D8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct Obj { u8 pad[0x294]; void *objs[27]; u32 mode; } Obj;
typedef struct { u16 x0; Obj *a; void (*cb)(); } Req;
struct Actor;
extern void IRCBATTLEMENU_HookTopMenuPressed(u8 *p);
extern void func_0204B92C(struct Obj *p, u32 v);
struct Cmd;
extern void CLACT_ApplyActorAnimCommand(struct Actor *a, const struct Cmd *cmd);
extern void CLACT_RestartActorAnim(struct Actor *a);
extern void IRCBATTLEMENU_SetSeq(Obj *, void (*)(), u32);
extern void IRCBATTLEMENU_SeqIdleTop();

void IRCBATTLEMENU_SeqPressTopButton(Obj *a)
{
    Req r;
    u32 i;

    i = a->mode;
    r.x0 = 0;
    r.a = a;
    r.cb = IRCBATTLEMENU_HookTopMenuPressed;
    if (i == 5) {
        i = 0;
    } else if (i == 6) {
        i = 1;
    } else if (i == 7) {
        i = 3;
    }
    func_0204B92C(a->objs[i], 1);
    CLACT_ApplyActorAnimCommand(a->objs[i], (const struct Cmd *)(&r));
    CLACT_RestartActorAnim(a->objs[i]);
    IRCBATTLEMENU_SetSeq(a, IRCBATTLEMENU_SeqIdleTop, 0x3BF);
}
