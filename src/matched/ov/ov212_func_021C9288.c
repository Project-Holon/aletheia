/*
 * function: ZUKAN_LoadListAndSelection
 * address: 0x021C9288
 * packet: pkt_ov212_021C9288
 * region: ov212
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: branch-local calls retain the original boolean polarity and hoist
 * the shared output-address setup; initializing selected follows the call.
 * symbols:
 *   ZUKAN_SAVE_GetViewMode 0x0200CA70 thumb
 *   ZUKAN_SAVE_IsCaught 0x0200CED4 thumb
 *   ZUKAN_SAVE_IsSeen 0x0200D064 thumb
 *   ZUKAN_SEARCH_ENGINE_LoadSpeciesIds 0x021C976C thumb ov212
 */
typedef unsigned short u16;
struct Blk37;
extern unsigned ZUKAN_SAVE_GetViewMode(struct Blk37 *);
extern unsigned ZUKAN_SAVE_IsCaught(struct Blk37 *,u16);
extern unsigned ZUKAN_SAVE_IsSeen(struct Blk37 *,u16);
typedef unsigned int   u32;
extern u32 ZUKAN_SEARCH_ENGINE_LoadSpeciesIds(u32 mode, int heap, u16 **out);
u16 ZUKAN_LoadListAndSelection(struct Blk37 *save,u16 **out,unsigned heap)
{
    u16 *list;
    unsigned count,i;
    u16 selected;
    if(ZUKAN_SAVE_GetViewMode(save)==1)count=ZUKAN_SEARCH_ENGINE_LoadSpeciesIds(0,heap,&list);
    else count=ZUKAN_SEARCH_ENGINE_LoadSpeciesIds(1,heap,&list);
    selected=0;
    for(i=0;i<count;i++){
        if(ZUKAN_SAVE_IsCaught(save,list[i])==1||ZUKAN_SAVE_IsSeen(save,list[i])==1)selected=i+1;
    }
    *out=list;
    return selected;
}
