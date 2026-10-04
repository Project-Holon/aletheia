/*
 * function: func_021B7368
 * address: 0x021B7368
 * packet: pkt_ov133_021B7368
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B7458 0x021B7458 thumb ov133
 *   func_021BA188 0x021BA188 thumb ov133
 *   func_021BA19C 0x021BA19C thumb ov133
 *   func_021BA100 0x021BA100 thumb ov133
 *   func_021BA21C 0x021BA21C thumb ov133
 *   func_021BA218 0x021BA218 thumb ov133
 *   func_021F4EB4 0x021F4EB4 thumb ov112
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
extern void func_021B7458(u8 *, Pair *);
extern u32 func_021BA188(u8 *);
extern u8 *func_021BA19C(u16,void *,u8 *,Vec *);
extern void func_021BA100(void *,u8 *),func_021BA21C(u8 *,Pair *);
extern u32 func_021BA218(u8 *);
extern void func_021F4EB4(int,int,s16,s16);
void func_021B7368(u8 *p,u16 id)
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
        func_021B7458(p,&pos);
        if((int)pos.x>0) scale.x=(int)(0.5f+(float)((int)pos.x<<12));
        else scale.x=(int)((float)((int)pos.x<<12)-0.5f);
        if((int)pos.y>0) y=(int)(0.5f+(float)((int)pos.y<<12));
        else y=(int)((float)((int)pos.y<<12)-0.5f);
        scale.y=y;
        scale.z=(10<<12)-(func_021BA188(*(u8 **)(p+0x1820))<<10);
        q=func_021BA19C(*(u16 *)p,*(void **)(p+0x1884),e,&scale);
        func_021BA100(*(void **)(p+0x1820),q);
        func_021BA21C(q,&pos);
        func_021F4EB4(*(int *)(p+0x1884),func_021BA218(q),0x1000,0x1000);
        *(u32 *)(e+0xc)=1;
    }
}
