/*
 * function: COMM_ENTRY_MENU_UpdateMemberList
 * address:  0x021CE2BC
 * packet:   pkt_ov021_021CE2BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   COMM_ENTRY_MENU_UpdateMemberName  0x021CE8B0  thumb  ov021
 *   COMM_ENTRY_MENU_ClearMemberName  0x021CE8F4  thumb  ov021
 *   COMM_ENTRY_MENU_PrintMemberName  0x021CE934  thumb  ov021
 *   COMM_ENTRY_MENU_PrintRemaining  0x021CE84C  thumb  ov021
 *   COMM_ENTRY_MENU_IsIdle  0x021CE78C  thumb  ov021
 *   COMM_ENTRY_MENU_PrintMessage  0x021CE9E4  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00011.h"

typedef unsigned char u8;
typedef signed char   s8;
typedef unsigned int  u32;

extern void COMM_ENTRY_MENU_UpdateMemberName(u8 *p, u8 *e, int i);
extern void COMM_ENTRY_MENU_ClearMemberName(u8 *p, u8 *e, int i);
extern void COMM_ENTRY_MENU_PrintMemberName(u8 *p, u8 *e, int i);
extern int COMM_ENTRY_MENU_PrintRemaining(u32 *p, int n);
extern int COMM_ENTRY_MENU_IsIdle(u32 a);
extern void COMM_ENTRY_MENU_PrintMessage(u8 *p, int n);

void COMM_ENTRY_MENU_UpdateMemberList(u8 *p)
{
    u8 *e;
    int i;
    int n;

    n = 0;
    i = 0;
    e = p + 0x50;
    for (; i < 4; i++) {
        if (p[0x70 + i * 0x2c]) {
            COMM_ENTRY_MENU_UpdateMemberName(p, e + i * 0x2c, i);
            n++;
        } else {
            COMM_ENTRY_MENU_ClearMemberName(p, e + i * 0x2c, i);
        }
    }
    if (n == 0) {
        COMM_ENTRY_MENU_PrintMemberName(p, p + 0x30, 0);
        n++;
    }
    if (*(s8 *)&((struct Obj00011 *)p)->f572 != n) {
        if (COMM_ENTRY_MENU_PrintRemaining((u32 *)p, n) == 1) {
            p[0x572] = n;
            if (p[0x520] == 1 && n == 1) {
                p[0x579] = 1;
            }
        }
    }
    if (p[0x579] == 1) {
        if (COMM_ENTRY_MENU_IsIdle((u32)p) == 1 && ((struct Obj00011 *)p)->f130 == 0) {
            if (n == 1) {
                COMM_ENTRY_MENU_PrintMessage(p, 8);
            }
            p[0x579] = 0;
        }
    }
}
