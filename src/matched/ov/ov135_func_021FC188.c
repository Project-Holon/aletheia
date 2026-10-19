/*
 * function: WORLDTRADE_DETAIL_Exit
 * address: 0x021FC188
 * packet: pkt_ov135_021FC188
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORLDTRADE_DETAIL_DeleteActors 0x021FC3D0 thumb ov135
 *   WORLDTRADE_DETAIL_DeleteStrings 0x021FC568 thumb ov135
 *   WORLDTRADE_DETAIL_DeleteWindows 0x021FC4E4 thumb ov135
 *   WORLDTRADE_DETAIL_ExitBgPlanes 0x021FC2A4 thumb ov135
 *   WORLDTRADE_TITLE_ExitBgPlanes 0x022000E4 thumb ov135
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   WORLDTRADE_AdvanceScreenId 0x021F4EC8 thumb ov135
 */
#include "../include/Obj00287.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Obj;
extern void WORLDTRADE_DETAIL_DeleteActors(u8 *p);
extern void WORLDTRADE_DETAIL_DeleteStrings(char *p);
extern void WORLDTRADE_DETAIL_DeleteWindows(char *);
extern void WORLDTRADE_DETAIL_ExitBgPlanes(void);
extern void WORLDTRADE_TITLE_ExitBgPlanes(char *p);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void WORLDTRADE_AdvanceScreenId(u8 *p);
int WORLDTRADE_DETAIL_Exit(u8 *p) {WORLDTRADE_DETAIL_DeleteActors(p);WORLDTRADE_DETAIL_DeleteStrings((char *)p);WORLDTRADE_DETAIL_DeleteWindows((char *)p);WORLDTRADE_DETAIL_ExitBgPlanes();WORLDTRADE_TITLE_ExitBgPlanes((char *)p);CLACT_SetActorDrawEnable(((struct Obj00287 *)p)->fD38,0);WORLDTRADE_AdvanceScreenId(p);return 0;}
