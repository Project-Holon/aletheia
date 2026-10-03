/*
 * function: func_021BC720
 * address:  0x021BC720
 * packet:   pkt_ov211_021BC720
 * region:   ov211
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02035C38   0x02035C38  arm
 *   func_020355D8   0x020355D8  arm
 *   func_020362DC   0x020362DC  arm
 *   func_021C93C4   0x021C93C4  thumb ov212
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int  func_02035C38(void);
extern void func_020355D8(u8 v);
extern u32 func_020362DC(void);
extern void func_021C93C4(u32 heap);

int func_021BC720(char *p)
{
    u32 v = 1;

    if (*(u16 *)(p + 8) == 0x12C)
        return 5;
    *(u16 *)(p + 8) = *(u16 *)(p + 8) + 1;
    if (func_02035C38() == 1) {
        func_020355D8(1);
        return 5;
    }
    if (func_020362DC() & 1) {
        func_020355D8(0);
        return 5;
    }
    if (func_020362DC() & 2) {
        func_020355D8(0);
        v = 0;
        *(u32 *)(*(u32 *)p + 8) = v;
        func_021C93C4(0x7E);
        return 3;
    }
    if (func_020362DC() & 0x400) {
        func_020355D8(0);
        *(u32 *)(*(u32 *)p + 8) = v;
        func_021C93C4(0x7E);
        return 3;
    }
    return 4;
}
