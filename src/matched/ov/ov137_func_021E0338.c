/*
 * function: GURU2_MAIN_CreateNameWindows
 * address: 0x021E0338
 * packet: pkt_ov137_021E0338
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Store the call result directly into its slot, then reuse that slot; declare counter before section base.
 * symbols:
 *   BMP_WIN_Create 0x020450F0 arm
 *   gGuru2SlotDescTable 0x021E1E30 data a4
 */
#include "../include/Obj23773.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 layer; u8 a,b,c,d; u16 e,pad; } Desc;
extern const Desc *const gGuru2SlotDescTable[];
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
void GURU2_MAIN_CreateNameWindows(u8 *p,int count)
{
    int i;
    u8 *s;
    const Desc *table;
    u32 obj;
    u32 *slot;
    const Desc *entry;
    s=p+3296;
    i=0;
    table=gGuru2SlotDescTable[count];
    ((struct Obj23773 *)s)->f0=count;
    for(;i<count;i++) {
        entry=&table[i];
        slot=(u32 *)(s+i*4);
        slot[5]=BMP_WIN_Create((u8)entry->layer,entry->a,entry->b,entry->c,entry->d,entry->e,1);
        obj=slot[5];
        *(u32 *)(s+48+i*8)=obj;
        *(u8 *)(s+52+i*8)=0;
    }
}
