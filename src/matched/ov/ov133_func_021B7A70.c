/*
 * function: func_021B7A70
 * address: 0x021B7A70
 * packet: pkt_ov133_021B7A70
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02035C60 0x02035C60 arm
 *   func_02035CB8 0x02035CB8 arm
 *   func_021B7F54 0x021B7F54 thumb ov133
 *   func_021B7F00 0x021B7F00 thumb ov133
 *   func_021BA148 0x021BA148 thumb ov133
 *   func_021BA100 0x021BA100 thumb ov133
 *   func_021B8930 0x021B8930 thumb ov133
 *   func_021B8FF4 0x021B8FF4 thumb ov133
 *   func_021B7CFC 0x021B7CFC thumb ov133
 *   func_021BA18C 0x021BA18C thumb ov133
 *   func_021B8140 0x021B8140 thumb ov133
 *   func_021BA098 0x021BA098 thumb ov133
 *   func_021B8444 0x021B8444 thumb ov133
 *   func_021B82E8 0x021B82E8 thumb ov133
 *   func_021B8680 0x021B8680 thumb ov133
 *   func_021B8254 0x021B8254 thumb ov133
 *   func_021B765C 0x021B765C thumb ov133
 *   func_020061E4 0x020061E4 thumb
 *   _fflt 0x0209BDBC arm
 *   _fmul 0x0209C77C arm
 *   _ffix 0x0209C494 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern int func_02035C60(void),func_02035CB8(int *,int *);
extern void func_021B7F54(u8 *,int),func_021BA148(void *,u8 *),func_021BA100(void *,u8 *);
extern int func_021B7F00(u8 *,void *,u32),func_021B8930(u8 *),func_021B8FF4(int,int,int,float),func_021BA18C(void *);
extern void func_021B7CFC(u8 *,int,int),func_021B8140(u8 *),func_021BA098(u8 *),func_021B8444(u8 *),func_021B82E8(u8 *,int),func_021B8680(u8 *),func_021B8254(u8 *),func_021B765C(u8 *,u16,s16,int,u16),func_020061E4(u32);
void func_021B7A70(u8 *p)
{
    int moved=0,other=0,hit=0,outer,n,dx,dy;
    if(*(int *)(p+0x183c)==0){*(int *)(p+0x14)=func_02035C60();*(int *)(p+0x18)=func_02035CB8((int *)(p+0x1c),(int *)(p+0x20));}
    if(*(int *)(p+0x14)!=0 || *(int *)(p+0x18)!=0){
        if(*(u32 *)(p+0x20)>176)*(u32 *)(p+0x20)=176;
        if(*(u32 *)(p+0x20)<16)*(u32 *)(p+0x20)=16;
        if(*(int *)(p+0x3c)==2 && *(u8 **)(p+0x38))func_021B7F54(p,1);
        else if(*(int *)(p+0x14)==1){
            hit=func_021B7F00(p,*(void **)(p+0x1824),3);
            if(hit==1){func_021BA148(*(void **)(p+0x1824),*(u8 **)(p+0x38));func_021BA100(*(void **)(p+0x1820),*(u8 **)(p+0x38));func_021B7F54(p,0);}
            else other=func_021B8930(p);
        }
        if(hit==0 && other==0 && ((*(u8 **)(p+0x38)==0 && *(int *)(p+0x14)==1)||*(int *)(p+0x3c)==1)){
            dy=(s16)(*(u32 *)(p+0x20)-80);dx=(s16)(*(u32 *)(p+0x1c)-128);
            hit=func_021B8FF4(dx,dy,28,0.5384615659713745f);
            outer=func_021B8FF4(dx,dy,68,0.739130437374115f);
            if(hit==0 && outer==1){moved=1;func_021B7CFC(p,dx,dy);}
            else if((hit==0 && outer==0)||(hit==1 && outer==1)){
                if(func_021BA18C(*(void **)(p+0x1820))==0 && *(int *)(p+0x3c)==1 && *(u8 **)(p+0x38)){
                    n=*(s16 *)(p+0x182e);if(n<0)n=-n;
                    if(n<364)func_021B8140(p);
                }
            }
            if(moved==0 && *(int *)(p+0x14)==1)func_021B7F00(p,*(void **)(p+0x1820),2);
        }
        if(*(int *)(p+0x14)!=0 && *(u8 **)(p+0x38)==0 && *(u32 *)(p+0x20)>160 && *(u32 *)(p+0x1c)>96 && *(u32 *)(p+0x1c)<160){
            *(int *)(p+12)=2;*(int *)(p+16)=0;func_020061E4(0x622);func_021BA098(p);
        }
    }else {
        dy=(s16)(*(u32 *)(p+0x28)-80);dx=(s16)(*(u32 *)(p+0x24)-128);
        hit=func_021B8FF4(dx,dy,28,0.5384615659713745f);outer=func_021B8FF4(dx,dy,68,0.739130437374115f);
        if(*(int *)(p+0x3c)==2 && *(u8 **)(p+0x38)){
            if(*(int *)(p+0x34)!=10)func_021B8444(p);
            else if(hit==0 && outer==1)func_021B82E8(p,0);
            else if(hit==1)func_021B8680(p);
            else func_021B8254(p);
        }
        *(int *)(p+0x30)=0;*(int *)(p+0x38)=0;*(int *)(p+0x3c)=0;*(int *)(p+0x40)=0;*(int *)(p+0x34)=10;
    }
    if(*(s16 *)(p+0x182e)!=0 && moved==0){
        n=*(u16 *)(p+0x182c)+0x10000-*(s16 *)(p+0x182e);if(n<0)n+=0x10000;if(n>=0x10000)n-=0x10000;
        *(u16 *)(p+0x182c)=n;func_021B765C(p,*(u16 *)(p+0x182c),*(s16 *)(p+0x182e),72,48);
        if(*(s16 *)(p+0x182e)>128 || *(s16 *)(p+0x182e)<-128)*(s16 *)(p+0x182e)*=0.75f;
        else *(s16 *)(p+0x182e)=0;
    }
    *(u32 *)(p+0x24)=*(u32 *)(p+0x1c);*(u32 *)(p+0x28)=*(u32 *)(p+0x20);
}
