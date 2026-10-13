/*
 * unit:     yes
 * function: BTLV_B_GAUGE_DeletePartyBallBar, BTLV_B_GAUGE_IsPartyBallBarActive
 * address:  0x02209068
 * packet:   pkt_ov094_02209068
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   func_020307B0  0x020307B0  arm
 */
typedef unsigned int u32;

typedef struct {
    int h0;
    int h4;
    int h8;
    int hc;
    struct { int f10; char pad[0x18]; } e[7];
} W;

struct Bank;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern u32 func_020307B0(void *p);

void BTLV_B_GAUGE_DeletePartyBallBar(W *w)
{
    int i;

    for (i = 0; i < 7; i++)
        CLACT_DeleteActor((struct Obj *)w->e[i].f10);
    CLACT_ReleaseCharacter(w->h4);
    CLACT_ReleasePalette(w->hc);
    CLACT_ReleaseCellAnim(w->h8);
    CLACT_DeleteUnit((struct Bank *)w->h0);
    func_020307B0(w);
}

int BTLV_B_GAUGE_IsPartyBallBarActive(int *p)
{
    if (p[0xd8 / 4 + 0] != 0)
        return 1;
    return 0;
}
