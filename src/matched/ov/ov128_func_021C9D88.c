/*
 * function: WF2DMAP_TOUCH_FindNextEntry
 * address: 0x021C9D88
 * packet: pkt_ov128_021C9D88
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero padding at 021C9E0E before next label 021C9E10.
 * lever: writing the reloaded signed byte on the left of == fixes both cmp operands.
 * symbols:
 *   GAME_DATA_GetWifiList 0x0201283C thumb
 *   func_02009864 0x02009864 thumb
 *   _u32_div_f 0x0209C2B0 arm
 */
#include "../include/Obj00992.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
struct BigObj;
extern u32 GAME_DATA_GetWifiList(const struct BigObj *p);
struct Sub020097BCObj;
extern u32 func_02009864(const struct Sub020097BCObj *obj, u32 i, u32 field);
int WF2DMAP_TOUCH_FindNextEntry(u8 *p,int direction)
{
    int index;
    u32 data;
    u32 count;
    data=GAME_DATA_GetWifiList(((struct Obj00992 *)p)->f4);
    index=((struct Obj00992 *)p)->fB;
    if(direction==0) {
        for(count=0;count<((struct Obj00992 *)p)->f10-1;count++) {
            index--;
            if(index<0) index+=((struct Obj00992 *)p)->f10;
            if(((struct Obj00992 *)p)->fB==index) goto fail;
            if(func_02009864((const struct Sub020097BCObj *)data,p[index+24],9)!=2) return 1;
        }
    } else {
        for(count=0;count<((struct Obj00992 *)p)->f10-1;count++) {
            index=(u32)(index+1)%((struct Obj00992 *)p)->f10;
            if(((struct Obj00992 *)p)->fB==index) goto fail;
            if(func_02009864((const struct Sub020097BCObj *)data,p[index+24],9)!=2) return 1;
        }
    }
fail:
    return 0;
}
