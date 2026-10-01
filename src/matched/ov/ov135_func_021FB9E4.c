/*
 * function: func_021FB9E4
 * address: 0x021FB9E4
 * packet: pkt_ov135_021FB9E4
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Tail: two zero bytes of alignment padding after the return.
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B898 0x0204B898 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B98C 0x0204B98C arm
 *   func_021F9660 0x021F9660 thumb ov135
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_0204B3DC(u32 p, int on);
extern u32 func_0204B898(u32 p);
extern void func_0204B878(u32 p, u16 k);
extern u32 func_0204B98C(void *p);
extern void func_021F9660(void *p, u32 mode);
extern void func_0202CD64(void *p, u32 idx, signed char dx, signed char dy, u8 frames);
extern void func_0202CAE4(void *p, int a, int b, int c, int d);
int func_021FB9E4(u8 *p)
{
    if (func_0204B98C(*(void **)(p + 8)) != 0) return -1;
    func_0204B3DC(*(u32 *)(p + 8), 0);
    func_021F9660(p, 5);
    if (*(s16 *)(p + 0x3a) < 0) {
        *(int *)(p + 0x48) = 21;
    } else {
            func_0202CD64(*(void **)(p + 0x18), 0, -4, 0, 3);
            if (*(u32 *)(p + 0x14) != 0) func_0204B3DC(*(u32 *)(p + 0x14), 0);
            func_0204B878(*(u32 *)(p + 8), 7);
            *(int *)(p + 0x48) = 2;
            func_0202CAE4(*(void **)(p + 0x18), 0, 0x60, 0x18, 1);
            *(int *)(p + 0x4c) = 26;
    }
    return -1;
}
