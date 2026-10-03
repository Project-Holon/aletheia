/*
 * function: func_0217F5F0
 * address: 0x0217F5F0
 * packet: pkt_ov018_0217F5F0
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: a switch with empty sentinel and default arms retains the dead
 * comparison before the shared bitfield return.
 * symbols:
 *   func_02026478 0x02026478 thumb
 *   func_02012B58 0x02012B58 thumb
 *   func_02012950 0x02012950 thumb
 *   func_02008550 0x02008550 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 pad0[0x18];
    u16 f18;
    u8 f1A : 4;
} Ent;

typedef struct {
    u8 pad0[4];
    void *f04;
    u8 pad8[0x70 - 8];
    Ent cur;
    Ent arr[];
} Ov018Obj;

void *func_02026478(void *);
int func_02012B58(void *);
void *func_02012950(void *, int);
int func_02008550(void *);

int func_0217F5F0(Ov018Obj *p, int idx)
{
    Ent *e;
    enum Guard { ZERO, INVALID = 0xFFFF } h;

    void *sub;

    sub = func_02026478(p->f04);
    if (idx == func_02012B58(sub)) {
        e = &p->cur;
    } else {
        e = &p->arr[idx];
    }
    h = e->f18;
    switch (h) {
    case 0:
        if (func_02008550(func_02012950(func_02026478(p->f04), idx)) == 0) {
            return 3;
        }
        return 4;
    case 0xFFFF:
        break;
    default:
        break;
    }
    return e->f1A;
}
