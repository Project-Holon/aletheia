/*
 * function: ZUKAN_FixLastViewedSpecies
 * address: 0x021C92EC
 * packet: pkt_ov212_021C92EC
 * region: ov212
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ZUKAN_SAVE_GetLastViewedSpecies 0x0200CA8C thumb
 *   ZUKAN_SAVE_IsSeen 0x0200D064 thumb
 *   ZUKAN_SAVE_SetLastViewedSpecies 0x0200CA78 thumb
 */
typedef unsigned short u16;
struct Blk37;
extern u16 ZUKAN_SAVE_GetLastViewedSpecies(struct Blk37 *p);
extern unsigned int ZUKAN_SAVE_IsSeen(struct Blk37 *p, u16 id);
typedef unsigned int   u32;
struct Blk37;
extern void ZUKAN_SAVE_SetLastViewedSpecies(struct Blk37 *p, u32 v);
void ZUKAN_FixLastViewedSpecies(void *p,u16 *ids,unsigned count)
{
    unsigned current;
    u16 chosen,i;
    chosen=0xFFFF;current=ZUKAN_SAVE_GetLastViewedSpecies(p);
    for(i=0;i<count;i++) {
        if(ZUKAN_SAVE_IsSeen(p,ids[i])==1) {
            if(current==ids[i]) return;
            if(chosen==0xFFFF) chosen=ids[i];
        }
    }
    if(chosen!=0xFFFF) ZUKAN_SAVE_SetLastViewedSpecies(p,chosen);
}
