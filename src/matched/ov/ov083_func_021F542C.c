/*
 * function: func_021F542C
 * address:  0x021F542C
 * packet:   pkt_ov083_021F542C
 * region:   ov083
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 *   func_020061E4  0x020061E4  thumb
 */

typedef unsigned int u32;

typedef signed int     s32;
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int  func_0204E804(void);
extern void func_020061E4(u32 a);

int func_021F542C(int a0, int *p)
{
    switch (*p) {
    case 0:
        func_0204E720(4, 10, 16, 4);
        func_020061E4(0x5E0);
        (*p)++;
        break;
    case 1:
        if (func_0204E804() != 0)
            break;
        func_0204E720(4, 16, 0, 8);
        (*p)++;
    case 2:
        if (func_0204E804() != 0)
            break;
    default:
        return 1;
    }
    return 0;
}
