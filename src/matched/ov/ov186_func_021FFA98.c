/*
 * packet: pkt_ov186_021FFA98
 * function: func_021FFA98, func_021FFACC, func_021FFAD8, func_021FFAE4, func_021FFAF0, func_021FFAFC, func_021FFB08
 * unit: yes
 * address: 0x021FFA98
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * region: ov186
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6A08 0x021D6A08 thumb ov125
 *   func_02034714 0x02034714 arm
 *   func_021FFB68 0x021FFB68 thumb ov186
 *   func_021FF8E4 0x021FF8E4 thumb ov186
 *   d_02200D98 0x02200D98 data a1
 */
typedef unsigned int   u32;
extern int func_021D6A08(char *p, int a, int b);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_021FFB68(char *, int);
extern void func_021FF8E4(void *, int, int);
extern const char d_02200D98[];
void func_021FFA98(char *p, int unused, char *q)
{
    if (!func_021D6A08(q, *(unsigned *)(q + 0x5b0), *(unsigned *)(q + 0x5b4)))
        func_02034714(d_02200D98, 0, d_02200D98);
    func_021FFB68(p, (int)func_021FF8E4);
}
void func_021FFACC(char *p) { *(int *)(p + 0x5b8) = 1; }
void func_021FFAD8(char *p) { *(int *)(p + 0x5bc) = 1; }
void func_021FFAE4(char *p) { *(int *)(p + 0x5c0) = 1; }
void func_021FFAF0(char *p) { *(int *)(p + 0x5c8) = 1; }
void func_021FFAFC(char *p) { *(int *)(p + 0x5c4) = 1; }
void func_021FFB08(char *p) { *(int *)(p + 0x5d8) = 1; }
