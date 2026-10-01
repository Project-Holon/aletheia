/*
 * function: func_02184470
 * address: 0x02184470
 * packet: pkt_ov219_02184470
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 28604 legacy trailing three inputs neither read nor forwarded:
 * full body, 437AC and307B0 targets use only incoming r0; caller sets only r0.
 * ED04 legacy void leaves307B0 result live in r0 for following845A4 input;
 * preserve that return.306F0 caller explicitly truncates heap input to u16.
 * symbols:
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_02040588 0x02040588 arm
 *   func_0204363C 0x0204363C arm
 *   func_02028604 0x02028604 thumb
 *   func_02031140 0x02031140 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_021845A4 0x021845A4 thumb ov219
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 */
typedef unsigned short u16;
struct PrintSys;struct S02031140;struct S020315D4;struct WordSet;
extern void func_0201C6EC(struct PrintSys *),func_0201C4C0(struct PrintSys *);
extern void func_02040588(unsigned,unsigned),func_0204363C(unsigned);
extern int func_02028604(int);
extern void func_02031140(struct S02031140 *);
extern unsigned func_0201ED04(struct WordSet *);
extern void func_021845A4(int),func_020315D4(struct S020315D4 *),func_020306F0(u16);
int func_02184470(struct S020315D4 *controller,void *unused1,void *unused2,char *p)
{
    unsigned heap=*(unsigned *)p;
    func_0201C6EC(*(struct PrintSys **)(p+0xc080));
    func_0201C4C0(*(struct PrintSys **)(p+0xc080));
    func_02040588(6,0);func_02040588(2,0);func_02040588(7,0);func_02040588(3,0);
    func_0204363C(1);
    func_02028604(*(int *)(p+0xc088));
    func_02031140(*(struct S02031140 **)(p+0xc0a4));
    func_021845A4(func_0201ED04(*(struct WordSet **)(p+0xc0a8)));
    func_020315D4(controller);func_020306F0(heap);
    return 1;
}
