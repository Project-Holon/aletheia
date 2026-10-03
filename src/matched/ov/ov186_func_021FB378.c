/*
 * function: func_021FB378
 * address: 0x021FB378
 * packet: pkt_ov186_021FB378
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: 021FB3BA..021FB3BC is two zero alignment bytes.
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   func_021FB3BC 0x021FB3BC thumb ov186
 */
extern void *func_02045EC0(int, int);
struct U16Vec;
extern void func_02045808(struct U16Vec *vec);
extern void *func_021FB3BC(void *, void *, int, int, int, int, int, void *, unsigned short);
void *func_021FB378(void *ctx, int file, int a, int b, int c, int d, int e, int archive, void *config, unsigned short heap)
{
    void *data;
    void *result;
    data = func_02045EC0(archive, file);
    result = func_021FB3BC(ctx, data, a, b, c, d, e, config, heap);
    func_02045808(data);
    return result;
}
