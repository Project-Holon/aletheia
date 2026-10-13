/*
 * function: BTL_SERVER_Delete
 * address:  0x021BAB5C
 * packet:   pkt_ov093_021BAB5C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   STRBUF_Delete  0x02045808  arm
 *   func_020307B0  0x020307B0  arm
 *   BTL_SERVER_FLOW_Destroy  0x021BBB48  thumb  ov093
 *   BTL_ADAPTER_Delete  0x021EEAE0  thumb  ov093
 */
#include "../include/Obj07749.h"
#include "../include/Obj13289.h"

typedef unsigned char  u8;
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void BTL_SERVER_FLOW_Destroy(u8 *p);
extern void BTL_ADAPTER_Delete(void *p);

void BTL_SERVER_Delete(int a)
{
    int i;
    char *p = (char *)a;
    STRBUF_Delete((struct U16Vec *)(((struct Obj13289 *)p)->fAC));
    BTL_SERVER_FLOW_Destroy((u8 *)(((struct Obj13289 *)p)->f44));
    for (i = 0; i < 4; i++) {
        unsigned char *e = (unsigned char *)p + i * 0xc;
        if (e[0x1f] != 0xff && ((struct Obj07749 *)e)->f14 != 0 && e[0x1e] == 0)
            BTL_ADAPTER_Delete((void *)(((struct Obj07749 *)e)->f14));
    }
    func_020307B0((void *)a);
}
