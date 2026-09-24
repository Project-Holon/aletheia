/*
 * function: func_0216DFAC
 * address:  0x0216DFAC
 * packet:   pkt_0216DFAC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030EAC  0x02030EAC  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02030EAC();

int func_0216DFAC(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = a0 + 0x84;
a0 = *(int *)((char *)a0);
    if (a0 == 0) goto loc_0216DFC2;
loc_0216DFB8:
    a0 = func_02030EAC();
loc_0216DFBC:
a0 = 0;
t4 = t4 + 0x84;
*(int *)((char *)t4) = a0;
loc_0216DFC2:
    return a0;}
