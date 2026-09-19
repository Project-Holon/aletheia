/*
 * function: func_0202F498
 * address:  0x0202F498
 * packet:   pkt_0202F498
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02017DBC  0x02017DBC  thumb
 *   func_02017DE4  0x02017DE4  thumb
 *   func_02017E88  0x02017E88  thumb
 *   func_02017EB4  0x02017EB4  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202F498.c \
 *       --func func_0202F498 --addr 0x0202F498 --cc 1.1p1 --thumb
 */

extern void *func_02017DBC(void *a);
extern void  func_02017DE4(void *a, void *b);
extern int   func_02017E88(void *a, int b, int c);
extern int   func_02017EB4(void *a);

int func_0202F498(void *a0, int a1)
{
    void *p = func_02017DBC(a0);
    int x = func_02017E88(a0, 5, 0);
    int y = func_02017E88(a0, 0x96, 0);
    int z = func_02017E88(a0, 0x6d, 0);
    int w = func_02017EB4(a0);
    int flag = 0;

    if (func_02017E88(a0, 0x8f, flag) != 0
        || func_02017E88(a0, 0x90, flag) != 0
        || func_02017E88(a0, 0x91, flag) != 0
        || func_02017E88(a0, 0x95, flag) != 0) {
        flag = 1;
    }
    func_02017DE4(a0, p);

    switch (a1) {
    case 0:
        if (x == 0xfb && y == 0x753a && z == 1 && flag == 0 && w == 0) {
            return 1;
        }
        break;
    case 1:
        if (x == 0xfb && y == 0x753b && z == 1 && flag == 0 && w == 0) {
            return 1;
        }
        break;
    case 2:
        if ((unsigned)(x - 0xf3) <= 2 && y == 0x753c && w == 1 && z == 1
            && flag == 0) {
            return 1;
        }
        break;
    case 3:
        if ((unsigned)(x - 0xf3) <= 2 && y == 0x753d && w == 1 && z == 1
            && flag == 0) {
            return 1;
        }
        /* fall through */
    case 4:
        if (x == 0x287 && z == 1 && flag == 0) {
            return 1;
        }
        break;
    case 5:
        if (x == 0x288 && z == 1 && flag == 0) {
            return 1;
        }
        break;
    case 6:
        if (x == 0x289 && z == 1 && flag == 0) {
            return 1;
        }
        break;
    case 7:
        if (x == 0x1ec && z == 1 && flag == 0) {
            return 1;
        }
        break;
    }
    return 0;
}
