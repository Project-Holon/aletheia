/*
 * function: func_02184558
 * address: 0x02184558
 * packet: pkt_ov219_02184558
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: heap forwarded full-width without caller truncation to 3F8F4,
 * 46440 and 45088; widen their legacy narrow parameters accordingly.
 * symbols:
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_02046440 0x02046440 arm
 *   func_0204044C 0x0204044C arm
 *   func_02045088 0x02045088 arm
 *   func_0204361C 0x0204361C arm
 *   d_02185F18 0x02185F18 data ov219 a4
 */
typedef unsigned short u16;
struct DispConfig {unsigned a,b,c,d;};
extern const struct DispConfig d_02185F18;
extern void func_0203F8F4(unsigned),func_0203FC28(struct DispConfig *);
extern void func_02046440(unsigned,unsigned,unsigned,unsigned,u16,unsigned,void (*)(void));
extern void func_0204044C(unsigned),func_02045088(unsigned),func_0204361C(void);
void func_02184558(unsigned heap)
{
    struct DispConfig cfg=d_02185F18;
    func_0203F8F4(heap);func_0203FC28(&cfg);
    func_02046440(0,3,0,2,0,heap,0);
    func_0204044C(1);func_02045088(heap);func_0204361C();
}
