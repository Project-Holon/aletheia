/*
 * file:     unit_0206AF08_p01.c
 * unit:     yes
 * function: func_0206AF08, func_0206AF74
 * address:  0x0206AF08
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
struct Node0206AF08;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef void (*Cb0206AF08)(u32 a0, struct Node0206AF08 *n, u32 v);

struct Node0206AF08 {
    u32 pad00[3];
    Cb0206AF08 cb;
    struct Node0206AF08 *next;
    u32 pad14;
    u8  pad18;
    u8  count;
    u16 v[1];
};

typedef signed int s32;

int func_0206AF08(u32 a0, struct Node0206AF08 *n, u32 idx);
void func_0206AF74(volatile s32 *dst, s32 *src, s32 v, int flag);


int func_0206AF08(u32 a0, struct Node0206AF08 *n, u32 idx)
{
    int r = 0;

    while (n != 0) {
        if (idx < n->count) {
            u16 v = n->v[idx];

            if ((v & 0x300) == 0x100) {
                Cb0206AF08 cb = n->cb;

                if (cb != 0) {
                    cb(a0, n, v & 0xff);
                    r = 1;
                }
            }
        }
        n = n->next;
    }
    return r;
}


/*
 * Mixes two three-word vectors into dst: with `flag` set it just adds the
 * scalar v to each word, otherwise it accumulates the 12.12 fixed-point
 * product (v * src[i]) >> 12.
 *
 * `dst` must be spelled `volatile`: with a plain `s32 *` mwcc schedules the
 * two arms differently.  The plain-pointer spelling matches the `else` arm
 * exactly (ldr src, ldr dst, mul, add, str) but groups the `if` arm into
 * three hoisted loads, three adds and three stores; the volatile spelling
 * reproduces the original's strictly sequential ldr/add/str per word.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206AF74.c \
 *       --func func_0206AF74 --addr 0x0206AF74 --arm --cc 1.1p1
 */
void func_0206AF74(volatile s32 *dst, s32 *src, s32 v, int flag)
{
    if (flag) {
        dst[0] += v;
        dst[1] += v;
        dst[2] += v;
    } else {
        dst[0] += (v * src[0]) >> 12;
        dst[1] += (v * src[1]) >> 12;
        dst[2] += (v * src[2]) >> 12;
    }
}
