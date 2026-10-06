/*
 * function: func_021BD9BC
 * address:  0x021BD9BC
 * packet:   pkt_ov021_021BD9BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021D9BC8     0x021D9BC8  data  ov021  a4
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u32 v[6]; } T6;

extern const T6 d_021D9BC8;
struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *, void *, void *, u32);
extern void *func_020124E8(struct Obj *);

int func_021BD9BC(u32 *p)
{
    T6 t = d_021D9BC8;
    u32 i;
    u32 r;

    switch (p[5]) {
    case 0:
        i = 0;
        break;
    case 1:
        i = 0;
        break;
    case 2:
        i = 2;
        break;
    case 3:
        i = 1;
        break;
    case 4:
        i = 2;
        break;
    case 5:
        i = 3;
        break;
    case 6:
        i = 5;
        break;
    default:
        i = 4;
        break;
    }
    r = (u32)func_020122C0((void *)p[1], (void *)p[0], (void *)t.v[i], 4);
    *(u32 *)func_020124E8((struct Obj *)r) = (u32)p;
    return r;
}
