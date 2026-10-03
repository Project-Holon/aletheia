/*
 * function: func_021BDBC4
 * address: 0x021BDBC4
 * packet: pkt_ov172_021BDBC4
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Extent remainder: zero alignment halfword at 021BDC6E.
 * symbols:
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201C450 0x0201C450 thumb
 *   func_02049B40 0x02049B40 arm
 *   func_0201DD68 0x0201DD68 thumb
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_0203101C 0x0203101C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_0201D7EC(int,int,int,int,int);
extern u32 func_02045B38(int,int,int,int);
extern u32 func_0201C450(int,int);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0201DD68(void);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern u32 func_0203101C(int,int,int,int);
void func_021BDBC4(u8 *p)
{
    *(u32 *)(p+0x1c8)=func_0201D7EC(23,0,0,0,*(u16 *)p);
    *(u32 *)(p+0x1cc)=func_02045B38(0,2,27,*(u16 *)p);
    *(u32 *)(p+0x1d0)=func_0201C450(0x800,*(u16 *)p);
    func_02049B40(23,5,0,0x140,32,*(u16 *)p);
    func_02049B40(23,5,4,0x140,32,*(u16 *)p);
    func_0201DD68();
    func_0201F5BC(4,0x140,9,0,*(u16 *)p);
    func_0201F5BC(0,0x200,9,0,*(u16 *)p);
    *(u32 *)(p+0x1d8)=func_0203101C(*(u16 *)p,*(u16 *)p,1,0);
    *(u32 *)(p+0x1dc)=0;
}
