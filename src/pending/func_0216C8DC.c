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
