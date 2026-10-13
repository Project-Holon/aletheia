/*
 * function: func_0220B048
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
 *   func_0220B2E0 0x0220B2E0 thumb ov207
 *   func_0220B6E4 0x0220B6E4 thumb ov207
 *   func_021BA2CC 0x021BA2CC thumb ov206
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_0220B3B8 0x0220B3B8 thumb ov207
 *   overlay206 0x000000CE data
 *   overlay67 0x00000043 data
 *   GF_FONT_Delete  0x0201D83C  thumb  arm9
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb  arm9
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb  arm9
 */
typedef unsigned int   u32;
struct Node;
struct PrintSys;
struct S020315D4;
extern void func_02030EAC(struct Node *n);
extern void func_0220B2E0(u32 *p);
extern void func_0220B6E4(unsigned *p);
extern void func_021BA2CC(char *p);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 GF_FONT_Delete(void *ptr);
extern void func_0220B3B8(unsigned *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(u32 heap);
typedef enum OverlayId { OVERLAY_ZERO=0 } OverlayId;
extern void func_02034A5C(int);
extern char overlay206[],overlay67[];
int func_0220B048(void *a,int b,int c,unsigned *p)
{
    func_02030EAC((void *)p[10]);
    func_0220B2E0(p);
    func_0220B6E4((void *)p[9]);
    func_021BA2CC((void *)p[8]);
    PRINTSYS_QUE_Clear((void *)p[3]);
    PRINTSYS_QUE_Delete((void *)p[3]);
    GF_FONT_Delete((void *)p[2]);
    func_0220B3B8((void *)p[1]);
    func_020315D4(a);
    func_020306F0(106);
    func_02034A5C((OverlayId)overlay206);
    func_02034A5C((OverlayId)overlay67);
    return 1;
}
