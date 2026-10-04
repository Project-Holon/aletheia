/*
 * function: func_0215AD7C
 * address:  0x0215AD7C
 * packet:   pkt_ov010_0215AD7C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * blocker:  byte-correct (80/80, MATCH*). The bl at +003C to 0x02014184 is
 * unresolved: 0x02014184 is an unlabelled Thumb leaf in the ARM9 image (a
 * 64-byte run that disasm.py prints as ARM junk, no func_ label) with one
 * caller image-wide, so label / sole-ref/code refuse it. evidence class:
 * label / sole-ref/code (target not a traced function start).
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AA0  0x02012AA0  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02012AE4  0x02012AE4  thumb
 *   func_02014184  0x02014184  thumb
 *   func_0201289C  0x0201289C  thumb
 */

typedef struct {
    int w[7];
} V28;

extern int func_0215A5E4(int);
extern int func_020127A4(void);
extern int *func_02012AA0(void);
extern int func_02012AC8(int);
extern int func_02012AE4(int);
extern void func_02014184(V28 *, int, short, int, int, int);
extern void func_0201289C(int, V28 *);

int func_0215AD7C(int a, int b)
{
    V28 v;
    int t = func_0215A5E4(b);
    int r5 = func_020127A4();
    int *r4 = func_02012AA0();
    int r7 = func_02012AC8(r5);

    func_02014184(&v, r7, func_02012AE4(r5), r4[0], r4[1], r4[2]);
    func_0201289C(t, &v);
    return 0;
}
