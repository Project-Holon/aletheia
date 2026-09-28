/*
 * function: func_021F3A70
 * address:  0x021F3A70
 * packet:   pkt_021F3A70
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F3A98  0x021F3A98  thumb
 *   func_021F3AB4  0x021F3AB4  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;

extern int func_021F3A98(u8 *p);
extern int func_021F3AB4(void *p);

int func_021F3A70(u8 *p)
{
    if (func_021F3A98(p) == 1 || func_021F3AB4(p) == 1) {
        if (*(u16 *)(p + 0x64) != 0) {
            return 1;
        }
    }
    return 0;
}
