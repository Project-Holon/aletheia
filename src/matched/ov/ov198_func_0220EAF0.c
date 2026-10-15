/*
 * function: B_PLIST_DRAW_LayoutMode0
 * address: 0x0220EAF0
 * packet: pkt_ov198_0220EAF0
 * region: ov198
 * status: EXACT
 * lever: the final pointer-table subscript preserves the unscaled index
 * spill and its fresh shift. Byte-offset pointer arithmetic CSEs that shift.
 * symbols:
 *   B_PLIST_MAIN_GetOrderIndex 0x022110D4 thumb ov198
 *   B_PLIST_DRAW_PlaceActor 0x0220E7CC thumb ov198
 *   B_PLIST_DRAW_SetActorAnim 0x0220E974 thumb ov198
 *   B_PLIST_DRAW_SetActorAnimByMode 0x0220EA30 thumb ov198
 *   d_02211DB4 0x02211DB4 data a2
 *   d_02211DCC 0x02211DCC data a2
 *   d_02211DE4 0x02211DE4 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {short x,y;} Pair;
typedef struct {u8 low:3;u8 kind:4;u8 high:1;} Bits;
typedef struct {u8 bytes[76];} Record;
extern const Pair d_02211DB4[],d_02211DCC[],d_02211DE4[];
extern int B_PLIST_MAIN_GetOrderIndex(u8 *,int);
extern void B_PLIST_DRAW_PlaceActor(u8 *,unsigned);
typedef unsigned int   u32;
struct Vec2;
extern void B_PLIST_DRAW_SetActorAnim(int mode, u8 *p, const struct Vec2 *q);
extern void B_PLIST_DRAW_SetActorAnimByMode(u32 mode, u8 *p, const struct Vec2 *q);
void B_PLIST_DRAW_LayoutMode0(Record *records) {
    u8 *p=(u8 *)records;
    short i;
    int index,offset;
    Pair pair;
    for(i=0;i<6;i++) {
        index=B_PLIST_MAIN_GetOrderIndex(p,i);
        offset=index*76;
        if(*(u16 *)((char *)records+offset+8)!=0) {
            B_PLIST_DRAW_PlaceActor(*(u8 **)(p+index*4+0x1ed8),(unsigned)&d_02211DB4[i]);
            B_PLIST_DRAW_SetActorAnim(((Bits *)(p+0x1b))[offset].kind,*(u8 **)(p+index*4+0x1ef0),(const struct Vec2 *)(&d_02211DCC[i]));
            if(((Bits *)(p+0x1b))[offset].high==0)
                B_PLIST_DRAW_PlaceActor(*(u8 **)(p+index*4+0x1f08),(unsigned)&d_02211DE4[i]);
            pair=d_02211DB4[i];
            pair.x+=8;
            pair.y+=8;
            B_PLIST_DRAW_SetActorAnimByMode(*(u16 *)((char *)records+offset+0x1e),((u8 **)(p+0x1ebc))[index],(const struct Vec2 *)(&pair));
        }
    }
}
