/*
 * function: func_021D7770
 * address: 0x021D7770
 * packet: pkt_ov125_021D7770
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   d_021D9E40 0x021D9E40 data a4
 *   d_021DA040 0x021DA040 data a4
 *   func_021D8588 0x021D8588 arm ov125
 *   func_021D7CF4 0x021D7CF4 arm ov125
 *   func_021D7CD4 0x021D7CD4 arm ov125
 *   func_021D7808 0x021D7808 arm ov125
 */
typedef struct { int words[78]; } Record;
typedef struct { Record record; int f138; char pad13c[4]; char name[256]; char pad240[24]; int f258; char pad25c[16]; int f26c; } State;
extern State d_021D9E40;
extern char d_021DA040[];
extern void func_021D8588(void);
extern int func_021D7CF4(void);
extern int func_021D7CD4(void);
extern char *func_02094798(char *, const char *);
extern void func_021D7808(void);
static inline Record *copy(Record *dst, const Record *src) { *dst = *src; return dst; }
int func_021D7770(const char *a, unsigned short b, Record *src)
{
    if (src) {
        d_021D9E40.record = *src;
        d_021D9E40.f138 = 0;
    }
    func_021D8588();
    if (!func_021D7CF4()) return 0;
    func_021D7CD4();
    func_02094798(d_021D9E40.name, a);
    *(short *)(d_021DA040 + 0x40) = b;
    d_021D9E40.f258 = 0;
    d_021D9E40.f26c = -1;
    func_021D7808();
    return 1;
}
