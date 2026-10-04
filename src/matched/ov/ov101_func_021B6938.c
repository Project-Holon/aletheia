/*
 * function: func_021B6938
 * address: 0x021B6938
 * packet: pkt_ov101_021B6938
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02030734 0x02030734 arm
 *   func_021B6BE4 0x021B6BE4 thumb ov101
 *   func_020120F4 0x020120F4 thumb
 *   func_021B6100 0x021B6100 thumb ov101
 *   func_021B6A3C 0x021B6A3C thumb ov101
 *   func_021B6A4C 0x021B6A4C thumb ov101
 *   func_02005DE4 0x02005DE4 thumb
 *   func_02005E64 0x02005E64 thumb
 *   d_021B753C 0x021B753C data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0203064C(u32,u32,u32);
extern u8 *func_0203159C(int,int,int);
extern void func_02082BCC(void *,int,u32);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void func_021B6BE4(u8 *,int);
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_021B6100(int,int,int,int);
extern void func_021B6A3C(u8 *,u32);
extern void func_021B6A4C(u8 *p, u16 *state);
extern void func_02005DE4(void *p);
extern void func_02005E64(void);
extern const char d_021B753C[];
int func_021B6938(int a,int b,int c)
{
    u8 *p;
    int handle;
    func_0203064C(1,58,0x8000);
    p=func_0203159C(a,64,58);
    func_02082BCC(p,0,64);
    handle=0;
    *(int *)(p+0x10)=c;
    *(void **)(p+0x3c)=func_02030734(58,44,0,d_021B753C,0x119);
    func_02082BCC(*(void **)(p+0x3c),0,44);
    func_021B6BE4(p+4,58);
    if(*(int *)*(int *)(p+0x10)) handle=(int)func_020120F4((const struct Ctx *)(*(int *)*(int *)(p+0x10)));
    *(void **)p=func_021B6100(-1,handle,58,0);
    *(int *)(p+0x34)=1;
    func_021B6A3C(p,(u32)func_021B6A4C);
    func_02005DE4((void *)1);
    func_02005E64();
    return 1;
}
