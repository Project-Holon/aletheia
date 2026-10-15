/*
 * function: B_BAG_MAIN_DrawItemRow
 * address: 0x0220C724
 * packet: pkt_ov197_0220C724
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * matching: pair aggregate copy emits two unsigned halfword transfers;
 *   explicit objects base keeps the first indexed address split correctly.
 * symbols:
 *   B_BAG_MAIN_PlaceActor 0x0220C4D4 thumb ov197
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
struct Pair { short x,y; };
extern void B_BAG_MAIN_PlaceActor(int,int);
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
void B_BAG_MAIN_DrawItemRow(char *p,u16 slot,u8 a,u8 b,const struct Pair *src)
{
    struct Pair v;
    u16 i;
    s8 left,right;
    void **objects=(void **)(p+0x424);
    B_BAG_MAIN_PlaceActor((int)objects[slot],(int)src);
    CLACT_SetActorAnimSeq(objects[slot],a);
    slot++;
    left=a;
    right=b;
    v=*src;
    v.x+=12;
    for(i=0;i<7;i++) {
        if(left<=0) {
            if(right<=0) CLACT_SetActorAnimSeq(*(void **)(p+slot*4+0x424),15);
            else if(right==1) {CLACT_SetActorAnimSeq(*(void **)(p+slot*4+0x424),19);right--;}
            else {CLACT_SetActorAnimSeq(*(void **)(p+slot*4+0x424),20);right-=2;}
        } else if(left==1) {
            if(right==0) CLACT_SetActorAnimSeq(*(void **)(p+slot*4+0x424),16);
            else if(right>0) {CLACT_SetActorAnimSeq(*(void **)(p+slot*4+0x424),18);right--;}
            left--;
        } else {CLACT_SetActorAnimSeq(*(void **)(p+slot*4+0x424),17);left-=2;}
        B_BAG_MAIN_PlaceActor(*(int *)(p+slot*4+0x424),(int)&v);
        v.x+=8;
        slot++;
    }
}
