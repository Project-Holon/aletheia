/*
 * function: func_021C5B74
 * address:  0x021C5B74
 * packet:   pkt_ov093_021C5B74
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D5FA4  0x021D5FA4  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021C604C  0x021C604C  thumb  ov093
 *   func_021C5BD4  0x021C5BD4  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 func_021D5440(u8 *p);
struct Unk021D5FA4;
extern void func_021D5FA4(struct Unk021D5FA4 *p, u16 n);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021C604C(u8 *p, u8 *a, int n);
extern int func_021C5BD4(void *p, int v);

void func_021C5B74(u8 *p, u8 *a, int c, int d)
{
    u8 n = func_021D5440(a);
    if (c > 0) {
        func_021D5FA4((struct Unk021D5FA4 *)a, (u16)c);
        func_021CD4B0(*(void **)(p + 0xc), 2, n, (u16)c);
    } else if (c < 0) {
        func_021C604C(p, a, -c);
    }
    if (d) {
        if (func_021C5BD4(p + 0x1AB8, n) != 6) {
            func_021CD4B0(*(void **)(p + 0xc), 0x41, n);
        }
    }
}
