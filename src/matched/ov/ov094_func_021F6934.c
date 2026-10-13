/*
 * function: func_021F6934
 * address:  0x021F6934
 * packet:   pkt_ov094_021F6934
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Lever: the element address is `i * 16 + (u32)o->arr[j]` (integer first);
 * `&o->arr[j][i]` is normalised pointer-first and swaps the add operands.
 *
 * symbols:
 *   G3D_SYSTEM_LoopObjectAnimeFrame  0x02047910  arm
 *   func_021F9364  0x021F9364  thumb  ov094
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int kind;       /* 0x00 */
    int f4;
    int f8;
    int fc;
} Ent;

typedef struct {
    int f0;
    int n;              /* 0x04 */
    Ent *arr[2];        /* 0x08 */
    char pad10[0x24 - 0x10];
    void *h[2];         /* 0x24 */
    char pad2c[0xa4 - 0x2c];
    char sub[0x10];     /* 0xa4 */
} Obj;

extern int G3D_SYSTEM_LoopObjectAnimeFrame(void *a, int idx, int amount);
extern void func_021F9364(void *p);

void func_021F6934(Obj *o)
{
    int i;
    int j;
    int amt;

    if (o->n != 0) {
        for (i = 0; i < o->n; i++) {
            for (j = 0; j < 2; j++) {
                Ent *e;

                e = (Ent *)(i * 16 + (u32)o->arr[j]);
                amt = 0;
                switch (e->kind) {
                case 0:
                    amt = 0x1000;
                    break;
                case 1:
                    if (e->f4 == 1) {
                        amt = e->f8;
                        e->fc--;
                        if (((Ent *)(i * 16 + (u32)o->arr[j]))->fc == 0)
                            ((Ent *)(i * 16 + (u32)o->arr[j]))->f4 = 0;
                    }
                    break;
                }
                if (amt != 0)
                    G3D_SYSTEM_LoopObjectAnimeFrame(o->h[j], (u16)i, amt);
            }
        }
    }
    func_021F9364(o->sub);
}
