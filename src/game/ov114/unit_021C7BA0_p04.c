/*
 * file:     unit_021C7BA0_p04.c
 * unit:     yes
 * function: func_021C8E18, func_021C8EB4, func_021C8F2C
 * address:  0x021C8E18
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021D3D28 0x021D3D28 data a4
 *   d_021D3D2C 0x021D3D2C data a4
 *   d_021CF538 0x021CF538 data a4
 *   d_021CF6B8 0x021CF6B8 data a4
 *   d_021D3D40 0x021D3D40 data a4
 *   func_02087C6C 0x02087C6C arm
 *   func_02092344 0x02092344 arm
 *   func_021C9EE4 0x021C9EE4 arm ov114
 *   func_021CA470 0x021CA470 arm ov114
 *   func_021CA1B4 0x021CA1B4 arm ov114
 *   DWC_UpdateConnection  0x0205D074  arm
 *   DWC_ClearError        0x02059F18  arm
 *   d_021D4084 0x021D4084 data a4
 *   d_021D3EFC 0x021D3EFC data a4
 */
#include "../../matched/include/G_Six.h"

typedef struct { unsigned words[114]; unsigned value; } State;

typedef unsigned int u32;

extern void func_02087C6C(void *);
extern void *func_02092344(void *, const void *, unsigned);
extern void func_021C9EE4(int server, char *initdata);
extern int func_021CA470(void *, unsigned, void *, unsigned, unsigned);
extern void func_021CA1B4(void);
extern int DWC_UpdateConnection(void);
extern void DWC_ClearError(void);
void func_021C8E18(unsigned char *p, unsigned x);
int func_021C8EB4(u32 type);
void func_021C8F2C(unsigned a, unsigned b, unsigned c, unsigned mode);
extern void *d_021D3D28;
extern State d_021D3D2C;
extern struct Six d_021D3D40;
extern unsigned d_021CF538[], d_021CF6B8[];
extern unsigned d_021D4084[];
extern unsigned d_021D3EFC;

void func_021C8E18(unsigned char *p, unsigned x)
{
    func_02087C6C(p + 0x1c);
    func_02092344(((unsigned *)&d_021D3D40), p, 100);
    d_021D3D2C.value = x;
    func_021C9EE4((int)d_021D3D28, (char *)d_021CF538);
    if (func_021CA470(d_021CF6B8, d_021D3D2C.words[2], ((unsigned *)&d_021D3D40), 100, 0) == 0) {
        d_021D3D2C.words[0] = 22;
        return;
    }
    d_021D3D2C.words[0] = 24;
    d_021D3D2C.words[1] = -13;
    func_021CA1B4();
}


/*
 * Non-SDK callee of func_021C7C1C (ov114 dependency tree).  Switch on the
 * request kind maps to a DWC result code; DWC_UpdateConnection failing
 * demotes -13 to -14; DWC_ClearError always runs on the non--13 path.
 *
 * Case-order tell: mwcc lays the per-arm stubs down in SOURCE order, so the
 * only spelling that reproduces the image lists case 5 before case 4 even
 * though the jump table is indexed by value.  -15, -14, -13 are the three
 * result codes; the r5==-13 (case 7) path skips both calls entirely.
 */
int func_021C8EB4(u32 type)
{
    int r;

    switch (type) {
    case 0:
    case 1:
    case 2:
        r = -15;
        break;
    case 3:
        r = -14;
        break;
    case 5:
        r = -14;
        break;
    case 4:
        r = -15;
        break;
    case 6:
        r = -14;
        break;
    case 7:
        r = -13;
        break;
    default:
        r = -14;
        break;
    }

    if (r != -13) {
        if (DWC_UpdateConnection() != 0)
            r = -14;
        DWC_ClearError();
    }

    return r;
}

void func_021C8F2C(unsigned a, unsigned b, unsigned c, unsigned mode)
{
    d_021D4084[0] = 1;
    d_021D4084[1] = 0;
    d_021D4084[2] = a;
    d_021D4084[3] = b;
    d_021D4084[4] = c;
    switch (mode) {
    case 0: d_021D3EFC = 0; break;
    case 1: d_021D3EFC = 1; break;
    case 2: d_021D3EFC = 2; break;
    default: d_021D3EFC = 1; break;
    }
}
