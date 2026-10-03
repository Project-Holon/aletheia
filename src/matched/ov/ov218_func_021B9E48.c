/*
 * function: func_021B9E48
 * address: 0x021B9E48
 * packet: pkt_ov218_021B9E48
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototype: 0203159C leaves allocator r0 live through final store/pop; original consumes that return despite legacy void source.
 * symbols:
 *   ov067_id 0x43 data
 *   func_02034AC4 0x02034AC4 arm
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   tbl_021BAC80 0x021BAC80 data ov218 a4
 *   func_021BA780 0x021BA780 thumb ov218
 *   func_0207D534 0x0207D534 arm
 *   func_021BA848 0x021BA848 thumb ov218
 *   d_021BAB20 0x021BAB20 data a4
 *   func_021B6100 0x021B6100 thumb ov067
 *   func_021B96CC 0x021B96CC thumb ov218
 *   func_021B9964 0x021B9964 thumb ov218
 *   func_021BA960 0x021BA960 thumb ov218
 *   func_021B9820 0x021B9820 thumb ov218
 *   func_021B9C80 0x021B9C80 thumb ov218
 *   func_021B9C84 0x021B9C84 thumb ov218
 *   func_02027F60 0x02027F60 thumb
 *   func_021BA290 0x021BA290 thumb ov218
 *   func_021B9D48 0x021B9D48 thumb ov218
 *   func_021BA328 0x021BA328 thumb ov218
 *   func_021BA61C 0x021BA61C thumb ov218
 *   func_0207D63C 0x0207D63C arm
 *   func_021BA238 0x021BA238 thumb ov218
 *   func_02005624 0x02005624 thumb
 *   func_0203D34C 0x0203D34C arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern int tbl_021BAC80[];
extern char ov067_id[];
extern char d_021BAB20[];
extern int func_02034AC4(int);
extern void func_0203064C(u32,u32,u32);
extern char *func_0203159C(void *,u32,u32);
extern void func_02082BCC(void *,u32,u32);
extern u32 func_021BA780(int);
extern void func_0207D534(u16 *,int);
extern void *func_021BA848(u32,u32);
extern void *func_021B6100(u32,void *,u8,u16,void *);
extern void func_021B96CC(void *,u32);
extern void *func_021B9964(u16);
extern int func_021BA960(void *);
extern void *func_021B9820(int,int);
extern u32 func_021B9C80(void *),func_021B9C84(void *);
extern void *func_02027F60(u16,u16,u32,u32,u16);
extern void func_021BA290(char *),func_021B9D48(char *),func_021BA328(char *),func_021BA61C(char *);
extern void func_0207D63C(u32 *,u32,u32,u32,u32);
extern void func_021BA238(void);
extern void *func_02005624(u32,void *,u32);
extern void func_0203D34C(u32,u32);
char *func_021B9E48(void *owner,char *input)
{
    char *p;
    int i,value;
    u32 a,b;
    func_02034AC4((int)ov067_id);
    func_0203064C(1,122,0x30000);
    p=func_0203159C(owner,0x330,122);
    func_02082BCC(p,0,0x330);
    *(u16 *)p=122;
    *(char **)(p+0x20)=input;
    for(i=0;i<130;i++) {
        if(*(u8 *)(input+0x2f+tbl_021BAC80[i]))*(u32 *)(p+0x34+i*4)=1;
        else *(u32 *)(p+0x34+i*4)=0;
    }
    for(i=0;i<20;i++) {
        value=*(u16 *)(input+8+i*2);
        if(value!=0)value=func_021BA780(value);
        else value=65535;
        *(int *)(p+0x2dc+i*4)=value;
    }
    func_0207D534((u16 *)0x0400006c,-16);
    func_0207D534((u16 *)0x0400106c,-16);
    *(void **)(p+4)=func_021BA848(0,*(u16 *)p);
    *(void **)(p+0x24)=func_021B6100(*(u16 *)p,d_021BAB20,3,0,p);
    func_021B96CC(p,*(u16 *)p);
    *(void **)(p+0x28)=func_021B9964(*(u16 *)p);
    *(void **)(p+8)=func_021B9820(func_021BA960(*(void **)(p+4)),*(u16 *)p);
    a=func_021B9C80(*(void **)(p+0x28));
    b=func_021B9C84(*(void **)(p+0x28));
    *(void **)(p+0x18)=func_02027F60(1,11,a,b,*(u16 *)p);
    func_021BA290(p);
    func_021B9D48(p);
    func_021BA328(p);
    func_021BA61C(p);
    func_0207D63C((u32 *)0x04001050,4,8,6,10);
    *(void **)(p+0x23c)=func_02005624((u32)func_021BA238,p,0);
    func_0203D34C(1,*(u16 *)p);
    return p;
}
