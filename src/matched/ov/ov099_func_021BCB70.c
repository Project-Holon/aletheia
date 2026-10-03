/*
 * function: func_021BCB70
 * address: 0x021BCB70
 * packet: pkt_ov099_021BCB70
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02012934 0x02012934 thumb
 *   func_0201A090 0x0201A090 thumb
 */
typedef unsigned int u32;
struct BigObj;
extern void *func_02012934(const struct BigObj *);
extern int func_0201A090(void *, void *, u32 *);
int func_021BCB70(void *rules, const struct BigObj *obj, u32 *mask)
{
    *mask = 0;
    return func_0201A090(rules, func_02012934(obj), mask);
}
