/*
 * function: func_02209B30
 * address:  0x02209B30
 * packet:   pkt_ov094_02209B30
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02209C18  0x02209C18  thumb  ov094
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm  arm9
 *   CLACT_ReleasePalette  0x0204ADA4  arm  arm9
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm  arm9
 *   CLACT_DeleteUnit  0x0204B1CC  arm  arm9
 */

typedef struct {
    int h0;
    int f4;
    void *f8;
    int fc;
    int f10;
    int f14;
} P;

typedef unsigned int   u32;
struct Node;
extern void func_02030EAC(struct Node *n);
extern void func_02209C18(char *p);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void CLACT_ReleasePalette(u32 i);
struct Bank;
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern u32 func_020307B0(void *p);

void func_02209B30(P *p)
{
    func_02030EAC(p->f8);
    func_02209C18((char *)p);
    CLACT_ReleaseCharacter(p->fc);
    CLACT_ReleaseCellAnim(p->f14);
    CLACT_ReleasePalette(p->f10);
    CLACT_DeleteUnit((struct Bank *)p->h0);
    func_020307B0(p);
}
