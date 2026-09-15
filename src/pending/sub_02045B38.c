/*
 * function: sub_02045B38
 * address:  0x02045B38
 * packet:   pkt_02045AA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 *
 * status:   MATCH
 *
 * Every concrete byte is right; the file is capped at MATCH by one
 * relocation site, the bl to func_02046084 at +0x70.  Blocking evidence
 * class: none available.  0x02046084 has exactly one witness image wide,
 * the call at 0x02045BA8 inside this very function, so --suggest-split
 * reports "the whole range as one file is NOT viable" with a best partition
 * of 0 pieces: no cut can attest it.  It unsticks the moment 0x02046084 is
 * itself taken EXACT (the `matched` class); 0x02046084 is outside this
 * agent's territory.
 *
 * symbols:
 *   str_020A7E8C   0x020A7E8C  data
 *   func_02030734  0x02030734  arm
 *   sub_020490F4   0x020490F4  arm
 *   func_02049578  0x02049578  arm
 *   func_02046084  0x02046084  arm
 *   func_020461B8  0x020461B8  arm
 *   func_02046110  0x02046110  arm
 *
 * The constructor of the 0x1c-byte object this packet's family hangs off.
 * It records the heap it was built on at +0x18, wires up the two records
 * sub_020490F4 and func_02049578 return, derives a third from the pair, and
 * optionally allocates a scratch buffer whose size the derived record
 * carries at its own +0x4.
 *
 *   +0x00  ptr  derived record from func_02046084 (its +0x4 is a size)
 *   +0x04  ptr  scratch buffer, allocated only when the +0x1b flag is set
 *   +0x10  ptr  func_02049578's record
 *   +0x14  ptr  sub_020490F4's record
 *   +0x18  u16  heap id
 *   +0x1a  u8   answer of func_020461B8
 *   +0x1b  u8   flag from the first argument
 *
 * Both allocation sites share one pool word for the debug site string
 * (0x020A7E8C) and differ only in the tag on the stack, 0x68 and 0x7b; they
 * are also the reason the site pointer lives in a callee-saved register
 * across the whole body.
 *
 * The record at +0x14 is re-read from memory for the func_02046084 call
 * while the one at +0x10 arrives in a register, because the latter is a
 * named local that is both stored and passed while the former only ever
 * lives in the field.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_02045B38.c \
 *       --func sub_02045B38 --addr 0x02045B38 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Derived {
    u32 unk_00;
    u32 size;
};

struct Obj {
    struct Derived *derived;
    void *scratch;
    u8    pad_08[8];
    void *unk_10;
    void *unk_14;
    u16   heap;
    u8    unk_1a;
    u8    flag;
};

extern const char str_020A7E8C[];

extern void *func_02030734(u16 heap, u32 size, u32 flags, const char *file, u32 line);
extern void *sub_020490F4(void *owner, u32 heap);
extern void *func_02049578(void *rec, u32 arg);
extern struct Derived *func_02046084(void *a, void *b, u16 heap);
extern u8 func_020461B8(struct Derived *d);
extern void func_02046110(struct Obj *o);

struct Obj *sub_02045B38(u8 flag, void *owner, u32 arg, u16 heap)
{
    struct Obj *o;
    void *rec;

    o = func_02030734(heap, 0x1c, 0, str_020A7E8C, 0x68);

    o->heap = heap;
    o->unk_14 = sub_020490F4(owner, heap);

    rec = func_02049578(o->unk_14, arg);
    o->unk_10 = rec;
    o->flag = flag;

    o->derived = func_02046084(o->unk_14, rec, o->heap);
    o->unk_1a = func_020461B8(o->derived);

    if (o->flag == 0) {
        o->scratch = 0;
    } else {
        o->scratch = func_02030734(o->heap, o->derived->size, 0, str_020A7E8C,
                                   0x7b);
        func_02046110(o);
    }

    return o;
}
