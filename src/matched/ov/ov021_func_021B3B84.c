/*
 * function: func_021B3B84
 * address:  0x021B3B84
 * packet:   pkt_ov021_021B3B84
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B3B84 0x021B3B84 thumb
 *   func_02031140 0x02031140 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 */

extern void func_02031140(void *);
extern void func_0201ED04(void *);
extern void func_02045808(void *);
extern void func_02045C04(void *);

void func_021B3B84(char *p)
{
    func_02031140(*(void **)(p + 436));
    func_0201ED04(*(void **)(p + 400));
    func_02045808(*(void **)(p + 412));
    func_02045808(*(void **)(p + 408));
    func_02045808(*(void **)(p + 416));
    func_02045808(*(void **)(p + 404));
    func_02045C04(*(void **)(p + 392));
    func_02045C04(*(void **)(p + 396));
}
