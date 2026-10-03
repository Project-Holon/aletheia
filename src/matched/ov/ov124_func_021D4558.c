/*
 * function: func_021D4558
 * address: 0x021D4558
 * packet: pkt_ov124_021D4558
 * region: ov124
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 0x021D4696.
 * interface: 0204B294 returns its forwarding target's live r0, used here.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049F78 0x02049F78 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B92C 0x0204B92C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u16 x, y, z; u8 a, b; } Request;
extern u32 func_020490F4(void *, u32);
extern void func_02049B68(u32, u32, u32, u32, u32, u16);
extern void func_02049658(u32, u32, u32, u32, u32, u32, u16);
extern void func_020498F4(u32, u32, u32, u32, u32, u32, u16);
extern void func_02049238(u32);
struct Obj;
struct Sub0200852CObj;
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern int func_0204AC18(u32, u32, u32, u32, u16, u16, u16);
extern int func_0204A6C8(u32, u32, u32, u32, u16);
extern int func_0204AF28(u32, u32, u32, u16);
extern void *func_02049F78(u32, u32, u32, u32);
extern void *func_0204B294(void *, u32, u32, u32, Request *, u16, u16);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B92C(struct Obj *p, u32 v);
void func_021D4558(char *p)
{
    u32 handle;
    Request req;
    handle = func_020490F4((void *)0x1d, *(u16 *)p);
    func_02049B68(handle, 1, 4, 0, 0, *(u16 *)p);
    func_02049658(handle, 4, 6, 0, 0, 0, *(u16 *)p);
    func_020498F4(handle, 10, 6, 0, 0, 0, *(u16 *)p);
    func_02049658(handle, 4, 7, 0, 0, 0, *(u16 *)p);
    func_020498F4(handle, 9, 7, 0, 0, 0, *(u16 *)p);
    func_02049238(handle);
    handle = func_020490F4((void *)0x1e, *(u16 *)p);
    if (func_02008550(**(void ***)(p + 4)) == 0)
        *(int *)(p + 0x50) = func_0204AC18(handle, 19, 1, 0, 0, 15, *(u16 *)p);
    else
        *(int *)(p + 0x50) = func_0204AC18(handle, 12, 1, 0, 0, 15, *(u16 *)p);
    *(int *)(p + 0x54) = func_0204A6C8(handle, 22, 0, 1, *(u16 *)p);
    *(int *)(p + 0x58) = func_0204AF28(handle, 21, 20, *(u16 *)p);
    func_02049658(handle, 0, 4, 0, 0, 0, *(u16 *)p);
    *(void **)(p + 0x44) = func_02049F78(handle, 13, (u32)(p + 0x48), *(u16 *)p);
    func_02049238(handle);
    req.x = 32;
    req.y = 48;
    req.z = 0;
    req.a = 0;
    req.b = 0;
    *(void **)(p + 0x5c) = func_0204B294(*(void **)(p + 0x4c), *(u32 *)(p + 0x50), *(u32 *)(p + 0x54), *(u32 *)(p + 0x58), &req, 1, *(u16 *)p);
    func_0204B3DC(*(void **)(p + 0x5c), 0);
    func_0204B92C(*(void **)(p + 0x5c), 1);
}
