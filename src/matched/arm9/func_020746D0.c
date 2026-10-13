/*
 * function: NNSi_SndArcDisposeFat
 * address:  0x020746D0
 * packet:   pkt_020737C0
 * status:   EXACT
 * isa:      arm
 * compiler: ../2.0/sp2
 *
 * Release callback NNSi_SndArcLoadTables registers with NNS_SndHeapAlloc for the
 * allocation it stores at Arc +0x88: the request drain (NNS_SndHeapClear /
 * NNS_SndHeapLoadState) invokes it as cb(node + 0x20, f08, f10, f14) with f10 the
 * Arc object, and it forgets the pointer.  One of three 12-byte unlabelled
 * leaves disasm.py prints as .word data after pool_020746C0.
 */
typedef unsigned char u8;
typedef unsigned int  u32;

struct Arc { u8 pad_00[0x88]; u32 f88; u32 f8c; u32 f90; };

void NNSi_SndArcDisposeFat(void *payload, u32 size, struct Arc *c)
{
    c->f88 = 0;
}
