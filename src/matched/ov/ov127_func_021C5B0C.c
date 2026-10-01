/*
 * function: func_021C5B0C
 * address: 0x021C5B0C
 * packet: pkt_ov127_021C5B0C
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021C5B98 0x021C5B98 thumb ov127
 *   func_02041B6C 0x02041B6C arm
 *   func_02041EE4 0x02041EE4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
extern void func_021C5B98(void *,int,void *,s16,s16);
extern void func_02041B6C(u8);
extern void func_02041EE4(u8,int,int);
void func_021C5B0C(char *p,int x,int y)
{
    s16 tx,ty,rx,ry;
    tx=x/8; ty=y/8; rx=x%8; ry=y%8;
    if(tx!=*(u16 *)(p+24)||ty!=*(u16 *)(p+26)) {
        *(u16 *)(p+26)=ty; *(u16 *)(p+24)=tx;
        func_021C5B98(*(void **)(p+4),*(int *)(p+20),*(void **)(p+12),-tx,-ty);
        func_02041B6C(*(int *)(p+20));
    }
    func_02041EE4(*(int *)(p+20),0,rx);
    func_02041EE4(*(int *)(p+20),3,ry);
}
