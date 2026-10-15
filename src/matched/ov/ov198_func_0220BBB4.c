/*
 * function: B_PLIST_ANM_CountActiveRecords
 * address: 0x0220BBB4
 * packet: pkt_ov198_0220BBB4
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * leaf: sole unresolved blocker of B_PLIST_ANM_UpdateByMode.
 */
#include "../include/Obj25128.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u8 low:7,high:1;} Bits;
u8 B_PLIST_ANM_CountActiveRecords(u8 *p)
{
 u16 i,count=0;
 for(i=0;i<6;i++){
  u8 *rec=(u8 *)((u32)p+i*0x4c);
  if(((struct Obj25128 *)rec)->f8!=0 && !((Bits *)(rec+0x1b))->high) count++;
 }
 return count>=2;
}
