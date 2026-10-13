/*
 * function: IRCBATTLEMENU_SeqPressPartyButton
 * address:  0x02196D24
 * packet:   pkt_ov021_02196D24
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sPartyMenuActorIndex     0x021D3F9C  data  ov021  a1
 *   IRCBATTLEMENU_HookPartyMenuPressed  0x02196CD8  thumb  ov021
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_ApplyActorAnimCommand  0x0204BA00  arm
 *   CLACT_RestartActorAnim  0x0204B9A0  arm
 *   IRCBATTLEMENU_SetSeq  0x02196034  thumb  ov021
 *   IRCBATTLEMENU_SeqIdleParty  0x02196D20  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct Obj { u32 x0; u32 x4; u32 x8; u32 xc; u8 pad[0x284]; void *objs[27]; u32 mode; } Obj;
typedef struct { u16 x0; Obj *a; void (*cb)(); } Req;
typedef struct { u8 v[3]; } Tbl3;
extern const Tbl3 sPartyMenuActorIndex;
struct Actor;
extern void IRCBATTLEMENU_HookPartyMenuPressed(u8 *p);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
struct Cmd;
extern void CLACT_ApplyActorAnimCommand(struct Actor *a, const struct Cmd *cmd);
extern void CLACT_RestartActorAnim(struct Actor *a);
extern void IRCBATTLEMENU_SetSeq(Obj *, void (*)(), u32);
extern void IRCBATTLEMENU_SeqIdleParty();

void IRCBATTLEMENU_SeqPressPartyButton(Obj *a)
{
    Tbl3 t = sPartyMenuActorIndex;
    Req r;
    int i;

    i = t.v[a->xc];
    r.x0 = 0;
    r.a = a;
    r.cb = IRCBATTLEMENU_HookPartyMenuPressed;
    CLACT_SetActorAutoAnim(a->objs[i], 1);
    CLACT_ApplyActorAnimCommand(a->objs[i], (const struct Cmd *)(&r));
    CLACT_RestartActorAnim(a->objs[i]);
    IRCBATTLEMENU_SetSeq(a, IRCBATTLEMENU_SeqIdleParty, 0x504);
}
