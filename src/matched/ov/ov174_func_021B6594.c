/*
 * function: func_021B6594
 * address: 0x021B6594
 * packet: pkt_ov174_021B6594
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020498F4 0x020498F4 arm
 *   func_02012944 0x02012944 thumb
 *   func_020490F4 0x020490F4 arm
 *   func_0204ACEC 0x0204ACEC arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02008550 0x02008550 thumb
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020409B4 0x020409B4 arm
 *   func_020413B0 0x020413B0 arm
 *   func_02049238 0x02049238 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B92C 0x0204B92C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned u32;
typedef struct { u16 x,y,z; u8 a,b; } Spec;
extern void func_020498F4(void *,u32,u32,u32,u32,u32,u16);
typedef signed int     s32;
struct Obj;
struct Sub0200852CObj;
extern u8 *func_02012944(void *p);
extern void *func_020490F4(u32,u16);
extern int func_0204ACEC(void *,u32,u32,u32,u16);
extern int func_0204A6C8(void *,u32,u32,u32,u16);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern void func_02049658(void *,u32,u32,u32,u32,u32,u16);
extern void func_020409B4(u32);
extern void func_020413B0(u32,u8,u8,u8,u8,u8);
extern void func_02049238(void *);
extern void *func_0204B294(u32,u32,u32,u32,u32,u16,u16);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B92C(struct Obj *p, u32 v);
void func_021B6594(u8 *p)
{
    int id=37;
    void *save;
    void *arc;
    Spec s;
    if(*(int *)(p+8)!=2) id=38;
    func_020498F4(*(void **)(p+24),id,2,0,0,0,*(u16 *)p);
    func_020498F4(*(void **)(p+24),id,3,0,0,0,*(u16 *)p);
    save=func_02012944(*(void **)(*(u8 **)(p+48)+4));
    arc=func_020490F4(172,*(u16 *)p);
    *(int *)(p+68)=func_0204ACEC(arc,3,0,0,*(u16 *)p);
    *(int *)(p+72)=func_0204A6C8(arc,24,0,0,*(u16 *)p);
    *(int *)(p+76)=func_0204AF28(arc,20,22,*(u16 *)p);
    if(func_02008550(save)==0) func_02049B68(arc,7,4,0,0x60,*(u16 *)p);
    else func_02049B68(arc,6,4,0,0x60,*(u16 *)p);
    func_02049658(arc,11,7,0,0,0,*(u16 *)p);
    func_020498F4(arc,14,7,0,0,0,*(u16 *)p);
    func_020409B4(7);
    func_02049B68(arc,0,0,0x160,0x20,*(u16 *)p);
    func_02049658(arc,8,1,0,0,0,*(u16 *)p);
    func_020498F4(arc,13,1,0,0,0,*(u16 *)p);
    func_020413B0(1,0,0,32,32,11);
    func_020409B4(1);
    func_02049238(arc);
    s.a=10; s.b=1; s.x=0;s.y=0;s.z=0;
    *(void **)(p+84)=func_0204B294(*(u32 *)(p+80),*(u32 *)(p+72),*(u32 *)(p+68),*(u32 *)(p+76),(u32)&s,0,*(u16 *)p);
    func_0204B3DC(*(void **)(p+84),0);
    func_0204B92C(*(void **)(p+84),1);
}
