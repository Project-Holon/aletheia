/*
 * function: func_021C124C
 * address: 0x021C124C
 * packet: pkt_ov110_021C124C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Blocked on ARM9 0x02024910 (no outside witness); verified leaf C follows.
 * blocker: 0x02024910 Thumb, EXACT (block24910.log)
 *   typedef unsigned char u8;
 *   void *PMS_WORD_GetSaveEntry(u8 *p,int i) { return p+8+i*8; }
 * symbols:
 *   PMS_WORD_GetSaveEntry 0x02024910 thumb
 *   PMSI_PARAM_GetSentenceType 0x0202452C thumb
 *   func_021C080C 0x021C080C thumb ov110
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   PMS_DRAW_SetPrintColor 0x0202DE64 thumb
 *   PMS_DRAW_SetNullColorPalette 0x0202DE5C thumb
 *   PMSI_PARAM_IsComplete 0x02024464 thumb
 *   PMS_DRAW_Print 0x0202DC48 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct CharBuf;
struct Descriptor;
struct PmsDraw;
struct T;
extern void *PMS_WORD_GetSaveEntry(char *p, int idx);
extern int PMSI_PARAM_GetSentenceType(const u16 *p);
extern void func_021C080C(u8 *,int,int,int);
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void PMS_DRAW_SetPrintColor(struct PmsDraw *p, u16 v);
extern void PMS_DRAW_SetNullColorPalette(struct PmsDraw *p, u8 v);
extern int PMSI_PARAM_IsComplete(struct T *p, u32 a1);
extern void PMS_DRAW_Print(u32 a, u32 b, u32 c, u32 d);
void func_021C124C(u8 *p,int index,u8 which,int flag) {
    void *item;
    item=PMS_WORD_GetSaveEntry(*(void **)(p+0x20),which);
    func_021C080C(p+0x24,index,PMSI_PARAM_GetSentenceType(item),flag);
    if (flag) {
        BMP_Clear(func_02045770(*(void **)(p+0x6c+index*4)),14);
        PMS_DRAW_SetPrintColor(*(void **)(p+0x8c),0x44e);
        PMS_DRAW_SetNullColorPalette(*(void **)(p+0x8c),14);
    } else {
        BMP_Clear(func_02045770(*(void **)(p+0x6c+index*4)),13);
        PMS_DRAW_SetPrintColor(*(void **)(p+0x8c),0x44d);
        PMS_DRAW_SetNullColorPalette(*(void **)(p+0x8c),13);
    }
    if (PMSI_PARAM_IsComplete(item,*(u16 *)(p+4))==1) {
        PMS_DRAW_Print((u32)(*(void **)(p+0x8c)),(u32)(*(void **)(p+0x6c+index*4)),(u32)item,index);
        *(int *)(p+0x7c+index*4)=1;
    }
}
