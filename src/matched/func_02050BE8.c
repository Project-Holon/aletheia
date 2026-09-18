/*
 * function: func_02050BE8
 * address:  0x02050BE8
 * packet:   pkt_02050340
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050BE8.c \
 *       --func func_02050BE8 --addr 0x02050BE8 --cc 1.1p1 --arm
 */

extern int func_02051504(void);
extern int func_02051534(void);
extern int func_02051574(void);

void func_02050BE8(void)
{
    if (func_02051504() == 0)
        return;
    func_02051534();
    func_02051574();
}
