/*
 * function: VCT_MAIN_SetMuted
 * address: 0x021AF30C
 * packet: pkt_ov013_021AF30C
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gVctWork 0x021B3C80 data ov013 a4
 *   VCT_SESSION_RemoveMember 0x021B074C arm ov013
 *   VCT_SESSION_AddMember 0x021B0614 arm ov013
 */

#include "../include/G_Work.h"

typedef unsigned char u8;
typedef unsigned short u16;
extern struct Work *gVctWork;
extern void VCT_SESSION_RemoveMember(void *);
extern int VCT_SESSION_AddMember(void *);
void VCT_MAIN_SetMuted(int a)
{
    if (((u8 *)gVctWork) != 0) {
        *(u16 *)(((u8 *)gVctWork) + 0x19B2) = a;
        if (*(void **)(((u8 *)gVctWork) + 0x1A1C) != 0) {
            if (a != 0) VCT_SESSION_RemoveMember(*(void **)(((u8 *)gVctWork) + 0x1A1C));
            else VCT_SESSION_AddMember(*(void **)(((u8 *)gVctWork) + 0x1A1C));
        }
    }
}
