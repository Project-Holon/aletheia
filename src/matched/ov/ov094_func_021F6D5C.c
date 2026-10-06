/*
 * function: func_021F6D5C
 * address:  0x021F6D5C
 * packet:   pkt_ov094_021F6D5C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Lever: the `adds r6, r4, #0` before the loop is a zero (r4 is 0 there) that
 * the loop-back branch skips; it is the constant 0 (default amount and the
 * cleared field), not a copy of i. Flags word is a bitfield (lsls/lsrs).
 *
 * symbols:
 *   func_02047910  0x02047910  arm
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
    Ent *arr;           /* 0x08 */
    char pad0c[0x0c];
    void *h18;          /* 0x18 */
    char pad1c[0x58 - 0x1c];
    char sub[0x10];     /* 0x58 */
    u32 bit0 : 1;       /* 0x68 */
    u32 bit1 : 1;
} Obj;

extern int func_02047910(void *a, int idx, int amount);
extern void func_021F9364(void *p);

void func_021F6D5C(Obj *o)
{
    int i;
    int amt;

    if (o->bit1) {
        o->bit1 = 0;
        return;
    }
    if (o->n != 0) {
        for (i = 0; i < o->n; i++) {
            Ent *e;

            e = &o->arr[i];
            amt = 0;
            switch (e->kind) {
            case 0:
                amt = 0x1000;
                break;
            case 1:
                if (e->f4 == 1) {
                    amt = e->f8;
                    e->fc--;
                    if (o->arr[i].fc == 0)
                        o->arr[i].f4 = 0;
                }
                break;
            }
            if (amt != 0)
                func_02047910(o->h18, (u16)i, amt);
        }
    }
    func_021F9364(o->sub);
}
