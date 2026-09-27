/*
 * function: func_02008450
 * address:  0x02008450
 * packet:   pkt_02012BC8
 * region:   arm9
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Setter for bit 10 of a u16 flag word; func_02008448 (EXACT*, the four
 * bytes before it) is the matching getter.  An unlabelled leaf: it saves
 * no lr, so disasm.py never gave it a label, and its only reference in the
 * image is the tail-call pool word in func_02012BC8.  Filed as a compiled
 * witness for that call (class `matched`); wants seeding into
 * layout/function_starts.txt.
 */

typedef unsigned short u16;

struct Flags02008450 {
    u16 lo   : 10;
    u16 flag : 1;
    u16 hi   : 5;
};

void func_02008450(struct Flags02008450 *p, int on)
{
    p->flag = (u16)on;
}
