/*
 * function: func_021CC2C0
 * address:  0x021CC2C0
 * packet:   pkt_ov093_021CC2C0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5B48  0x021D5B48  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021D805C  0x021D805C  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D7B74  0x021D7B74  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D5B48(u8 *p);
extern int func_021D5B68(void *m);
extern u8 func_021D5440(u8 *p);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C88C8(void *a, void *b);
extern u32 func_021D805C(void *s, int k);
extern int func_021D59B4(u8 *p, int k);
extern int func_021D7B74(u8 *p, u32 k);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(void *p, u32 v);

int func_021CC2C0(void *a, void *m, void *s)
{
    int id;
    u8 *r;
    u32 k;

    if (func_021D5B48(m) == 0 && func_021D5B68(m) == 0) {
        id = func_021D5440(m);
        r = (u8 *)func_021C88A4(a, 5, id);
        r[6] = id;
        r[7] = 1;
        k = func_021D805C(s, 0x3a);
        switch (k) {
        case 0xff:
            *(u16 *)(r + 4) = func_021D59B4(m, 14);
            break;
        case 0xfe:
            *(u16 *)(r + 4) = func_021D7B74(m, 2);
            break;
        case 0xfd:
            *(u16 *)(r + 4) = func_021D7B74(m, 4);
            break;
        default:
            *(u16 *)(r + 4) = k;
            break;
        }
        func_021C8838(r + 8, 2, 387);
        func_021C8860(r + 8, id);
        func_021C88C8(a, r);
        return 1;
    }
    return 0;
}
