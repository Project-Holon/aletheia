/*
 * function: sub_020490F4
 * address:  0x020490F4
 * packet:   pkt_02048F9C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sub_020490F4_File  0x020A7EE0  data
 *   func_02030734      0x02030734  arm
 *   func_02048DDC      0x02048DDC  arm
 *   func_0204919C      0x0204919C  arm
 *
 * Constructor: take a 0x50-byte record from the debug allocator, tie it to
 * the caller's object through func_02048DDC, run the one-time init at
 * func_0204919C and hand the record back.  The allocator's __FILE__/__LINE__
 * pair is the usual ABS32 into the packed string area plus a pooled 0x209,
 * which is not an ARM rotated immediate.
 */

typedef unsigned int u32;

extern const char sub_020490F4_File[];

extern void *func_02030734(u32 heap, u32 size, u32 align, const char *file,
                           u32 line);
extern void func_02048DDC(void *rec, u32 id);
extern void func_0204919C(void *rec);

void *sub_020490F4(u32 id, u32 heap)
{
    void *rec = func_02030734(heap, 0x50, 0, sub_020490F4_File, 0x209);

    func_02048DDC(rec, id);
    func_0204919C(rec);
    return rec;
}
