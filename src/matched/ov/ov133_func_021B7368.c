/*
 * function: DUP_FITTING_AddFitElemById
 * address: 0x021B7368
 * packet: pkt_ov133_021B7368
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DUP_FITTING_RandomPos 0x021B7458 thumb ov133
 *   DUP_FITTING_ITEM_ListGetCount 0x021BA188 thumb ov133
 *   DUP_FITTING_ITEM_CreateElem 0x021BA19C thumb ov133
 *   DUP_FITTING_ITEM_InsertElem 0x021BA100 thumb ov133
 *   DUP_FITTING_ITEM_ElemSetPos 0x021BA21C thumb ov133
 *   DUP_FITTING_ITEM_ElemGetRenderElem 0x021BA218 thumb ov133
 *   MUSICAL_MCSS_SetElemRotZ 0x021F4EB4 thumb ov112
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef struct { int x,y,z; } Vec;
typedef struct { u32 x,y; } Pair;
struct Object;
extern void DUP_FITTING_RandomPos(void *unused, int *p);
extern unsigned short DUP_FITTING_ITEM_ListGetCount(char *p);
extern u8 *DUP_FITTING_ITEM_CreateElem(u16 heap, struct Object *q, u8 *r, int *v);
extern void DUP_FITTING_ITEM_InsertElem(u8 *p, u8 *q);
extern void DUP_FITTING_ITEM_ElemSetPos(u8 *p, const u8 *src);
extern u32 DUP_FITTING_ITEM_ElemGetRenderElem(u8 *);
extern void MUSICAL_MCSS_SetElemRotZ(u32 unused, u32 p, s16 a, s16 b);
void DUP_FITTING_AddFitElemById(u8 *p,u16 id)
{
    Pair pos;
    Vec scale;
    u8 *e,*q;
    u8 i;
    e=0;
    for(i=0;i<*(u16 *)(p+0xa8);i++){
        if(id==*(u16 *)(p+i*20+0xac)){e=p+0xac+i*20;break;}
    }
    if(e){
        int y;
        DUP_FITTING_RandomPos(p,(int *)(&pos));
        if((int)pos.x>0) scale.x=(int)(0.5f+(float)((int)pos.x<<12));
        else scale.x=(int)((float)((int)pos.x<<12)-0.5f);
        if((int)pos.y>0) y=(int)(0.5f+(float)((int)pos.y<<12));
        else y=(int)((float)((int)pos.y<<12)-0.5f);
        scale.y=y;
        scale.z=(10<<12)-(DUP_FITTING_ITEM_ListGetCount((char *)(*(u8 **)(p+0x1820)))<<10);
        q=DUP_FITTING_ITEM_CreateElem(*(u16 *)p,*(void **)(p+0x1884),e,(int *)(&scale));
        DUP_FITTING_ITEM_InsertElem(*(void **)(p+0x1820),q);
        DUP_FITTING_ITEM_ElemSetPos(q,(const u8 *)(&pos));
        MUSICAL_MCSS_SetElemRotZ(*(int *)(p+0x1884),DUP_FITTING_ITEM_ElemGetRenderElem(q),0x1000,0x1000);
        *(u32 *)(e+0xc)=1;
    }
}
