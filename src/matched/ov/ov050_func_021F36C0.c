/*
 * function: func_021F36C0
 * address: 0x021F36C0
 * packet: pkt_ov050_021F36C0
 * region: ov050
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: two-byte alignment padding at 0x021F36EA follows the return.
 * symbols:
 *   FIELDMAP_GetHeapId 0x02188C84 thumb ov021
 *   FIELDMAP_AllocCommonWork 0x02189764 thumb ov021
 *   GIMMICK50_InitModels 0x021F383C thumb ov050
 *   GIMMICK50_InitExtra 0x021F3890 thumb ov050
 */
#include "../include/Obj20550.h"

extern unsigned short FIELDMAP_GetHeapId(unsigned char *);
extern void *FIELDMAP_AllocCommonWork(unsigned char *, int, int, int);
extern void GIMMICK50_InitModels(int, int);
extern void GIMMICK50_InitExtra(void *, unsigned char *);
void func_021F36C0(unsigned char *p) { unsigned short h; void *q; h=FIELDMAP_GetHeapId(p); q=FIELDMAP_AllocCommonWork(p,1,h,2); ((struct Obj20550 *)q)->f0=h; GIMMICK50_InitModels((int)q,(int)p); GIMMICK50_InitExtra(q,p); }
