/*
 * function: func_021FE2BC
 * address: 0x021FE2BC
 * packet: pkt_ov186_021FE2BC
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * lever: A named x load before the last halfword store preserves the interleaved copy.
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_021FE2F8 0x021FE2F8 thumb ov186
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Pair{int x,y;} Pair;
extern void func_02082BCC(void *,int,int);
extern int func_021FE2F8(char *,int *,int);
void func_021FE2BC(u8 *p,const Pair *origin,u16 a,u16 b,u16 c,u16 d,int duration)
{
    int x;
    func_02082BCC(p,0,28);
    *(u16 *)(p+16)=a;
    *(u16 *)(p+18)=b;
    *(u16 *)(p+20)=c;
    x=origin->x;
    *(u16 *)(p+22)=d;
    *(int *)p=x;
    *(int *)(p+24)=duration;
    *(int *)(p+4)=origin->y;
    func_021FE2F8((char *)p,(int *)(p+8),0);
}
