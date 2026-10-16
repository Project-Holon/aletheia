/*
 * function: ZUKAN_TOROKU_GRAPHIC_Exit
 * address: 0x0220B048
 * packet: pkt_ov207_0220B048
 * region: ov207
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: extern overlay-id addresses preserve the pooled FS_OVERLAY_ID values.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   ZUKAN_TOROKU_GRAPHIC_DeleteBg 0x0220B2E0 thumb ov207
 *   ZUKAN_NICKNAME_Delete 0x0220B6E4 thumb ov207
 *   ZUKAN_INFO_Delete 0x021BA2CC thumb ov206
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   ZUKAN_TOROKU_GRAPHIC_DeleteDisplay 0x0220B3B8 thumb ov207
 *   overlay206 0x000000CE data
 *   overlay67 0x00000043 data
 *   GF_FONT_Delete  0x0201D83C  thumb  arm9
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb  arm9
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb  arm9
 */
typedef unsigned int   u32;
struct Node;
struct PrintSys;
struct Proc;
extern void func_02030EAC(struct Node *n);
extern void ZUKAN_TOROKU_GRAPHIC_DeleteBg(u32 *p);
extern void ZUKAN_NICKNAME_Delete(unsigned *p);
extern void ZUKAN_INFO_Delete(char *p);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 GF_FONT_Delete(void *ptr);
extern void ZUKAN_TOROKU_GRAPHIC_DeleteDisplay(unsigned *p);
extern void func_020315D4(struct Proc *p);
extern void GFL_HEAP_DeleteChecked(u32 heap);
typedef enum OverlayId { OVERLAY_ZERO=0 } OverlayId;
extern void func_02034A5C(int);
extern char overlay206[],overlay67[];
int ZUKAN_TOROKU_GRAPHIC_Exit(void *a,int b,int c,unsigned *p)
{
    func_02030EAC((void *)p[10]);
    ZUKAN_TOROKU_GRAPHIC_DeleteBg(p);
    ZUKAN_NICKNAME_Delete((void *)p[9]);
    ZUKAN_INFO_Delete((void *)p[8]);
    PRINTSYS_QUE_Clear((void *)p[3]);
    PRINTSYS_QUE_Delete((void *)p[3]);
    GF_FONT_Delete((void *)p[2]);
    ZUKAN_TOROKU_GRAPHIC_DeleteDisplay((void *)p[1]);
    func_020315D4(a);
    GFL_HEAP_DeleteChecked(106);
    func_02034A5C((OverlayId)overlay206);
    func_02034A5C((OverlayId)overlay67);
    return 1;
}
