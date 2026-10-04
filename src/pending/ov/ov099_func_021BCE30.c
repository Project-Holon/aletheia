/*
 * function: func_021BCE30
 * address:  0x021BCE30
 * packet:   pkt_ov099_021BCE30
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * note (2026-10-04): DIFF, 80 bytes, all else equal. Original block order is case3, case2 (movs 0x97; b J), case4 (movs 0x90), J: subs r0,#9; strb; movs 0x8a, i.e. a shared byte store with value in r1 and the pool offset kept in r0. Per-arm stores (this file) give case2 with its own store and case4 jumping back. goto-shared-tail forms give 84 bytes (offset constant reloaded, switch value in r0). if-chain forms differ in block order.
 *
 * symbols:
 *   func_021BC06C  0x021BC06C  thumb  ov099
 *   func_021BA8EC  0x021BA8EC  thumb  ov099
 *   func_020362DC  0x020362DC  arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_020362DC(void);
extern void func_021BC06C(char *p);
extern void func_021BA8EC(char *p);

int func_021BCE30(char *p, int v)
{
    int r;
    if (func_020362DC() != 0) {
        func_021BC06C(p);
        func_021BA8EC(p);
        switch (*(int *)(p + 0x135C)) {
        case 3:
            r = 0x4E;
            break;
        case 2:
            *(u8 *)(p + 0x1353) = 0x97;
            r = 0x8A;
            break;
        case 4:
            *(u8 *)(p + 0x1353) = 0x90;
            r = 0x8A;
            break;
        default:
            r = 0x72;
            break;
        }
        *(int *)(p + 0x1CC) = r;
    }
    return v;
}
