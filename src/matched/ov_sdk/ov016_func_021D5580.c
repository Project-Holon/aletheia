/*
 * function: DWCi_EFFlCheck
 * address:  0x021D5580
 * packet:   pkt_ov016_021D5580
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   MemEffect                        0x021DE67C  data
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(effect.o), symbol DWCi_EFFlCheck (name and prototype
 * from the vendor object DWARF). Callee of DWCi_SceneOptMovConfirm/endScene chains.
 * The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which no tools/mwccarm
 * build writes, so it stays on default 1.1p1.
 */
typedef _Bool bool;

struct EFFPRM {
    char pad[9];
    bool f9;
    char pad2[2];
};

struct MEMEFFECT {
    struct EFFPRM param[2];
};

extern struct MEMEFFECT *MemEffect;

bool DWCi_EFFlCheck(int lcd)
{
    struct EFFPRM *p;

    if (lcd == 1)
        p = &MemEffect->param[0];
    else
        p = &MemEffect->param[1];
    return p->f9;
}
