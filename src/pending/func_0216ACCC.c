/*
 * function: func_0216ACCC
 * address:  0x0216ACCC
 * packet:   pkt_0216ACCC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocked:  
 *
 * symbols:
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200E0B0  0x0200E0B0  thumb
 *   func_0216AED0  0x0216AED0  thumb  ov010
 *   func_0217C294  0x0217C294  thumb
 *   func_0216628C  0x0216628C  thumb  ov010
 *   func_0216AF3C  0x0216AF3C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02159B10();
extern int func_02159AE8();
extern int func_0215A5E4();
extern int func_02012EBC();
extern int func_0200E0B0();
extern int func_0216AED0();
extern int func_0217C294();
extern int func_0216628C();
extern int func_0216AF3C();

int func_0216ACCC(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    int t7;

t4 = a0 + 0;
t5 = a1 + 0;
    a0 = func_02159B10();
loc_0216ACD6:
t7 = a0 + 0;
a0 = t4 + 0;
a1 = t5 + 0;
    a0 = func_02159AE8(a0, a1);
loc_0216ACE0:
t4 = a0 + 0;
a0 = t5 + 0;
    a0 = func_0215A5E4(a0);
loc_0216ACE8:
    a0 = func_02012EBC();
loc_0216ACEC:
    a0 = func_0200E0B0();
loc_0216ACF0:
t6 = a0 + 0;
a0 = t5 + 0;
a1 = t7 + 0;
    a0 = func_0216AED0(a0, a1);
loc_0216ACFA:
    if (a0 == 0) goto loc_0216AD14;
loc_0216ACFE:
    a0 = func_0217C294();
loc_0216AD02:
a1 = a0 + 0;
a0 = t6 + 0;
    a0 = func_0216628C(a0, a1);
loc_0216AD0A:
*(u16 *)((char *)t4) = a0;
a0 = t5 + 0;
    a0 = func_0216AF3C(a0);
loc_0216AD12:
    goto loc_0216AD18;
loc_0216AD14:
a0 = 0;
*(u16 *)((char *)t4) = a0;
loc_0216AD18:
a0 = 0;
    return a0;}
