/*
 * function: func_021DEF60
 * address:  0x021DEF60
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021ECCCC  0x021ECCCC  thumb  ov170
 *   func_021ED028  0x021ED028  thumb  ov170
 *   func_021EB2A4  0x021EB2A4  thumb  ov170
 *   func_021DF11C  0x021DF11C  thumb  ov170
 *   func_021DF144  0x021DF144  thumb  ov170
 *
 * Six-step handover: stage 0xb, rebuild, refresh, push the 0x10
 *   tag word, re-tag, then release handle 3.
 */
#include "../include/Obj00000.h"
#include "../include/Obj18457.h"


extern void func_021ECCCC(char *p, void **mon, int index);
extern void func_021ED028(char *p, unsigned char *q);
extern void func_021EB2A4(char *, int);
extern void func_021DF11C(char *, int);
extern void func_021DF144(int, int);
typedef unsigned int   u32;
extern void func_02041EE4(u32 index, u32 a, u32 b);
void func_021DEF60(char *p, int a)
{
    func_021ECCCC(p, (void **)a, 0xb);
    func_021ED028((char *)(*(int *)&((struct Obj00000 *)p)->f2C), (unsigned char *)a);
    func_021EB2A4(p, a);
    func_021DF11C(p, ((struct Obj18457 *)a)->f10);
    func_021DF144(*(int *)&((struct Obj00000 *)p)->f2C, a);
    func_02041EE4(5, 3, 0);
}
