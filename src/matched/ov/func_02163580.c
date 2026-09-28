/*
 * function: func_02163580
 * address:  0x02163580
 * packet:   pkt_02163580
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021AB3D4  0x021AB3D4  thumb
 *   func_021AB3E0  0x021AB3E0  thumb
 *   func_021AB334  0x021AB334  thumb
 *   func_021AB328  0x021AB328  thumb
 *   func_021AB41C  0x021AB41C  thumb
 *   func_021BBDD4  0x021BBDD4  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021AB3D4();
extern int func_021AB3E0();
extern int func_021AB334();
extern int func_021AB328();
extern int func_021AB41C();
extern int func_021BBDD4();

void func_02163580(int a0, int a1, int a2)
{
    int t4;
    int t5;
    int t6;

t5 = a1 + 0;
a1 = *(u16 *)((char *)t5 + 0xc);
t6 = a0 + 0;
a0 = 8;
    if ((a0 & a1) == 0) goto loc_02163616;
loc_0216358E:
a0 = *(u16 *)((char *)t5 + 8);
t4 = 5;
    a0 = func_021AB3D4(a0);
loc_02163596:
    if (a0 == 0) goto loc_021635AE;
loc_0216359A:
a0 = *(u8 *)((char *)t5 + 0x18);
    if (a0 != 3) goto loc_02163608;
loc_021635A0:
a0 = *(int *)((char *)t5 + 0x10);
t4 = 2;
a0 = *(u8 *)((char *)a0 + 5);
    if (a0 != 2) goto loc_02163608;
loc_021635AA:
t4 = 3;
    goto loc_02163608;
loc_021635AE:
a0 = *(u16 *)((char *)t5 + 8);
    a0 = func_021AB3E0(a0);
loc_021635B4:
    if (a0 == 0) goto loc_021635CE;
loc_021635B8:
a0 = *(u8 *)((char *)t5 + 0x18);
    if (a0 == 0) goto loc_021635C2;
loc_021635BE:
    if (a0 != 3) goto loc_02163608;
loc_021635C2:
a0 = *(int *)((char *)t5 + 0x10);
t4 = 2;
a0 = *(u8 *)((char *)a0 + 5);
    if (a0 != 2) goto loc_02163608;
loc_021635CC:
    goto loc_021635AA;
loc_021635CE:
a0 = *(u16 *)((char *)t5 + 8);
    a0 = func_021AB334(a0);
loc_021635D4:
    if (a0 == 1) goto loc_021635E2;
loc_021635D8:
a0 = *(u16 *)((char *)t5 + 8);
    a0 = func_021AB328(a0);
loc_021635DE:
    if (a0 != 1) goto loc_021635EE;
loc_021635E2:
a0 = *(int *)((char *)t5 + 0x10);
t4 = 2;
a0 = *(u8 *)((char *)a0 + 5);
    if (a0 != 2) goto loc_02163608;
loc_021635EC:
    goto loc_021635AA;
loc_021635EE:
a0 = *(u16 *)((char *)t5 + 8);
    a0 = func_021AB41C(a0);
loc_021635F4:
    if (a0 != 1) goto loc_021635FC;
loc_021635F8:
t4 = 4;
    goto loc_02163608;
loc_021635FC:
a0 = *(int *)((char *)t5 + 0x10);
t4 = 0;
a0 = *(u8 *)((char *)a0 + 5);
    if (a0 != 2) goto loc_02163608;
loc_02163606:
t4 = 1;
loc_02163608:
    if (t4 == 5) goto loc_02163616;
loc_0216360C:
a1 = *(int *)((char *)t5 + 0x14);
a0 = t6 + 0;
a2 = t4 + 0;
    a0 = func_021BBDD4(a0, a1, a2);
loc_02163616:
    return;}
