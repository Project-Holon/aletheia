/*
 * unit:     no
 * address:  0x020314B8
 * packet:   pkt_02031324
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: sub_020314B8
 *
 * symbols:
 *   ENV_SetResourceSet  0x020307B0  arm
 *   func_020882D0       0x020882D0  arm
 *
 * Frees an owned sub-object at +8 if present, then re-registers the object
 * itself with ENV_SetResourceSet. The same shutdown/re-init shape as
 * sub_02031140 and sub_020315D4 in the neighbouring packets, all working
 * the TwlSDK ENV resource-set table.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020314B8.c \
 *       --func sub_020314B8 --addr 0x020314B8 --cc 1.1p1
 */

struct S020314B8 {
    char  pad[8];
    void *field8;
};

extern void func_020882D0(void *p);
extern void ENV_SetResourceSet(void *p);

void sub_020314B8(struct S020314B8 *p)
{
    if (p->field8 != 0) {
        func_020882D0(p->field8);
    }
    ENV_SetResourceSet(p);
}
