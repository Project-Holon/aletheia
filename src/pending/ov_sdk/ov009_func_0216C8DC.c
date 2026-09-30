/*
 * function: func_0216C8DC
 * address:  0x0216C8DC
 * packet:   pkt_0216C8DC
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF   (parked; not EXACT/MATCH)
 *
 * DWC_AddMatchKeyInt (dwc_match.o): resolve/create the match-key slot at
 * 0x021AAA40 (12-byte stride: f0 key id, f1 flag, f2 u16, f4 string ptr,
 * f8 int), free the old string, strdup the new one and record the int.
 *
 * BLOCKER (codegen only, size correct at 296): the whole body is logically
 * right but mwcc allocates the three parameters differently -- original
 * keeps a0=r7, a1=r6, a2=r5 with the index in r4 and rematerialises a zero
 * into r2; this front end hoists a zero into r4 and maps a0=r8, a1=r7,
 * a2=r6 with the index in r5.  Every branch target and constant is right;
 * only the register file assignment differs.  Not a witness problem.
 *
 * lane U22 (2026-09-30): one CONCRETE byte is wrong in the draft, not just
 * registers.  The image's first key test is +0020 `cmp r7,#0x64; blo` --
 * cond 0x3 (unsigned LO, word 0F 00 00 3A) -- while the parked `a0 >= 0x64`
 * on a signed int emits cond 0xB (`blt`, word 0F 00 00 BA).  Spelling the
 * guard `(unsigned)a0 >= 0x64u` produces the image's word, so the original
 * keys off an unsigned comparison.  The rest is the +1 register roll: ours
 * materialises a shared zero into the callee-saved r4 at +0014 (the image
 * rematerialises `mov r2,#0` at the stores) and that live zero pushes
 * keyID->r8, keyString->r7, valueSrc->r6 with index->r5, against the image's
 * r7/r6/r5 with index->r4.  Measured and not moving the roll: u8 return and
 * u8 params, int* valueSrc, inline indexing (`g[a0-0x64]`), unsigned index,
 * `(u8)0`/`(u16)0` typed zero stores, swap of the two zero stores, zero
 * stores before the f0 store, decl order.  The hoisted zero is the only
 * thing standing between the draft and EXACT on this row and its twin
 * 0x0216CA04.
 *
 * symbols:
 *   g_021AAA40     0x021AAA40  data  ov009
 *   func_02173AD8  0x02173AD8  arm  ov009
 *   func_020948E0  0x020948E0  arm
 *   func_0205A1B0  0x0205A1B0  arm
 *   func_0209477C  0x0209477C  arm
 *   func_0205A16C  0x0205A16C  arm
 *   func_02094798  0x02094798  arm
 *   func_0216EB68  0x0216EB68  arm  ov009
 *   func_0219D158  0x0219D158  arm  ov009
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Key {
    u8  f0;
    u8  f1;
    u16 f2;
    u32 f4;
    u32 f8;
};

extern struct Key g_021AAA40[];
extern int  func_02173AD8(void);
extern int  func_020948E0(u32 p);
extern void func_0205A1B0(int a0);
extern int  func_0209477C(char *s);
extern void *func_0205A16C(int a0, int a1);
extern void func_02094798(void *dst, char *src);
extern void func_0216EB68(int a0, int a1);
extern void func_0219D158(int a0, void *a1);

int func_0216C8DC(int a0, char *a1, int a2)
{
    int i;

    if (a1 == 0 || a2 == 0)
        return 0;

    if (a0 >= 0x64 && g_021AAA40[a0 - 0x64].f0 != 0) {
        if (g_021AAA40[a0 - 0x64].f4 != 0 &&
            func_020948E0(g_021AAA40[a0 - 0x64].f4) != 0)
            return 0;
    } else {
        a0 = func_02173AD8();
        if (a0 == 0)
            return 0;
    }

    i = a0 - 0x64;
    g_021AAA40[i].f0 = a0;
    g_021AAA40[i].f1 = 0;
    g_021AAA40[i].f2 = 0;
    if (g_021AAA40[i].f4 != 0)
        func_0205A1B0(4);
    g_021AAA40[i].f4 = (u32)func_0205A16C(4, func_0209477C(a1) + 1);
    if (g_021AAA40[i].f4 == 0) {
        func_0216EB68(9, (int)0xFFFEC77F);
        return 0;
    }
    func_02094798((void *)g_021AAA40[i].f4, a1);
    g_021AAA40[i].f8 = a2;
    func_0219D158(a0, (void *)g_021AAA40[i].f4);
    return a0;
}
