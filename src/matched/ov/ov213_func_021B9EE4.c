/*
 * function: COMM_BTL_DEMO_MAIN_InitActorRow
 * address: 0x021B9EE4
 * packet: pkt_ov213_021B9EE4
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: negative constant multiplication keeps Thumb shift/negate/add; unary negation is folded back into constant-minus-shift.
 * symbols:
 * POKEPARTY_GetCount 0x0201AA18 thumb
 * POKEPARTY_GetMember 0x0201AB28 thumb
 * COMM_BTL_DEMO_MAIN_IsFullPartyMode 0x021B9E50 thumb ov213
 * COMM_BTL_DEMO_MAIN_HasVisibleActors 0x021B9E80 thumb ov213
 * COMM_BTL_DEMO_MAIN_TypeToFrame 0x021B9EB0 thumb ov213
 * COMM_BTL_DEMO_MAIN_CreateActor 0x021BA71C thumb ov213
 * CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
struct C {void *owner,*parent; u8 kind,index,n,count; void *obj[6]; int step; u8 active; u8 pad[3]; const u8 *types;};
struct Obj;
extern u32 POKEPARTY_GetCount(void *p);
extern void *POKEPARTY_GetMember(void*,u32);
extern int COMM_BTL_DEMO_MAIN_IsFullPartyMode(u32),COMM_BTL_DEMO_MAIN_HasVisibleActors(u32);
extern int COMM_BTL_DEMO_MAIN_TypeToFrame(void*,u32);
extern void *COMM_BTL_DEMO_MAIN_CreateActor(char *p, int a, int b, unsigned short c);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
void COMM_BTL_DEMO_MAIN_InitActorRow(struct C *p,void *owner,u8 kind,u8 index,void *a,void *parent,const u8 *types)
{
    int i,x,y,frame;
    void *entry;
    p->kind=kind;p->index=index;p->owner=owner;
    p->n=POKEPARTY_GetCount(owner);
    if(COMM_BTL_DEMO_MAIN_IsFullPartyMode(kind))p->count=6;else p->count=3;
    p->parent=parent;p->step=0;p->types=types;
    for(i=0;i<p->count;i++){
        if(COMM_BTL_DEMO_MAIN_IsFullPartyMode(kind)){
            x=(s16)((i<<4)+0x88);
            y=(s16)(index==0?0xa8:0x38);
            if(index==0)x*=-1;
        }else{
            switch(index){
            case 0:x=(s16)(i * -16+0x50);y=0x88;break;
            case 1:x=(s16)(i * -16+0x90);y=0xb0;break;
            case 2:x=(s16)((i<<4)+0x80);y=0x30;break;
            case 3:x=(s16)((i<<4)+0xc0);y=0x58;break;
            }
        }
        entry=0;
        if(i<p->n)entry=POKEPARTY_GetMember(owner,i);
        frame=COMM_BTL_DEMO_MAIN_TypeToFrame(entry,types[i]);
        if(!COMM_BTL_DEMO_MAIN_HasVisibleActors(kind)&&frame!=0xd)frame=0xa;
        p->obj[i]=COMM_BTL_DEMO_MAIN_CreateActor(a,x,y,(u16)frame);
        if(COMM_BTL_DEMO_MAIN_HasVisibleActors(kind))CLACT_SetActorDrawEnable(p->obj[i],0);
        else CLACT_SetActorDrawEnable(p->obj[i],1);
    }
}
