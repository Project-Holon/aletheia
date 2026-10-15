/*
 * function: PROCSYS_AllocProcWork
 * address:  0x0203159C
 * packet:   pkt_020314F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02030734      0x02030734  arm
 *   func_0203159C_File 0x020A783C  data
 *
 * Allocate the object's +0x14 buffer.  The size never reaches a register
 * of its own: it arrives in r1 and is handed straight to the allocator's
 * r1, which is the arity tell, three parameters with the size second, not
 * two with a size read from the object.
 *
 * __LINE__ is 390 and does not fit an ARM immediate, so it costs its own
 * pool word next to the __FILE__ pointer.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PROCSYS_AllocProcWork.c \
 *       --func PROCSYS_AllocProcWork --addr 0x0203159C --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct Proc {
    u32 pad00[5];
    void *buffer;
};

extern const char func_0203159C_File[];

typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap)
{
    obj->buffer = func_02030734(heap, size, 0, func_0203159C_File, 390);
    return obj->buffer;
}
