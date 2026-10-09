/*
 * file:     nhttp_rap_p02.c
 * unit:     yes
 * function: func_021B9B4C, func_021B9B58
 * address:  0x021B9B4C
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02086028  0x02086028  arm
 */
typedef unsigned char u8;

typedef unsigned int u32;

extern void func_02086004(void);
extern void func_02086028(void);
void func_021B9B4C(int *mutex_p);
void func_021B9B58(void);


void func_021B9B4C(int *mutex_p)
{
    func_02086004();
}


/*
 * ARM linker veneer / far tail call: ldr ip,[pc,#0]; bx ip; .word
 * 0x02086028, printed as a .word run by disasm.py at 0x021B9B58 in ov114.
 * Blocker target of func_021BEFCC (pkt_021B9500).
 */
void func_021B9B58(void)
{
    func_02086028();
}
