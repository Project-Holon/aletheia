/*
 * function: func_021FC0AC
 * address: 0x021FC0AC
 * packet: pkt_ov132_021FC0AC
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021F9DC4 0x021F9DC4 thumb ov132
 *   func_02030734 0x02030734 arm
 *   func_021FADA0 0x021FADA0 thumb ov132
 *   func_021FC178 0x021FC178 thumb ov132
 *   d_021FDD00 0x021FDD00 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_0201134C(void *);
extern void *func_021F9DC4(void *,u8);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void *func_021FADA0(char *,u32,u32,u32);
extern void func_021FC178(int,char *);
extern const char d_021FDD00[];
int func_021FC0AC(int unused,char *p)
{
    char *owner,*q;
    void *target;
    u32 j,i,h,g,f,e,d,c,b,a;
    owner=*(char **)p;
    a=func_0201134C(*(void **)(p+4));
    b=func_0201134C(*(void **)(p+4));
    c=func_0201134C(*(void **)(p+4));
    d=func_0201134C(*(void **)(p+4));
    e=func_0201134C(*(void **)(p+4));
    f=func_0201134C(*(void **)(p+4));
    g=func_0201134C(*(void **)(p+4));
    h=func_0201134C(*(void **)(p+4));
    i=func_0201134C(*(void **)(p+4));
    j=func_0201134C(*(void **)(p+4));
    target=func_021F9DC4(*(void **)(owner+52),a);
    q=func_02030734(*(u16 *)owner,56,0,d_021FDD00,0x691);
    *(char **)(q+48)=owner;
    *(void **)(q+16)=target;
    *(u16 *)(q+44)=b;
    *(u32 *)(q+20)=e;
    *(u32 *)(q+24)=f;
    *(u32 *)(q+28)=g;
    *(u32 *)(q+32)=h-e;
    *(u32 *)(q+36)=i-f;
    *(u32 *)(q+40)=j-g;
    *(void **)q=*(void **)(owner+52);
    *(u32 *)(q+4)=0;
    *(u32 *)(q+8)=c;
    *(u32 *)(q+12)=d;
    *(void **)(q+52)=func_021FADA0(owner,(u32)func_021FC178,(u32)q,10);
    return 0;
}
