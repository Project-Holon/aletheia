/*
 * function: MANUAL_CATEGORY_DeleteOptionSlots
 * address: 0x021BBCF4
 * packet: pkt_ov225_021BBCF4
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct PrintSys;
struct Descriptor;
extern void PRINTSYS_QUE_Clear(struct PrintSys *);
extern void BMP_WIN_ClearScreen(struct Descriptor *);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void BG_SYS_MarkTileDirty(u32);
void MANUAL_CATEGORY_DeleteOptionSlots(char *p) { u8 i; for(i=0;i<3;i++) { *(u32 *)(p+i*4+0x28)=0; PRINTSYS_QUE_Clear(*(struct PrintSys **)(p+i*4+0x1c)); BMP_WIN_ClearScreen(*(struct Descriptor **)(p+i*4+0x10)); BMP_WIN_Delete(*(struct Descriptor **)(p+i*4+0x10)); } BG_SYS_MarkTileDirty(5); }
