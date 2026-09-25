/*
 * function: func_021F8624
 * address:  0x021F8624
 * packet:   pkt_021F8624
 * region:   ov184
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Blocker: every concrete byte reproduces; 0x021FE7B0 and 0x021FD744 lie
 *   outside ov184's 0x5A0-byte region and no listing labels them, so the
 *   two calls stay wildcarded.
 *
 * symbols:
 *   func_021FE784   0x021FE784  thumb
 *   func_021FE7B0   0x021FE7B0  thumb
 *   func_021FD744   0x021FD744  thumb
 *   func_021F9BA0   0x021F9BA0  thumb
 *
 * Three-state step over the object at *(p+0x30): submit on 0, poll on 1,
 *   release the two child handles on 2.
 */


extern int func_021FE784(int, int, int, int);
extern int func_021FE7B0(int);
extern void func_021FD744(int);
extern void func_021F9BA0(int);

void func_021F8624(int a, int *state, char *p)
{
    switch (*state) {
    case 0:
        func_021FE784(*(int *)(*(int *)(p + 0x30)), 4, 3, 1);
        *state = 1;
        break;
    case 1:
        if (func_021FE7B0(*(int *)(*(int *)(p + 0x30))))
            *state = 2;
        break;
    case 2:
        func_021FD744(*(int *)(p + 0xC));
        func_021F9BA0(*(int *)(*(int *)(p + 0x30) + 0x10));
        break;
    }
}
