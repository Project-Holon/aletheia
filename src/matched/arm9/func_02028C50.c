/*
 * unit:     no
 * function: func_02028C50
 * address:  0x02028C50
 * packet:   pkt_02028C50
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02074324  0x02074324  arm
 *   func_0207466C  0x0207466C  arm
 *   func_020743EC  0x020743EC  arm
 *   func_02074450  0x02074450  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct EntryA {
    u32 f00;
    u16 f04;
};

struct EntryB {
    u32 f00;
    u16 f04[4];
};

struct EntryC {
    u32 f00 : 24;
};

extern struct EntryA *func_02074324(int index);
extern void          *func_0207466C(u32 id);
extern struct EntryB *func_020743EC(u32 id);
extern struct EntryC *func_02074450(u32 id);

u32 func_02028C50(int index)
{
    struct EntryA *a;
    int i;
    struct EntryB *b;

    a = func_02074324(index);
    if (func_0207466C(a->f00) == 0) {
        return 0;
    }

    b = func_020743EC(a->f04);
    if (func_0207466C(b->f00) == 0) {
        return 0;
    }

    for (i = 0; i < 4; i++) {
        if (b->f04[i] != 0xffff) {
            if (func_0207466C(func_02074450(b->f04[i])->f00) == 0) {
                return 0;
            }
        }
    }

    return 1;
}
