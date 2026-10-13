/*
 * function: func_02201CA4
 * address:  0x02201CA4
 * packet:   pkt_ov094_02201CA4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm  arm9
 *   CLACT_ReleasePalette  0x0204ADA4  arm  arm9
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm  arm9
 *   CLACT_DeleteActor  0x0204B3B4  arm  arm9
 */
typedef struct Ent { void *h8; void *hc; void *h10; void *h14; } Ent;
typedef struct Res { void *owner; void *h; Ent e[7]; } Res;
typedef unsigned int   u32;
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);

void func_02201CA4(Res *r, int i)
{
    CLACT_ReleaseCharacter((u32)r->e[i].hc);
    CLACT_ReleasePalette((u32)r->e[i].h10);
    CLACT_ReleaseCellAnim((u32)r->e[i].h14);
    CLACT_DeleteActor(r->e[i].h8);
    r->e[i].h8 = 0;
}
