/*
 * file:     time_icon_p09.c
 * unit:     yes
 * function: func_0202F498, func_0202F630, func_0202F640
 * address:  0x0202F498
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02017DBC  0x02017DBC  thumb
 *   func_02017DE4  0x02017DE4  thumb
 *   func_02017E88  0x02017E88  thumb
 *   func_02017EB4  0x02017EB4  thumb
 */
struct Sav;
typedef unsigned int   u32;

extern unsigned int func_02017DBC(struct Sav *p);
extern unsigned int func_02017DE4(struct Sav *p, unsigned int f);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern u32 func_02017EB4(void *p);
extern u32  func_020185F0(u32 a);
extern void func_02017E64(void *p, u32 id, u32 v);
int func_0202F498(void *a0, int a1);
void func_0202F630(u32 a, u32 b);
void func_0202F640(u32 a, u32 b);



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202F498.c \
 *       --func func_0202F498 --addr 0x0202F498 --cc 1.1p1 --thumb
 */
int func_0202F498(void *a0, int a1)
{
    void *p = (void *)func_02017DBC(a0);
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
    func_02017DE4(a0, (unsigned int)p);

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



/*
 * Promoted out of src/pending: the callee func_0202F640 became a manifest
 * entry this pass, so the second call site resolves on `matched`.
 */
void func_0202F630(u32 a, u32 b)
{
    func_0202F640(func_020185F0(a), b);
}


/*
 * The two trailing pool words (0x753B / 0x753D, bare literals with no
 * relocation) are part of the compiled body, so the compared output is 72
 * bytes against the worklist's 62 code bytes; the listing extent runs to the
 * end of the packet.  All four call sites resolve on `label`.
 */
void func_0202F640(u32 a, u32 b)
{
    u32 r = func_02017DBC((struct Sav *)a);

    if (func_0202F498((void *)a, b) == 1) {
        switch (b) {
        case 0:
            func_02017E64((void *)a, 0x96, 0x753B);
            break;
        case 2:
            func_02017E64((void *)a, 0x96, 0x753D);
            break;
        }
    }
    func_02017DE4((struct Sav *)a, r);
}
