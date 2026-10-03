/*
 * function: func_021D60A4
 * address: 0x021D60A4
 * packet: pkt_ov131_021D60A4
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201AB28 0x0201AB28 thumb
 */
typedef unsigned int u32;

extern void *func_0201AB28(void *p, u32 idx);
struct Src { int v; int pad[2]; unsigned char kind; };
int func_021D60A4(char *p)
{
    struct Src *s = *(struct Src **)(p + 8);
    switch (s->kind) {
    case 0:
        return s->v;
    case 1:
        return (int)func_0201AB28((void *)s->v, *(unsigned short *)(p + 0x18));
    case 2:
        return *(int *)(p + 0x258);
    default:
        return 0;
    }
}
