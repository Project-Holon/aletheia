/*
 * function: func_0204D324
 * address:  0x0204D324
 * packet:   pkt_0204CA74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   g_020A13B8  0x020A13B8  data
 *
 * Dispatch on the object's kind word through the table at 0x020A13B8,
 * passing the object itself.  The kind is read fresh and used as a word
 * index, so the table is an array of function pointers, not a table of
 * records.
 *
 * The second parameter is real, not a leftover: the original steps over r1
 * entirely (kind in r3, table base in r2) where the one-parameter spelling
 * uses r2 and r1.  A register that the body never touches and never
 * reallocates is a live argument being forwarded.
 *
 * PARKED AT MATCH.  Every concrete byte is right; the one wildcard is the
 * ABS32 at +0x18, the pool word holding 0x020A13B8.  That dispatch table
 * is data, so `label` and `veneer` are out and there is no code whose
 * EXACT bytes could serve as `matched`; it is binary, not a NUL-terminated
 * run, so `string` is out; and the pool word inside this function is the
 * only occurrence of the word 0x020A13B8 anywhere in the image, so
 * `literal` discards its only witness for being inside the compared range.
 * The function is atomic, so --suggest-split has nothing to cut.
 *
 * Consequence: src/pending/sub_0204B878.c (fan-in 459) was blocked only on
 * this address and stays at MATCH.  Both unstick if a second reference to
 * 0x020A13B8 turns up, most likely in an overlay's pool.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0204D324.c \
 *       --func func_0204D324 --addr 0x0204D324 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct Obj0204D324 {
    u32 kind;
};

extern void (*const g_020A13B8[])(struct Obj0204D324 *obj, u32 arg);

void func_0204D324(struct Obj0204D324 *obj, u32 arg)
{
    g_020A13B8[obj->kind](obj, arg);
}
