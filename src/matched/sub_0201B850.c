/*
 * function: sub_0201B850
 * address:  0x0201B850
 * packet:   pkt_0201B850
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Applies an EV/stat-like gain to party record id 9, scaled by a per-band
 * table the caller supplies.  The species read (id 0xAB) gates the whole
 * body: species 0 and species 650 both return early.
 *
 * The band index `idx` doubles as the literal zero argument of the three
 * func_02017E1C reads, which is why it is a named u8 initialised before the
 * species call rather than three separate `0` literals; and the two
 * increments must be spelled `idx++` (post-increment), not `idx = idx + 1`,
 * or the compiler proves idx is still 0 at the first band test and folds it
 * to `movs r5, #1`, costing the `adds/lsls/lsrs` triple.
 *
 * The function returns void: an `int` return adds a `movs r0, #0` before the
 * epilogue.
 *
 * VERSION SENSITIVITY: 650 is a species id and 0xAB / 6 / 9 / 0x96 / 0x98 are
 * party-record ids; both are content numbering and should be re-read for a
 * White build.  0x35 is the value func_02020FE4 returns for one particular
 * kind and is content numbering too.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/sub_0201B850.c \
 *       --func sub_0201B850 --addr 0x0201B850 --cc 1.1p1 --thumb
 *   python tools/match.py tu --src src/matched/sub_0201B850.c \
 *       --addr 0x0201B850 --thumb
 * symbols:
 *   func_02013E4C   0x02013E4C  thumb
 *   func_02017E1C   0x02017E1C  thumb
 *   func_02017E40   0x02017E40  thumb
 *   func_02020FE4   0x02020FE4  thumb
 *   func_02011014   0x02011014  thumb
 *   _s32_div_f      0x0209C0A4  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;

extern int func_02013E4C(int a0);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32 func_02020FE4(u32 species, u32 a1, u32 a2);
extern int func_02011014(int a0);

void sub_0201B850(void *mon, const s8 *tbl, int a2, u32 a3)
{
    int t;
    u32 species;
    u32 kind;
    int cur;
    int n;
    u8 idx;

    t = func_02013E4C(a2);
    idx = 0;
    species = (u16)func_02017E1C(mon, 0xAB, 0);
    if (species == 0 || species == 650) {
        return;
    }
    kind = (u8)func_02020FE4((u16)func_02017E1C(mon, 6, idx), 1, a3);
    cur = func_02017E1C(mon, 9, idx);

    if (cur >= 100) {
        idx++;
    }
    if (cur >= 200) {
        idx++;
    }
    n = tbl[idx];
    if (n > 0) {
        if (func_02017E1C(mon, 0x98, 0) == 11) {
            n = n + 1;
        }
    }
    if (t != 0 && n > 0) {
        if (t == (int)func_02017E1C(mon, 0x96, 0)) {
            n = n + 1;
        }
    }
    if (n > 0 && kind == 0x35) {
        n = n * 150 / 100;
    }
    cur = cur + func_02011014(n);
    if (cur < 0) {
        cur = 0;
    }
    if (cur > 255) {
        cur = 255;
    }
    func_02017E40(mon, 9, cur);
    return;
}
