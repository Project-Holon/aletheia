/*
 * function: func_021DD8D0
 * address: 0x021DD8D0
 * packet: pkt_ov170_021DD8D0
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKE_PERSONAL_LoadFormTable 0x0201AF80 thumb
 *   ZUKAN_SAVE_GetFromGameData 0x0200CA1C thumb
 *   ZUKAN_SAVE_IsNationalDexEnabled 0x0200CA38 thumb
 */
#include "../include/Obj10646.h"
#include "../include/Obj23832.h"
#include "../include/Obj23834.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Bank; struct CharBuf; struct Descriptor; struct Rec; struct Node; struct Blk37;
extern u16 *POKE_PERSONAL_LoadFormTable(u32 heap, u16 *countOut);
extern void *ZUKAN_SAVE_GetFromGameData(void *);
extern u32 ZUKAN_SAVE_IsNationalDexEnabled(struct Blk37 *);
void func_021DD8D0(char *p) { *(u16 * *)&((struct Obj23832 *)(*(char * *)&((struct Obj10646 *)p)->f2C))->f180=POKE_PERSONAL_LoadFormTable(76,0);((struct Obj23834 *)(*(char * *)&((struct Obj10646 *)p)->f2C))->f17C=ZUKAN_SAVE_IsNationalDexEnabled(ZUKAN_SAVE_GetFromGameData(**(void ** *)&((struct Obj10646 *)p)->f0)); }
