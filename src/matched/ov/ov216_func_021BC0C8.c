/*
 * function: func_021BC0C8
 * address: 0x021BC0C8
 * packet: pkt_ov216_021BC0C8
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203101C 0x0203101C arm
 *   func_020490F4 0x020490F4 arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_0201C450 0x0201C450 thumb
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201EC74 0x0201EC74 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_020457B0 0x020457B0 arm
 */
struct Tcbl; struct GfFont; struct WordSet; struct MsgBank; struct U16Vec;
extern struct Tcbl *func_0203101C(unsigned,unsigned short,unsigned,unsigned);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_0201DD78(unsigned,unsigned,unsigned);
extern void *func_0201C450(unsigned short,unsigned);
extern struct GfFont *func_0201D7EC(int,int,int,int,unsigned);
extern struct WordSet *func_0201EC74(unsigned,unsigned,unsigned);
extern struct MsgBank *func_02045B38(unsigned,unsigned,unsigned,unsigned);
extern struct U16Vec *func_020457B0(unsigned,unsigned);
void func_021BC0C8(char *p)
{
    *(struct Tcbl **)(p+0x18)=func_0203101C(*(unsigned short *)p,*(unsigned short *)p,64,128);
    *(void **)(p+0x54)=func_020490F4((void *)173,*(unsigned short *)p);
    func_0201DD78(7,8,15);
    *(void **)(p+0x12c)=func_0201C450(2048,*(unsigned short *)p);
    *(struct GfFont **)(p+0x128)=func_0201D7EC(23,0,0,0,*(unsigned short *)p);
    *(struct WordSet **)(p+0x138)=func_0201EC74(8,64,*(unsigned short *)p);
    *(struct MsgBank **)(p+0x130)=func_02045B38(0,2,7,*(unsigned short *)p);
    *(struct MsgBank **)(p+0x134)=func_02045B38(0,2,231,*(unsigned short *)p);
    *(struct U16Vec **)(p+0x13c)=func_020457B0(109,*(unsigned short *)p);
    *(struct U16Vec **)(p+0x140)=func_020457B0(109,*(unsigned short *)p);
    *(struct U16Vec **)(p+0x144)=func_020457B0(109,*(unsigned short *)p);
}
