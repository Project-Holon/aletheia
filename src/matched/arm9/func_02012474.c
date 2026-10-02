/*
 * function: func_02012474
 * address:  0x02012474
 * packet:   pkt_020123D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02012474.c \
 *       --func func_02012474 --addr 0x02012474 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern void sub_020124E4(void *p);
extern void func_02012374(void *evt, void **out);
extern void func_02034A5C(void *p);

int func_02012474(void *a0, u32 *a1, u32 *a2)
{
    sub_020124E4(a0);
    switch (*a1) {
    case 0:
        func_02012374(a0, (void *)a2[1]);
        (*a1)++;
        break;
    case 1:
        func_02034A5C((void *)a2[0]);
        return 1;
    }
    return 0;
}
