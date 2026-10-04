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
 * note (2026-10-04, lane17): lane17 wave D2: now 80 bytes, 9 differing bytes. Shape that gets there: enum Off o=0x135C assigned after the two calls, `s = *(int *)(p + o); switch (s)`, case 2: r=0x97; goto store; case 4: r=0x90; store: *(u8 *)(p + (o - 9)) = r; r = 0x8A. Residue: original keeps the 0x135C pool offset in r0 and the switch value in r1 (subs r0,#9; strb r1,[r5,r0]); ours has them swapped (offset r1, value r0). Tried: separate t local, unified r, int/u32 switch local, declaration order, pointer local q (worse).
 *
 * symbols:
 *   func_021BC06C  0x021BC06C  thumb  ov099
 *   func_021BA8EC  0x021BA8EC  thumb  ov099
 *   func_020362DC  0x020362DC  arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef enum { K135c = 0x135C } Off;
extern u32 func_020362DC(void);
extern void func_021BC06C(char *p);
extern void func_021BA8EC(char *p);

int func_021BCE30(char *p, int v)
{
    Off o;
    int r;
    int s;
    if (func_020362DC() != 0) {
        func_021BC06C(p);
        func_021BA8EC(p);
        o = K135c;
        s = *(int *)(p + o);
        switch (s) {
        case 3:
            r = 0x4E;
            break;
        case 2:
            r = 0x97;
            goto store;
        case 4:
            r = 0x90;
        store:
            *(u8 *)(p + (o - 9)) = r;
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
