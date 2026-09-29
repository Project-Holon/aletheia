/*
 * function: func_021B4AA4
 * address:  0x021B4AA4
 * packet:   pkt_ov021_021B4AA4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203633C 0x0203633C arm
 *   func_020362DC 0x020362DC arm
 *   func_021B49EC 0x021B49EC thumb ov021
 *   func_020061E4 0x020061E4 thumb
 *   func_021B42D0 0x021B42D0 thumb ov021
 *   func_021B4804 0x021B4804 thumb ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern u32 func_0203633C(void);
extern u32 func_020362DC(void);
extern int func_021B49EC(s16 *p, int max, int key);
extern void func_020061E4(u32 se);
extern void func_021B42D0(char *w, u32 a, u32 b);
extern void func_021B4804(char *w, u32 b);

int func_021B4AA4(char *w)
{
    if (func_0203633C() & 0x40) {
        if (func_021B49EC((s16 *)(w + 0x208), (u16)*(u32 *)(w + 0x204), 1) != 0) {
            func_020061E4(0x548);
            func_021B42D0(w, *(u16 *)(w + 0x208), *(u32 *)(w + 0x200));
        }
    } else if (func_0203633C() & 0x80) {
        if (func_021B49EC((s16 *)(w + 0x208), (u16)*(u32 *)(w + 0x204), -1) != 0) {
            func_020061E4(0x548);
            func_021B42D0(w, *(u16 *)(w + 0x208), *(u32 *)(w + 0x200));
        }
    } else if (func_0203633C() & 0x20) {
        if (func_021B49EC((s16 *)(w + 0x208), (u16)*(u32 *)(w + 0x204), -10) != 0) {
            func_020061E4(0x548);
            func_021B42D0(w, *(u16 *)(w + 0x208), *(u32 *)(w + 0x200));
        }
    } else if (func_0203633C() & 0x10) {
        if (func_021B49EC((s16 *)(w + 0x208), (u16)*(u32 *)(w + 0x204), 10) != 0) {
            func_020061E4(0x548);
            func_021B42D0(w, *(u16 *)(w + 0x208), *(u32 *)(w + 0x200));
        }
    }
    if (func_020362DC() & 1) {
        func_020061E4(0x54C);
        func_021B4804(w, *(u8 *)(w + 0x162));
        *(u8 *)(w + 1) = 6;
        return 10;
    }
    if (func_020362DC() & 2) {
        func_020061E4(0x551);
        return 4;
    }
    return 3;
}
