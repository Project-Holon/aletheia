/*
 * function: func_021BA4A4
 * address:  0x021BA4A4
 * packet:   pkt_ov070_021BA4A4
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204ABBC  0x0204ABBC  arm
 *   func_020437D4  0x020437D4  arm
 *   func_020437EC  0x020437EC  arm
 *   func_020862F0  0x020862F0  arm
 *   func_0207E780  0x0207E780  arm
 *   func_021B811C  0x021B811C  thumb  ov070
 *   func_0204B878  0x0204B878  arm
 *   func_0204B3DC  0x0204B3DC  arm
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern u8 *func_0204ABBC(u32, u32);
struct Bmp;
extern void *func_020437D4(const struct Bmp *bmp);
extern u32 func_020437EC(const struct Bmp *bmp);
extern void func_020862F0(void *, u32);
extern void func_0207E780(void *, void *, u32);
extern int func_021B811C(char *);
struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);

void func_021BA4A4(char *p)
{
    int i;
    u8 *src;
    u8 *dst;

    for (i = 0; i < 8; i++) {
        src = func_0204ABBC(*(u32 *)(p + i * 4 + 0x5F4), 0);
        dst = func_020437D4(*(void **)(p + i * 4 + 0x614));
        func_020862F0(dst, func_020437EC(*(void **)(p + i * 4 + 0x614)));
        func_0207E780(dst + 0x100, src + 0x80, 0x80);
        func_0207E780(dst + 0x280, src + 0x100, 0x80);
        func_0207E780(dst, src + 0x300, 0x100);
        func_0207E780(dst + 0x180, src + 0x400, 0x100);
        if (*(u32 *)(p + i * 4 + 0x654) != 0) {
            if (*(int *)(p + 0x80C) == 4) {
                if (func_021B811C(p) == 1 && *(u32 *)(p + i * 4 + 0x654) != 3) {
                    func_0204B878((struct Obj *)(*(int *)(p + i * 4 + 0x674)), *(u32 *)(p + i * 4 + 0x654) - 1);
                    func_0204B3DC((struct Obj *)*(int *)(p + i * 4 + 0x674), 1);
                } else {
                    func_0204B3DC((struct Obj *)*(int *)(p + i * 4 + 0x674), 0);
                }
            } else if (*(int *)(p + 0x80C) == 0 && *(u32 *)(p + i * 4 + 0x654) >= 4) {
                func_0204B878((struct Obj *)(*(int *)(p + i * 4 + 0x674)), *(u32 *)(p + i * 4 + 0x654) - 1);
                func_0204B3DC((struct Obj *)*(int *)(p + i * 4 + 0x674), 1);
            } else if (*(int *)(p + 0x80C) == 2 && *(u32 *)(p + i * 4 + 0x654) >= 7) {
                func_0204B878((struct Obj *)(*(int *)(p + i * 4 + 0x674)), *(u32 *)(p + i * 4 + 0x654) - 1);
                func_0204B3DC((struct Obj *)*(int *)(p + i * 4 + 0x674), 1);
            } else {
                func_0204B3DC((struct Obj *)*(int *)(p + i * 4 + 0x674), 0);
            }
            func_0204B3DC((struct Obj *)*(int *)(p + i * 4 + 0x634), 1);
        } else {
            func_0204B3DC((struct Obj *)*(int *)(p + i * 4 + 0x674), 0);
            func_0204B3DC((struct Obj *)*(int *)(p + i * 4 + 0x634), 0);
        }
    }
}
