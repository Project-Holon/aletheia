/*
 * function: func_02050894
 * address:  0x02050894
 * packet:   pkt_02050340
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * blocker:  PC24 func_02050738 at +0x30: only branch anywhere in the image to 0x02050738 is inside this range; matching that 88-byte function (pkt_02050340) would attest it as `matched`
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050894.c \
 *       --func func_02050894 --addr 0x02050894 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct S8 {
    u16 h;
    u16 pad;
    u32 w;
};

struct S40 {
    u32 f0;
    u16 f4;
    u16 f6;
    u32 f8;
    u32 f12;
    u32 f16;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f32;
    u32 f36;
};

extern int func_02050738(void *p, void *q);

int func_02050894(void *p, int idx, int j)
{
    struct S8  *arr = *(struct S8 **)((char *)p + 12);
    struct S40 *rec = *(struct S40 **)((char *)p + 24);
    u16 e = rec[idx].f4;
    u32 v = arr[j].w;

    arr[e].w = v;
    return func_02050738(p, &arr[e]);
}
