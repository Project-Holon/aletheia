/*
 * function: func_021DFF40
 * address: 0x021DFF40
 * packet: pkt_ov093_021DFF40
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DFCE8.c and filed here.
 *
 * symbols:
 *   d_021F1874 0x021F1874 data ov093 a4
 */

int *func_021DFF40(int *p);

/* 021DFF4C  stack-arg wrapper: func_021E0284(a, b, c, d, 0xc) */
extern int d_021F1874[];

/*
 * 2026-10-02: the 02045CAC/0201F250/021E0FF4 statements are repeated in both arms of
 *  the 0x11EE test (the compiler tail-merges them), which keeps the 0x834 and 0x724
 *  constants live into the merged tail.
 */
int *func_021DFF40(int *p)
{
    *p = 3;
    return d_021F1874;
}
