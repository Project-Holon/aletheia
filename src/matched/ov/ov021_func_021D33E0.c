/*
 * function: FIELD_PALACE_SYS_Delete
 * address:  0x021D33E0
 * packet:   pkt_ov021_021D33E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_020307B0(void *p);

void FIELD_PALACE_SYS_Delete(u32 *p)
{
    if (p[2] != 0) {
        func_020307B0((void *)p[2]);
    }
    func_020307B0(p);
}
