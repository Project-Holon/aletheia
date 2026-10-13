/*
 * function: IRCBATTLEMENU_SeqPressKindBack
 * address:  0x02196B94
 * packet:   pkt_ov021_02196B94
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   IRCBATTLEMENU_HookKindBackPressed  0x02196B7C  thumb  ov021
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_ApplyActorAnimCommand  0x0204BA00  arm
 *   CLACT_RestartActorAnim  0x0204B9A0  arm
 *   IRCBATTLEMENU_SetSeq  0x02196034  thumb  ov021
 *   IRCBATTLEMENU_SeqIdleKindBack  0x02196B90  thumb  ov021
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
extern void IRCBATTLEMENU_HookKindBackPressed(u8 *p);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
struct Cmd;
extern void CLACT_ApplyActorAnimCommand(struct Actor *a, const struct Cmd *cmd);
extern void CLACT_RestartActorAnim(struct Actor *a);
extern void IRCBATTLEMENU_SetSeq(Obj *, void (*)(), u32);
extern void IRCBATTLEMENU_SeqIdleKindBack();

void IRCBATTLEMENU_SeqPressKindBack(Obj *a)
{
    Req r;

    r.x0 = 0;
    r.a = a;
    r.cb = IRCBATTLEMENU_HookKindBackPressed;
    CLACT_SetActorAutoAnim(a->objs[a->mode], 1);
    CLACT_ApplyActorAnimCommand(a->objs[a->mode], (const struct Cmd *)(&r));
    CLACT_RestartActorAnim(a->objs[a->mode]);
    IRCBATTLEMENU_SetSeq(a, IRCBATTLEMENU_SeqIdleKindBack, 0x492);
}
