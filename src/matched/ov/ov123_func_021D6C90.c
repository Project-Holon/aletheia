/*
 * function: func_021D6C90
 * address: 0x021D6C90
 * packet: pkt_ov123_021D6C90
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes zero alignment padding follow the return.
 * symbols:
 *   func_0204B7C8 0x0204B7C8 arm
 *   func_02082D44 0x02082D44 arm
 *   func_020862F0 0x020862F0 arm
 *   func_0207E51C 0x0207E51C arm
 */
typedef unsigned int u32;
typedef struct { u32 x[9]; } Desc;
struct Struct36;
extern void func_0204B7C8(const char *src, struct Struct36 *dst);
extern void func_02082D44(void *,void *,int);
extern void func_020862F0(void *,int);
extern void func_0207E51C(void *,int,int);
void func_021D6C90(char *p,int i,void *h)
{
    Desc d;
    func_0204B7C8(h,(struct Struct36 *)(&d));
    func_02082D44(p+0xdc+i*0x224,(void *)(d.x[1]+0x6400000),0x200);
    func_020862F0(p+0xbc+i*0x224,0x20);
    func_0207E51C(p+0xbc+i*0x224,0x100,0x20);
}
