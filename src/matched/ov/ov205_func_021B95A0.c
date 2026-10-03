/*
 * function: func_021B95A0
 * address: 0x021B95A0
 * packet: pkt_ov205_021B95A0
 * region: ov205
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082A7C 0x02082A7C arm
 *   func_020120F4 0x020120F4 thumb
 *   func_02012944 0x02012944 thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_020071F0 0x020071F0 thumb
 */
typedef unsigned short u16;
extern void func_0203064C(void *,unsigned,unsigned);
extern char *func_0203159C(void *,unsigned,unsigned);
extern void func_02082A7C(unsigned,void *,unsigned);
typedef unsigned char  u8;
struct Big;
struct Ctx;
struct Sub020071E4Ctrl;
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012944(void *p);
extern void *func_02012EBC(struct Big *p);
extern int func_020071F0(struct Sub020071E4Ctrl *ctrl);
int func_021B95A0(void *owner,int unused,void **args)
{
    void *context;
    char *p;
    context=*args;
    func_0203064C((void *)1,84,1<<18);
    p=func_0203159C(owner,76,84);
    func_02082A7C(0,p,76);
    *(u16 *)p=84;
    *(u16 *)(p+2)=36;
    *(void **)(p+4)=func_020120F4(context);
    *(void **)(p+8)=func_02012944(*(void **)(p+4));
    if(func_020071F0(func_02012EBC(*(void **)(p+4)))!=0)
        *(int *)(p+64)=1;
    return 1;
}
