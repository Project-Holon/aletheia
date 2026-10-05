/*
 * function: func_02168CF4
 * address: 0x02168CF4
 * packet: pkt_ov010_02168CF4
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * recoup 2026-10-05 (P21L10): extent 60 B includes a 2-byte pad (movs r0,r0); code is 58 B.
 * The old draft (12 B off, only the ldr r2 position and the lsls/adds r6 order) closed by
 * dropping const from the record pointer and the byte-pointer casts: EXACT* in c99 and c.
 * Not filed as matched: the Offset enum local (off = KIND_OFF, then off - 4, off - 8) is only
 * there to stop mwcc folding 0x12c into the load offsets. With int k or a plain int typedef,
 * literals, struct fields or a named kind local the compiler folds to a 0x49 base (40 B off).
 * A human reason for the held 0x12c is not known; integrator decides. Callee func_021681C8
 * has u8 kind/n params in the ov021 twin caller but this caller passes full words (no
 * truncation), so the prototype here is int. pragmas scheduling/peephole/opt_lifetimes off:
 * no change on the old const form (12 B). unsigned kind: 15 B.
 * symbols:
 *   func_0201210C 0x0201210C thumb
 *   func_021681C8 0x021681C8 thumb ov010
 *   func_0216E910 0x0216E910 thumb ov010
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef enum { KIND_OFF = 0x12c } Offset;
typedef struct {
    u8 pad[0x124];
    int count;
    void *save;
    Offset kind;
} Record;
extern void *func_0201210C(void *);
extern void *func_021681C8(void *, void *, int, const void *, const void *, int);
extern int func_0216E910(void *, void *, void *);
int func_02168CF4(void *a, Record *p)
{
    void *b;
    Offset kind;
    Offset off;
    b = func_0201210C(a);
    off = KIND_OFF;
    kind = (Offset)*(int *)((u8 *)p + off);
    return func_0216E910(a, b, func_021681C8(a, *(void *const *)((u8 *)p + (off - 4)), kind, p, 0, *(int *)((u8 *)p + (off - 8))));
}
