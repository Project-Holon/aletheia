/*
 * function: func_021FBA84
 * address: 0x021FBA84
 * packet: pkt_ov135_021FBA84
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202CAE4 0x0202CAE4 thumb
 *   func_0202CB4C 0x0202CB4C thumb
 *   func_020355C4 0x020355C4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_021F9260 0x021F9260 thumb ov135
 *   func_021F8908 0x021F8908 thumb ov135
 *   func_021FB364 0x021FB364 thumb ov135
 *   func_021F9EEC 0x021F9EEC thumb ov135
 *   func_021FBF04 0x021FBF04 thumb ov135
 *   func_021FBEB8 0x021FBEB8 thumb ov135
 *   func_021F4FF4 0x021F4FF4 thumb ov135
 *   tbl_02203324 0x02203324 data a4
 *   tbl_02203236 0x02203236 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct {u8 x,y;} Cell;
typedef signed char s8;
struct WinMgr;
extern const int tbl_02203324[];
extern const Cell tbl_02203236[];
extern void func_0202CAE4(struct WinMgr *mgr, u32 idx, u32 arc, u32 member, u32 alloc);
extern void func_0202CB4C(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern u8 func_020355C4(void);
extern void func_0204B3DC(u32,int);
extern void func_0204B878(u32,u16);
extern void func_0204B92C(u32,int);
extern void func_021F9260(void *,u32);
extern int func_021F8908(void *,void *,int);
extern void func_021FB364(void *,int,int);
extern int func_021F9EEC(u32,u32);
extern void func_021FBF04(void *,void *,void *,int,u32);
extern void func_021FBEB8(void *,void *,void *,u32,void *);
extern void func_021F4FF4(u32,u32,u32);
int func_021FBA84(u8 *p)
{
    u8 pages;
    func_0202CAE4(*(void **)(p+0x18),0,0x60,0x18,1);
    func_021F9260(p,3);
    *(int *)(p+0x58)=func_021F8908(p+0x30,*(void **)(p+0x28),*(s16 *)(p+0x3A)+tbl_02203324[*(s16 *)(p+0x38)]);
    func_021FB364(p,0,*(int *)(p+0x58));
    *(s16 *)(p+0x56)=0;
    pages=func_021F9EEC(*(int *)(p+0x58),5);
    func_021FBF04(*(void **)(p+0x18),*(void **)(p+0x34),*(void **)(*(u8 **)p+0x14),*(s16 *)(p+0x56),pages);
    func_021FBEB8(*(void **)(p+0x18),*(void **)(p+0x20),*(void **)(*(u8 **)p+0x38),0x4A,p+0x7C);
    func_0202CB4C(*(void **)(p+0x18),0,1,0);
    *(int *)(p+0x44)=0;
    func_021F4FF4(*(u32 *)(p+8),tbl_02203236[*(int *)(p+0x44)].x,tbl_02203236[*(int *)(p+0x44)].y);
    func_021F4FF4(*(u32 *)(p+12),0xB0,0x88);
    func_021F4FF4(*(u32 *)(p+16),0x58,0x88);
    if(func_020355C4()==1)
        func_0204B3DC(*(u32 *)(p+8),0);
    else
        func_0204B3DC(*(u32 *)(p+8),1);
    if(pages==1) {
        func_0204B878(*(u32 *)(p+12),0x3D);
        func_0204B878(*(u32 *)(p+16),0x3E);
    } else {
        func_0204B878(*(u32 *)(p+12),0x26);
        func_0204B878(*(u32 *)(p+16),0x27);
    }
    func_0204B92C(*(u32 *)(p+12),0);
    func_0204B92C(*(u32 *)(p+16),0);
    func_0204B3DC(*(u32 *)(p+12),1);
    func_0204B3DC(*(u32 *)(p+16),1);
    *(int *)(p+0x48)=27;
    return -1;
}
