/*
 * function: func_021C4B04
 * address:  0x021C4B04
 * packet:   pkt_ov021_021C4B04
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Notifies the owner when the field-object query succeeds (EXACT*:
 * follower).
 *
 * symbols:
 *   func_021AC154  0x021AC154  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 *p;
    u32 f4;
    u16 id;
} S;

extern int func_020508EC(u32 a, u32 id, void *out);
extern void func_021AC154(void *a);

void func_021C4B04(void *a, S *s)
{
    u32 tmp;

    if (func_020508EC(s->p[1], s->id, &tmp) != 0)
        func_021AC154(a);
}
