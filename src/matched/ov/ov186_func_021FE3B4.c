/*
 * function: func_021FE3B4
 * address: 0x021FE3B4
 * packet: pkt_ov186_021FE3B4
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * lever: The two-word origin copy is a Pair assignment; separate field stores reorder it.
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_021FE3E4 0x021FE3E4 thumb ov186
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Pair{int x,y;} Pair;
extern void func_02082BCC(void *,int,int);
extern int func_021FE3E4(void *,Pair *,int);
void func_021FE3B4(u8 *p,const Pair *origin,u16 a,u16 b,int duration)
{
    func_02082BCC(p,0,24);
    *(Pair *)p=*origin;
    *(int *)(p+20)=duration;
    *(u16 *)(p+16)=a;
    *(u16 *)(p+18)=b;
    func_021FE3E4(p,0,0);
}
