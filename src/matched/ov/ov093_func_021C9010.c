/*
 * function: func_021C9010
 * address:  0x021C9010
 * packet:   pkt_ov093_021C9010
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021C0898  0x021C0898  thumb  ov093
 *   func_021C99A0  0x021C99A0  thumb  ov093
 *   func_021C7194  0x021C7194  thumb  ov093
 *   func_021C2128  0x021C2128  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern u8 *func_021B9934(char *p, int i);
extern int func_021D5B68(void *p);
extern int func_021C0898(int a, int b, int c, int d);
extern void func_021C99A0(int a, void *b);
extern int func_021C7194(int a, int b, int c);
extern int func_021C2128(u8 *p, u8 *a);

typedef struct {
    u32 w; u8 b4; u8 b5; u8 b6; u8 f7a : 1; u8 f7b : 1; u8 f7c : 6;
} Ent;

int func_021C9010(int p, const Ent *e)
{
    int a;

    a = (int)func_021B9934(*(char **)(p + 8), e->b5);
    if (func_021D5B68((void *)a) == 0 || e->f7b) {
        if (func_021C0898(p, a, e->b6, e->b4)) {
            func_021C99A0(p, (void *)((u8 *)e + 8));
            if (func_021C7194(p, a, e->b6))
                func_021C2128((u8 *)p, (u8 *)a);
        }
        return 1;
    }
    return 0;
}
