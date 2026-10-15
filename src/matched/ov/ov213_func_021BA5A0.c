/*
 * function: COMM_BTL_DEMO_MAIN_InitBattleContext
 * address: 0x021BA5A0
 * packet: pkt_ov213_021BA5A0
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: source kind,a,b emits image a,kind,b stores and both entry copies; source a,kind,b left115 differing bytes.
 * symbols:
 *   COMM_BTL_DEMO_MAIN_CreateSideActor 0x021BA750 thumb ov213
 *   COMM_BTL_DEMO_MAIN_CreateActor 0x021BA71C thumb ov213
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 * domain: loop index is exactly 0,1,2; each switch arm initializes both coordinates before use.
 */
typedef unsigned short u16;
typedef unsigned char u8;
extern void *COMM_BTL_DEMO_MAIN_CreateSideActor(void *p, int kind, unsigned a);
extern void *COMM_BTL_DEMO_MAIN_CreateActor(char *p, int a, int b, unsigned short c);
typedef unsigned int   u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
typedef struct {int pad0;const void *owner;void *other;u16 a,b;void *one,*two,*objects[3];char pad24[2];u8 kind;} Context;
void COMM_BTL_DEMO_MAIN_InitBattleContext(Context *p,const void *owner,void *other,u16 a,u16 b,u8 kind)
{
    int i,x,y;
    p->owner=owner;p->other=other;
    p->kind=kind;p->a=a;p->b=b;
    p->one=COMM_BTL_DEMO_MAIN_CreateSideActor((void *)owner,0,(u8)p->a);
    p->two=COMM_BTL_DEMO_MAIN_CreateSideActor((void *)owner,1,(u8)p->b);
    for(i=0;i<3;i++) {
        switch(i) {
        case 0:x=206;y=152;break;
        case 1:x=50;y=40;break;
        case 2:x=128;y=96;break;
        }
        p->objects[i]=COMM_BTL_DEMO_MAIN_CreateActor((void *)owner,x,y,7);
        CLACT_SetActorDrawEnable(p->objects[i],0);
    }
}
