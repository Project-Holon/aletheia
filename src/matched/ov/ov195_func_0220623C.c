/*
 * function: func_0220623C
 * address:  0x0220623C
 * packet:   pkt_0220623C
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MCSS_SetVanishFlag 0x02015EA0 thumb
 *   MCSS_Del 0x02015BA4 thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Owner {
    u8 pad00[0x4c];
    void *sys;
    void *obj[2];
} Owner;

extern void MCSS_SetVanishFlag(void *obj);
extern void MCSS_Del(void *sys, void *obj);

void func_0220623C(Owner *o)
{
    u8 i;

    for (i = 0; i < 2; i++) {
        if (o->obj[i] != 0) {
            MCSS_SetVanishFlag(o->obj[i]);
            MCSS_Del(o->sys, o->obj[i]);
        }
    }
}
