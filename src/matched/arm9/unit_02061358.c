/*
 * function: NNS_FndInitAllocatorForExpHeap, NNS_G2dStubReturnZeroA, NNS_G2dStubReturnMinusOneA, NNS_G2dStubReturnZeroB,
 *           NNS_G2dStubReturnMinusOneB
 * address:  0x02061358
 * packet:   pkt_0206123C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * unit:     yes
 *
 * functions:
 *   NNS_FndInitAllocatorForExpHeap  0x02061358  arm
 *   NNS_G2dStubReturnZeroA  0x02061370  arm
 *   NNS_G2dStubReturnMinusOneA  0x02061378  arm
 *   NNS_G2dStubReturnZeroB  0x02061380  arm
 *   NNS_G2dStubReturnMinusOneB  0x02061388  arm
 *
 * symbols:
 *   g_020A1708     0x020A1708  data
 *
 * The four eight-byte functions after the first are the `0` / `-1` stub
 * pair the object's own dispatch table points at (the word stored at
 * 0x020A1708 is 0x0206128C, and the stubs sit right behind the table pointer
 * this function installs).  `disasm.py` never labels them, because a leaf
 * that saves no register has no prologue to sweep, so they print as a run of
 * `.word`s between two literal pools -- see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.  They are read
 * out of the bytes here, and folding them into this unit is also what makes
 * the unit EXACT rather than EXACT*: on its own, NNS_FndInitAllocatorForExpHeap's inferred
 * extent runs 56 bytes to the next label at 0x02061390.
 *
 * The store order in the first function is the whole of its codegen: the zero
 * word has to be written *second* in the source (after the table pointer,
 * before the two arguments) for mwcc to fold the a/b/0 stores into a single
 * `stmib r0, {r1, r2, r3}`.  With `unkC = 0` written last the compiler emits
 * a two-register `stmib` plus a separate `str` and the literal pool moves
 * four bytes along.
 *
 * The one relocation site is the pool word for the data object at 0x020A1708;
 * it resolves as `data_table` (40 witnesses elsewhere in the image), which is
 * why this file is EXACT rather than the MATCH the single-function,
 * own-pool-witness reading would suggest.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02061358.c \
 *       --addr 0x02061358 --arm
 *   EXACT, 56 bytes, 5 functions, 1 relocation site, resolved.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S02061358 {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
};

extern u8 g_020A1708[];

void NNS_FndInitAllocatorForExpHeap(struct S02061358 *s, u32 a, u32 b)
{
    s->unk0 = (u32)g_020A1708;
    s->unkC = 0;
    s->unk4 = a;
    s->unk8 = b;
}

int NNS_G2dStubReturnZeroA(void)  { return 0; }
int NNS_G2dStubReturnMinusOneA(void)  { return -1; }
int NNS_G2dStubReturnZeroB(void)  { return 0; }
int NNS_G2dStubReturnMinusOneB(void)  { return -1; }
