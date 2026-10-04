/*
 * function: func_021DEFF8
 * address: 0x021DEFF8
 * packet: pkt_ov170_021DEFF8
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: final two bytes are zero alignment padding.
 * symbols:
 *   func_021DD2D0 0x021DD2D0 thumb ov170
 *   func_02017DBC 0x02017DBC thumb
 *   func_021DEDD8 0x021DEDD8 thumb ov170
 *   func_021ECCCC 0x021ECCCC thumb ov170
 *   func_021ED028 0x021ED028 thumb ov170
 *   func_021EB2A4 0x021EB2A4 thumb ov170
 *   func_021DEF58 0x021DEF58 thumb ov170
 *   func_02017DE4 0x02017DE4 thumb
 */
#include "../include/Obj00000.h"
extern int func_021DD2D0(void ***p, int a, unsigned b);
typedef unsigned int   u32;
struct Sav;
extern u32 func_02017DBC(struct Sav *p);
extern void *func_021DEDD8(void *p);
extern void func_021ECCCC(char *p, void **mon, int index);
extern void func_021ED028(char *p, unsigned char *q);
extern void func_021EB2A4(char *p, void *s);
extern void func_021DEF58(void *s);
extern u32 func_02017DE4(struct Sav *p, u32 f);
void func_021DEFF8(char *p, unsigned b)
{
    void *mon;
    void *s;
    int state;
    mon = (void *)func_021DD2D0((void ***)p, ((struct Obj00000 *)p)->f14, b);
    state = func_02017DBC(mon);
    s = func_021DEDD8(mon);
    func_021ECCCC(p, s, 11);
    func_021ED028(((struct Obj00000 *)p)->f2C, s);
    func_021EB2A4(p, s);
    func_021DEF58(s);
    func_02017DE4(mon, state);
}
