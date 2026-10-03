/*
 * function: func_021B99A0
 * address: 0x021B99A0
 * packet: pkt_ov223_021B99A0
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: record index initialized before the accessor and stored into each slot.
 * symbols:
 *   setup 0x021BC7BC data a4
 *   positions 0x021BC7CC data a4
 *   func_02047E88 0x02047E88 arm
 *   func_021B95B0 0x021B95B0 thumb ov223
 *   func_020489F4 0x020489F4 arm
 *   func_02048A18 0x02048A18 arm
 *   func_0204779C 0x0204779C arm
 *   func_020477A4 0x020477A4 arm
 *   func_02011510 0x02011510 thumb
 *   func_021BC52C 0x021BC52C thumb ov223
 *   func_02011B8C 0x02011B8C thumb
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct {int x,y,z;} Vec;
struct Record{u16 id,pad;Vec translation,scale;u32 matrix[9],flag;};
struct Util;struct Setup;struct G3dSys;
extern const struct Setup setup;
extern const Vec positions[];
extern u16 func_02047E88(struct Util *,const struct Setup *);
extern struct Record *func_021B95B0(u32,u32);
extern u32 func_020489F4(u8 *,int);
extern int *func_02048A18(u8 *,int);
extern int func_0204779C(int *);
extern u32 func_020477A4(struct G3dSys *,u32);
extern void *func_02011510(u32,u32,u32,u32);
extern void *func_021BC52C(void *);
extern void func_02011B8C(void *,void *);
void func_021B99A0(char *p)
{
    u16 i,n,j;
    u32 base,count;
    int *obj;
    struct Record *r;
    *(u16 *)(p+46)=func_02047E88(*(struct Util **)(p+40),&setup);
    *(u16 *)(p+58)=4;
    *(struct Record **)(p+60)=func_021B95B0(*(u16 *)p,*(u16 *)(p+58));
    n=0;
    base=func_020489F4(*(u8 **)(p+40),*(u16 *)(p+46));
    for(i=0;i<4;i++) {
        *(u16 *)(p+i*2+50)=n;
        r=*(struct Record **)(p+60)+n;
        r->id=base+i;
        r->flag=1;
        if(i+1>=2&&i+1<=4)r->translation=*(positions+i-1);
        n++;
    }
    obj=func_02048A18(*(u8 **)(p+40),*(u16 *)(*(char **)(p+60)+*(u16 *)(p+50)*68));
    count=func_0204779C(obj);
    for(j=0;j<count;j++)func_020477A4((struct G3dSys *)obj,j);
    *(void **)(p+64)=func_02011510(*(u16 *)p,205,36,10);
    func_02011B8C(func_021BC52C(*(void **)(p+20)),*(void **)(p+64));
    *(u32 *)(p+80)=0;
}
