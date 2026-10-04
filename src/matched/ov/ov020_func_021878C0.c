/*
 * function: func_021878C0
 * address:  0x021878C0
 * packet:   pkt_ov020_021878C0
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020433E0  0x020433E0  arm
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_0204047C  0x0204047C  arm
 *   func_020414AC  0x020414AC  arm
 *   d_02187E58     0x02187E58  data  ov020
 *   d_02187E28     0x02187E28  data  ov020
 *   d_02187E38     0x02187E38  data  ov020
 */
#include "../include/Obj19478.h"

typedef unsigned short u16;

extern char d_02187E58[];
extern char d_02187E28[];
extern char d_02187E38[];

void func_020433E0(void *p);
void func_0203F8F4(u16 heapId);
void func_0203FC28(void *p);
void func_0203FCA0(int a, void *p, int c);
void func_0204047C(int idx, unsigned short val);
void func_020414AC(int a);

void func_021878C0(char *o)
{
    func_020433E0(d_02187E58);
    func_0203F8F4(((struct Obj19478 *)o)->f8);
    func_0203FC28(d_02187E28);
    func_0203FCA0(3, d_02187E38, 0);
    func_0204047C(0, 1);
    func_0204047C(3, 0);
    func_0204047C(1, 3);
    func_0204047C(2, 3);
    func_020414AC(3);
}
