/*
 * function: func_02031B8C
 * address:  0x02031B8C
 * packet:   pkt_0203195C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02031B8C.c \\
 *       --func func_02031B8C --addr 0x02031B8C --arm --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_02032970(u8 *p, u32 v);
struct SaveBackup;
extern void func_020331D0(struct SaveBackup *p);

void func_02031B8C(u8 *p)
{
    if (*(u32 *)(*(u32 *)0x02146994) != 0) {
        func_02032970(p, 1);
    }
}
