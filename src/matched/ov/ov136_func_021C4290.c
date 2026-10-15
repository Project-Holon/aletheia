/*
 * function: MAILSYS_ProcExit
 * address:  0x021C4290
 * packet:   pkt_ov136_021C4290
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MAILSYS_ProcExit 0x021C4290 thumb
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   TCBL_Destroy 0x02031140 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   func_020315D4 0x020315D4 arm
 *   func_0203084C 0x0203084C arm
 *   func_020306F0 0x020306F0 arm
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern void BG_SYS_Delete(void);
struct S02031140;
extern void TCBL_Destroy(struct S02031140 *p);
extern u32 GF_FONT_Delete(void *ptr);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *p);
extern void func_0203084C(u16 v);
extern void func_020306F0(u32 v);
int MAILSYS_ProcExit(void *a, void *b, void *c, u32 *p)
{
    u32 h;
    BG_SYS_Delete();
    TCBL_Destroy((struct S02031140 *)p[0x40]);
    GF_FONT_Delete((void *)p[9]);
    h = p[0];
    func_020315D4(a);
    func_0203084C(h);
    func_020306F0((u16)h);
    return 1;
}
