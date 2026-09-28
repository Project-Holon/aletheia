/*
 * function: func_02156344
 * address:  0x02156344
 * packet:   pkt_ov009_02156344
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * blocker: byte-correct; two callees are unlabelled Thumb leaves with no
 *   witness outside this range. 0x0215631C (ov009, `*(g_021A8264+0x76c)=0`,
 *   referenced only by this function's pool word) and 0x021AF18C (ov013,
 *   a setter `*(g+0x1984)=r0`, only caller the bl here). Seeding both into
 *   layout/function_starts.txt (thumb) lets sole-ref/code resolve them.
 *   The old note had the switch mapping wrong: 0,1,5,default -> 4; 2 -> 1;
 *   3 -> 2; 4 -> 3, and case 5 needs its own arm (the table's lone `b`).
 *
 * symbols:
 *   g_021A8264  0x021A8264  data  ov009  a4
 *   func_0215631C  0x0215631C  thumb  ov009
 *   func_021AEF6C  0x021AEF6C  thumb  ov013
 *   func_021AF18C  0x021AF18C  thumb  ov013
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 *g_021A8264;
extern void func_0215631C(void);
extern void func_021AEF6C(u32, u32, u32);
extern void func_021AF18C(void (*)(void));

void func_02156344(u32 a)
{
    u32 v;
    *(u16 *)(g_021A8264 + 0x794) = 1;
    *(u32 *)(g_021A8264 + 0x790) = 1;
    *(u16 *)(g_021A8264 + 0x796) = 1;
    if (*(u32 *)(g_021A8264 + 0x76c) == 0) {
        v = 1;
        switch (*(u32 *)(g_021A8264 + 0x77c)) {
        case 2:
            v = 1;
            break;
        case 3:
            v = 2;
            break;
        case 4:
            v = 3;
            break;
        case 5:
            v = 4;
            break;
        default:
            v = 4;
            break;
        }
        func_021AEF6C(a, v, 1);
        func_021AF18C(func_0215631C);
        *(u32 *)(g_021A8264 + 0x76c) = 1;
    }
}
