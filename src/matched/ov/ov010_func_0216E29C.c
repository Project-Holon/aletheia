/*
 * function: func_0216E29C
 * address:  0x0216E29C
 * packet:   pkt_ov010_0216E29C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (saves no lr, so disasm.py prints it as .word data):
 * a tail call through a pool word, the sole blocker of ov020 func_021857C0.
 *
 * symbols:
 *   func_02048F4C  0x02048F4C  arm
 */

typedef struct Obj {
    char pad[0x44];
    void *f44;
} Obj;

typedef unsigned int   u32;
void func_02048F4C(void *dst, u32 archive_id, u32 member);

void func_0216E29C(Obj *o, int v)
{
    func_02048F4C(o->f44, 0x3a, v);
}
