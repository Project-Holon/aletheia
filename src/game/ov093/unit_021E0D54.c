/*
 * file:     unit_021E0D54.c
 * function: func_021E0D54, func_021E0DB8
 * address:  0x021E0D54
 * packet:   pkt_ov093_021E0D54
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   d_021F26FC     0x021F26FC  data   ov093  a4
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C7D00  0x021C7D00  thumb  ov093
 *   func_021C7F68  0x021C7F68  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
extern int func_021C7D00(u8 *p, int b);
extern u8 func_021C7F68(int *p, int b, u8 *out);

void func_021E0D54(int unused, void *q, int id)
{
    u8 *r;
    int k;

    if (id == BTL_EVENT_GetVar(3)) {
        r = (u8 *)func_021C88A4(q, 0x10, id);
        k = 0x10;
        r[4] = func_021C7F68(q, (u16)((k << 7) | func_021C7D00(q, id)), r + 5);
        func_021C88C8(q, r);
        r = (u8 *)func_021C88A4(q, 4, id);
        func_021C8838(r + 4, 1, 0x65);
        func_021C88C8(q, r);
    }
}


extern int d_021F26FC[];
int *func_021E0DB8(int *p);

int *func_021E0DB8(int *p)
{
    *p = 1;
    return d_021F26FC;
}
