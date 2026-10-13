/*
 * function: func_020627F0
 * address:  0x020627F0
 * packet:   pkt_020627F0
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned short u16;
typedef signed short s16;

struct CellData {
    u16 numOam;
    u16 cellAttr;
    void *oam;
};

struct CellDataEx {
    u16 numOam;
    u16 cellAttr;
    void *oam;
    s16 t, l, b, r;
};

struct CellDataBank {
    u16 numCells;
    u16 bankAttr;
    void *cells;
};

void *func_020627F0(struct CellDataBank *bank)
{
    if (bank->bankAttr & 1) {
        return (struct CellDataEx *)bank->cells + bank->numCells;
    } else {
        return (struct CellData *)bank->cells + bank->numCells;
    }
}
