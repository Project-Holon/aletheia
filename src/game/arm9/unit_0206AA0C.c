/*
 * file:     unit_0206AA0C.c
 * unit:     yes
 * function: func_0206AA0C, func_0206AA3C
 * address:  0x0206AA0C
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
 *   g_02148B4C       0x02148B4C  data
 *   g_02148BCC       0x02148BCC  data
 */
typedef unsigned int u32;

typedef struct {
    u32 a;
    u32 b;
    u32 c;
} Rec0206AA0C;

void func_0206AA0C(Rec0206AA0C *p);
void func_0206AA3C(int idx, int a, int b, int c);
extern u32 g_02148B4C[];
extern u32 g_02148BCC[];


/*
 * Copies the caller's three-word record into the block at 0x02148C38 and
 * clears the 0xa4 bit pair of the flag word at 0x02148B4C + 0xFC.
 *
 * The destination is spelled as one object with the flag word (0x02148C38 is
 * g_02148B4C + 0xEC) because that is what decides the schedule: with the two
 * addresses as separate objects the compiler hoists the flag-word load above
 * the store and needs a second pool register (`push {r3, lr}`, 52 bytes); as
 * one object every access is ordered behind the 12-byte copy and the leaf
 * comes out at the original 48 bytes with `ldr r3/r0, [pc]` twice.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206AA0C.c \
 *       --func func_0206AA0C --addr 0x0206AA0C --cc 1.1p1 --arm
 */
void func_0206AA0C(Rec0206AA0C *p)
{
    if (p == 0) {
        return;
    }
    *(Rec0206AA0C *)(g_02148B4C + 0x3b) = *p;
    g_02148B4C[0x3f] &= ~0xa4u;
}


/*
 * Packs three 10-bit fields (each taken from a signed value shifted right by
 * three) plus the slot index at bits 30..31 into one word of g_02148BCC.
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206AA3C.c \
 *       --func func_0206AA3C --addr 0x0206AA3C --cc 1.1p1 --arm
 */
void func_0206AA3C(int idx, int a, int b, int c)
{
    g_02148BCC[idx] = (u32)(((a >> 3) & 0x3FF) | (((b >> 3) & 0x3FF) << 10)
                            | (((c >> 3) & 0x3FF) << 20) | (idx << 30));
}
