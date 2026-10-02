/*
 * function: func_021D9F24
 * address: 0x021D9F24
 * packet: pkt_ov121_021D9F24
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: duplicate the case 2/0 drawing bodies; cross-jumping retains the case 2 branch.
 * interface: 02028590 forwards the allocation result of 020285A4 in r0;
 *            this caller stores that result at +0x30 despite the old void definition.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_021DA010 0x021DA010 thumb ov121
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02045770(void *);
extern void func_02043B5C(void *,u8);
extern void func_0201CE48(void *);
extern void func_02028604(void *);
extern void func_021DA010(u8 *);
extern u32 func_020056BC(void);
extern void *func_0202EE30(u32,void *,u8,u8,u16);
extern void func_0201C6FC(u32,void *,u32,u32,void *,u32);
extern void func_02028470(void *,u32);
extern void *func_02028590(u32,u32,u32,u32);
extern signed char func_02012FFC(void);
extern void *func_0201CCE4(void *,u32,u32,u32,u32,int,void *,u32,u16,u16);
void func_021D9F24(u8 *p,int mode)
{
    u32 q;
    func_02043B5C(func_02045770(*(void **)(p+0x10)),*(u16 *)(p+0x18));
    if(*(void **)(p+8)) {
        func_0201CE48(*(void **)(p+8));
        *(void **)(p+8)=0;
    }
    if(*(void **)(p+0x30)) {
        func_02028604(*(void **)(p+0x30));
        *(void **)(p+0x30)=0;
    }
    func_021DA010(p);
    switch(mode) {
    case 2:
        *(void **)(p+0x3c)=func_0202EE30(func_020056BC(),*(void **)(p+0x10),*(u16 *)(p+0x18),16,*(u16 *)(p+0x1a));
        q=*(u32 *)(p+0x24);
        func_0201C6FC(q,func_02045770(*(void **)(p+0x1c)),0,0,*(void **)(p+0x14),*(u32 *)(p+4));
        p[0x20]=1;
        *(u32 *)(p+0x28)=0;
        break;
    case 0:
        q=*(u32 *)(p+0x24);
        func_0201C6FC(q,func_02045770(*(void **)(p+0x1c)),0,0,*(void **)(p+0x14),*(u32 *)(p+4));
        p[0x20]=1;
        *(u32 *)(p+0x28)=0;
        break;
    case 1:
        func_02028470(p+0x34,2);
        *(void **)(p+0x30)=func_02028590(*(u16 *)(p+0x18),1,0,*(u16 *)(p+0x1a));
        *(void **)(p+8)=func_0201CCE4(*(void **)(p+0x10),0,0,*(u32 *)(p+0x14),*(u32 *)(p+4),func_02012FFC(),*(void **)(p+0xc),0,*(u16 *)(p+0x1a),*(u16 *)(p+0x18));
        *(u32 *)(p+0x28)=1;
        break;
    }
    *(u32 *)(p+0x2c)=0;
}
