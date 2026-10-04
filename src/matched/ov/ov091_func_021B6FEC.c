/*
 * function: func_021B6FEC
 * address:  0x021B6FEC
 * packet:   pkt_ov091_021B6FEC
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Blocker: func_02061C30 (arm9, unlabelled ARM tail-call stub, Ilias's leaf):
 * `ldr ip,[pc,#4]; ldr r0,[pc,#4]; bx ip; .word 0x02061B5C; .word 0x02146B80`,
 * no witness outside this range.  Leaf C tried (DIFF only, the two loads and
 * the two pool words come out swapped, 8 bytes):
 *   extern void func_02061B5C(void *); extern char d_02146B80[];
 *   void func_02061C30(void) { func_02061B5C(d_02146B80); }
 *   (`return func_02061B5C((int)d_02146B80)` with int types: same DIFF)
 *
 * symbols:
 *   func_02061C30  0x02061C30  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_021B7034  0x021B7034  thumb
 *   func_020403F4  0x020403F4  arm
 *   func_020450C8  0x020450C8  arm
 *   func_0203F9B4  0x0203F9B4  arm
 */

extern void func_02061C30(void);
extern void func_0204A5AC(void);
extern void func_021B7034(int);
typedef unsigned int   u32;
extern void func_020403F4(u32 i);
extern void func_020450C8(void);
extern void func_0203F9B4(void);

void func_021B6FEC(int a)
{
    func_02061C30();
    func_0204A5AC();
    func_021B7034(a);
    func_020403F4(3);
    func_020403F4(2);
    func_020403F4(1);
    func_020403F4(7);
    func_020403F4(6);
    func_020403F4(5);
    func_020403F4(4);
    func_020450C8();
    func_0203F9B4();
}
