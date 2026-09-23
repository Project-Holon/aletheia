/*
 * function: func_02033A88
 * address:  0x02033A88
 * packet:   pkt_02033A88
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     savedata.c: lay out the save blocks (id check, per-block size
 *           from func_02033A3C, offsets rounded up to 0x100) and assert the
 *           total fits.  Closed in wave 16 by two declaration facts:
 *           func_02034734 takes FIVE arguments (the total in r3 and the
 *           limit on the stack, which is what the image's `sub sp, sp, #8`
 *           and `str r4, [sp]` are), and the locals are declared src, i,
 *           count, dst, total (i before count puts i in r5 and count in r6).
 *           The `mov r1, r5` the old note called dead is func_02033A3C's
 *           second argument.
 * symbols:
 *   str_020A78CC   0x020A78CC  data
 *   str_020A78F0   0x020A78F0  data
 *   str_020A7908   0x020A7908  data
 *   func_02033A3C  0x02033A3C  arm
 *   func_02034714  0x02034714  arm
 *   func_02034734  0x02034734  arm
 */
typedef unsigned char u8;
typedef unsigned int  u32;

struct Src { u32 id; void *fn; u32 w08; };
struct Dst { u32 id; u32 size; u32 offset; };
struct Save {
    struct Src *src;   /* +0x00 */
    u32 count;         /* +0x04 */
    u32 f08;           /* +0x08 */
    u32 f0c;           /* +0x0c */
    u32 f10;           /* +0x10 */
    struct Dst *dst;   /* +0x14 */
    u32 f18;           /* +0x18 */
};

extern const u8 str_020A78CC[];
extern const u8 str_020A78F0[];
extern const u8 str_020A7908[];
extern u32  func_02033A3C(struct Save *p, u32 i);
extern void func_02034714(const u8 *file, int line, const u8 *msg);
extern void func_02034734(const u8 *file, int line, const u8 *msg, u32 v, u32 max);
void func_02033A88(struct Save *p, u32 v)
{
    struct Src *src;
    u32 i;
    u32 count;
    struct Dst *dst;
    u32 total;
    u32 size;
    u32 off;
    u32 pad;

    src = p->src;
    count = p->count;
    dst = p->dst;
    total = 0;

    for (i = 0; i < count; i++) {
        if (i != src[i].id) {
            func_02034714(str_020A78CC, 0x9e, str_020A78F0);
        }
        dst[i].id = src[i].id;
        size = func_02033A3C(p, i);
        dst[i].size = size;
        dst[i].offset = total;
        off = v + size;
        pad = off & 0xff;
        if (pad != 0)
            pad = 0x100 - pad;
        else
            pad = 0;
        total += off + pad;
    }
    p->f0c = p->f08 + (total + p->f18);
    if (p->f0c > p->f10) {
        func_02034734(str_020A78CC, 0xb3, str_020A7908, p->f0c, p->f10);
    }
}
