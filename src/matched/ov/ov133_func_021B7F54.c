/*
 * function: func_021B7F54
 * address: 0x021B7F54
 * packet: pkt_ov133_021B7F54
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA218 0x021BA218 thumb ov133
 *   func_021BA21C 0x021BA21C thumb ov133
 *   func_021BA254 0x021BA254 thumb ov133
 *   func_021B8BB4 0x021B8BB4 thumb ov133
 *   func_021B8B78 0x021B8B78 thumb ov133
 *   func_021F5450 0x021F5450 thumb ov112
 *   func_021F4EE8 0x021F4EE8 thumb ov112
 *   func_021F4B24 0x021F4B24 thumb ov112
 *   func_021F4E8C 0x021F4E8C thumb ov112
 *   func_021F4ED4 0x021F4ED4 thumb ov112
 *   func_021F4EC4 0x021F4EC4 thumb ov112
 *   func_021F4EB4 0x021F4EB4 thumb ov112
 *   func_020061E4 0x020061E4 thumb
 *   _fflt 0x0209BDBC arm
 *   _fdiv 0x0209CE10 arm
 *   _ffix 0x0209C494 arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   d_021BA5A0 0x021BA5A0 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct {int x,y,z;} Vec;
typedef struct {int x,y;} Pair;
typedef struct {s16 y,x;u16 limit;} Scale;
extern const Vec d_021BA5A0;
extern u32 func_021BA218(u8 *p);
extern u8 *func_021F5450(u8 *,int);
extern int func_021B8BB4(u8 *,void *,const int *,u16 *),func_021B8B78(u8 *,int),func_021F4B24(u8 *);
extern void func_021BA21C(u8 *,Pair *),func_021BA254(u8 *,int),func_020061E4(u32);
extern void func_021F4EE8(int,int,int),func_021F4E8C(int,int,Vec *),func_021F4ED4(int,int,u16),func_021F4EC4(int,int,s16 *,s16 *),func_021F4EB4(int,int,s16,s16);
void func_021B7F54(u8 *p,int sound)
{
    Vec v;
    Pair pos,relative;
    Scale scale;
    int old,index;
    u8 *sprite,*q;
    u16 rotation=0;
    scale.limit=12;v=d_021BA5A0;
    old=*(int *)(p+0x34);sprite=(u8 *)func_021BA218(*(u8 **)(p+0x38));
    relative.x=*(int *)(p+0x1c)-128;relative.y=*(int *)(p+0x20)-112;
    index=func_021B8BB4(p,sprite,(const int *)&relative,&scale.limit);*(int *)(p+0x34)=index;
    if(index!=10){
        q=func_021F5450(*(u8 **)(p+0x1880),index);
        pos.x=(int)((float)(*(int *)(q+4)+*(int *)(q+16))/4096.f)+128;
        pos.y=(int)((float)(*(int *)(q+8)+*(int *)(q+20))/4096.f)+96;
        rotation=*(u16 *)(q+0x36);func_021F4EE8(*(int *)(p+0x1884),(int)sprite,1);
        if(func_021F4B24(sprite)==1)v.z=0x1a000;
        if(func_021B8B78(p,*(int *)(p+0x34))==0){*(int *)(p+0x40)=3;*(int *)(p+0x44)=pos.x;*(int *)(p+0x48)=pos.y;}
        func_021BA254(*(u8 **)(p+0x38),*(int *)(p+0x34));
        if(old!=*(int *)(p+0x34) && sound==1)func_020061E4(0x627);
    }else{
        *(int *)(p+0x34)=10;pos.x=*(int *)(p+0x1c);pos.y=*(int *)(p+0x20);
        func_021F4EE8(*(int *)(p+0x1884),(int)sprite,rotation);
    }
    if(pos.x>0)v.x=(int)(0.5f+(float)(int)((u32)pos.x<<12));else v.x=(int)((float)(int)((u32)pos.x<<12)-0.5f);
    if(pos.y>0)v.y=(int)(0.5f+(float)(int)((u32)pos.y<<12));else v.y=(int)((float)(int)((u32)pos.y<<12)-0.5f);
    func_021F4E8C(*(int *)(p+0x1884),(int)sprite,&v);
    func_021BA21C(*(u8 **)(p+0x38),&pos);
    q=(u8 *)func_021BA218(*(u8 **)(p+0x38));func_021F4ED4(*(int *)(p+0x1884),(int)q,rotation);
    func_021F4EC4(*(int *)(p+0x1884),(int)sprite,&scale.x,&scale.y);
    if(scale.x<4096 || scale.y<4096){
        scale.x+=410;scale.y+=410;
        if(scale.x>4096)scale.x=4096;if(scale.y>4096)scale.y=4096;
        func_021F4EB4(*(int *)(p+0x1884),(int)sprite,scale.x,scale.y);
    }
}
