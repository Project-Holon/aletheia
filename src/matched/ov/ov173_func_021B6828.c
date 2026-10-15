/*
 * function: POKE_SUMMARY_MAIN_DeleteBmpWindows
 * address: 0x021B6828
 * packet: pkt_ov173_021B6828
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: 2 zero alignment bytes at 0x021B684E follow the 38-byte function; no follower.
 * symbols:
 *   APP_KEYCURSOR_Delete 0x02028604 thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 */
#include "../include/Obj24151.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int APP_KEYCURSOR_Delete(int);
struct Descriptor;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void BMP_WIN_Exit(void);
void POKE_SUMMARY_MAIN_DeleteBmpWindows(char *p) { u32 i; APP_KEYCURSOR_Delete(((struct Obj24151 *)p)->f21C); for(i=0;i<16;i++) BMP_WIN_Delete(*(void **)((u32)p+i*4+4)); BMP_WIN_Exit(); }
