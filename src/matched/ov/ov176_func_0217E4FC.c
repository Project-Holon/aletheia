/*
 * function: func_0217E4FC
 * address:  0x0217E4FC
 * packet:   pkt_ov176_0217E4FC
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020399A8   0x020399A8  arm
 *   func_0203D1A4   0x0203D1A4  arm
 *   func_02034714   0x02034714  arm
 *   d_0217E64C      0x0217E64C  data  ov176
 */
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern unsigned int func_0203D1A4(struct Link *p);
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern char d_0217E64C[];

int func_0217E4FC(int a, int b)
{
    if (a == func_0203D1A4((struct Link *)func_020399A8())) {
        func_02034714(d_0217E64C, 0, d_0217E64C);
        return 0;
    }
    return b + 6;
}
