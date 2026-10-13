/*
 * function: BTL_SETUP_SetupTrainerBase
 * address:  0x020134F4
 * packet:   pkt_02013360
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_SetupTrainerBase.c \
 *       --func BTL_SETUP_SetupTrainerBase --addr 0x020134F4 --cc 1.1p1 --thumb
 *
 * symbols:
 *   BTL_SETUP_SetPlayerParty  0x0201333C  thumb
 *   BTL_SETUP_InitCommon  0x02013360  thumb
 *   BTL_SETUP_Clear  0x020130C4  thumb
 */
#include "../include/Obj00155.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

extern void BTL_SETUP_Clear(u8 *p);
extern void BTL_SETUP_InitCommon(u8 *o, void *a1, const void *a2);
extern int BTL_SETUP_SetPlayerParty(int a0, int a1, int a2);

void BTL_SETUP_SetupTrainerBase(u8 *p, u32 a1, u32 a2, u32 a3, u16 h)
{
    BTL_SETUP_Clear(p);
    BTL_SETUP_InitCommon(p, (void *)a1, (const void *)a3);
    BTL_SETUP_SetPlayerParty((int)p, a1, h);
    ((struct Obj00155 *)p)->f0 = 1;
    ((struct Obj00155 *)p)->f4 = a2;
    ((struct Obj00155 *)p)->f1A = 0x47d;
}
