/*
 * function: BOX2_SEQ_RegisterBoxChars
 * address: 0x021EC0DC
 * packet: pkt_ov170_021EC0DC
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
typedef unsigned short u16;
extern void *func_020490F4(unsigned int id, unsigned int heap);
typedef signed int     s32;
typedef unsigned int   u32;
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *);
#define SLOT(p,o) (*(void **)((p)+(o)))
void BOX2_SEQ_RegisterBoxChars(char *p)
{
    void *h;
    unsigned i,j;
    h=func_020490F4(116,76);
    for(j=0;j<6;j++) SLOT(p+j*4,0xA0D8)=(void *)CLACT_RegisterCharacter(h,71,1,0,76);
    SLOT(p,0xA11C)=(void *)CLACT_RegisterPalette(h,72,0,0,76);
    SLOT(p,0xA148)=(void *)CLACT_RegisterCellAnim(h,73,74,76);
    for(i=0;i<37;i++) SLOT(p+i*4,0x9FF4)=(void *)CLACT_RegisterCharacter(h,75,1,0,76);
    SLOT(p,0xA0F0)=(void *)CLACT_RegisterCharacter(h,67,1,0,76);
    SLOT(p,0xA120)=(void *)CLACT_RegisterPalette(h,70,0,192,76);
    SLOT(p,0xA14C)=(void *)CLACT_RegisterCellAnim(h,68,69,76);
    SLOT(p,0xA0F4)=(void *)CLACT_RegisterCharacter(h,64,1,0,76);
    SLOT(p,0xA150)=(void *)CLACT_RegisterCellAnim(h,65,66,76);
    SLOT(p,0xA090)=(void *)CLACT_RegisterCharacter(h,76,1,0,76);
    SLOT(p,0xA140)=(void *)CLACT_RegisterCellAnim(h,77,78,76);
    ARC_TOOL_DeleteHandle(h);
}
