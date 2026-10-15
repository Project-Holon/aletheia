/*
 * function: MONOLITH_TOOL_Exit
 * address:  0x021B6458
 * packet:   pkt_ov071_021B6458
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte-correct. Blocker: GPOWER_FreePowerTable (arm9 unlabelled tail-call stub,
 * the integrator's leaf) has no witness outside this range. Verified C for the leaf
 * (EXACT, arm9, --thumb, symbols: func_020307B0 0x020307B0 arm):
 *   void GPOWER_FreePowerTable(void *p) { void func_020307B0(void *); func_020307B0(p); }
 *
 * symbols:
 *   func_0203133C  0x0203133C  arm
 *   func_02030EAC  0x02030EAC  arm
 *   GPOWER_FreePowerTable  0x02010F8C  thumb
 *   MONOLITH_TOOL_FreeActorResources  0x021B6960  thumb  ov071
 *   MONOLITH_TOOL_FreeActors  0x021B68B4  thumb  ov071
 *   MONOLITH_TOOL_FreeText  0x021B6808  thumb  ov071
 *   MONOLITH_TOOL_FreeSubBgChar  0x021B677C  thumb  ov071
 *   MONOLITH_TOOL_FreeBackgrounds  0x021B6624  thumb  ov071
 *   MONOLITH_TOOL_FreePalAnm  0x021B6588  thumb  ov071
 *   MONOLITH_TOOL_ExitBmpWin  0x021B6538  thumb  ov071
 *   MONOLITH_TOOL_DeleteBg  0x021B6524  thumb  ov071
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   func_020315D4  0x020315D4  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 */

typedef unsigned int   u32;
struct Node;
struct PalAnmSlot;
struct S020314B8;
struct Proc;
int MONOLITH_TOOL_Exit(int a, int b, int c, int *w)
{
    void func_0203133C(struct S020314B8 *p);
    void func_02030EAC(struct Node *n);
    void GPOWER_FreePowerTable(void *p);
    void MONOLITH_TOOL_FreeActorResources(u32 *p);
    void MONOLITH_TOOL_FreeActors(void **p);
    void MONOLITH_TOOL_FreeText(void **p);
    void MONOLITH_TOOL_FreeSubBgChar(u32 *p);
    void MONOLITH_TOOL_FreeBackgrounds(void);
    void MONOLITH_TOOL_FreePalAnm(struct PalAnmSlot **p);
    void MONOLITH_TOOL_ExitBmpWin(void);
    void MONOLITH_TOOL_DeleteBg(void);
    void ARC_TOOL_DeleteHandle(int);
    void func_020315D4(struct Proc *p);
    void GFL_HEAP_DeleteChecked(u32 heap);

    func_0203133C((struct S020314B8 *)w[0x12c / 4]);
    func_0203133C((struct S020314B8 *)w[0x130 / 4]);
    func_02030EAC((struct Node *)w[0x128 / 4]);
    GPOWER_FreePowerTable((void *)w[0x34 / 4]);
    MONOLITH_TOOL_FreeActorResources((u32 *)w);
    MONOLITH_TOOL_FreeActors((void **)w);
    MONOLITH_TOOL_FreeText((void **)w);
    MONOLITH_TOOL_FreeSubBgChar((u32 *)w);
    MONOLITH_TOOL_FreeBackgrounds();
    MONOLITH_TOOL_FreePalAnm((struct PalAnmSlot **)w);
    MONOLITH_TOOL_ExitBmpWin();
    MONOLITH_TOOL_DeleteBg();
    ARC_TOOL_DeleteHandle(w[0x30 / 4]);
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    func_020315D4((struct Proc *)a);
    GFL_HEAP_DeleteChecked(0x61);
    return 1;
}
