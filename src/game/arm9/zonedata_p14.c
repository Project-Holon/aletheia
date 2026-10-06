/*
 * file:     zonedata_p14.c
 * unit:     yes
 * function: func_020144DC, func_0201450C, func_02014554
 * address:  0x020144DC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02188BD8  0x02188BD8  thumb  ov021
 *   func_0215FA44  0x0215FA44  thumb  ov010
 */
#include "../../matched/include/Obj06860.h"
#include "../../matched/include/Obj06862.h"

struct BigObj;
struct Ctx;
typedef unsigned int   u32;

typedef unsigned char  u8;

extern unsigned int func_02012A30(const struct BigObj *v);
extern void func_02188BD8(u8 *obj);
extern u32 func_020120F0(const struct Ctx *p);
extern void func_0215FA44(void);
int func_020144DC(int a0, int a1);
int func_0201450C(int a0, int *a1, int *a2);
int func_02014554(int a0, int a1);


int func_020144DC(int a0, int a1){ int t0, t1, t2; t0 = func_020122C0((int)a0, (int)0, (int)0x2014489, (int)0x10); t1 = func_020124E8((int)t0); ((struct Obj06860 *)((char *)((t1 + 0))))->f0 = (int)(a0 + 0); ((struct Obj06860 *)((char *)((t1 + 0))))->f4 = (int)(a1 + 0); t2 = func_020120F4((int)((a0 + 0) + 0)); ((struct Obj06860 *)((char *)((t1 + 0))))->f8 = (int)t2; ((struct Obj06860 *)((char *)((t1 + 0))))->fC = (int)1; return ((t0 + 0) + 0); }


/*
 * promoted: seed round 9, EXACT (fresh match.py one) once the ov010 callees
 *           0x0215FA34 and 0x0215FA44 were seeded in layout/function_starts.txt
 * note:     re-verified 2026-09-20: MATCH*; see verify output
 * note:     re-verified 2026-09-22 (family wave 6, field_status.c): still
 *           MATCH*, 2 of 4 sites resolved, no change to the C.  Same two
 *           overlay targets as src/pending/sub_02014488.c, and re-checked
 *           the same way: 0x02188BD8 and 0x0215FA44 are a function start
 *           in none of the overlays whose window covers them, so the
 *           `label` refusal is not an ambiguity a region hint can settle.
 *           listing carries a func_ label at either address; 4 overlays
 *           overlap 0x02188BD8 (ov009, ov021, ov096, ov230) and 2 overlap
 *           0x0215FA44 (ov009, ov010), so `label` refuses to guess.
 *
 * Byte-correct at all 70 bytes; 2 of 4 relocation sites stay wildcarded.
 * Seeded from an arm9 dispatcher (arm9_main calls the same pair at 0x020144A8
 * and 0x020144CE, which is inside the same source unit but outside this
 * compared range - it is still not a label, so it does not attest).
 *
 * This row was screened `ready` by the band brief; it is one of the minority
 * the screen cannot see, because the call targets are overlay exports rather
 * than arm9 or runtime code.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0201450C.c \
 *       --func func_0201450C --addr 0x0201450C --cc 1.1p1 --thumb
 * wave15:   overlay callees are unlabelled Thumb starts: 0x0215FA34 and
 *           0x0215FA44 in ov010 (.word 0x4B024801, ldr r0/ldr r3 thunks),
 *           0x02188BD8 in ov021; need seeds in those overlays' listings.
 */
int func_0201450C(int a0, int *a1, int *a2)
{
    int v7 = a2[0];
    int v6 = a2[1];

    func_02012A30((const struct BigObj *)a2[2]);
    switch (*a1) {
    case 0:
        func_02188BD8((u8 *)v6);
        *a1 = *a1 + 1;
        break;
    case 1:
        if (func_020120F0((const struct Ctx *)v7) == 0) {
            if (a2[3] != 0) {
                func_0215FA44();
            }
            return 1;
        }
        break;
    }
    return 0;
}


int func_02014554(int a0, int a1){ int t0, t1, t2; t0 = func_020122C0((int)a0, (int)0, (int)0x201450D, (int)0x10); t1 = func_020124E8((int)t0); ((struct Obj06862 *)((char *)((t1 + 0))))->f0 = (int)(a0 + 0); ((struct Obj06862 *)((char *)((t1 + 0))))->f4 = (int)(a1 + 0); t2 = func_020120F4((int)((a0 + 0) + 0)); ((struct Obj06862 *)((char *)((t1 + 0))))->f8 = (int)t2; ((struct Obj06862 *)((char *)((t1 + 0))))->fC = (int)0; return ((t0 + 0) + 0); }
