/*
 * function: GTSNEGO_MSG_CreateActorAt
 * address: 0x021D6AF0
 * packet: pkt_ov120_021D6AF0
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 0x021D6B5A..021D6B5C is two bytes of zero alignment padding.
 * symbols:
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
struct GtsnegoMsgCtx {
    unsigned char pad_0[16];
    void * f10;
    unsigned char pad_14[4];
    unsigned int f18;
    unsigned char pad_1C[12];
    unsigned int f28;
    unsigned char pad_2C[72];
    unsigned int f74;
    unsigned char pad_78[124];
    unsigned short fF4;
};
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
typedef struct Record {u16 x,y,z;u8 a,b;} Record;
struct Obj;
extern struct Obj *CLACT_CreateActor(void *,u32,u32,u32,const void *,u16,u16);
extern void CLACT_SetActorAutoAnim(struct Obj *,u32);extern void CLACT_SetActorDrawEnable(struct Obj *,u32);
void GTSNEGO_MSG_CreateActorAt(u8 *p,u16 x,u16 y,int flag) {
Record r;int i;
for(i=0;i<12;i++) {
if(!*(void **)(p+i*4+0xc4)) {
r.x=x;r.y=y;r.z=flag?2:0;r.a=0;r.b=1;
*(void **)(p+0xc4+i*4)=CLACT_CreateActor((void *)((struct GtsnegoMsgCtx *)p)->f10,((struct GtsnegoMsgCtx *)p)->f28,((struct GtsnegoMsgCtx *)p)->f18,((struct GtsnegoMsgCtx *)p)->f74,&r,1,((struct GtsnegoMsgCtx *)p)->fF4);
CLACT_SetActorAutoAnim(*(void **)(p+0xc4+i*4),1);
CLACT_SetActorDrawEnable(*(void **)(p+0xc4+i*4),1);
return;
}
}
}
