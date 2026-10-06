/*
 * function: func_02031C04
 * address:  0x02031C04
 * packet:   pkt_0203195C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02031C04.c \\
 *       --func func_02031C04 --addr 0x02031C04 --arm --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct SaveBackup;
extern void func_02032970(struct SaveBackup *p, u32 flag);
extern void func_020331D0(struct SaveBackup *p);

void func_02031C04(struct SaveBackup *a0)
{
    func_020331D0(a0);
}
