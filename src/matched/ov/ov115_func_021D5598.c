/*
 * packet: pkt_ov115_021D5598
 * region: ov115
 * function: func_021D5598
 * address: 0x021D5598
 * isa: thumb
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * status: EXACT
 * lang: c99
 * lever: an enum zero assigned after archive allocation and passed only in full-width outgoing zero slots preserves the independent literal register zeros.
 * checks: fixed one EXACT with all 26 relocations resolved; earlier typed permuter consumed and not repeated.
 * ABI: 49990 fifth argument is explicitly truncated16; B294 result
 *   is consumed by stores and setters despite its legacy void spelling.
 * symbols:
 *   sub_020490F4 0x020490F4 arm
 *   sub_02049B68 0x02049B68 arm
 *   sub_02049740 0x02049740 arm
 *   func_02049990 0x02049990 arm
 *   sub_0204A6C8 0x0204A6C8 arm
 *   sub_0204AC18 0x0204AC18 arm
 *   sub_0204AF28 0x0204AF28 arm
 *   sub_02049238 0x02049238 arm
 *   sub_0204B294 0x0204B294 arm
 *   sub_0204B92C 0x0204B92C arm
 *   sub_0204B3DC 0x0204B3DC arm
 *   func_0207D63C 0x0207D63C arm
 *   sub_02005624 0x02005624 thumb
 *   func_021D58B4 0x021D58B4 thumb ov115
 *   func_02024230 0x02024230 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Rect { s16 x,y; u16 z; u8 kind,mode; };
struct Obj;
typedef signed int     s32;
extern void *sub_020490F4(u32 id, u16 heap);
extern void sub_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 sub_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern u32 func_02049990(u32,u32,u32,u32,u16,u32,u32,u16);
extern s32 sub_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 sub_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 sub_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void sub_02049238(void *);
extern struct Obj *sub_0204B294(void *,unsigned int,unsigned int,unsigned int,const void *,unsigned short,unsigned short);
extern void sub_0204B92C(struct Obj *,u32);
extern void sub_0204B3DC(struct Obj *,u32);
extern void func_0207D63C(void *,int,int,int,int);
extern void *sub_02005624(u32,u32,u32);
extern void func_021D58B4(void *,u8 *);
extern void func_02024230(s16 *,u32,u16,int);

void func_021D5598(u8 *p)
{
    enum { Zero=0 } zero;
    u32 res;
    struct Rect a,b;
    res = (u32)sub_020490F4((u32)((void *)143), *(u16 *)(p+12));
    zero=Zero;
    sub_02049B68((void *)((u32)res),0,4,zero,0,*(u16 *)(p+12));
    *(u32 *)p = sub_02049740((void *)((u32)res),7,4,zero,0,*(u16 *)(p+12));
    func_02049990((u32)res,18,4,0,*(u32 *)p,zero,0,*(u16 *)(p+12));
    func_02049990((u32)res,19,6,0,*(u32 *)p,zero,0,*(u16 *)(p+12));
    func_02049990((u32)res,20,7,0,*(u32 *)p,zero,0,*(u16 *)(p+12));
    sub_02049B68((void *)((u32)res),0,0,zero,0,*(u16 *)(p+12));
    *(u32 *)(p+4) = sub_02049740((void *)((u32)res),6,0,zero,0,*(u16 *)(p+12));
    func_02049990((u32)res,15,0,0,*(u32 *)(p+4),zero,0,*(u16 *)(p+12));
    func_02049990((u32)res,16,1,0,*(u32 *)(p+4),zero,0,*(u16 *)(p+12));
    func_02049990((u32)res,17,2,0,*(u32 *)(p+4),zero,0,*(u16 *)(p+12));
    *(int *)(p+0x990) = sub_0204A6C8((void *)((u32)res),9,0,1,*(u16 *)(p+12));
    *(int *)(p+0x98c) = sub_0204AC18((void *)((u32)res),3,1,0,0,3,*(u16 *)(p+12));
    *(int *)(p+0x994) = sub_0204AF28((void *)((u32)res),12,25,*(u16 *)(p+12));
    sub_02049238((void *)res);
    a.x=128; a.y=96; a.z=10; a.kind=0; a.mode=2;
    *(struct Obj **)(p+0x99c) = sub_0204B294((void *)*(u32 *)(p+0x980),*(u32 *)(p+0x990),*(u32 *)(p+0x98c),*(u32 *)(p+0x994),&a,1,*(u16 *)(p+12));
    sub_0204B92C(*(struct Obj **)(p+0x99c),1);
    sub_0204B3DC(*(struct Obj **)(p+0x99c),1);
    b.x=128; b.y=96; b.z=11; b.kind=1; b.mode=2;
    *(struct Obj **)(p+0x9a0) = sub_0204B294((void *)*(u32 *)(p+0x980),*(u32 *)(p+0x990),*(u32 *)(p+0x98c),*(u32 *)(p+0x994),&b,1,*(u16 *)(p+12));
    sub_0204B92C(*(struct Obj **)(p+0x9a0),1);
    sub_0204B3DC(*(struct Obj **)(p+0x9a0),1);
    func_0207D63C((void *)0x04000050,4,3,6,16);
    func_0207D63C((void *)0x04001050,8,21,6,16);
    *(void **)(p+0x988) = sub_02005624((u32)func_021D58B4,(u32)p,0);
    func_02024230((s16 *)(p+0x9ca),192,1456,6144);
    *(u16 *)(p+0xb4a) = 10;
}
