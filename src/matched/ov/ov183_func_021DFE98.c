/*
 * function: func_021DFE98
 * address: 0x021DFE98
 * packet: pkt_ov183_021DFE98
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: A const record array indexed at zero, rather than a scalar record, keeps the final halfword load in place (224 B DIFF to EXACT).
 * abi: F878 fifth heap word retained because the caller writes it to sp before bl.
 * symbols:
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_0201F81C 0x0201F81C thumb
 *   func_0201F878 0x0201F878 thumb
 *   func_021FC8C8 0x021FC8C8 thumb ov186
 *   func_02082BCC 0x02082BCC arm
 *   func_021FC124 0x021FC124 thumb ov186
 *   func_021FB378 0x021FB378 thumb ov186
 *   d_021E3758 0x021E3758 data a4
 *   d_021E3728 0x021E3728 data a4
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct {u32 words[10];} Config;
typedef struct {int a,b,c;} Triple;
typedef struct {u16 a,b,c;u8 flag,pad;} Params;
typedef struct {u8 a,b,c,d;u16 file,pad;} Record;
typedef struct Slot Slot;
extern const Config d_021E3758;
extern const Record d_021E3728[];
extern unsigned func_021FC20C(char *p);
extern int func_021FC214(char *);
extern void func_021FB964(int,int,u16);
extern Slot *func_0201F81C(u32,u32);
extern void func_0201F878(Slot *,u32,u32,u32,u32);
extern void *func_021FC8C8(Config *,u32);
extern void func_02082BCC(void *,u32,u32);
extern int func_021FC124(int,int,Triple *);
extern void *func_021FB378(void *,int,int,int,int,int,int,int,void *,u16);
int func_021DFE98(char *p,char *q)
{
    int first,second,i;
    Config cfg;
    Triple triple;
    Params params;
    first=func_021FC20C(*(char **)(q+8));
    second=func_021FC214(*(char **)(q+8));
    func_021FB964(*(int *)(q+8),27,*(u16 *)(p+0x54));
    *(Slot **)(p+0x14)=func_0201F81C(19,*(u16 *)(p+0x54));
    for(i=0;i<19;i++)func_0201F878((Slot *)((u32)*(Slot **)(p+0x14)+i*8),second,i+205,i,*(u16 *)(p+0x54));
    cfg=d_021E3758;
    cfg.words[0]=*(u32 *)(p+0x14);cfg.words[1]=19;
    cfg.words[5]=*(u32 *)(q+8);cfg.words[6]=*(u32 *)(q+4);
    *(void **)(p+0x18)=func_021FC8C8(&cfg,*(u16 *)(p+0x54));
    func_02082BCC(&params,0,8);
    func_021FC124(*(int *)(q+8),6,&triple);
    params.a=d_021E3728[0].a;params.b=d_021E3728[0].b;params.c=d_021E3728[0].c;params.flag=1;
    *(void **)(p+0xc)=func_021FB378(&params,d_021E3728[0].file,96,1,*(int *)(q+4),*(int *)(p+0x44),first,second,&triple,*(u16 *)(p+0x54));
    return 1;
}
