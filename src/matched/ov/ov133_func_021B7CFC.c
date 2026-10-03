/*
 * function: func_021B7CFC
 * address: 0x021B7CFC
 * packet: pkt_ov133_021B7CFC
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203F768 0x0203F768 arm
 *   func_021BA184 0x021BA184 thumb ov133
 *   func_021BA208 0x021BA208 thumb ov133
 *   func_021BA20C 0x021BA20C thumb ov133
 *   func_021BA25C 0x021BA25C thumb ov133
 *   func_021B765C 0x021B765C thumb ov133
 *   func_020061E4 0x020061E4 thumb
 *   _u32_div_f 0x0209C2B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern int func_0203F768(int,int,int,int,int,int,int);
extern u8 *func_021BA184(void *),*func_021BA208(u8 *),*func_021BA20C(u8 *);
extern int func_021BA25C(u8 *,int,int);
extern void func_021B765C(u8 *,u16,s16,int,u16),func_020061E4(u32);
void func_021B7CFC(u8 *p,s16 unused_x,s16 unused_y)
{
    int y0,y1,angle,hit,n;
    u8 *e,*data;
    y0=(*(u32 *)(p+0x28)*72)/48;
    y1=(*(u32 *)(p+0x20)*72)/48;
    angle=func_0203F768(*(int *)(p+0x24),y0,*(int *)(p+0x1c),y1,128,80,72);
    *(u16 *)(p+0x1830)+=(u16)(angle<0?-angle:angle);
    if(*(int *)(p+0x14)==1 || *(u16 *)(p+0x1830)>=0x71c){
        e=func_021BA184(*(void **)(p+0x181c));hit=0;
        if(*(int *)(p+0x14)==1)*(u16 *)(p+0x182e)=0;
        *(u16 *)(p+0x1830)=0;*(u8 **)(p+0x38)=0;
        while(e){
            data=func_021BA20C(e);
            if(func_021BA25C(e,*(int *)(p+0x1c),*(int *)(p+0x20))==1){
                hit=1;
                if(*(int *)(data+12)==0){*(u8 **)(p+0x38)=e;*(int *)(p+0x3c)=1;e=0;}
            }
            if(*(u8 **)(p+0x38)==0)e=func_021BA208(e);
        }
        if(*(int *)(p+0x14)==1 && hit==1 && *(u8 **)(p+0x38)==0){*(int *)(p+0x3c)=1;func_020061E4(0x557);}
    }
    if(*(int *)(p+0x30)==1){
        if((angle<0?-angle:angle)>227 && (angle<0?-angle:angle)<0x4000){
            n=*(u16 *)(p+0x182c)+0x10000-angle;
            if(n<0)n+=0x10000;
            if(n>=0x10000)n-=0x10000;
            *(u16 *)(p+0x182c)=n;
            func_021B765C(p,*(u16 *)(p+0x182c),(s16)angle,72,48);
            if(angle>=0 && *(s16 *)(p+0x182e)>0 && angle<*(s16 *)(p+0x182e))
                *(s16 *)(p+0x182e)=(*(s16 *)(p+0x182e)+angle)/2;
            else if(angle<=0 && *(s16 *)(p+0x182e)<0 && angle>*(s16 *)(p+0x182e))
                *(s16 *)(p+0x182e)=(*(s16 *)(p+0x182e)+angle)/2;
            else *(s16 *)(p+0x182e)=angle;
            n=*(s16 *)(p+0x182e);
            if((n>0 && *(s16 *)(p+0x1838)>0)||(n<0 && *(s16 *)(p+0x1838)<0))*(s16 *)(p+0x1838)=0;
            else if(n>0 && *(s16 *)(p+0x1838)>-0x3000){
                if(n*15>*(s16 *)(p+0x1838)*-10)*(s16 *)(p+0x1838)-=256;
            } else if(n<0 && *(s16 *)(p+0x1838)<0x3000){
                if(n*-15>*(s16 *)(p+0x1838)*10)*(s16 *)(p+0x1838)+=256;
            }
        }else *(s16 *)(p+0x182e)=0;
    }
    *(int *)(p+0x30)=1;
}
