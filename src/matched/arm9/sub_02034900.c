/*
 * function: sub_02034900
 * address:  0x02034900
 * packet:   pkt_02034734
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   G2_GetBG0ScrPtr   0x0207DF60  arm
 *   func_020437D4     0x020437D4  arm
 *   DC_FlushRange     0x020862F0  arm
 *   GXS_LoadBG0Char   0x0207EE68  arm
 *   OS_Terminate      0x02088234  arm
 *   unk_021469AC      0x021469AC  data
 *
 * The third of the three default assert handlers sub_02034978 registers:
 * the die handler.  It fills the main BG0 screen map with the identity
 * mapping (256 tiles laid out 32 per row over 8 rows, the counter running
 * straight through both loops rather than restarting per row), uploads the
 * 0x2000 byte font character data the object at 0x021469AC owns to the sub
 * screen, and stops the machine.
 *
 * The row stride is written as `p += 0x20` on a `u16 *`, which is the
 * `add r0, r0, #0x40` at the bottom of the outer loop; the inner index is a
 * plain subscript, hence `lsl r1, r3, #1` per store rather than a walking
 * pointer.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02034900.c \
 *       --func sub_02034900 --addr 0x02034900 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void *unk_021469AC;

extern u16 *G2_GetBG0ScrPtr(void);
struct Bmp;
extern void *func_020437D4(const struct Bmp *bmp);
extern void DC_FlushRange(void *addr, u32 size);
extern void GXS_LoadBG0Char(const void *src, u32 offset, u32 size);
extern void OS_Terminate(void);

void sub_02034900(void)
{
    u16 *p;
    int j;
    int i;
    int n;
    void *src;

    p = G2_GetBG0ScrPtr();

    n = 0;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 0x20; j++) {
            p[j] = n;
            n++;
        }
        p += 0x20;
    }

    src = func_020437D4(unk_021469AC);
    DC_FlushRange(src, 0x2000);
    GXS_LoadBG0Char(src, 0, 0x2000);
    OS_Terminate();
}
