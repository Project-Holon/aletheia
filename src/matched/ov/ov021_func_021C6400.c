/*
 * function: FIELD_G3DOBJ_Delete
 * address:  0x021C6400
 * packet:   pkt_ov021_021C6400
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_G3DOBJ_DestroyObject  0x021C6A90  thumb  ov021
 *   FIELD_G3DOBJ_FreeResource  0x021C6940  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 kind : 2;
    u32 rest : 30;
    u16 f4;
    u16 f6;
    u8 pad8[0x3C];
    void *f44;
    u8 pad48[0x20];
} Elem;

typedef struct {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    u8 *f8;
    Elem *fC;
} Mgr;

extern void FIELD_G3DOBJ_DestroyObject(u32 *p, u8 *q);
extern void FIELD_G3DOBJ_FreeResource(u8 *p);
extern u32 func_020307B0(void *p);

void FIELD_G3DOBJ_Delete(Mgr *m)
{
    u32 i;
    Elem *e;
    u8 *s;

    i = 0;
    m->f2 = 0;
    e = m->fC;
    if (i < m->f6)
        for (; i < m->f6; i++) {
            if (e->kind == 1 && e->f44 != 0)
                FIELD_G3DOBJ_DestroyObject((u32 *)e, m->f8 + e->f4 * 0x2c);
            e++;
        }
    func_020307B0(m->fC);
    i = 0;
    s = m->f8;
    if (i < m->f4)
        for (; i < m->f4; i++) {
            FIELD_G3DOBJ_FreeResource(s);
            s += 0x2c;
        }
    func_020307B0(m->f8);
    func_020307B0(m);
}
