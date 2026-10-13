/*
 * function: DELIVERY_BEACON_Delete
 * address:  0x02157938
 * packet:   pkt_02157938
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   DELIVERY_BEACON_Delete  0x02157938  thumb
 *   func_020307B0  0x020307B0  arm
 *   GFL_NET_Exit  0x0203CEAC  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_020307B0(void *p);
extern int GFL_NET_Exit(int a0);

int DELIVERY_BEACON_Delete(void *a0)
{

    a0 = (void *)func_020307B0(a0);
loc_0215793E:
a0 = 0;
    a0 = (void *)GFL_NET_Exit((int)a0);
loc_02157944:
    return (int)a0;}
