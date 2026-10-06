/*
 * file:     time_icon_p08.c
 * unit:     yes
 * function: func_0202F47C, func_0202F488
 * address:  0x0202F47C
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
 *   func_02017E64  0x02017E64  thumb
 */
typedef unsigned int u32;

extern void func_02017E64(void *p, u32 id, u32 v);
void func_0202F47C(void *p);
int func_0202F488(int a0, int a1);


/*
 * note:     unlabelled 12-byte Thumb leaf (a tail call through a pool word
 *           to func_02017E64 with id 0x77, value 0x15) after func_0202F464;
 *           filed as the witness for func_0202F1B4's call at +0x58, the
 *           only branch to it image-wide.  Needs a seed in
 *           layout/function_starts.txt.
 */
void func_0202F47C(void *p)
{
    func_02017E64(p, 0x77, 0x15);
}

int func_0202F488(int a0, int a1){ int t0 = func_020185F0(); int t1 = func_0202F498((int)t0, (int)((a1 + 0) + 0)); return t1; }
