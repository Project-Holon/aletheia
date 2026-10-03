/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 * unit:     yes
 * address:  0x0200C3F4
 * packet:   pkt_0200C0E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_0200C3F4, func_0200C3F8, func_0200C404, func_0200C40C,
 *           func_0200C418, func_0200C44C, func_0200C464, func_0200C468,
 *           func_0200C480, func_0200C4E8
 *
 * 300 bytes, 0x0200C3F4..0x0200C520, 10 functions, six of which carry no
 * label in the generated listing.
 *
 * The object is the save block with id 0x36 and it is 26 bytes of nothing but
 * a list: 25 slots holding small ids, with 25 itself as the empty marker, and
 * one slot past the end that func_0200C418 writes into when the list is full.
 * The size getter, the constructor's `MI_CpuFill8(p, 25, 26)` and the three
 * loop bounds all agree, which is what pins the length.
 *
 * func_0200C480 is a most-recently-used insert: it removes the id if it is
 * already listed, then either takes the first free slot (when the caller
 * passes 0xFF) or shifts the tail down by one and drops the id in at the
 * requested position.  Three things in it are worth recording.
 *
 *  - the index of the first loop is `s16` and the index of the second is
 *    `u8`, which is not a guess: one increments through `lsls #0x10 / asrs
 *    #0x10` and the other through `lsls #0x18 / lsrs #0x18`, and the widths
 *    are the types.
 *  - the store `a[pos] = id` and the `return pos` exist once between them
 *    all, reached by a branch from each arm.  Writing the early exit as
 *    `a[pos] = id; goto out;` inside the loop is what produces that: the
 *    compiler cross-jumps the two identical blocks and leaves the loop with
 *    `bne` over a `b` to the shared copy.  Written as `return pos;` the
 *    block is emitted twice and the function is four bytes long; written as
 *    a bare `goto store;` to a label in front of the store it is two bytes
 *    short, because a single conditional branch then reaches the target.
 *  - func_0200C4E8 clamps `i + 1` into 1..24 before using it as the swap
 *    partner, so slot 0 and slot 24 are both their own neighbour at the
 *    ends.  The clamp is two compares against hoisted constants, which is
 *    what an `if`/`else if` pair gives and a `min`/`max` pair does not.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

extern void  MI_CpuFill8(void *dest, u8 value, u32 size);
struct Sub020071CCCtrl;
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);

struct Blk36 {
    u8 unk00[26];
};

void func_0200C4E8(u8 *a);

u32 func_0200C3F4(void)
{
    return sizeof(struct Blk36);
}

void func_0200C3F8(struct Blk36 *p)
{
    MI_CpuFill8(p, 25, sizeof(struct Blk36));
}

void *func_0200C40C(void *sys);

void *func_0200C404(void *sys)
{
    return func_0200C40C(sys);
}

void *func_0200C40C(void *sys)
{
    return func_020071CC(sys, 0x36);
}

void func_0200C418(u8 *a, u8 id, u32 on)
{
    s32 i;

    if (on) {
        for (i = 0; i < 25; i++) {
            if (id == a[i]) {
                return;
            }
            if (a[i] == 25) {
                break;
            }
        }
        a[i] = id;
    } else {
        for (i = 0; i < 25; i++) {
            if (id == a[i]) {
                a[i] = 25;
            }
        }
    }
    func_0200C4E8(a);
}

u32 func_0200C44C(const u8 *a, u8 id)
{
    s32 i;

    for (i = 0; i < 25; i++) {
        if (id == a[i]) {
            return 1;
        }
    }
    return 0;
}

u8 func_0200C464(const u8 *a, u32 i)
{
    return a[i];
}

u16 func_0200C468(const u8 *a)
{
    s32 i;
    s32 n = 0;

    for (i = 0; i < 25; i++) {
        if (a[i] != 25) {
            n++;
        }
    }
    return n;
}

u8 func_0200C480(u8 *a, u8 id, u8 pos)
{
    s16 i;
    s16 j;

    for (i = 0; i < 25; i++) {
        if (id == a[i]) {
            break;
        }
    }
    func_0200C418(a, id, 0);
    if (pos == 0xFF) {
        for (pos = 0; pos < 25; pos++) {
            if (a[pos] == 25) {
                a[pos] = id;
                goto out;
            }
        }
        goto out;
    }
    if (i < pos) {
        pos--;
    }
    for (j = 24; j >= pos; j--) {
        a[j] = a[j - 1];
    }
    a[pos] = id;
out:
    return pos;
}

void func_0200C4E8(u8 *a)
{
    u16 i;
    u16 k;
    s32 t;
    u8 tmp;

    for (i = 0; i < 25; i++) {
        t = i + 1;
        if (t > 24) {
            t = 24;
        } else if (t < 1) {
            t = 1;
        }
        k = t;
        tmp = a[i];
        if (tmp == 25) {
            a[i] = a[k];
            a[k] = tmp;
        }
    }
}
