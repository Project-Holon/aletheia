/*
 * function: func_021F36C0
 * address: 0x021F36C0
 * packet: pkt_ov049_021F36C0
 * region: ov049
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   FIELDMAP_GetHeapId 0x02188C84 thumb ov021
 *   FIELDMAP_AllocCommonWork 0x02189764 thumb ov021
 *   func_021F3714 0x021F3714 thumb ov049
 *   GIMMICK49_InitExtra 0x021F3864 thumb ov049
 */
#include "../include/Obj20549.h"
typedef unsigned short u16;
typedef unsigned char  u8;
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern void *FIELDMAP_AllocCommonWork(unsigned char *p,int id,int a,int b);
extern void func_021F3714(unsigned int a0,unsigned int a);
extern void GIMMICK49_InitExtra(void *q,unsigned char *p);
void func_021F36C0(unsigned char *p) { unsigned short h; void *q; h=FIELDMAP_GetHeapId((u8 *)((int)p)); q=FIELDMAP_AllocCommonWork(p,0,h,2); ((struct Obj20549 *)q)->f0=h; func_021F3714((unsigned int)q,(unsigned int)p); GIMMICK49_InitExtra(q,p); }
