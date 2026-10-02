/*
 * function: func_021C9728
 * address: 0x021C9728
 * packet: pkt_ov093_021C9728
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of trailing alignment padding.
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021D5FC0 0x021D5FC0 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct UtilWork;
extern int func_021B9934(char *, int);
extern int func_021D5B68(void *);
extern void func_021D5FC0(struct UtilWork *, u32);
int func_021C9728(u8 *p, u8 *q)
{
    int a = func_021B9934(*(char **)(p + 8), q[8]);
    if (!func_021D5B68((void *)a)) {
        func_021D5FC0((struct UtilWork *)a, *(u32 *)(q + 4));
        return 1;
    }
    return 0;
}
