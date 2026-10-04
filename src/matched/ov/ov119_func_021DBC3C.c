/*
 * function: func_021DBC3C
 * address: 0x021DBC3C
 * packet: pkt_ov119_021DBC3C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8AA8 0x021D8AA8 thumb ov119
 *   func_021DD5B4 0x021DD5B4 thumb ov119
 *   func_021DB0A0 0x021DB0A0 thumb ov119
 *   func_021D8B38 0x021D8B38 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DBE70 0x021DBE70 thumb ov119
 */
#include "../include/Obj00001.h"
extern int func_021D8AA8(void *);
extern int func_021DD5B4(char *p, int a, int b);
extern int func_021DB0A0(char *p);
extern void func_021D8B38(char *p);
extern void func_021D8E84(void *,int);
extern void func_021DBE70(char *p);
void func_021DBC3C(char *p) {
 if(func_021D8AA8(p)) { if(func_021DD5B4(p,((struct Obj00001 *)p)->fF84,((struct Obj00001 *)p)->fF88)==0) return; }
 else { if(func_021DB0A0(p)==0) return; }
 ((struct Obj00001 *)p)->fF98=-1; ((struct Obj00001 *)p)->fF94=-1;
 ((struct Obj00001 *)p)->fF7C=-1; ((struct Obj00001 *)p)->fF80=-1;
 func_021D8B38(p); func_021D8E84(p,(int)func_021DBE70);
}
