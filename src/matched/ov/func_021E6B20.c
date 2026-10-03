/*
 * function: func_021E6B20
 * address:  0x021E6B20
 * packet:   pkt_021B75A8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E6B20   0x021E6B20  thumb
 *   func_021D775C   0x021D775C  thumb
 *   func_021C8174   0x021C8174  thumb
 *   func_021C8030   0x021C8030  thumb
 *   func_021D76BC   0x021D76BC  thumb
 *
 * 16-case jump table on func_021C8174(a), gated on b == func_021D775C(2);
 * every value 0..15 is covered by eight bodies sitting at 6B66, 6B6A, 6B6E,
 * 6B72, 6B76, 6B7A, 6B7E, 6B82 -- that is the order they are written in
 * below.  Each body picks a script id (0x192 and 0x1aa come out of the pool
 * because they do not fit a movs); the id goes to func_021C8030 and to
 * func_021D76BC(0x12,...), and func_021C8030's result to func_021D76BC(0xd,...).
 *
 * The `default:` label belongs on the case 4/14 group, not on a block of its
 * own: the `bhi` out-of-range arm of the table jumps to 6B6A, which is that
 * group's body, and the out-of-range arm being a real body is also what puts
 * the switch's temporary in r5 and the parameter a in r4 (mwcc allocates r4 to
 * the first web the dispatch block defines).  `default:` as a separate group
 * costs 40 bytes of diff; without it at all the `bhi` lands on the shared tail.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern int func_021D775C(int a);
extern int func_021C8174(int a);
extern int func_021C8030(int a, int b, int c);
extern int func_021D76BC(int key, u32 val);

void func_021E6B20(int x, int a, int b)
{
    int v;
    int r;

    if (func_021D775C(2) != b)
        return;
    switch (func_021C8174(a)) {
    case 1: case 2: case 3: case 8: case 15:
        v = 0x59;
        break;
    case 4: case 14: default:
        v = 0xa1;
        break;
    case 10:
        v = 0x9d;
        break;
    case 0: case 5:
        v = 0x192;
        break;
    case 6: case 11: case 12:
        v = 0x38;
        break;
    case 9:
        v = 0x1aa;
        break;
    case 7:
        v = 0x3b;
        break;
    case 13:
        v = 0x3a;
        break;
    }
    r = func_021C8030(a, b, v);
    func_021D76BC(0x12, v);
    func_021D76BC(0xd, r);
}
