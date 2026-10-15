/*
 * function: BR_CODEIN_ProfileDestroyObject
 * address: 0x021E0808
 * packet: pkt_ov183_021E0808
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: existing matched callback 021E083C and its alignment follow the pool.
 * symbols:
 *   func_02034714 0x02034714 arm
 *   STRBUF_Delete 0x02045808 arm
 *   func_020307B0 0x020307B0 arm
 *   d_021E3974 0x021E3974 data a4
 */
#include "../include/Obj14437.h"
typedef unsigned int   u32;
struct U16Vec;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 func_020307B0(void *p);
extern char d_021E3974[];
void BR_CODEIN_ProfileDestroyObject(char *p){if(!((struct Obj14437 *)p)->f18)func_02034714(d_021E3974,0,d_021E3974);if(!p)func_02034714(d_021E3974,0,d_021E3974);STRBUF_Delete(((struct Obj14437 *)p)->f18);func_020307B0(p);}
