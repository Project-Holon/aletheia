/*
 * function: COMM_BTL_DEMO_MAIN_UpdateActorRow
 * address: 0x021BA034
 * packet: pkt_ov213_021BA034
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 * COMM_BTL_DEMO_MAIN_GetSoundId 0x021B98DC thumb ov213
 * GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 * COMM_BTL_DEMO_MAIN_IsFullPartyMode 0x021B9E50 thumb ov213
 * COMM_BTL_DEMO_MAIN_HasVisibleActors 0x021B9E80 thumb ov213
 * COMM_BTL_DEMO_MAIN_StartEffects 0x021BA8F4 thumb ov213
 * CLACT_SetActorDrawEnable 0x0204B3DC arm
 * COMM_BTL_DEMO_MAIN_SetRowActorAnim 0x021BA1C8 thumb ov213
 * CLACT_SetActorBgPriority 0x0204B84C arm
 * zero 0x021BB08C data ov213
 */
typedef unsigned int u32;
typedef unsigned char u8;
struct V {int x,y,z;};
struct C {void *owner,*parent; u8 kind,index,n,count; void *obj[6]; int step; u8 active; u8 pad[3]; const u8 *types;};
extern struct V zero;
extern int COMM_BTL_DEMO_MAIN_GetSoundId(int,int);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern int COMM_BTL_DEMO_MAIN_IsFullPartyMode(u32),COMM_BTL_DEMO_MAIN_HasVisibleActors(u32);
extern void COMM_BTL_DEMO_MAIN_StartEffects(char *p, int v);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v),CLACT_SetActorBgPriority(void*,u32);
extern void COMM_BTL_DEMO_MAIN_SetRowActorAnim(char *p, void *list, const u8 *flags, int index);
void COMM_BTL_DEMO_MAIN_UpdateActorRow(struct C *p, u32 time)
{
    int i=p->step-time;
    int x,y;
    struct V pos;
    if(i < p->count) {
        if(i==0 && p->index==0) GFL_USE_PlaySeDefaultVolume(COMM_BTL_DEMO_MAIN_GetSoundId(0,0));
        if(COMM_BTL_DEMO_MAIN_IsFullPartyMode(p->kind)) {
            if(p->index==0){x=-0x400-(i<<11);y=-0x2500;}
            else if(p->index==1){x=(i<<11)+0x300;y=0x1300;}
        } else {
            if(p->index==0){x=-0x1800-(i<<11);y=-0x1500;}
            else if(p->index==1){x=0x800-(i<<11);y=-0x2800;}
            else if(p->index==2){x=(i<<11)-0x100;y=0x1800;}
            else if(p->index==3){x=(i<<11)+0x1f00;y=0x300;}
        }
        pos=zero; pos.x=x; pos.y=y;
        COMM_BTL_DEMO_MAIN_StartEffects(p->parent,(int)(&pos));
        if(COMM_BTL_DEMO_MAIN_HasVisibleActors(p->kind)) CLACT_SetActorDrawEnable(p->obj[i],1);
        else COMM_BTL_DEMO_MAIN_SetRowActorAnim((char *)p,p->owner,p->types,p->count-1-i);
    } else {
        for(i=0;i<p->count;i++) CLACT_SetActorBgPriority(p->obj[i],1);
        p->active=0;
    }
}
