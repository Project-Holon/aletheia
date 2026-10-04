/*
 * function: func_021B9AAC
 * address:  0x021B9AAC
 * packet:   pkt_ov070_021B9AAC
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B97E8  0x021B97E8  thumb  ov070
 *   func_020456F8  0x020456F8  arm
 *   func_0204B3DC  0x0204B3DC  arm
 */

extern void func_021B97E8(char *, int);
extern void func_020456F8(int);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);

void func_021B9AAC(char *p)
{
    unsigned i;
    unsigned j;
    func_021B97E8(p, 0);
    func_020456F8(*(int *)(p + 0x734));
    for (i = 0; i < 3; i++) {
        func_0204B3DC((struct Obj *)*(int *)(p + i * 4 + 0x6C0), 0);
    }
    for (j = 0; j < 0x11; j++) {
        func_0204B3DC((struct Obj *)*(int *)(p + j * 4 + 0x6CC), 0);
    }
}
