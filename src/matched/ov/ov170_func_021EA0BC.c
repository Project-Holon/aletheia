/*
 * function: func_021EA0BC
 * address:  0x021EA0BC
 * packet:   pkt_ov170_021EA0BC
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EC768 0x021EC768 thumb
 *   func_021ED594 0x021ED594 thumb
 *   func_021EE038 0x021EE038 thumb
 *   func_021EF680 0x021EF680 thumb
 *   func_021EF69C 0x021EF69C thumb
 *   func_02026124 0x02026124 thumb
 *   func_021E8FC0 0x021E8FC0 thumb
 *   func_021E0778 0x021E0778 thumb
 */
#include "../include/Obj00000.h"

typedef struct {
    int pad[9];
    int x24;
} Top;

extern void func_021EC768(char *p, unsigned i, int flag);
extern void func_021ED594(char *p, unsigned i);
extern void func_021EE038(char *p, int a, int b, int c);
extern void func_021EF680(char *w);
extern void func_021EF69C(char *w);
typedef unsigned int   u32;
struct Sound;
extern void func_02026124(struct Sound *obj, u32 idx);
extern int func_021E8FC0(char *p, int a, int b);
extern int func_021E0778(unsigned char *p);

#define WORK(p) (*(char **)((p) + 0x2C))

void func_021EA0BC(unsigned char *p, unsigned char i)
{
    p[0x18] = 1;
    p[0x16] = i;
    func_021EC768(WORK(p), 0x24, 0);
    func_021ED594((char *)p, 0x24);
    func_021EE038((char *)p, 2, 1, 0);
    if ((*(Top * *)&((struct Obj00000 *)p)->f0)->x24 == 4) {
        func_021EF680(WORK(p));
        func_021EF69C(WORK(p));
        func_02026124(*(void **)(WORK(p) + 0x70), 0x27);
    }
    func_021E8FC0((char *)p, (int)func_021E0778, 0x20);
}
