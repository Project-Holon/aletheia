/*
 * function: func_021BE3D4
 * address: 0x021BE3D4
 * packet: pkt_ov210_021BE3D4
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: each int offset is assigned 0x1DC, then its final literal;
 *        spilled locals retain both stores without a reload.
 * symbols:
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 */
typedef unsigned char u8;
struct PrintSys;
struct Descriptor;
extern unsigned func_0201C4E4(struct PrintSys *);
extern void *func_02045770(struct Descriptor *);
extern unsigned func_0201C6C4(struct PrintSys *, void *);
extern void func_02045334(struct Descriptor *);
void func_021BE3D4(u8 *p)
{
    int release, clear, get, flag;
    unsigned i;
    func_0201C4E4(*(struct PrintSys **)(p + 0x1dc));
    release = 0x1dc; release = 0x14c;
    clear = 0x1dc; clear = 0x150;
    get = 0x1dc; get = 0x14c;
    flag = 0x1dc; flag = 0x150;
    for (i = 0; i < 16; i++) {
        struct PrintSys *ps = *(struct PrintSys **)(p + 0x1dc);
        u8 *record = p + i * 8;
        if (record[flag] != 0 && func_0201C6C4(ps, func_02045770(*(struct Descriptor **)(record + get))) == 0) {
            func_02045334(*(struct Descriptor **)(record + release));
            record[clear] = 0;
        }
    }
}
