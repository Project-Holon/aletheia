/*
 * function: func_021B9C80
 * address: 0x021B9C80
 * packet: pkt_ov181_021B9C80
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9C58 0x021B9C58 thumb ov181
 */
extern void func_021B9C58(char *p, void *s, unsigned i);
#define IDX(p) (*(unsigned char *)((p) + 0x2BA))
void func_021B9C80(char *p)
{
    if (IDX(p) < *(unsigned short *)(p + 0x2B8)) {
        func_021B9C58(p, *(void **)(p + IDX(p) * 8 + 0xB8), *(int *)(p + IDX(p) * 8 + 0xBC));
        func_021B9C58(p, *(void **)(p + IDX(p) * 8 + 0xB8), *(int *)(p + IDX(p) * 8 + 0xBC) + 1);
        IDX(p)++;
    }
}
