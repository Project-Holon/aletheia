/*
 * function: func_021BBD60
 * address: 0x021BBD60
 * packet: pkt_ov110_021BBD60
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: legacy 02040618 fourth input is unused by its full 02042360 target; caller sets only r0-r2.
 * symbols:
 *   func_021BC068 0x021BC068 thumb ov110
 *   func_021BC120 0x021BC120 thumb ov110
 *   func_021BC160 0x021BC160 thumb ov110
 *   func_021BC23C 0x021BC23C thumb ov110
 *   func_021BC1B8 0x021BC1B8 thumb ov110
 *   func_020498F4 0x020498F4 arm
 *   func_02040618 0x02040618 arm
 *   func_02049658 0x02049658 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045374 0x02045374 arm
 *   func_0202CA3C 0x0202CA3C thumb
 *   func_0202CB18 0x0202CB18 thumb
 *   func_0202CB4C 0x0202CB4C thumb
 *   func_0202CEBC 0x0202CEBC thumb
 *   func_0202CC58 0x0202CC58 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned u32;
typedef short s16;
typedef signed char s8;
struct WinMgr;
extern void func_021BC068(u8 *,void *);
extern void func_020498F4(u32,u32,u32,u32,u32,u32,u16);
extern void func_02040618(u32,u32,u32);
extern void func_02049658(u32,u32,u32,u32,u32,u32,u16);
extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
struct Cfg;
extern void func_02045374(struct Cfg *cfg);
extern void func_021BC120(u8 *);
extern void func_021BC160(void *);
extern void func_021BC23C(void *);
extern void func_021BC1B8(u8 *);
extern void func_0202CA3C(struct WinMgr *mgr, u32 idx, u32 bg, u32 w, u32 h);
extern void func_0202CB18(struct WinMgr *mgr, u32 idx, void *arc, u32 member, u32 alloc);
extern void func_0202CB4C(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern void func_0202CEBC(struct WinMgr *mgr, u32 idx, void *a);
extern void func_0202CC58(struct WinMgr *mgr, u32 idx);
void func_021BBD60(u8 *p,u32 a)
{
    func_021BC068(p,(void *)a);
    func_020498F4(a,25,0,0,0,0,42);
    func_020498F4(a,25,4,0,0,0,42);
    *(s16 *)(p+0x19a)=-192;
    func_02040618(4,3,*(s16 *)(p+0x19a));
    func_02049658(a,14,0,0,0,0,42);
    func_02049658(a,14,4,0,0,0,42);
    *(u32 *)(p+0xc)=func_020450F0(0,3,1,28,4,0,1);
    *(u32 *)(p+0x10)=func_020450F0(4,3,1,28,4,0,1);
    func_02045374(*(void **)(p+0xc));
    func_02045374(*(void **)(p+0x10));
    func_021BC120(p);
    func_021BC160(p);
    func_021BC23C(p);
    func_021BC1B8(p);
    func_0202CA3C(*(void **)(p+0x1b4),0,0,32,6);
    func_0202CB18(*(void **)(p+0x1b4),0,(void *)a,25,0);
    func_0202CB4C(*(void **)(p+0x1b4),0,0,0);
    func_0202CEBC(*(void **)(p+0x1b4),0,*(void **)(p+0xc));
    func_0202CC58(*(void **)(p+0x1b4),0);
    *(u32 *)(p+0x1b8)=0;
}
