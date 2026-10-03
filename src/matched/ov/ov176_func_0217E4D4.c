/*
 * function: func_0217E4D4
 * address: 0x0217E4D4
 * packet: pkt_ov176_0217E4D4
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Entry;
struct Link;
extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(struct Link *);
void func_0217E4D4(u32 a, void *b, void *c, u8 *p, struct Entry *e)
{
    if (e == func_020399A8()) {
        if (a != func_0203D1A4((struct Link *)func_020399A8()))
            *(u32 *)(p + 0x1014) = 1;
    }
}
