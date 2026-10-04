/*
 * function: func_021B8140
 * address: 0x021B8140
 * packet: pkt_ov133_021B8140
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA20C 0x021BA20C thumb ov133
 *   func_021BA19C 0x021BA19C thumb ov133
 *   func_021BA100 0x021BA100 thumb ov133
 *   func_021BA21C 0x021BA21C thumb ov133
 *   func_021BA218 0x021BA218 thumb ov133
 *   func_021BA228 0x021BA228 thumb ov133
 *   func_021B7A18 0x021B7A18 thumb ov133
 *   func_021F4EC4 0x021F4EC4 thumb ov112
 *   func_021F4EB4 0x021F4EB4 thumb ov112
 *   func_021F4EE8 0x021F4EE8 thumb ov112
 *   func_020061E4 0x020061E4 thumb
 *   _ffltu 0x0209BE04 arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   d_021BA5B8 0x021BA5B8 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int x,y,z; } Vec;
typedef struct { u32 x,y; } Pair;
typedef struct { short y,x; } Scale;
extern const Vec d_021BA5B8;
extern u32 func_021BA20C(u8 *p);
extern u32 func_021BA218(u8 *p);
extern u8 *func_021BA19C(u16,void *,u8 *,Vec *);
extern void func_021BA100(void *,u8 *),func_021BA21C(u8 *,Pair *);
extern u32 *func_021BA228(u8 *);
extern void func_021F4EC4(int,int,short *,short *),func_021F4EB4(int,int,short,short);
extern void func_021F4EE8(int,int,int),func_021B7A18(u8 *),func_020061E4(u32);
void func_021B8140(u8 *p)
{
    Vec scale=d_021BA5B8;
    Pair pos;
    Scale old;
    u8 *q,*data,*s,*t;
    u32 *v;
    data=(u8 *)func_021BA20C(*(u8 **)(p+0x38));
    pos.x=*(u32 *)(p+0x1c);pos.y=*(u32 *)(p+0x20);
    if(pos.x!=0) scale.x=(int)(0.5f+(float)(pos.x<<12));
    else scale.x=(int)((float)(pos.x<<12)-0.5f);
    if(*(u32 *)(p+0x20)!=0) scale.y=(int)(0.5f+(float)(*(u32 *)(p+0x20)<<12));
    else scale.y=(int)((float)(*(u32 *)(p+0x20)<<12)-0.5f);
    q=func_021BA19C(*(u16 *)p,*(void **)(p+0x1884),data,&scale);
    func_021BA100(*(void **)(p+0x1820),q);
    func_021BA21C(q,&pos);
    s=(u8 *)func_021BA218(*(u8 **)(p+0x38));t=(u8 *)func_021BA218(q);
    func_021F4EC4(*(int *)(p+0x1884),(int)s,&old.x,&old.y);
    func_021F4EB4(*(int *)(p+0x1884),(int)t,old.x,old.y);
    func_021F4EE8(*(int *)(p+0x1884),(int)t,0);
    v=func_021BA228(*(u8 **)(p+0x38));
    *(u32 *)(p+0x40)=1;
    *(u32 *)(p+0x44)=v[0];*(u32 *)(p+0x48)=v[1];
    *(u32 *)(p+0x3c)=2;*(u8 **)(p+0x38)=q;*(u32 *)(p+0x40)=1;
    *(u32 *)(data+12)=1;
    func_021B7A18(p);func_020061E4(0x625);
}
