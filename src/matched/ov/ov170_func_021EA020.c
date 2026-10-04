/*
 * function: func_021EA020
 * address:  0x021EA020
 * packet:   pkt_ov170_021EA020
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EC768 0x021EC768 thumb
 *   func_021ED588 0x021ED588 thumb
 *   func_021EF534 0x021EF534 thumb
 *   func_021E8FE0 0x021E8FE0 thumb
 *   func_021E8FC0 0x021E8FC0 thumb
 *   func_021E070C 0x021E070C thumb
 */

struct WinMgr;
extern void func_021EC768(char *p, unsigned i, int flag);
extern void func_021ED588(char *p);
extern void func_021EF534(struct WinMgr *mgr);
extern int func_021E8FE0(char *p, int v);
extern int func_021E8FC0(char *p, int a, int b);
extern int func_021E070C(char *p);

#define WORK(p) (*(char **)((p) + 0x2C))

void func_021EA020(char *p, unsigned char i, int v)
{
    p[0x16] = i;
    *(unsigned char *)(WORK(p) + 0xA172) = 1;
    func_021EC768(WORK(p), (unsigned char)p[0x16], 1);
    func_021ED588(p);
    func_021EF534(*(struct WinMgr **)(WORK(p) + 0x74));
    func_021E8FC0(p, (int)func_021E070C, func_021E8FE0(p, v));
}
