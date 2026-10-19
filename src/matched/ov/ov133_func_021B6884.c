/*
 * function: DUP_FITTING_VBlank
 * address: 0x021B6884
 * packet: pkt_ov133_021B6884
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: 2026-10-04 (D2-13): filed src/matched/arm9/BILLBOARD_GetImagePlttKey.c and BILLBOARD_SetImageTexAddr.c (both EXACT, 24 and 48 bytes). The two relocations stay unresolved until the integrator builds their shards; expect EXACT after that.
 * blocker: ARM9 0204F32C and 0204F2FC have no outside witness; no overlay leaves filed.
 *   0204F32C verified EXACT by concurrent ov112_func_021F4DE0.c blocker (copy retained):
 *   typedef unsigned int u32;
 *   void BILLBOARD_GetImagePlttKey(char *p,u32 i,u32 *out) { *out = *(u32 *)(*(char **)(p+4)+i*40+36); }
 *   0204F2FC scratch one EXACT, 48 bytes, no relocations:
 *   typedef unsigned char u8;
 *   void BILLBOARD_SetImageTexAddr(u8 *p,u32 i,u32 value) {
 *       u32 off = i*40;
 *       *(u32 *)(*(u8 **)(p+4)+off+32) = value;
 *       *(u32 *)(*(u8 **)(p+4)+off+12) = (*(u32 *)(*(u8 **)(p+4)+off+32)<<16)>>13;
 *   }
 * symbols:
 *   DUP_FITTING_ITEM_ListGetHead 0x021BA184 thumb ov133
 *   DUP_FITTING_ITEM_ElemGetRenderElem 0x021BA218 thumb ov133
 *   DUP_FITTING_ITEM_ElemGetData 0x021BA20C thumb ov133
 *   DUP_FITTING_ITEM_ElemGetSprite 0x021BA214 thumb ov133
 *   DUP_FITTING_ITEM_FreeElemImage 0x021BA1EC thumb ov133
 *   DUP_FITTING_ITEM_ElemGetNext 0x021BA208 thumb ov133
 *   DUP_FITTING_FreeHeldElem 0x021B7A18 thumb ov133
 *   MUSICAL_MCSS_GetActorPoolResource 0x021F4F10 thumb ov112
 *   MUSICAL_MCSS_GetElemPtr 0x021F4F54 thumb ov112
 *   MUSICAL_MCSS_NoOp6 0x021F4F70 thumb ov112
 *   MUSICAL_MCSS_FreeElemImage 0x021F4D74 thumb ov112
 *   MUSICAL_MCSS_NoOp3 0x021F4AA4 thumb ov112
 *   BILLBOARD_GetImagePlttKey 0x0204F32C arm
 *   BILLBOARD_GetImageTexKey 0x0204F2E4 arm
 *   BILLBOARD_SetImageTexAddr 0x0204F2FC arm
 *   BILLBOARD_GetImageSizeFromFlags 0x0204EDD0 arm
 *   BILLBOARD_AddImageFromVramKeys 0x0204F044 arm
 *   BILLBOARD_ReleaseImageVramIfUsed 0x0204F1A0 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Board;
struct Obj0204F1A0;
extern void *DUP_FITTING_ITEM_ListGetHead(char *p);
extern u32 DUP_FITTING_ITEM_ElemGetRenderElem(u8 *p);
extern u32 DUP_FITTING_ITEM_ElemGetData(u8 *p);
extern u32 DUP_FITTING_ITEM_ElemGetSprite(u8 *p);
extern void DUP_FITTING_ITEM_FreeElemImage(u8 *p, u8 *q, u8 *r);
extern u32 DUP_FITTING_ITEM_ElemGetNext(u8 *p);
extern void DUP_FITTING_FreeHeldElem(u8 *);
extern u32 MUSICAL_MCSS_GetActorPoolResource(u8 *);
extern u8 *MUSICAL_MCSS_GetElemPtr(u8 *, int);
extern int MUSICAL_MCSS_NoOp6(int *);
extern void MUSICAL_MCSS_FreeElemImage(u8 *, u8 *, int, u16);
extern void MUSICAL_MCSS_NoOp3(void *);
extern void BILLBOARD_GetImagePlttKey(int p0, int p1, int p2);
extern void BILLBOARD_GetImageTexKey(u8 *, int, u32 *);
extern void BILLBOARD_SetImageTexAddr(u8 *p, int i, u32 value);
extern void BILLBOARD_GetImageSizeFromFlags(int, u16 *, u16 *);
extern int BILLBOARD_AddImageFromVramKeys(struct Board *b, int w, int h, int a3, u32 a4, u8 a5, u8 a6);
extern void BILLBOARD_ReleaseImageVramIfUsed(struct Obj0204F1A0 *a0, u32 a1);
extern void CLACT_VBlankSystem(void);
void DUP_FITTING_VBlank(void *unused, u8 *p)
{
    u32 height, width;
    u16 sizes[2];
    int changed;
    u8 *e, *q, *r;
    u8 *table;
    int flags;
    u16 index;
    e = DUP_FITTING_ITEM_ListGetHead(*(void **)(p + 0x181c));
    changed = 0;
    while (e) {
        DUP_FITTING_ITEM_ElemGetRenderElem(e);
        q = (u8 *)DUP_FITTING_ITEM_ElemGetData(e);
        r = (u8 *)DUP_FITTING_ITEM_ElemGetSprite(e);
        if (*(u16 *)q != *(u16 *)r) {
            DUP_FITTING_ITEM_FreeElemImage(e, *(void **)(p + 0x1884), r);
            changed = 1;
        }
        e = (u8 *)DUP_FITTING_ITEM_ElemGetNext(e);
    }
    if (changed == 1) DUP_FITTING_FreeHeldElem(p);
    if (*(u8 **)(p + 0x38)) {
        q = (u8 *)DUP_FITTING_ITEM_ElemGetData(*(u8 **)(p + 0x38));
        if (*(u16 *)(p + 0x50) != *(u16 *)q) {
            table = (u8 *)MUSICAL_MCSS_GetActorPoolResource(*(u8 **)(p + 0x1884));
            *(u16 *)(p + 0x50) = *(u16 *)q;
            BILLBOARD_GetImagePlttKey((int)(*(void **)(p + 0x188c)), *(int *)(p + 0x54), (int)(&height));
            BILLBOARD_GetImageTexKey(*(u8 **)(p + 0x188c), *(int *)(q + 4), &width);
            BILLBOARD_SetImageTexAddr(*(void **)(p + 0x188c), *(int *)(p + 0x54), width);
            flags = MUSICAL_MCSS_NoOp6((int *)MUSICAL_MCSS_GetElemPtr(table, *(u16 *)(p + 0x50)));
            BILLBOARD_GetImageSizeFromFlags(flags, &sizes[1], &sizes[0]);
            index = BILLBOARD_AddImageFromVramKeys(*(void **)(p + 0x188c), width, height, 0, flags, sizes[1], sizes[0]);
            MUSICAL_MCSS_FreeElemImage(*(u8 **)(p + 0x1884), *(u8 **)(p + 0x4c), *(u16 *)(p + 0x50), index);
            BILLBOARD_ReleaseImageVramIfUsed(*(void **)(p + 0x188c), *(u32 *)(p + 0x54));
            *(u32 *)(p + 0x54) = index;
        }
    }
    CLACT_VBlankSystem();
    MUSICAL_MCSS_NoOp3(*(void **)(p + 0x1884));
}
