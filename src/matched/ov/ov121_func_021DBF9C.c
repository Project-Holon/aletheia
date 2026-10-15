/*
 * function: MYSTERY_ALBUM_GetEntryGraphicIndex
 * address: 0x021DBF9C
 * packet: pkt_ov121_021DBF9C
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding follow the return.
 * symbols:
 *   MYSTERY_ALBUM_GetEntryKind 0x021DC024 thumb ov121
 *   MYSTERY_ALBUM_GetEntryCard 0x021DC02C thumb ov121
 *   POKE_TOOL_CalcGraphicIndex  0x0201BABC  thumb  arm9
 *   FILE_UTIL_Get  0x02020E60  thumb  arm9
 */
#include "../include/Obj06452.h"
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;
extern int MYSTERY_ALBUM_GetEntryKind(void *);
extern char *MYSTERY_ALBUM_GetEntryCard(void *);
extern u32 POKE_TOOL_CalcGraphicIndex(u32 species, u32 form, u32 gender, u32 isEgg);
extern u32 FILE_UTIL_Get(u32,u32);
int MYSTERY_ALBUM_GetEntryGraphicIndex(void *p)
{
    char *q;
    switch(MYSTERY_ALBUM_GetEntryKind(p)) {
    case 1:
        q=MYSTERY_ALBUM_GetEntryCard(p);
        return POKE_TOOL_CalcGraphicIndex(((struct Obj06452 *)q)->f1A,((struct Obj06452 *)q)->f1C,((struct Obj06452 *)q)->f35,((struct Obj06452 *)q)->f5C);
    case 2:
        q=MYSTERY_ALBUM_GetEntryCard(p);
        return FILE_UTIL_Get((u16)((struct Obj06452 *)q)->f0,1);
    default: return 12;
    }
}
