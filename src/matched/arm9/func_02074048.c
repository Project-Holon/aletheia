/*
 * function: NNSi_SndArcLoadTables
 * address:  0x02074048
 * packet:   pkt_020737C0
 * status:   EXACT
 * isa:      arm
 * compiler: ../2.0/sp2
 * symbols:
 *   func_02078B44  0x02078B44  arm
 *   FS_ReadFile  0x02078B70  arm
 *   NNS_SndHeapAlloc  0x0207482C  arm
 *   NNSi_SndArcDisposeInfo  0x020746C4  arm
 *   NNSi_SndArcDisposeFat  0x020746D0  arm
 *   NNSi_SndArcDisposeSymbol  0x020746DC  arm
 *
 * The archive header load: seek to 0 and read the 0x30-byte header over the
 * object itself, then (only with a heap) allocate and read the three tables
 * the header names -- (+0x18 offset, +0x1c size) into +0x90, (+0x20, +0x24)
 * into +0x88, and, when `all` is set and +0x14 is non-zero, (+0x10, +0x14)
 * into +0x8c.  Each allocation goes through NNS_SndHeapAlloc with a 12-byte
 * release callback (NNSi_SndArcDisposeInfo / D0 / DC, filed EXACT alongside) that
 * nulls the matching pointer.
 *
 * Two levers: the heap test is a wrapping `if (heap != 0) { ... }` so the
 * null case branches to the shared `return 1` (a separate early return is 8
 * bytes long), and each read's result is a named local, which is what puts
 * it in cmp's left slot (docs/idioms/cmp-operand-order-names-the-temporary.md).
 * The listing extent is 472 bytes including the three-word pool.
 */
typedef unsigned char u8;
typedef unsigned int  u32;

struct Arc {
    u8  pad_00[0x10];
    u32 f10_off;
    u32 f14_size;
    u32 f18_off;
    u32 f1c_size;
    u32 f20_off;
    u32 f24_size;
    u8  pad_28[0x0c];
    u8  f34_file[0x48];
    u8  pad_7c[0x0c];
    void *f88;
    void *f8c;
    void *f90;
};

extern int   func_02078B44(void *file, u32 pos, int origin);
extern int   FS_ReadFile(void *file, void *dst, int len);
extern void *NNS_SndHeapAlloc(u32 *heap, u32 size, void (*cb)(void *, u32, struct Arc *),
                           struct Arc *c, u32 e);
extern void  NNSi_SndArcDisposeInfo(void *payload, u32 size, struct Arc *c);
extern void  NNSi_SndArcDisposeFat(void *payload, u32 size, struct Arc *c);
extern void  NNSi_SndArcDisposeSymbol(void *payload, u32 size, struct Arc *c);

u32 NNSi_SndArcLoadTables(struct Arc *c, u32 *heap, u32 all)
{
    int n;

    if (func_02078B44(c->f34_file, 0, 0) == 0) return 0;
    if (FS_ReadFile(c->f34_file, c, 0x30) != 0x30) return 0;
    if (heap != 0) {
        c->f90 = NNS_SndHeapAlloc(heap, c->f1c_size, NNSi_SndArcDisposeInfo, c, 0);
        if (c->f90 == 0) return 0;
        if (func_02078B44(c->f34_file, c->f18_off, 0) == 0) return 0;
        n = FS_ReadFile(c->f34_file, c->f90, c->f1c_size);
        if (n != c->f1c_size) return 0;

        c->f88 = NNS_SndHeapAlloc(heap, c->f24_size, NNSi_SndArcDisposeFat, c, 0);
        if (c->f88 == 0) return 0;
        if (func_02078B44(c->f34_file, c->f20_off, 0) == 0) return 0;
        n = FS_ReadFile(c->f34_file, c->f88, c->f24_size);
        if (n != c->f24_size) return 0;

        if (all != 0 && c->f14_size != 0) {
            c->f8c = NNS_SndHeapAlloc(heap, c->f14_size, NNSi_SndArcDisposeSymbol, c, 0);
            if (c->f8c == 0) return 0;
            if (func_02078B44(c->f34_file, c->f10_off, 0) == 0) return 0;
            n = FS_ReadFile(c->f34_file, c->f8c, c->f14_size);
            if (n != c->f14_size) return 0;
        }
    }
    return 1;
}
