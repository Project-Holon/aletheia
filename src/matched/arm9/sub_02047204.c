/*
 * function: func_02047204
 * address:  0x02047204
 * packet:   pkt_02046EFC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0206E964  0x0206E964  arm
 *   func_0206A00C  0x0206A00C  arm
 *   func_0206A12C  0x0206A12C  arm
 *   DC_FlushRange  0x020862F0  arm
 *
 * Publish the built buffer: locate its last record with 0x0206E964, bail out
 * if there is none, flush the buffer's own byte length (the word at +8 of
 * the buffer header) out of the data cache, then hand the record to the two
 * upload routines and report success.
 *
 * The literal 1 is materialised once into r4 and serves as both upload
 * calls' second argument and the return value
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md,
 * read in the direction where the argument does share it).
 *
 * `movs r5, r0` doing the NULL test on the way into the callee-saved
 * register is what a named local assigned from the call and then tested
 * looks like.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02047204.c \
 *       --func func_02047204 --addr 0x02047204 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Tagged {
    u16   tag;
    u16   pad02;
    void *buf;
};

struct BufHdr {
    u32 unk00;
    u32 unk04;
    u32 size;
};

extern void *func_0206E964(struct BufHdr *buf);
extern void  func_0206A00C(void *rec, u32 flag);
extern void  func_0206A12C(void *rec, u32 flag);
extern void  DC_FlushRange(void *addr, u32 size);

u32 func_02047204(struct Tagged *p)
{
    struct BufHdr *buf = p->buf;
    void          *last = func_0206E964(buf);

    if (last == 0) {
        return 0;
    }
    DC_FlushRange(buf, buf->size);
    func_0206A00C(last, 1);
    func_0206A12C(last, 1);
    return 1;
}
