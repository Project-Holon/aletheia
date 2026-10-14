/*
 * function: func_021BD5F4
 * address:  0x021BD5F4
 * packet:   pkt_ov217_021BD5F4
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   RESEARCH_COMMON_GetHeapId  0x021C09AC  thumb  ov217
 *   func_021BFA14  0x021BFA14  thumb  ov217
 *   func_021BFA30  0x021BFA30  thumb  ov217
 *   func_021BF74C  0x021BF74C  thumb  ov217
 *   func_021BF754  0x021BF754  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;
extern u32 RESEARCH_COMMON_GetHeapId(void *p);
extern u32 func_021BFA14(u32 a0);
extern void func_021BFA30(char *p);
extern void func_021BF74C(void *a, void *b);
extern void func_021BF754(void *p, u32 v);

void *func_021BD5F4(void *p)
{
    void *r;
    void *a;
    a = (void *)RESEARCH_COMMON_GetHeapId(p);
    r = (void *)func_021BFA14((u32)a);
    func_021BFA30(r);
    func_021BF74C(r, a);
    func_021BF754(r, (u32)p);
    return r;
}
