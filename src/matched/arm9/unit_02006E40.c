/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x02006E40
 * packet:   pkt_02006E40
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02006E40, sub_02006E64, sub_02006E7C, sub_02006EA4
 *
 * symbols:
 *   sub_02006E40_File  0x020A7048  data
 *   func_02030734      0x02030734  arm
 *   func_020307B0      0x020307B0  arm
 *   func_02048F74      0x02048F74  arm
 *
 * alias: the file identity is in the image.  sub_02006E40 and sub_02006EA4
 * both pass 0x020A7048 to the debug allocator at 0x02030734, and the bytes
 * at 0x020A7048 spell "bgm_info.c".  The string before it is "snd_mic.c",
 * whose terminator at 0x020A7045 plus two bytes of padding fixes 0x020A7048
 * by construction, so the address is carried by the `string` class: the two
 * pool words that name it are both inside this range and `literal` discards
 * them.  See "The string class" in docs/MATCHING.md.
 *
 * A twelve byte record holding a count and two parallel arrays: a u16 key
 * array at +4 and a u8 value array at +8, both allocated from the same heap
 * by sub_02006EA4 and both freed by sub_02006E64.  sub_02006E7C is the
 * lookup, a linear scan of the key array returning the value at the same
 * index.
 *
 * Two things the bytes settle:
 *
 *  - sub_02006E7C saves r4 and r5 and no lr, so it is a leaf, and it still
 *    carries a label because the sweep accepts `push {r4, r5}` when the
 *    trace reaches it from a branch.  Its loop bound is signed (`ble` on the
 *    guard, `blt` on the back edge) even though the count is a `u8` field,
 *    which is the ordinary integer promotion of a byte compared against an
 *    `int` induction variable.
 *  - the fourth argument of the four func_02048F74 calls is a running
 *    counter, not a function of the loop index.  Written as `i * 3 + 1` and
 *    `i * 3 + 3` the compiler reassociates the multiply against the array
 *    index and computes the value inside the loop (`adds r6, r4, r1`), which
 *    is 49 bytes wrong; written as a variable stepped by three it produces
 *    the original's `adds r3, r6, #0` and `adds r3, r6, #2`.
 *  - where that variable is stepped decides two registers and one
 *    instruction.  The original materialises its value 1 as `adds r6, r4, #1`
 *    off the zero already in r4, immediately before the first allocation, so
 *    the increment has to sit between the first func_02048F74 call and the
 *    two allocations.  Move it after them and the compiler hoists the file
 *    name pool word into r7 instead, loading it once rather than twice, and
 *    puts the heap id in r6.  Write the increment as `k = 1` anywhere and the
 *    constant is common-subexpression-eliminated with the 1 that is the fifth
 *    argument of the first call, which deletes the instruction outright and
 *    shifts the rest of the function by two bytes.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Sub02006E40Obj {
    u8   count;
    u8   pad01[3];
    u16 *unk04;
    u8  *unk08;
};

extern const char sub_02006E40_File[];

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void  func_020307B0(void *p);
extern void func_02048F74(void *dst, u32 archive_id, u32 member, u32 mode, u32 *size_out);

void sub_02006EA4(struct Sub02006E40Obj *obj, u32 heap);

struct Sub02006E40Obj *sub_02006E40(u32 heap)
{
    struct Sub02006E40Obj *obj = func_02030734(
        heap, sizeof(struct Sub02006E40Obj), 0, sub_02006E40_File, 0x47);

    sub_02006EA4(obj, heap);
    return obj;
}

void sub_02006E64(struct Sub02006E40Obj *obj)
{
    func_020307B0(obj->unk04);
    func_020307B0(obj->unk08);
    func_020307B0(obj);
}

u8 sub_02006E7C(const struct Sub02006E40Obj *obj, u16 key)
{
    int i;

    for (i = 0; i < obj->count; i++) {
        if (key == obj->unk04[i]) {
            return obj->unk08[i];
        }
    }
    return 0;
}

void sub_02006EA4(struct Sub02006E40Obj *obj, u32 heap)
{
    int i;
    int k;

    k = 0;
    func_02048F74(obj, 0x57, 0, k, (u32 *)1);
    k++;
    obj->unk04 = func_02030734(heap, obj->count * 2, 0, sub_02006E40_File,
                               0xAF);
    obj->unk08 = func_02030734(heap, obj->count, 0, sub_02006E40_File, 0xB0);
    for (i = 0; i < obj->count; i++) {
        func_02048F74(&obj->unk04[i], 0x57, 0, k, (u32 *)2);
        func_02048F74(&obj->unk08[i], 0x57, 0, k + 2, (u32 *)1);
        k += 3;
    }
}
