/*
 * function: func_0217B80C
 * address: 0x0217B80C
 * packet: pkt_ov019_0217B80C
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: follower 0217B83C already has its own source and shard.
 * symbols:
 *   func_02012138 0x02012138 thumb
 *   func_02026474 0x02026474 thumb
 *   func_0217413C 0x0217413C thumb ov012
 */
struct Ctx;
extern unsigned int func_02012138(const struct Ctx *p);
typedef unsigned int   u32;
extern u32 func_02026474(void *obj);
extern int func_0217413C(int, int, unsigned char *);
int func_0217B80C(int a, int b)
{
    char *p;
    char *q;
    int result;
    p = (char *)func_02026474((void *)func_02012138((const struct Ctx *)a));
    result = 0;
    q = p + 0x3548;
    if (*(int *)(q + 4) != 0 && *(int *)q == 0) result = func_0217413C(a, b, (unsigned char *)p);
    return result;
}
