/*
 * function: SHINKA_DEMO_DeleteScene
 * address:  0x02204D5C
 * packet:   pkt_ov195_022040E0
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Leaf of the SHINKA_DEMO_Main dependency tree: the scene object's teardown.
 * It releases the two +0x104/+0x108 sub-objects, tears the controller links
 * down, then frees the +0x0c/+0x08/+0x04 allocations and drops the 0x43 /
 * 0x68 pools.
 *
 * symbols:
 *   SHINKA_DEMO_EFFECT_Destroy  0x02208770  thumb
 *   SHINKA_DEMO_VIEW_Destroy  0x02205D28  thumb
 *   SHINKA_DEMO_DeleteActors  0x02205100  thumb
 *   SHINKA_DEMO_Noop2  0x0220506C  thumb
 *   SHINKA_DEMO_DeleteConfirmMenu  0x02205580  thumb
 *   SHINKA_DEMO_DeleteWindows  0x022052E8  thumb
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   SHINKA_DEMO_GRAPHIC_ReleaseSubBg  0x02205A84  thumb
 *   SHINKA_DEMO_GRAPHIC_Destroy  0x022059A0  thumb
 *   func_02034A5C  0x02034A5C  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 *   ov067_id       0x00000043  data
 */
struct PrintSys;
extern void SHINKA_DEMO_EFFECT_Destroy(char *a);
extern void SHINKA_DEMO_VIEW_Destroy(char *p);
extern void SHINKA_DEMO_DeleteActors(void *unused, char *p);
extern void SHINKA_DEMO_Noop2(int, int *);
extern void SHINKA_DEMO_DeleteConfirmMenu(void *unused, char *p);
extern void SHINKA_DEMO_DeleteWindows(int, int *);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
typedef unsigned int   u32;
extern u32 GF_FONT_Delete(void *ptr);
extern void SHINKA_DEMO_GRAPHIC_ReleaseSubBg(int);
extern void SHINKA_DEMO_GRAPHIC_Destroy(char *p);
extern void func_02034A5C(int);
extern void GFL_HEAP_DeleteChecked(unsigned int);
extern unsigned char ov067_id[];

void SHINKA_DEMO_DeleteScene(int a, int *p)
{
    SHINKA_DEMO_EFFECT_Destroy((char *)p[0x42]);
    SHINKA_DEMO_VIEW_Destroy((char *)p[0x41]);
    SHINKA_DEMO_DeleteActors((void *)a, (char *)p);
    SHINKA_DEMO_Noop2(a, p);
    SHINKA_DEMO_DeleteConfirmMenu((void *)a, (char *)p);
    SHINKA_DEMO_DeleteWindows(a, p);
    PRINTSYS_QUE_Clear((struct PrintSys *)p[3]);
    PRINTSYS_QUE_Delete((struct PrintSys *)p[3]);
    GF_FONT_Delete((void *)p[2]);
    SHINKA_DEMO_GRAPHIC_ReleaseSubBg(p[1]);
    SHINKA_DEMO_GRAPHIC_Destroy((char *)p[1]);
    func_02034A5C((int)ov067_id);
    GFL_HEAP_DeleteChecked(0x68);
}
