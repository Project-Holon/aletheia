/*
 * function: func_021D7DC8
 * address: 0x021D7DC8
 * packet: pkt_ov120_021D7DC8
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * follower: existing 021D7E88, 021D7E9C, 021D7EB0 files remain separate.
 * symbols:
 *   func_021D7C1C 0x021D7C1C thumb ov120
 *   func_021D7CD4 0x021D7CD4 thumb ov120
 *   func_021D7D30 0x021D7D30 thumb ov120
 *   func_021D7710 0x021D7710 thumb ov120
 *   func_02051B84 0x02051B84 arm
 *   d_021D8BD8 0x021D8BD8 data a2
 *   d_021D8BE0 0x021D8BE0 data a2
 *   d_021D8B04 0x021D8B04 data a4
 */
typedef unsigned short u16;
extern const u16 d_021D8BD8[],d_021D8BE0[];
extern const int d_021D8B04[];
extern void func_021D7C1C(char *);
typedef unsigned int   u32;
extern void func_0201DD78(u32 r, u32 g, u32 b);
extern int func_021D7CD4(char *,int,int,int);
extern void func_021D7D30(char *);
extern void func_021D7710(char *);
typedef unsigned char  u8;
extern void *func_02051B84(u8 *a0, int a1, int a2, int a3);
void func_021D7DC8(char *p,int a,int b,int c,int d,int e)
{
    func_021D7C1C(p);
    func_0201DD78(15,2,0);
    func_021D7CD4(p,2,0,0);
    func_0201DD78(15,2,0);
    func_021D7CD4(p,3,3,6);
    func_021D7CD4(p,23,1,11);
    func_021D7CD4(p,24,1,16);
    func_0201DD78(1,2,0);
    *(int *)(p+0x24)=func_021D7CD4(p,d_021D8BD8[c],13,6);
    *(int *)(p+0x28)=func_021D7CD4(p,d_021D8BE0[d],16,11);
    *(int *)(p+0x2c)=func_021D7CD4(p,d_021D8BE0[e],16,16);
    func_021D7D30(p);
    func_021D7710(p);
    *(void **)(p+8)=func_02051B84((u8 *)d_021D8B04,a,b,*(u16 *)(p+0xc8));
}
