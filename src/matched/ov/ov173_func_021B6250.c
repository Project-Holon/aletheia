/*
 * function: POKE_SUMMARY_MAIN_Delete
 * address: 0x021B6250
 * packet: pkt_ov173_021B6250
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKE_SUMMARY_MAIN_ExitScreen 0x021B6460 thumb ov173
 *   TCBL_Destroy 0x02031140 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 */
#include "../include/Obj00362.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void POKE_SUMMARY_MAIN_ExitScreen(char *);
struct S02031140;
struct S020315D4;
extern void TCBL_Destroy(struct S02031140 *p);
extern u32 GF_FONT_Delete(void *ptr);
extern void func_020315D4(struct S020315D4 *p);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);
int POKE_SUMMARY_MAIN_Delete(void *p,u32 a,u32 b,char *ctx) { POKE_SUMMARY_MAIN_ExitScreen(ctx); TCBL_Destroy(((struct Obj00362 *)ctx)->f64); GF_FONT_Delete(((struct Obj00362 *)ctx)->f60); func_020315D4(p); GFL_HEAP_DeleteChecked(79); return 1; }
