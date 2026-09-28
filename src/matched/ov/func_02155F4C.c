/*
 * function: func_02155F4C
 * address:  0x02155F4C
 * packet:   pkt_02155F4C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02156CD8  0x02156CD8  thumb  ov010
 *   func_02156F98  0x02156F98  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 *   func_021F6888  0x021F6888  thumb
 *   func_0215716C  0x0215716C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02156CD8();
extern int func_02156F98();
extern int func_020307B0();
extern int func_021F6888();
extern int func_0215716C();

int func_02155F4C(int a0, int a1)
{
    int t4;

t4 = a0 + 0;
a0 = *(int *)((char *)t4 + 0x2c);
    if (a0 == 0) goto loc_02155F5A;
loc_02155F56:
    a0 = func_02156CD8(a0);
loc_02155F5A:
a0 = *(int *)((char *)t4 + 0x30);
    if (a0 == 0) goto loc_02155F64;
loc_02155F60:
    a0 = func_02156F98(a0);
loc_02155F64:
a0 = *(int *)((char *)t4 + 0x34);
    if (a0 == 0) goto loc_02155F76;
loc_02155F6A:
a0 = *(int *)((char *)a0 + 8);
    a0 = func_020307B0(a0);
loc_02155F70:
a0 = *(int *)((char *)t4 + 0x34);
    a0 = func_020307B0(a0);
loc_02155F76:
a0 = *(int *)((char *)t4 + 0x24);
    if (a0 == 0) goto loc_02155F80;
loc_02155F7C:
    a0 = func_021F6888(a0);
loc_02155F80:
a0 = *(int *)((char *)t4 + 0x3c);
    if (a0 == 0) goto loc_02155F8A;
loc_02155F86:
    a0 = func_020307B0(a0);
loc_02155F8A:
a0 = *(int *)((char *)t4 + 0x38);
    if (a0 == 0) goto loc_02155F94;
loc_02155F90:
    a0 = func_0215716C(a0);
loc_02155F94:
a0 = *(int *)((char *)t4 + 8);
a1 = 0;
*(int *)((char *)a0) = a1;
    return a0;}
