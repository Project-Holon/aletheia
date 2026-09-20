/*
 * function: func_0204B764
 * address:  0x0204B764
 * packet:   pkt_0204B764
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * function: func_0204B784
 * address:  0x0204B784
 * packet:   pkt_0204B764
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020637BC  0x020637BC  arm
 *
 * function: func_0204B7C8
 * address:  0x0204B7C8
 * packet:   pkt_0204B764
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef struct Struct20 {
    int w[5];
} Struct20;

typedef struct Struct36 {
    int w[9];
} Struct36;

extern void func_020637BC(void *ptr, int val);

static inline void copy_inline1(const Struct36 *src, Struct36 *dst) {
    *dst = *src;
}
static inline void copy_inline2(Struct36 *dst, const Struct36 *src) {
    *dst = *src;
}

void func_0204B764(const char *src, Struct20 *dst)
{
    const Struct20 *s = (const Struct20 *)(src + 0x40);
    *dst = *s;
}

void func_0204B784(char *dst, const Struct36 *src)
{
    Struct36 s;
    func_020637BC((void *)src, 1);
    func_020637BC((void *)src, 2);
    s = *src;
    *(Struct36 *)(dst + 0x1c) = s;
}

void func_0204B7C8(const char *src, Struct36 *dst)
{
    const Struct36 *s = (const Struct36 *)(src + 0x1c);
    *dst = *s;
}
