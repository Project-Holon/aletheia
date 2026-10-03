/*
 * function: func_021E2578
 * address: 0x021E2578
 * packet: pkt_ov183_021E2578
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F9B9C 0x021F9B9C thumb ov186
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02025538 0x02025538 thumb
 *   func_021FD6D8 0x021FD6D8 thumb ov186
 *   func_021E26B8 0x021E26B8 thumb ov183
 *   func_0201C440 0x0201C440 thumb
 *   func_021FD760 0x021FD760 thumb ov186
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern unsigned func_021F9B9C(char *p);
extern char *func_0203159C(void *,u32,u32);
extern void func_02082BCC(void *,int,unsigned);
extern void *func_02025538(unsigned int a0, void *a1);
extern void *func_021FD6D8(char *,void *,u32);
extern void func_021E26B8(void);
extern u32 func_0201C440(void *);
extern void *func_021FD760(void *,int,int,u16);
int func_021E2578(void *obj,int b,char *q)
{
    char *p;
    int i;
    p=func_0203159C(obj,0x54,func_021F9B9C(*(void **)(q+0x10)));
    func_02082BCC(p,0,0x54);
    *(char **)(p+0x3c)=q;
    *(u16 *)(p+0x38)=func_021F9B9C(*(void **)(q+0x10));
    *(void **)p=func_02025538(*(u16 *)(p+0x38),*(void **)(q+4));
    *(void **)(p+0xc)=func_021FD6D8(p,func_021E26B8,*(u16 *)(p+0x38));
    *(u32 *)(p+4)=func_0201C440((void *)(unsigned int)*(u16 *)(p+0x38));
    for (i=0;i<2;i++) *(void **)(p+i*4+0x30)=func_021FD760(*(void **)(q+4),*(int *)(q+8),i,*(u16 *)(p+0x38));
    return 1;
}
