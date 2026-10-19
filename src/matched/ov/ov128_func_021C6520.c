/*
 * function: Wf2dmapFriend_BuildEntryList
 * address: 0x021C6520
 * packet: pkt_ov128_021C6520
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * lever: direct assignment from postincrement preserves the old count load;
 *   the two-byte tail at 021C658A is zero padding.
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   GAME_DATA_GetWifiList 0x0201283C thumb
 *   func_02009A1C 0x02009A1C thumb
 *   func_02009864 0x02009864 thumb
 */
#include "../include/Obj03808.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
extern void MI_CpuFill8(void *,int,int);
struct BigObj;
extern u32 GAME_DATA_GetWifiList(const struct BigObj *p);
struct Sub020097BCObj;
extern int func_02009A1C(struct Sub020097BCObj *obj, u32 i);
extern u32 func_02009864(const struct Sub020097BCObj *obj, u32 i, u32 field);
void Wf2dmapFriend_BuildEntryList(char *p)
{
    int i;
    void *v;
    MI_CpuFill8(p+16,0,72);
    v=(void *)GAME_DATA_GetWifiList(((struct Obj03808 *)p)->f4);
    ((struct Obj03808 *)p)->f10=0;
    for(i=0;i<32;i++) {
        if(func_02009A1C(v,i)==1) {
            *(u8 *)(p+((struct Obj03808 *)p)->f10+24)=i;
            if(func_02009864(v,i,9)==2) *(u8 *)(p+((struct Obj03808 *)p)->f10+56)=255;
            else *(u8 *)(p+((struct Obj03808 *)p)->f10+56)=(((struct Obj03808 *)p)->f14)++;
            ((struct Obj03808 *)p)->f10=((struct Obj03808 *)p)->f10+1;
        }
    }
}
