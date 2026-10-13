/*
 * function: func_021F38E4
 * address:  0x021F38E4
 * packet:   pkt_021F38E4
 * region:   ov052
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call: passes the pointer at offset 0x24 of a to func_020307B0.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned int u32;

struct Obj20567 {
    unsigned char pad_0[36];
    void *f24;
};

extern u32 func_020307B0(void *p);

void func_021F38E4(char *a)
{
    func_020307B0(((struct Obj20567 *)a)->f24);
}
