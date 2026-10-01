/*
 * function: func_021BB2B4
 * address: 0x021BB2B4
 * packet: pkt_ov225_021BB2B4
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * arity: BB4F8 retains original visible r0 context although its fixed tail ignores it.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   file_021BC038 0x021BC038 data a1
 *   func_021BB400 0x021BB400 thumb ov225
 *   func_021BB4F8 0x021BB4F8 thumb ov225
 *   func_021BB3FC 0x021BB3FC thumb ov225
 *   func_020056A0 0x020056A0 thumb
 *   func_021BA068 0x021BA068 thumb ov225
 */
typedef unsigned short u16;
extern const char file_021BC038[];
extern void *func_02030734(unsigned, unsigned, int, const char *, u16);
extern void func_021BB400(char *);
extern void func_021BB4F8(char *);
extern void func_021BB3FC(void *);
extern void *func_020056A0(unsigned, unsigned, unsigned);
extern void func_021BA068(char *, unsigned);
char *func_021BB2B4(char *p, char *data)
{
    char *q;
    q = func_02030734(*(u16 *)(data + 4), 32, 1, file_021BC038, 157);
    *(char **)q = p;
    *(unsigned *)(p + 4) = 1;
    *(char **)(q + 4) = data;
    func_021BB400(q);
    func_021BB4F8(q);
    *(void **)(q + 0x14) = func_020056A0((unsigned)func_021BB3FC, (unsigned)q, 1);
    *(unsigned *)(q + 0x18) = 0;
    q[0x1c] = -1;
    func_021BA068(*(char **)(*(char **)(q + 4) + 0x34), 0);
    return q;
}
