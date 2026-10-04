/*
 * function: func_021C0490
 * address: 0x021C0490
 * packet: pkt_ov110_021C0490
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: test source byte +95 after copying to +94; bitfield clear and ordered In stores.
 * prototype: 021C1718 tail-forwards to the returned first-word accessor 021C1848.
 * symbols:
 *   func_020355C4 0x020355C4 arm
 *   func_021C1610 0x021C1610 thumb ov110
 *   func_021C1718 0x021C1718 thumb ov110
 *   func_021B6208 0x021B6208 thumb ov067
 *   func_021B629C 0x021B629C thumb ov067
 *   func_0204B84C 0x0204B84C arm
 *   func_0204B92C 0x0204B92C arm
 *   func_021C060C 0x021C060C thumb ov110
 *   func_021C09E0 0x021C09E0 thumb ov110
 *   func_021C0A54 0x021C0A54 thumb ov110
 *   func_02027F60 0x02027F60 thumb
 *   func_021C0B54 0x021C0B54 thumb ov110
 *   func_0203D34C 0x0203D34C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned u32;
typedef struct { u8 pad[0x99]; u8 flag:1,rest:7; } Bits;
typedef struct { int f0; u32 f4; int f8,fC,f10,f14,f18; u8 b1c,b1d,b1e; } In;
extern u8 func_020355C4(void);
extern void *func_021C1610(unsigned,u16);
extern u32 func_021C1718(u8 *);
extern void func_021B6208(void *,In *,int,u16);
extern int func_021B629C(void *,int,u16,u16,u8,u16);
extern void func_0204B84C(void *,u32);
struct Obj;
struct R;
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_021C060C(u8 *p, u16 heap, u32 font, void *print, void *bank);
extern void func_021C09E0(u8 *);
extern void *func_021C0A54(int,void *,int);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void func_021C0B54(char *);
extern void func_0203D34C(u32,u32);
void func_021C0490(u8 *p)
{
    int enabled;
    u32 resource;
    In in;
    ((Bits *)p)->flag=0;
    *(u32 *)(p+0xa4)=1;
    enabled=1;
    if(func_020355C4()!=1) enabled=0;
    *(int *)(p+0xa8)=enabled;
    p[0x94]=p[0x95];
    if(p[0x95]==255) {
        if(enabled) p[0x96]=0;
        else { p[0x95]=0; p[0x96]=0; }
    } else {
        if(enabled) p[0x95]=255;
    }
    *(void **)(p+0x50)=func_021C1610(0,*(u16 *)(p+4));
    resource=func_021C1718(*(u8 **)(p+0x50));
    in.f8=43; in.fC=7; in.f10=13; in.f14=35; in.f18=41;
    in.f0=0; in.f4=0;
    in.b1c=0; in.b1d=0; in.b1e=5;
    func_021B6208(p+12,&in,resource,*(u16 *)(p+4));
    *(int *)(p+8)=func_021B629C(p+12,resource,240,16,16,*(u16 *)(p+4));
    func_0204B84C(*(void **)(p+8),1);
    func_0204B92C(*(void **)(p+8),1);
    func_021C060C(p+0x24,*(u16 *)(p+4),(u32)(*(void **)(p+0x58)),*(void **)(p+0x5c),*(void **)(p+0x60));
    func_021C09E0(p+0x24);
    p[0x44]=0;
    *(int *)(p+0x40)=0;
    *(void **)(p+0x54)=func_021C0A54((int)p,(void *)func_021C1718(*(u8 **)(p+0x50)),*(u16 *)(p+4));
    *(void **)(p+0x64)=func_02027F60(0,12,*(u32 *)(p+0x58),*(u32 *)(p+0x5c),*(u16 *)(p+4));
    func_021C0B54((char *)p);
    func_0203D34C(1,*(u16 *)(p+4));
}
