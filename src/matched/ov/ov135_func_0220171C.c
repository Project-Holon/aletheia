/*
 * function: func_0220171C
 * address: 0x0220171C
 * packet: pkt_ov135_0220171C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C866C 0x021C866C arm ov114
 *   func_021C86A8 0x021C86A8 arm ov114
 *   func_022021F8 0x022021F8 thumb ov135
 *   func_022023A4 0x022023A4 thumb ov135
 *   func_022024B0 0x022024B0 thumb ov135
 *   func_02201B44 0x02201B44 thumb ov135
 *   func_021F513C 0x021F513C thumb ov135
 *   func_0203CA04 0x0203CA04 arm
 *   func_0203C968 0x0203C968 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021C866C(void);
extern int func_021C86A8(void);
extern void func_022021F8(u8 *,int);
extern void func_022023A4(u8 *p, void *mon, void *unused2, void *unused3, u32 index);
extern void func_022024B0(void *obj, u8 *p);
extern void func_02201B44(u8 *,void *,u8 *,void *);
extern void func_021F513C(u8 *p);
extern u32 func_0200FBB0(void);
extern void func_0203CA04(void);
extern void func_0200FBA0(void);
extern void func_0203C968(void);
int func_0220171C(u8 *p)
{
    int r;
    if(func_021C866C()) {
        r=func_021C86A8();
        *(u32 *)(p+0xF8C)=0;
        switch(r) {
        case 0:
            *(u32 *)(p+0x28)=0x22;
            func_022021F8(p,0);
            func_022023A4(p,p+0xA24,p+0xE4,p+0xA24,*(u16 *)(p+0xC4));
            func_022024B0(*(void **)(*(u8 **)p+0x18),p+0xA24);
            func_02201B44(p,p+0xA24,p+0xA24,p+0xE4);
            break;
        case -5:
            *(int *)(p+0x38)=r;
            *(u32 *)(p+0x28)=0x15;
            break;
        case -6: case -7: case -8: case -9: case -10: case -11:
            *(int *)(p+0x38)=r;
            *(u32 *)(p+0x28)=0x2D;
            break;
        case -12:
            *(int *)(p+0x38)=r;
            *(u32 *)(p+0x28)=0x2D;
            break;
        case -15: case -14: case -2:
            *(int *)(p+0x38)=r;
            *(u32 *)(p+0x28)=0x2B;
            func_0200FBB0(); func_0203CA04(); func_0200FBA0(); func_0203C968();
            break;
        case -13:
            func_021F513C(p);
            break;
        }
    } else {
        if(++*(u32 *)(p+0xF8C)==0xE10) func_021F513C(p);
    }
    return 2;
}
