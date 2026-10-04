/*
 * function: func_021849A4
 * address: 0x021849A4
 * packet: pkt_ov219_021849A4
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: explicit original heap shift pairs require narrow extern parameters for D7EC/40B94 despite their full-width own declarations;84968 returns descriptor pointer.
 * symbols:
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201DE00 0x0201DE00 thumb
 *   func_0201DD78 0x0201DD78 thumb
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414EC 0x020414EC arm
 *   func_02049658 0x02049658 arm
 *   func_02049B68 0x02049B68 arm
 *   func_020498F4 0x020498F4 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_02049B40 0x02049B40 arm
 *   func_02040B94 0x02040B94 arm
 *   func_02040EBC 0x02040EBC arm
 *   func_02184968 0x02184968 thumb ov219
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045334 0x02045334 arm
 *   func_0204044C 0x0204044C arm
 *   func_02184BAC 0x02184BAC thumb ov219
 *   d_02185E58 0x02185E58 data a4
 *   d_02185E78 0x02185E78 data a4
 *   d_02185DBD 0x02185DBD data a1
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct BgTemplate;
extern const struct BgTemplate d_02185E58,d_02185E78;
extern const u8 d_02185DBD[];
extern void *func_0201D7EC(int,int,int,int,u16);
extern void func_0201DE00(u8 *,u8 *,u8 *),func_0201DD78(u32,u32,u32);
extern void func_0203FCA0(u32,const struct BgTemplate *,u32),func_020414EC(u32);
extern void func_02049658(void *,u32,u32,u32,u32,u32,u16);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern void func_020498F4(void *,u32,u32,u32,u32,u32,u16);
extern void func_0201F5BC(u32,u32,u32,u32,u16);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern void func_02040B94(u32,u32,u32,u16),func_02040EBC(u32,u32);
extern u32 func_02184968(const u8 *p, int flag);
struct Descriptor;
extern void func_0201F73C(void *,int,int,int),func_02045334(struct Descriptor *),func_0204044C(u32),func_02184BAC(char *);
void func_021849A4(char *p,void *arc)
{
    *(void **)(p+0xc06c)=func_0201D7EC(0x17,0,0,0,*(u32 *)p);
    func_0201DE00((u8 *)p+0xc084,(u8 *)p+0xc085,(u8 *)p+0xc086);
    func_0201DD78(1,2,0xf);
    func_0203FCA0(6,&d_02185E58,0);
    func_020414EC(6);
    func_0203FCA0(7,&d_02185E78,0);
    func_02049658(arc,5,7,0,0,0,*(u32 *)p);
    func_02049B68(arc,6,4,0,0x80,*(u32 *)p);
    func_020498F4(arc,7,7,0,0,0,*(u32 *)p);
    func_0201F5BC(6,4,6,0,*(u32 *)p);
    func_0201F5BC(6,0x22,7,0,*(u32 *)p);
    func_02049B40(0x17,5,4,0x80,0x20,*(u32 *)p);
    func_02040B94(6,0x20,0,*(u32 *)p);
    func_02040EBC(6,0x4753);
    *(void **)(p+0xc01c)=(void *)func_02184968(d_02185DBD,1);
    func_0201F73C(*(void **)(p+0xc01c),0,4,6);
    func_02045334(*(void **)(p+0xc01c));
    *(u32 *)(p+0xc0b0)=0;
    func_0203FCA0(2,&d_02185E58,0);
    func_020414EC(2);
    func_0204044C(1);
    func_0203FCA0(3,&d_02185E78,0);
    func_02049658(arc,5,3,0,0,0,*(u32 *)p);
    func_02049B68(arc,6,0,0,0x80,*(u32 *)p);
    func_020498F4(arc,7,3,0,0,0,*(u32 *)p);
    func_0201F5BC(2,0x22,7,0,*(u32 *)p);
    func_02049B40(0x17,5,0,0x80,0x20,*(u32 *)p);
    func_02049B40(0x17,5,0,0x100,0x20,*(u32 *)p);
    func_02040B94(2,0x20,0,*(u32 *)p);
    func_02040EBC(2,0);
    func_02184BAC(p);
}
