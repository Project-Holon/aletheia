/*
 * function: func_021C4954
 * address:  0x021C4954
 * packet:   pkt_ov021_021C4954
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
    u16 id;
} S;

typedef unsigned char  u8;
extern u32 func_020508EC(u8 *p, int i, u16 *out);
extern void func_021AC154(void *a);

void func_021C4954(void *a, S *s)
{
    u32 tmp;

    if (func_020508EC((u8 *)s->p[1], s->id, (u16 *)(&tmp)) != 0)
        func_021AC154(a);
}
