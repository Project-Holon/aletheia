/*
 * file:     eventdata_system_p01.c
 * unit:     yes
 * function: func_02161E60, func_02161E78
 * address:  0x02161E60
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021620B0  0x021620B0  thumb  ov010
 *   func_02082BCC  0x02082BCC  arm
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021620B0();
extern void func_02082BCC(void *, unsigned, unsigned);
int func_02161E60(int a0, int a1);
void func_02161E78(void *a0);


int func_02161E60(int a0, int a1)
{

    if (a1 != 0) goto loc_02161E6E;
loc_02161E66:
a0 = a0 + 8;
    a0 = func_021620B0(a0);
loc_02161E6C:
    return a0;
loc_02161E6E:
a0 = a0 + 0xf8;
    a0 = func_021620B0(a0);
loc_02161E74:
    return a0;}


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_02082BCC, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02161E78.c \
 *       --func func_02161E78 --addr 0x02161E78 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_02161E78(void *a0)
{

    func_02082BCC(a0, 0, 24);
}
