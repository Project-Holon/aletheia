/*
 * function: DWCi_BTNlEnd
 * address:  0x021BCAE4
 * packet:   pkt_ov016_021BCAE4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   MemBtn                           0x021DE508  data
 *   taskEnd                          0x021BCE7C  arm
 *   DWCi_TSKlChangeFunc              0x021D771C  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(button.o), symbol DWCi_BTNlEnd (name and prototype from
 * the vendor object DWARF). Callee of endScene (sceneoptmovconfi). The object is stamped
 * Metrowerks C/C++ for ARM 4.0.0.1025, which no tools/mwccarm build writes, so 1.1p1.
 */

struct MEMBTN {
    char pad[0xc];
    int f0C;
    char pad2[9];
    unsigned char f19;
};

extern struct MEMBTN *MemBtn;
extern void DWCi_TSKlChangeFunc(int prm, void (*fn)(void *));

static void taskEnd(void *task);

void DWCi_BTNlEnd(void)
{
    MemBtn->f19 = 1;
    DWCi_TSKlChangeFunc(MemBtn->f0C, taskEnd);
}
