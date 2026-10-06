/*
 * function: func_021BBC68
 * address: 0x021BBC68
 * packet: pkt_ov206_021BBC68
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BB4E0 0x021BB4E0 thumb ov206
 *   func_021BBAB0 0x021BBAB0 thumb ov206
 *   func_021BBDA8 0x021BBDA8 thumb ov206
 *   func_021BACB0 0x021BACB0 thumb ov206
 */
#include "../include/Obj00031.h"
typedef unsigned short u16;
typedef struct S {
    char pad0[8];
    int f8;
    u16 fc;
    u16 fe;
    char pad10[0xd0];
    int fe0;
    char pad[0x190 - 0xe4];
} S;
extern void func_021BB4E0(char *p, int mode, int which);
typedef unsigned int   u32;
extern void func_021BBAB0(struct S *p, u32 a, u32 b, u32 idx);
struct State;
extern void func_021BBDA8(struct State *p, int v);
extern void func_021BACB0(char *p, int idx);
void func_021BBC68(S *p, int v)
{
    func_021BB4E0((char *)p, v, p->fe0);
    func_021BBAB0(p, p->fc, p->fe, ((struct Obj00031 *)p)->f190);
    func_021BBDA8((struct State *)p, p->f8);
    func_021BACB0((char *)p, v);
}
