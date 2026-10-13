/*
 * function: func_021B8050
 * address:  0x021B8050
 * packet:   pkt_021B6868
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Copies the 0x70-byte word template to the stack and submits it.
 *
 * symbols:
 *   func_021BE00C  0x021BE00C  thumb  ov172
 *   GFL_NET_StartSession  0x0203CBAC  arm
 *   GFL_NET_SetLoginOption  0x0203D7BC  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u16 func_021BE00C(u16 *p);
struct Req;
extern void GFL_NET_StartSession(struct Req *req, u32 a2, u32 a3);
extern void GFL_NET_SetLoginOption(u8 a0);

typedef struct {
    u32 w[0x1c];
} Blob;

void func_021B8050(void *a, void *b)
{
    Blob s = *(Blob *)0x021C6EF4;

    func_021BE00C(a);
    GFL_NET_StartSession((struct Req *)(&s), 0, (u32)b);
    GFL_NET_SetLoginOption(0);
}
