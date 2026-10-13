/*
 * function: BTLV_TIMER_Delete
 * address:  0x022092E8
 * packet:   pkt_ov094_022092E8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTLV_TIMER_DeleteActors  0x02209458  thumb  ov094
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm  arm9
 *   CLACT_ReleasePalette  0x0204ADA4  arm  arm9
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm  arm9
 *   CLACT_DeleteUnit  0x0204B1CC  arm  arm9
 */

typedef struct {
    int h0;
    int h4;
    char pad08[0x40 - 0x08];
    int h40;
    int h44;
    int h48;
} W;

extern void BTLV_TIMER_DeleteActors(W *w);
typedef unsigned int   u32;
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void CLACT_ReleasePalette(u32 i);
struct Bank;
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern u32 func_020307B0(void *p);

void BTLV_TIMER_Delete(W *w)
{
    BTLV_TIMER_DeleteActors(w);
    CLACT_ReleaseCharacter(w->h40);
    CLACT_ReleaseCellAnim(w->h44);
    CLACT_ReleasePalette(w->h48);
    CLACT_DeleteUnit((struct Bank *)w->h0);
    CLACT_DeleteUnit((struct Bank *)w->h4);
    func_020307B0(w);
}
