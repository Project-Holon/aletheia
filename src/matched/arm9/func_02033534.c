/*
 * function: func_02033534
 * address:  0x02033534
 * packet:   pkt_020334E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *           --suggest-split offers nothing (single function, the one
 *           unresolved site's only witness is inside this range).
 * blocker:  func_02076B2C (label) -- has no witness outside 02033534..020335AC,
 *           the only branch to it in the image is this function's own call.
 *           Every concrete byte of the body reproduces.
 * symbols:
 *   str_020A78A0   0x020A78A0  data
 *   str_020A78B0   0x020A78B0  data
 *   func_02034714  0x02034714  arm
 *   func_02084EB8  0x02084EB8  arm
 *   func_02075E9C  0x02075E9C  arm
 *   func_02076B2C  0x02076B2C  arm
 *   func_02075EAC  0x02075EAC  arm
 *   func_02084F10  0x02084F10  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern const u8 str_020A78A0[];
extern const u8 str_020A78B0[];
extern void func_02034714(const u8 *file, int line, const u8 *msg);
extern int  func_02084EB8(u32 a);
extern void func_02075E9C(u16 a);
extern int func_02076B2C(int type);
extern void func_02075EAC(u16 a);
extern void func_02084F10(u16 a);

int func_02033534(u32 a)
{
    int id = func_02084EB8(a);
    u32 h;

    if (id == -3) {
        func_02034714(str_020A78A0, 0x38, str_020A78B0);
    }
    func_02075E9C((u16)id);
    h = 0x00ff1302;
    if (func_02076B2C(h) == 0) {
        h = 0;
    }
    func_02075EAC((u16)id);
    func_02084F10((u16)id);
    return h != 0;
}
