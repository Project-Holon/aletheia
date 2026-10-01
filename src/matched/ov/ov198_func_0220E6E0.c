/*
 * function: func_0220E6E0
 * address: 0x0220E6E0
 * packet: pkt_ov198_0220E6E0
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B100 0x0204B100 arm
 *   func_0220E684 0x0220E684 thumb ov198
 *   func_0203D34C 0x0203D34C arm
 *   func_020216D4 0x020216D4 thumb
 *   func_0220E7E4 0x0220E7E4 thumb ov198
 *   d_02211DFC 0x02211DFC data a4
 */
typedef unsigned short u16;
extern unsigned func_0204B100(unsigned,unsigned,u16);
extern unsigned func_0220E684(char *,const int *);
extern void func_0203D34C(unsigned,u16);
extern void func_020216D4(unsigned,int,int,int);
extern void func_0220E7E4(void *);
extern const int d_02211DFC[][5];
void func_0220E6E0(char *p)
{
    unsigned i;
    *(unsigned *)(p+0x1eb8)=func_0204B100(45,0,(*(u16 *)(*(char **)p+0x10)&0x7fff)|0x8000);
    for(i=0;i<41;i++) *(unsigned *)(p+i*4+0x1ebc)=func_0220E684(p,d_02211DFC[i]);
    func_0203D34C(0,*(u16 *)(*(char **)p+0x10));
    func_020216D4(*(unsigned *)(p+0x1d8),3,0,0x1e0);
    func_0220E7E4(p);
}
