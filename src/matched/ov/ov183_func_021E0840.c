/*
 * function: func_021E0840
 * address: 0x021E0840
 * packet: pkt_ov183_021E0840
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FC124 0x021FC124 thumb ov186
 *   func_02034714 0x02034714 arm
 *   d_021E3978 0x021E3978 data ov183
 */
struct Triple { int a, b, c; };
extern int func_021FC124(void *, int, struct Triple *);
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern char d_021E3978[];
void func_021E0840(char *p)
{
    struct Triple t;
    if (!func_021FC124(*(void **)(p + 0x344), 11, &t)) func_02034714(d_021E3978, 0, d_021E3978);
    *(int *)(p + 0x260) = t.c;
    *(int *)(p + 0x26c) = t.b;
    *(int *)(p + 0x284) = t.a;
    if (!func_021FC124(*(void **)(p + 0x344), 12, &t)) func_02034714(d_021E3978, 0, d_021E3978);
    *(int *)(p + 0x268) = t.c;
    *(int *)(p + 0x274) = t.b;
    *(int *)(p + 0x28c) = t.a;
    if (!func_021FC124(*(void **)(p + 0x344), 6, &t)) func_02034714(d_021E3978, 0, d_021E3978);
    *(int *)(p + 0x264) = t.c;
    *(int *)(p + 0x270) = t.b;
    *(int *)(p + 0x288) = t.a;
}
