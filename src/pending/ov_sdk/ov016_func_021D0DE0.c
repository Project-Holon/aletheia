/*
 * function: func_021D0DE0
 * address:  0x021D0DE0
 * packet:   pkt_ov016_021D0DE0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * w9_nm: 148 B object vs 144 B: the object keeps the st != 0 arm as popne / mov / strb / pop, this compile if-converts it (moveq / strbeq). Tried: early-return spellings of the arm (three), the inline setSt helper, a block local, an explicit return after the store: always predicated.
 *
 * lane W7 (2026-09-30): re-measured 144/148, 6/6 relocations, 87 concrete
 * bytes.  The if-conversion is not source-reachable: volatile store, store
 * via a fresh unsigned char*, an `int eq = (prm[0]==2)` local and an inverted
 * else all recompile to the identical predicated `moveq/strbeq` 144 B.  Stays
 * capped on the compiler axis.
 *
 * sdk:      cbWm (libdwcutil.TWL.HYB.a usbap.o)
 *
 * T6: this row matches at -O1 (148 B EXACT in all nine pins) and is 144 B at
 * -O4,p in all nine. The residue is one if-conversion: the object keeps the
 * `st != 0` arm as `cmp r0,#2 / popne {r3,pc} / mov r0,#2 / strb r0,[r1,#0xb94]
 * / pop {r3,pc}`, this build predicates it (`moveq r0,#2 / strbeq`). -O1 is
 * out of scope for the project, so the row is capped on the compiler axis;
 * on the source axis five spellings (early return, store then return, nested
 * braces, goto to one shared set-label, volatile st) all compile to the same
 * predicated 144 B.
 * U26 re-measured: `-O1,p` is EXACT (148/148, 0 diffs) with 1.1p1 and with 1.1/1.2/../2.0/base;
 * `-O4,p` is 144 B / 87.  Object-mate evidence says the object build is -O4,p and not -O1:
 * usbap.o's func_021D0CEC is 220 B / 2 diffs at -O4,p against 228 B / 147 at -O1, and
 * func_021D0E74 is 332 / 286 against 368 / 272.  So the -O1 cell is a coincidence and the row
 * stays capped on the compiler axis (out of scope), as T6 recorded.
 *
 * symbols:
 *   func_021D0FCC  0x021D0FCC  arm  ov016
 *   func_021D0E74  0x021D0E74  arm  ov016
 *   func_021D0CB8  0x021D0CB8  arm  ov016
 *   func_02088234  0x02088234  arm
 *   g_021DE654     0x021DE654  data
 */

extern void func_0208F698();
extern void func_021D0E74(void *prm);
extern void func_021D0FCC(void *prm);
extern void func_021D0CB8(void);
extern void func_02088234(void);
typedef struct { unsigned char pad[0x1B94]; unsigned char st; unsigned char x; unsigned char fl; } M;
extern M *g_021DE654;

static inline void setSt(M *m, int v) { m->st = v; }

void func_021D0DE0(unsigned short *prm)
{
    if (prm[1] != 0)
        return;
    if (g_021DE654->st != 0) {
        if (prm[0] == 2)
            g_021DE654->st = 2;
    } else if (prm[0] == 0x26) {
        switch (prm[4]) {
        case 5:
            if (g_021DE654->fl != 0)
                func_021D0FCC(prm);
            else
                func_021D0E74(prm);
            func_021D0CB8();
            break;
        case 4:
            func_021D0CB8();
            break;
        default:
            func_02088234();
            break;
        }
    }
}
