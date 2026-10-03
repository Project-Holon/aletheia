/*
 * function: func_021CC350
 * address:  0x021CC350
 * packet:   pkt_ov093_021CC350
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Rec {
    int f00;
    u32 f04;
    u8 f08;
    u8 pad[11];
    u8 f14;
} Rec;

extern int func_021D5B68(void *m);
struct Unk021D62A8;
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern u8 func_021D5440(u8 *p);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C88C8(void *a, void *b);

int func_021CC350(void *a, void *m, int c, int d, u32 v)
{
    u8 id;
    Rec *r;

    if (func_021D5B68(m) == 0 && func_021D62C4(m, v) != 0) {
        id = func_021D5440(m);
        r = (Rec *)func_021C88A4(a, 11, id);
        r->f14 = 1;
        r->f08 = id;
        r->f04 = v;
        func_021C88C8(a, r);
        return 1;
    }
    return 0;
}
