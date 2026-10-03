/*
 * function: func_021FB2B0
 * address: 0x021FB2B0
 * packet: pkt_ov132_021FB2B0
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021FB1F4 0x021FB1F4 thumb ov132
 *   func_021F9DA0 0x021F9DA0 thumb ov132
 *   func_021F9DA4 0x021F9DA4 thumb ov132
 *   func_021F8044 0x021F8044 thumb ov112
 *   func_021F8054 0x021F8054 thumb ov112
 *   func_02030734 0x02030734 arm
 *   func_0207CA00 0x0207CA00 arm
 *   func_021FADA0 0x021FADA0 thumb ov132
 *   func_021FB528 0x021FB528 thumb ov132
 *   d_021FDD00 0x021FDD00 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {int x,y,z;} Vec;
extern u32 func_0201134C(void *);
extern int func_021FB1F4(char *,int);
extern void *func_021F9DA0(char *p);
extern void *func_021F9DA4(char *p, u32 i);
extern void func_021F8044(void *,void *,Vec *);
extern void func_021F8054(void *,void *,const Vec *);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void func_0207CA00(void *,void *,void *);
extern void *func_021FADA0(char *,u32,u32,u32);
extern void func_021FB528(int,char *);
extern const char d_021FDD00[];
int func_021FB2B0(int unused,char *p)
{
    int mask;
    char *owner,*q,*target;
    Vec pos;
    int delta[3];
    u32 wait,z,y,x,rate;
    char *ctx;
    u8 i;
    owner=*(char **)p;
    mask=func_021FB1F4(p,func_0201134C(*(void **)(p+4)));
    rate=func_0201134C(*(void **)(p+4));
    x=func_0201134C(*(void **)(p+4));
    y=func_0201134C(*(void **)(p+4));
    z=func_0201134C(*(void **)(p+4));
    wait=func_0201134C(*(void **)(p+4));
    ctx=func_021F9DA0(*(void **)(owner+52));
    for(i=0;i<4;i++) {
        if(mask&(1<<i)) {
            target=func_021F9DA4(*(void **)(owner+52),i);
            if (rate==0) {
                pos.x=x;pos.y=y;pos.z=z;
                func_021F8054(ctx,target,&pos);
            } else {
                q=func_02030734(*(u16 *)owner,56,0,d_021FDD00,0x2DA);
                *(char **)(q+48)=owner;
                *(char **)q=target;
                *(void **)(q+4)=*(void **)(owner+52);
                *(u16 *)(q+46)=0;
                func_021F8044(ctx,target,(Vec *)(q+8));
                *(u32 *)(q+20)=x;*(u32 *)(q+24)=y;*(u32 *)(q+28)=z;
                *(u16 *)(q+44)=rate;
                func_0207CA00(q+20,q+8,delta);
                *(int *)(q+32)=delta[0]/(int)rate;
                *(int *)(q+36)=delta[1]/(int)rate;
                *(int *)(q+40)=delta[2]/(int)rate;
                *(void **)(q+52)=func_021FADA0(owner,(u32)func_021FB528,(u32)q,10);
            }
        }
    }
    if(wait==1) {*(u16 *)(p+20)=rate;return 1;}
    return 0;
}
