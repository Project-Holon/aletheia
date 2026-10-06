/*
 * function: func_02157E8C
 * address:  0x02157E8C
 * packet:   pkt_02157E8C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_0203CEAC  0x0203CEAC  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_020307B0(void *p);
extern int func_0203CEAC(int a0);

int func_02157E8C(void *a0)
{

    a0 = (void *)func_020307B0(a0);
loc_02157E92:
a0 = 0;
    a0 = (void *)func_0203CEAC((int)a0);
loc_02157E98:
    return (int)a0;}
