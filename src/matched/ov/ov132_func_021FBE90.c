/*
 * function: func_021FBE90
 * address: 0x021FBE90
 * packet: pkt_ov132_021FBE90
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021F9DAC 0x021F9DAC thumb ov132
 *   func_021F9DB0 0x021F9DB0 thumb ov132
 *   func_021F6B9C 0x021F6B9C thumb ov112
 *   func_021F6BB0 0x021F6BB0 thumb ov112
 *   func_02030734 0x02030734 arm
 *   func_0207CA00 0x0207CA00 arm
 *   func_021FADA0 0x021FADA0 thumb ov132
 *   func_021FBF74 0x021FBF74 thumb ov132
 *   d_021FDD00 0x021FDD00 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_0201134C(void *);
extern void *func_021F9DAC(void *);
extern u32 *func_021F9DB0(void *,u8);
extern void func_021F6B9C(void *,u32 *,u32 *);
extern void func_021F6BB0(void *,u32 *,u32 *);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void func_0207CA00(void *,void *,void *);
extern void *func_021FADA0(char *,u32,u32,u32);
extern void func_021FBF74(int,char *);
extern const char d_021FDD00[];
int func_021FBE90(int unused,char *p)
{
    char *owner,*q;
    u32 pos[3];
    int delta[3];
    u32 e,d,c,b,a;
    u32 *target;
    void *ctx;
    owner=*(char **)p;
    a=func_0201134C(*(void **)(p+4));
    b=func_0201134C(*(void **)(p+4));
    c=func_0201134C(*(void **)(p+4));
    d=func_0201134C(*(void **)(p+4));
    e=func_0201134C(*(void **)(p+4));
    ctx=func_021F9DAC(*(void **)(owner+52));
    target=func_021F9DB0(*(void **)(owner+52),a);
    if (b==0) {
        pos[0]=c;pos[1]=d;pos[2]=e;
        func_021F6B9C(ctx,target,pos);
    } else {
        q=func_02030734(*(u16 *)owner,56,0,d_021FDD00,0x601);
        *(char **)(q+48)=owner;
        *(u32 **)q=target;
        *(void **)(q+4)=*(void **)(owner+52);
        *(u16 *)(q+46)=0;
        func_021F6BB0(ctx,target,(u32 *)(q+8));
        *(u32 *)(q+20)=c;*(u32 *)(q+24)=d;*(u32 *)(q+28)=e;
        *(u16 *)(q+44)=b;
        func_0207CA00(q+20,q+8,delta);
        *(int *)(q+32)=delta[0]/(int)b;
        *(int *)(q+36)=delta[1]/(int)b;
        *(int *)(q+40)=delta[2]/(int)b;
        *(void **)(q+52)=func_021FADA0(owner,(u32)func_021FBF74,(u32)q,10);
    }
    return 0;
}
