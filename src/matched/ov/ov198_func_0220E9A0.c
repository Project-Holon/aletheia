/*
 * function: B_PLIST_DRAW_SwapActorPair
 * address: 0x0220E9A0
 * packet: pkt_ov198_0220E9A0
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   B_PLIST_DRAW_TransferCharacter 0x0220E82C thumb ov198
 *   B_PLIST_DRAW_PlaceActor 0x0220E7CC thumb ov198
 */
typedef unsigned char u8;
typedef struct {short x,y;} Pair;
typedef struct {u8 low:5;u8 flip:1;u8 high:2;} Flags;
extern void B_PLIST_DRAW_TransferCharacter(char *,void *,int,int);
extern void B_PLIST_DRAW_PlaceActor(u8 *,unsigned);
void B_PLIST_DRAW_SwapActorPair(char *p,u8 *q,Pair *pos)
{
    int first,index;
    char *base;
    if(((Flags *)(p+0x2175))->flip==0){first=25;index=8;}
    else{first=27;index=10;}
    base=p+0x1ebc;
    B_PLIST_DRAW_TransferCharacter(p,*(void **)(base+first*4),index,q[20]);
    B_PLIST_DRAW_PlaceActor(*(u8 **)(base+first*4),(unsigned)pos);
    if(q[20]!=q[21]){
        B_PLIST_DRAW_TransferCharacter(p,*(void **)(p+0x1ebc+(first+1)*4),index+1,q[21]);
        B_PLIST_DRAW_PlaceActor(*(u8 **)(p+0x1ebc+(first+1)*4),(unsigned)(pos+1));
    }
    ((Flags *)(p+0x2175))->flip^=1;
}
