/*
 * file:     unit_0206A884_p01.c
 * unit:     yes
 * function: func_0206A884
 * address:  0x0206A884
 * packet:   pkt_0206A12C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02148B50       0x02148B50  data
 *   g_02148B98       0x02148B98  data
 *   g_02148BC8       0x02148BC8  data
 *   g_02148B4C       0x02148B4C  data
 *   func_0206DDA4    0x0206DDA4  arm
 *
 * Four registrations against the shared table at 0x02148B50/0x02148B98/
 * 0x02148BC8, the third of them with a one-word out-parameter whose address
 * is taken (hence the 8-byte frame), then the two low bits of the flags word
 * at 0x02148B4C + 0xFC are cleared and bit 1 set.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206A884.c \
 *       --func func_0206A884 --addr 0x0206A884 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern int  g_02148B50[];
extern int  g_02148B98[];
extern int  g_02148BC8[];
extern u32  g_02148B4C[];
extern void func_0206DDA4(u32 cmd, const void *params, u32 n);

/*
 * Four registrations against the shared table at 0x02148B50/0x02148B98/
 * 0x02148BC8, the third of them with a one-word out-parameter whose address
 * is taken (hence the 8-byte frame), then the two low bits of the flags word
 * at 0x02148B4C + 0xFC are cleared and bit 1 set.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206A884.c \
 *       --func func_0206A884 --addr 0x0206A884 --cc 1.1p1 --arm
 */
void func_0206A884(void)
{
    func_0206DDA4(0x1610, g_02148B50, 0x11);
    func_0206DDA4(0x19, g_02148B98, 0xC);
    {
        int v = 2;
        func_0206DDA4(0x10, &v, 1);
    }
    func_0206DDA4(0x15, g_02148BC8, 0x20);
    g_02148B4C[63] = (g_02148B4C[63] & ~1u) | 2;
}
