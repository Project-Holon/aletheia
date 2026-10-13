/*
 * function: TOWNMAP_GRH_UpdateLabel
 * address:  0x021BB548
 * packet:   pkt_ov072_021BB548
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_StartActorAnim  0x0204B95C  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   TOWNMAP_GRH_ClearTextBox  0x021BB49C  thumb  ov072
 *   CLACT_IsActorAnimActive  0x0204B98C  arm
 *   TOWNMAP_TownGetField  0x021BA774  thumb  ov072
 *   func_02013E4C  0x02013E4C  thumb
 *   TOWNMAP_GRH_PrintTextBoxMessage  0x021BB448  thumb  ov072
 *   CLACT_StopActorAnim  0x0204B974  arm
 */
typedef unsigned short u16;
typedef unsigned int   u32;

struct Actor;
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_StartActorAnim(struct Actor *a);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void TOWNMAP_GRH_ClearTextBox(void **p);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern int TOWNMAP_TownGetField(char *p, int i);
extern u32 func_02013E4C(u32 id);
extern void TOWNMAP_GRH_PrintTextBoxMessage(u32 *p, u32 a, int x, int y);
extern void CLACT_StopActorAnim(struct Actor *a);

void TOWNMAP_GRH_UpdateLabel(u32 *p)
{
    if (p[7] != 0) {
        p[7] = 0;
        CLACT_SetActorAnimSeq((void *)p[4], 0);
        CLACT_StartActorAnim((void *)p[4]);
        func_0204B3DC((void *)p[4], 1);
        TOWNMAP_GRH_ClearTextBox((void **)p);
        p[6] = 1;
    }
    if (p[6] != 0 && CLACT_IsActorAnimActive((struct Actor *)p[4]) == 0) {
        TOWNMAP_GRH_PrintTextBoxMessage(p, func_02013E4C((u16)TOWNMAP_TownGetField((char *)p[5], 0)), 0x10, 2);
        CLACT_StopActorAnim((void *)p[4]);
        p[6] = 0;
    }
}
