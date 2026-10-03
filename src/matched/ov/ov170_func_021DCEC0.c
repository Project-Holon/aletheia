/*
 * function: func_021DCEC0
 * address: 0x021DCEC0
 * packet: pkt_ov170_021DCEC0
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_02027F60 0x02027F60 thumb
 */
typedef unsigned int   u32;
struct MsgBank;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_02027F60(unsigned,unsigned,void *,void *,unsigned short);
#define WORK(p) (*(char **)((p)+0x2c))
#define PTR(p,n) (*(void **)(WORK(p)+(n)))
#define HALF(p,n) (*(unsigned short *)(WORK(p)+(n)))
void func_021DCEC0(char *p)
{
    PTR(p,0x184)=func_02045EC0(PTR(p,0x80),0x6e);
    HALF(p,0x188)=0x39e3;
    PTR(p,0x18c)=0;
    PTR(p,0x190)=func_02045EC0(PTR(p,0x80),0x6f);
    HALF(p,0x194)=0x39e3;
    PTR(p,0x198)=0;
    PTR(p,0x19c)=func_02027F60(0,8,PTR(p,0x78),PTR(p,0x8c),0x4c);
}
