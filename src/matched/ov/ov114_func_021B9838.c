/*
 * function: NHTTP_RAP_Destroy
 * address:  0x021B9838
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   NHTTP_RAP_FreePostData  0x021B99B8  thumb  ov114
 *
 *
 * Frees the record's buffer, then the record itself.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void NHTTP_RAP_FreePostData(u8 *);
extern u32 func_020307B0(void *p);

void NHTTP_RAP_Destroy(u8 *p)
{
    if (p == 0)
        return;
    NHTTP_RAP_FreePostData(p);
    func_020307B0(p);
}
