/*
 * function: func_0209455C
 * address:  0x0209455C
 * packet:   pkt_020929E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * note:     MSL stdlib qsort.c `qsort` (heapsort), 312 bytes, the real open
 *           code of worklist row pkt_02094534 (0x02094534..0x0209455C is the
 *           tail of sprintf, already EXACT as src/matched/func_02094530.c).
 *           disasm.py has NO label at 0x0209455C (the listing folds
 *           0x02094534..0x02094750 into one block), so the worklist counts
 *           these 312 bytes as data-adjacent extent, not code: integrator,
 *           seed 0x0209455C in layout/function_starts.txt.  Levers: the
 *           swap macro's count is assigned before its two pointers (sets
 *           the mov r2 / ldr r4 / ldr r3 order) and the bytes are unsigned
 *           char (ldrb, MSL is char-unsigned).  Verified with
 *             python3 tools/match.py one --src src/matched/func_0209455C.c \
 *                 --func func_0209455C --addr 0x0209455C --arm
 */

typedef unsigned long size_t;
typedef int (*_compare_function)(const void *, const void *);

#define table_ptr(i) (((char *)table_base) + (member_size * ((i) - 1)))

#define swap(dst, src, cnt)                          \
    do {                                             \
        size_t n = (cnt);                            \
        unsigned char *p = (unsigned char *)(src);   \
        unsigned char *q = (unsigned char *)(dst);   \
        if (n) do {                                  \
            unsigned char a = *p;                    \
            unsigned char b = *q;                    \
            *q++ = a;                                \
            *p++ = b;                                \
        } while (--n);                               \
    } while (0)

void func_0209455C(void *table_base, size_t num_members, size_t member_size,
                   _compare_function compare_members)
{
    size_t l, r, j;
    char *lp;
    char *rp;
    char *ip;
    char *jp;
    char *kp;

    if (num_members < 2)
        return;

    r = num_members;
    l = (r / 2) + 1;

    lp = table_ptr(l);
    rp = table_ptr(r);

    for (;;) {
        if (l > 1) {
            l--;
            lp -= member_size;
        } else {
            swap(lp, rp, member_size);

            if (--r == 1)
                return;

            rp -= member_size;
        }

        j = l;

        jp = table_ptr(j);

        while (j * 2 <= r) {
            j *= 2;

            ip = jp;
            jp = table_ptr(j);

            if (j < r) {
                kp = jp + member_size;

                if (compare_members(jp, kp) < 0) {
                    j++;
                    jp = kp;
                }
            }

            if (compare_members(ip, jp) < 0)
                swap(ip, jp, member_size);
            else
                break;
        }
    }
}
