/*
 * function: func_021B3470
 * address:  0x021B3470
 * packet:   pkt_ov021_021B3470
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B3470 0x021B3470 thumb
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_020200CC 0x020200CC thumb
 *   func_021B3370 0x021B3370 thumb ov021
 */

typedef unsigned short u16;

typedef signed int     s32;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Cfg;
struct Descriptor;
struct Obj;
struct PrintSys;
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern s32 func_020200CC(struct Obj *o);
extern void func_021B3370(char *w);

void func_021B3470(char *p)
{
    void *q;
    int r;
    char *e;

    if (func_0201C6B4(*(void **)(p + 432)) == 0) {
        return;
    }
    if (*(u16 *)(p + 522) == 0) {
        q = *(void **)(p + 364);
        func_02045334(q);
        func_02045374(q);
        func_020409B4(func_02045730(q));
        *(u16 *)(p + 522) = *(u16 *)(p + 522) + 1;
    }
    r = func_020200CC(*(void **)(p + 420));
    if (r == -1) {
        return;
    }
    if (r == -2) {
        *p = 11;
        return;
    }
    e = p + r * 8;
    *(u16 *)(p + 508) = *(u16 *)(e + 0x20);
    *(int *)(p + 512) = *(int *)(e + 0x24);
    *(u16 *)(p + 520) = 1;
    func_021B3370(p);
}
