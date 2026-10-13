/*
 * function: IRCBATTLEMENU_SeqPressKindButton
 * address:  0x02196B28
 * packet:   pkt_ov021_02196B28
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   IRCBATTLEMENU_HookKindMenuPressed  0x02196ACC  thumb  ov021
 *   func_0204B92C  0x0204B92C  arm
 *   CLACT_ApplyActorAnimCommand  0x0204BA00  arm
 *   CLACT_RestartActorAnim  0x0204B9A0  arm
 *   IRCBATTLEMENU_SetSeq  0x02196034  thumb  ov021
 *   IRCBATTLEMENU_SeqIdleKind  0x02196B24  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct Obj { u32 x0; u32 x4; u32 x8; u8 pad[0x288]; void *objs[27]; u32 mode; } Obj;
typedef struct { u16 x0; Obj *a; void (*cb)(); } Req;
struct Actor;
extern void IRCBATTLEMENU_HookKindMenuPressed(u8 *p);
extern void func_0204B92C(struct Obj *p, u32 v);
struct Cmd;
extern void CLACT_ApplyActorAnimCommand(struct Actor *a, const struct Cmd *cmd);
extern void CLACT_RestartActorAnim(struct Actor *a);
extern void IRCBATTLEMENU_SetSeq(Obj *, void (*)(), u32);
extern void IRCBATTLEMENU_SeqIdleKind();

void IRCBATTLEMENU_SeqPressKindButton(Obj *a)
{
    Req r;
    int i;

    i = 0;
    if (a->x8 == 5) {
        i = 1;
    }
    r.x0 = 0;
    r.a = a;
    r.cb = IRCBATTLEMENU_HookKindMenuPressed;
    func_0204B92C(a->objs[i], 1);
    CLACT_ApplyActorAnimCommand(a->objs[i], (const struct Cmd *)(&r));
    CLACT_RestartActorAnim(a->objs[i]);
    IRCBATTLEMENU_SetSeq(a, IRCBATTLEMENU_SeqIdleKind, 0x471);
}
