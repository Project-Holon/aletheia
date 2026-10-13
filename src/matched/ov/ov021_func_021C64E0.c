/*
 * function: FIELD_G3DOBJ_DrawAll
 * address:  0x021C64E0
 * packet:   pkt_ov021_021C64E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   G3D_SYSTEM_DrawObjectCulling  0x02047AC8  arm
 *   G3D_SYSTEM_DrawObject  0x02047A60  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 kind : 2;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
    u32 b5 : 1;
    u32 rest : 26;
    u16 f4;
    u16 f6;
    u8 f8[0x3C];
    void *f44;
    u8 pad48[0x20];
} Elem;

typedef struct {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    void *f8;
    Elem *fC;
} Mgr;

struct Arg;
extern int G3D_SYSTEM_DrawObjectCulling(void *a0, struct Arg *a1);
extern void G3D_SYSTEM_DrawObject(void *a0, struct Arg *a1);

void FIELD_G3DOBJ_DrawAll(Mgr *m)
{
    u32 i;
    Elem *e;

    e = m->fC;
    for (i = 0; i < m->f6; i++) {
        if (e->kind == 1) {
            if (e->b4 == 0 && e->b3 == 0) {
                if (e->b2 == 1)
                    G3D_SYSTEM_DrawObjectCulling(e->f44, (struct Arg *)e->f8);
                else
                    G3D_SYSTEM_DrawObject(e->f44, (struct Arg *)e->f8);
            }
            e->b5 = 0;
        }
        e++;
    }
}
