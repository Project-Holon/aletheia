/*
 * function: func_0206AD64
 * address:  0x0206AD64
 * packet:   pkt_0206AA78
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  DIFF/SIZE, 100 compiled against 88: the three calls and all five pool words are right, but mwccarm keeps g_02148C7C in a callee-saved register and reuses it for the second and third call (an extra push and twelve bytes); the original re-loads it from its pool word each time.  This is the same address-reload residue as docs/notes/pkt_0206A12C.c.txt records.  Evidence-capped as well: func_0207B60C's only caller in the image is this function, so that call site is its own witness.
 *           function, so the call site is its own witness and the entry can
 *           never reach EXACT.  (Deliberately left parked rather than split:
 *           no cut can help a site whose only witness is the call itself.)
 *
 * symbols:
 *   g_02148C08       0x02148C08  data
 *   g_02148B98       0x02148B98  data
 *   g_02148C7C       0x02148C7C  data
 *   g_02148CAC       0x02148CAC  data
 *   g_02148B4C       0x02148B4C  data
 *   func_0207B9F0    0x0207B9F0  arm
 *   func_0207B60C    0x0207B60C  arm
 *   func_0207B67C    0x0207B67C  arm
 *
 * Builds the 0x02148C7C sub-object: one three-argument constructor call, then
 * a five-argument one that takes three words of the flags object at
 * 0x02148B4C + 0xEC..0xF4 and two pointers to the same block, and finally a
 * two-argument registration call.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0206AD64.c \
 *       --func func_0206AD64 --addr 0x0206AD64 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern char  g_02148C08[];
extern char  g_02148B98[];
extern char  g_02148C7C[];
extern char  g_02148CAC[];
extern u32   g_02148B4C[];
extern void  func_0207B9F0(void *a, void *b, void *c);
extern void  func_0207B60C(void *a, void *b, u32 c, u32 d, u32 e);
extern void  func_0207B67C(void *a, void *b);

void func_0206AD64(void)
{
    func_0207B9F0(g_02148C08, g_02148B98, g_02148C7C);
    func_0207B60C(g_02148C7C, g_02148C7C, g_02148B4C[0x3B], g_02148B4C[0x3C],
                  g_02148B4C[0x3D]);
    func_0207B67C(g_02148C7C, g_02148CAC);
}
