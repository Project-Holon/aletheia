/*
 * file:     unit_0206AA78.c
 * unit:     yes
 * function: func_0206AA78, func_0206AA8C, func_0206AAB0
 * address:  0x0206AA78
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_02148BF4       0x02148BF4  data
 *   g_02148B4C       0x02148B4C  data
 */
typedef unsigned int u32;

void func_0206AA78(int idx, u32 v);
void func_0206AA8C(u32 v, u32 bits, u32 flag);
void func_0206AAB0(u32 v, u32 bits, u32 flag);
extern u32 g_02148BF4[];
extern u32 g_02148B4C[];



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206AA78.c \
 *       --func func_0206AA78 --addr 0x0206AA78 --cc 1.1p1 --arm
 */
void func_0206AA78(int idx, u32 v)
{
    g_02148BF4[idx] = v | (u32)(idx << 30);
}



/*
 * Unlabelled leaf: no prologue, so disasm.py never traced it and it sits in
 * the 76-byte gap between func_0206AA78 and func_0206AAD4, between two of the
 * flags object's literal pools.  Packs a 16-bit field, a one-bit flag at bit
 * 15 and a 16-bit payload into the word at 0x02148B4C + 0x94.
 *
 * Extent note: the follower at 0x0206AAB0 is unlabelled too, so the listing's
 * inferred extent for this address runs to the next label at 0x0206AAD4 and
 * the verdict is EXACT*.  Both addresses are reported for
 * layout/function_starts.txt rather than edited in.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206AA8C.c \
 *       --func func_0206AA8C --addr 0x0206AA8C --cc 1.1p1 --arm
 */
void func_0206AA8C(u32 v, u32 bits, u32 flag)
{
    g_02148B4C[0x25] = v | (bits << 16) | ((u32)(flag != 0) << 15);
}


/*
 * The +0x98 twin of func_0206AA8C, same unlabelled-leaf shape in the same
 * gap, same packing (field, one-bit flag at bit 15, payload).
 *
 * Extent note: the listing's inferred extent for this address runs to the
 * next label at 0x0206AAD4, so the verdict is EXACT*; 0x0206AAB0 joins
 * 0x0206AA8C in the unlabelled-follower report.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206AAB0.c \
 *       --func func_0206AAB0 --addr 0x0206AAB0 --cc 1.1p1 --arm
 */
void func_0206AAB0(u32 v, u32 bits, u32 flag)
{
    g_02148B4C[0x26] = v | (bits << 16) | ((u32)(flag != 0) << 15);
}
