/*
 * unit:     no
 * function: func_0203FC28
 * address:  0x0203FC28
 * packet:   pkt_0203EF5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0207D4B0  0x0207D4B0  arm
 *   func_0207D518  0x0207D518  arm
 *   func_0204349C  0x0204349C  arm
 *   func_02043558  0x02043558  arm
 *
 * TU: bg_sys.c (the initialiser at 0x0203FCA0 is the next function up).
 *
 * Bring the display back up from a saved four-word config block, then clear
 * REG_DISPCNT's two mode fields.  The two clears are separate read-modify-
 * writes in the original, each reloading through the base kept in r1, so
 * they are two statements in the source and not one masked store.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203FC28.c \
 *       --func func_0203FC28 --addr 0x0203FC28 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

#define REG_DISPCNT (*(volatile u32 *)0x04000000)

struct DispConfig {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
};

extern void func_0207D4B0(int dispMode, int bgMode, int bg0_2d3d);
extern void func_0207D518(u32 a);
extern void func_0204349C(void);
extern void func_02043558(void);

void func_0203FC28(struct DispConfig *cfg)
{
    func_0207D4B0(cfg->unk_00, cfg->unk_04, cfg->unk_0c);
    func_0207D518(cfg->unk_08);
    REG_DISPCNT &= ~0x38000000;
    REG_DISPCNT &= ~0x07000000;
    func_0204349C();
    func_02043558();
}
