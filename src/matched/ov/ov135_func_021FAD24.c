/*
 * function: func_021FAD24
 * address: 0x021FAD24
 * packet: pkt_ov135_021FAD24
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two-byte zero alignment padding at 0x021FAD82.
 * symbols:
 *   func_0204B98C 0x0204B98C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0202CD64 0x0202CD64 thumb
 */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
struct WinMgr;
struct Actor;
struct Obj;
extern u32 func_0204B98C(struct Actor *a);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0202CD64(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy, u8 frames);
int func_021FAD24(u8 *p)
{
    if (func_0204B98C(*(void **)(p + 8))) return -1;
    func_0204B3DC(*(void **)(p + 8), 0);
    func_0204B3DC(*(void **)(p + 12), 0);
    func_0204B3DC(*(void **)(p + 16), 0);
    if (*(s16 *)(p + 84) == 3 && *(int *)(p + 76) == 28)
        func_0202CD64(*(void **)(p + 24), 0, 6, 0, 6);
    else
        func_0202CD64(*(void **)(p + 24), 0, 4, 0, 4);
    *(int *)(p + 72) = 4;
    return -1;
}
