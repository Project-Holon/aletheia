/*
 * function: func_021D9BEC
 * address: 0x021D9BEC
 * packet: pkt_ov129_021D9BEC
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent ends with two bytes of zero alignment padding.
 * symbols:
 *   func_0204B294 0x0204B294 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B688 0x0204B688 arm
 *   func_021D9E60 0x021D9E60 thumb ov129
 *   func_021D9E98 0x021D9E98 thumb ov129
 *   func_021D9E48 0x021D9E48 thumb ov129
 */
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct { u16 x,y,frame; u8 speed,flag; } Params;
extern int func_0204B294(int,int,int,int,void *,int,int);
extern void func_0204B878(int,u16);
extern void func_0204B92C(int,int);
extern void func_0204B688(int,int);
extern void func_021D9E60(char *,int);
extern void func_021D9E98(char *,int);
extern void func_021D9E48(char *,int,int);
void func_021D9BEC(char *p)
{
    Params s;
    int h=*(int *)(p+0x25c);
    s.x=0; s.y=0; s.frame=0; s.speed=0; s.flag=0;
    *(int *)(p+0x194)=func_0204B294(h,*(int *)(p+0x274),*(int *)(p+0x268),*(int *)(p+0x28c),&s,0,50);
    *(int *)(p+0x1b0)=func_0204B294(h,*(int *)(p+0x274),*(int *)(p+0x268),*(int *)(p+0x28c),&s,0,50);
    *(int *)(p+0x1cc)=func_0204B294(h,*(int *)(p+0x274),*(int *)(p+0x268),*(int *)(p+0x28c),&s,0,50);
    func_021D9E60(p,0);
    func_0204B878(*(int *)(p+0x194),0);
    func_0204B92C(*(int *)(p+0x194),1);
    *(u16 *)(p+0x1b8)=0; *(u16 *)(p+0x1ba)=0;
    *(int *)(p+0x1a4)=1;
    func_021D9E98(p,0);
    func_0204B878(*(int *)(p+0x1b0),*(int *)(p+0x1a4));
    func_0204B92C(*(int *)(p+0x1b0),1);
    func_0204B688(*(int *)(p+0x1b0),1);
    *(u16 *)(p+0x1d4)=0; *(u16 *)(p+0x1d6)=0;
    *(int *)(p+0x1c0)=1;
    func_021D9E98(p,0);
    func_0204B878(*(int *)(p+0x1cc),*(int *)(p+0x1c0));
    func_0204B688(*(int *)(p+0x1cc),1);
    func_0204B92C(*(int *)(p+0x1cc),1);
    func_021D9E48(p,1,0);
    func_021D9E48(p,2,0);
}
