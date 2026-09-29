/*
 * function: func_021C16F8
 * address:  0x021C16F8
 * packet:   pkt_ov093_021C16F8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The empty `case 3: break;` is what keeps the `cmp r4, #3` and the
 * unconditional branch; a plain `if (k == 3) {}` compiles differently.
 *
 * symbols:
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021CD64C  0x021CD64C  thumb  ov093
 *   func_021CC8D8  0x021CC8D8  thumb  ov093
 *   func_021C1758  0x021C1758  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 func_021D5440(u8 *p);
extern void func_021CD64C(void *w, u8 id, ...);
extern u32 func_021CC8D8(void *lock, int line);
extern void func_021C1758(u8 *p, u8 *a, int k);
extern void func_021CC95C(void *lock, u32 v, int line);

void func_021C16F8(u8 *p, u8 *a, int k)
{
    u32 s;
    u8 n = func_021D5440(a);
    switch (k) {
    case 1:
        func_021CD64C(*(void **)(p + 0xc), 0x5b, 0x202, n, 0xffff0000);
        return;
    case 3:
        break;
    }
    s = func_021CC8D8(p + 0x1d74, 0x1a04);
    func_021C1758(p, a, k);
    func_021CC95C(p + 0x1d74, s, 0x1a07);
}
