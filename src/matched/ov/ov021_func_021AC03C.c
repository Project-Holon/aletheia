/*
 * function: FIELD_EFFECT_DeleteObjectMgr
 * address:  0x021AC03C
 * packet:   pkt_ov021_021AC03C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned int u32;

typedef struct {
    int f0;
    char pad[0xd0];
} E;

typedef struct {
    u32 f0;
    int f4;
    E *f8;
} U;

extern void FIELD_EFFECT_DeleteObject(E *e);
extern u32 func_020307B0(void *p);

void FIELD_EFFECT_DeleteObjectMgr(U *u)
{
    u32 i;
    for (i = 0; i < u->f0; i++) {
        if (u->f8[i].f0 != 0) {
            FIELD_EFFECT_DeleteObject(&u->f8[i]);
        }
    }
    func_020307B0(u->f8);
    func_020307B0(u);
}
