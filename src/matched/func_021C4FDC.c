/*
 * function: func_021C4FDC
 * address:  0x021C4FDC
 * packet:   pkt_021C4FDC
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)

 * Releases the file and the two allocations held in the 0x10-byte records.
 */


extern void func_02014CD4(int);
extern void func_02014BA8(int);
extern void func_02030DA4(int);
extern void func_020307B0(int);

typedef struct {
    int a;
    int b;
    int c;
    int d;
} T;

void func_021C4FDC(int unused, T *p)
{
    func_02014CD4(p[0].c);
    func_02014BA8(p[0].c);
    func_02030DA4(p[0x12].a);
    func_020307B0(p[0x11].d);
}

