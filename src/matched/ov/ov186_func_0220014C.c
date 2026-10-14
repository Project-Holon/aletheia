/*
 * function: BR_POKESEARCH_HasSeenInGroup
 * address: 0x0220014C
 * packet: pkt_ov186_0220014C
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: unsigned table indices preserve load scheduling; raw address casts differ by 12 bytes.
 * symbols:
 *   ZUKAN_SAVE_IsSeen 0x0200D064 thumb
 *   gBrPokeSearchGroupStart 0x02200C94 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u16 gBrPokeSearchGroupStart[];
struct Blk37;
extern u32 ZUKAN_SAVE_IsSeen(struct Blk37 *p, u16 id);
int BR_POKESEARCH_HasSeenInGroup(void *p,u32 n,const u16 *ids) { u32 i; u32 end; int found; end=gBrPokeSearchGroupStart[n+1];found=0;for(i=gBrPokeSearchGroupStart[n];i<end;i++) { if(ZUKAN_SAVE_IsSeen(p,*(const u16 *)((u32)ids+i*2)))found=1; }return found; }
