/*
 * function: EVENTDATA_SYSTEM_SetBgEventGridPos
 * address: 0x02162A74
 * packet: pkt_ov010_02162A74
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: 46 code bytes followed by two zero alignment bytes.
 * lever: inline setter takes the whole Rec and all three payload inputs;
 * its own Payload pointer preserves the parent base and explicit +8 copy.
 * domain: unsigned index comparison and modular word address arithmetic.
 */
#include "../include/Obj18964.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 e,f,g; } Payload;
typedef struct { u16 a,b,c,d; Payload data; } Rec;
typedef struct { u8 pad[18]; u16 n; u8 pad14[8]; Rec *r; } Ctx;
static inline void set(Rec *r, u32 a, u32 b, u16 d)
{
    Payload *p = &r->data;
    ((struct Obj18964 *)r)->f8 = a;
    p->f = d;
    p->g = b << 4;
}
void EVENTDATA_SYSTEM_SetBgEventGridPos(const Ctx *c, u32 i, u32 a, u32 b, u16 d)
{
    Rec *r;
    if (c->n >= i && c->r != 0) {
        r = (Rec *)((u32)c->r + i * 20u);
        if (r->d == 0) {
            set(r, a, b, d);
        }
    }
}
