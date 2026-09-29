/*
 * function: func_021C95D0
 * address:  0x021C95D0
 * packet:   pkt_ov093_021C95D0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C961C  0x021C961C  thumb  ov093
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021C99A0  0x021C99A0  thumb  ov093
 *   func_021C2314  0x021C2314  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021C961C(int a, u8 b);
extern int func_021B9934(int a, u8 b);
extern int func_021D5B68(void *p);
extern void func_021C99A0(int a, void *b);
extern void func_021C2314(int a, int b);

typedef struct { u32 w; u8 b4; u8 b5; } Ent;

int func_021C95D0(int p, const Ent *e)
{
    int a;

    if (func_021C961C(p + 0x1ab8, e->b4)) {
        a = func_021B9934(*(int *)(p + 8), e->b4);
        if (func_021D5B68((void *)a) == 0 || e->b5) {
            func_021C99A0(p, (void *)((u8 *)e + 8));
            func_021C2314(p, a);
            return 1;
        }
    }
    return 0;
}
