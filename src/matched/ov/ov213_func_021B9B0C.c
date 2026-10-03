/*
 * function: func_021B9B0C
 * address: 0x021B9B0C
 * packet: pkt_ov213_021B9B0C
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 * func_021B61FC 0x021B61FC thumb ov067
 * func_021B6200 0x021B6200 thumb ov067
 * func_021BA444 0x021BA444 thumb ov213
 * func_021BA650 0x021BA650 thumb ov213
 * func_021B9E50 0x021B9E50 thumb ov213
 * func_021BA95C 0x021BA95C thumb ov213
 * func_021BA81C 0x021BA81C thumb ov213
 * func_021BA480 0x021BA480 thumb ov213
 * func_021BA9D0 0x021BA9D0 thumb ov213
 * func_021B98DC 0x021B98DC thumb ov213
 * func_020061E4 0x020061E4 thumb
 * func_021BA68C 0x021BA68C thumb ov213
 * func_0204B3DC 0x0204B3DC arm
 * func_0204E720 0x0204E720 arm
 * func_021BA8E8 0x021BA8E8 thumb ov213
 * d0 0x021BB0D4 data a4
 * d1 0x021BB0E0 data ov213
 * d2 0x021BB068 data ov213
 * d3 0x021BB074 data ov213
 * d4 0x021BB080 data ov213
 * d5 0x021BB098 data a4
 */
typedef unsigned int u32;
struct V {int x,y,z;};
extern const struct V d0,d1,d2,d3,d4,d5;
extern u32 func_021B61FC(const unsigned char*);
extern void func_021B6200(unsigned char*);
extern void func_021BA444(void*),func_021BA650(void*);
extern int func_021B9E50(u32);
extern void func_021BA95C(unsigned char*,int),func_021BA81C(unsigned char*,u32),func_021BA480(void*);
extern int func_021BA9D0(unsigned char*),func_021B98DC(int,int);
extern void func_020061E4(u32 a);
extern void func_021BA68C(void*,int,int),func_0204B3DC(void*,u32),func_0204E720(u32,int,int,int);
extern void func_021BA8E8(void*,u32,const struct V*);
int func_021B9B0C(unsigned char *state,unsigned char *p)
{
    int stage,x,y,index;
    struct V v0,v1,v2,v3,v4,v5;
    stage=func_021B61FC(state);
    func_021BA444(p);func_021BA650(p+0x498c);
    switch(stage){
    case 0:
        if(func_021B9E50(p[0x49c8]))func_021BA95C(p+0x24,1);
        else func_021BA95C(p+0x24,3);
        func_021BA81C(p+0x24,0xd);
        func_021BA480(p);func_021B6200(state);break;
    case 1:
        if(func_021BA9D0(p+0x24)==0){
            if(*(int*)(p+0x49cc)==2)return 1;
            *(int*)(p+0x49d0)=0;
            func_021BA81C(p+0x24,0xc);func_021B6200(state);
        }break;
    case 2:
        if(*(int*)(p+0x49d0)==15){
            index=*(int*)(p+0x49cc)!=0;
            func_020061E4(func_021B98DC(2,*(int*)(*(unsigned char**)(p+4)+0x50)));
            func_021BA68C(p+0x498c,index,0);
        }else if(*(int*)(p+0x49d0)==24){
            index=*(int*)(p+0x49cc)!=0;
            func_0204B3DC(*(void**)((u32)p+(u32)index*4+0x499c),0);
        }else if(*(int*)(p+0x49d0)==45){
            index=*(int*)(p+0x49cc)!=1;
            func_021BA68C(p+0x498c,index,1);
        }else if(*(int*)(p+0x49d0)==54){
            index=*(int*)(p+0x49cc)!=1;
            func_0204B3DC(*(void**)((u32)p+(u32)index*4+0x499c),0);
        }else if(*(int*)(p+0x49d0)==120)func_0204E720(3,0,16,-3);
        else if(*(int*)(p+0x49d0)==128)return 1;
        if(*(int*)(p+0x49d0)%180==0){
            if(*(int*)(p+0x49cc)==1){x=-0x2800;y=0x2000;}
            else{x=0x2800;y=-0x1800;}
            v0=d0;v0.x=x;v0.y=y;func_021BA8E8(p+0x24,0,&v0);
            v1=d1;v1.x=x;v1.y=y;func_021BA8E8(p+0x24,1,&v1);
            v2=d2;v2.x=x;v2.y=y;func_021BA8E8(p+0x24,2,&v2);
            v3=d3;v3.x=x;v3.y=y;func_021BA8E8(p+0x24,3,&v3);
            v4=d4;v4.x=x;v4.y=y;func_021BA8E8(p+0x24,4,&v4);
            v5=d5;v5.x=x;v5.y=y;func_021BA8E8(p+0x24,5,&v5);
        }
        (*(int*)(p+0x49d0))++;break;
    }
    return 0;
}
