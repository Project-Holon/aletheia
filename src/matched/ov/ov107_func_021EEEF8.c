/*
 * function: MB_COMM_SYS_VBlankRefreshBgStandalone
 * address: 0x021EEEF8
 * packet: pkt_ov107_021EEEF8
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * volatile: 021EEF02 re-reads counter after 021EEF00 store.
 * symbols:
 *   gMbParentUi 0x021F6EA0 data a4
 *   func_02040618 0x02040618 arm
 */

#include "../include/G_Counter.h"

typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
typedef struct {u16 f0;volatile u16 f2;} Counter;
extern struct Counter gMbParentUi; extern void func_02040618(unsigned,unsigned,unsigned);
void MB_COMM_SYS_VBlankRefreshBgStandalone(void) { gMbParentUi.f2++; if(gMbParentUi.f2>=5){gMbParentUi.f2=0;func_02040618(3,5,1);func_02040618(7,5,1);} }
