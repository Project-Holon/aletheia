/*
 * function: func_021D5280
 * address: 0x021D5280
 * packet: pkt_ov131_021D5280
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02035C08 0x02035C08 arm
 *   d_021DC114 0x021DC114 data a1
 */
struct Rect36 { unsigned char b[36]; };
extern const struct Rect36 d_021DC114;
extern int func_02035C08(const void *key);
void func_021D5280(char *p)
{
    struct Rect36 r = d_021DC114;
    *(int *)(p + 0x24) = func_02035C08(&r);
}
