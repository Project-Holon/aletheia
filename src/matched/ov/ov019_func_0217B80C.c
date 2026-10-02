/*
 * function: func_0217B80C
 * address: 0x0217B80C
 * packet: pkt_ov019_0217B80C
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: follower 0217B83C already has its own source and shard.
 * symbols:
 *   func_02012138 0x02012138 thumb
 *   func_02026474 0x02026474 thumb
 *   func_0217413C 0x0217413C thumb ov012
 */
extern void *func_02012138(void *);
extern char *func_02026474(void *);
extern int func_0217413C(int, int, unsigned char *);
int func_0217B80C(int a, int b)
{
    char *p;
    char *q;
    int result;
    p = func_02026474(func_02012138((void *)a));
    result = 0;
    q = p + 0x3548;
    if (*(int *)(q + 4) != 0 && *(int *)q == 0) result = func_0217413C(a, b, (unsigned char *)p);
    return result;
}
