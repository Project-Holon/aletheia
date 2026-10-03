/*
 * function: func_021C758C
 * address: 0x021C758C
 * packet: pkt_ov136_021C758C
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * func_021C73C8 0x021C73C8 thumb ov136
 * func_021C7420 0x021C7420 thumb ov136
 * func_021C5BE0 0x021C5BE0 thumb ov136
 * func_021C5B40 0x021C5B40 thumb ov136
 * func_021C66B8 0x021C66B8 thumb ov136
 * func_021C5C00 0x021C5C00 thumb ov136
 * func_021C630C 0x021C630C thumb ov136
 * func_021C71A8 0x021C71A8 thumb ov136
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct WinMgr;
extern void func_021C73C8(void *),func_021C7420(void *),func_021C5BE0(void *),func_021C5B40(void *),func_021C5C00(void *);
extern void func_021C66B8(void *,int,int);
extern void func_0202CC70(struct WinMgr *mgr, u32 idx);
extern void func_021C630C(void *,int);
extern int func_021C71A8(void *,int,int);
void func_021C758C(u8 *p)
{
    u16 n;
    func_021C73C8(p); func_021C7420(p); func_021C5BE0(p); func_021C5B40(p);
    if(*(u16 *)(*(u8 **)(p+8)+0x2fc)<=10) {
        func_021C66B8(*(void **)(p+8),0,0);
        func_021C66B8(*(void **)(p+8),1,0);
    }
    n=*(u16 *)(*(u8 **)(p+8)+0x2fe);
    if(*(u16 *)(p+28)>n) { *(u16 *)(p+28)=n; p[30]=0; }
    func_021C5C00(p);
    func_0202CC70(**(void ***)(p+8),10);
    func_021C630C(p,1);
    func_021C71A8(p,1,18);
}
