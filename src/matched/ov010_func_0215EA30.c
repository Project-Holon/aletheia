/*
 * function: func_0215EA30
 * address:  0x0215EA30
 * packet:   pkt_ov010_0215EA30
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf after func_0215E840's pool (bl from 0x0215FE3C).
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Query {
    u16 a;              /* 0x00 */
    u16 b;              /* 0x02 */
    u32 c;              /* 0x04 */
} Query;

void func_0215EA30(Query *q, u16 a, u16 b, u32 c)
{
    q->a = a;
    q->b = b;
    q->c = c;
}
