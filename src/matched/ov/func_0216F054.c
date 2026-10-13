/*
 * function: EVENT_BATTLE_FreeBtlSetup
 * address:  0x0216F054
 * packet:   pkt_0216F054
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SETUP_Delete  0x020130B4  thumb
 */
#include "../include/Obj12060.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_SETUP_Delete(int a0);

int EVENT_BATTLE_FreeBtlSetup(int a0)
{
    int a1;

a1 = ((struct Obj12060 *)a0)->f20;
    if (a1 != 0) goto loc_0216F062;
loc_0216F05C:
a0 = ((struct Obj12060 *)a0)->f8;
    a0 = BTL_SETUP_Delete(a0);
loc_0216F062:
    return a0;}
