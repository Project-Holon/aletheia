/*
 * function: func_021FAC8C
 * address: 0x021FAC8C
 * packet: pkt_ov135_021FAC8C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: explicit if/else calls preserve the flag argument's scheduling.
 * symbols:
 *   func_0202CE40 0x0202CE40 thumb
 *   func_020355C4 0x020355C4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B878 0x0204B878 arm
 *   func_021F4FF4 0x021F4FF4 thumb ov135
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct WinMgr;
extern u32 func_0202CE40(struct WinMgr *mgr, u32 idx);
extern u8 func_020355C4(void);
extern void func_0204B3DC(void *, u32);
extern void func_0204B92C(void *, u32);
extern void func_0204B878(void *, u16);
extern void func_021F4FF4(u32, u32, u32);
int func_021FAC8C(u8 *p)
{
    if (!func_0202CE40(*(struct WinMgr **)(p + 24), 0)) {
        if (func_020355C4() == 1)
            func_0204B3DC(*(void **)(p + 8), 0);
        else
            func_0204B3DC(*(void **)(p + 8), 1);
        if (*(s16 *)(p + 84) == 2) {
            func_0204B92C(*(void **)(p + 12), 0);
            func_0204B92C(*(void **)(p + 16), 0);
            func_0204B878(*(void **)(p + 12), 38);
            func_0204B878(*(void **)(p + 16), 39);
            func_021F4FF4(*(u32 *)(p + 12), 228, 120);
            func_021F4FF4(*(u32 *)(p + 16), 154, 120);
            func_0204B3DC(*(void **)(p + 12), 1);
            func_0204B3DC(*(void **)(p + 16), 1);
        }
        *(int *)(p + 72) = *(int *)(p + 76);
    }
    return -1;
}
