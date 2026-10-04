/*
 * function: func_0215843C
 * address: 0x0215843C
 * packet: pkt_ov010_0215843C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two zero alignment bytes at 0x02158466 precede 0x02158468.
 * lever: A named u8 id truncates the result in r0 before preparing r1.
 * symbols:
 *   func_02026478 0x02026478 thumb
 *   func_02012B70 0x02012B70 thumb
 *   func_02012B80 0x02012B80 thumb
 *   func_021583EC 0x021583EC thumb ov010
 *   func_0200855C 0x0200855C thumb
 */
typedef unsigned char u8;
typedef unsigned int   u32;
extern u32 func_02026478(void *obj);
struct BigObj;
struct Sub0200852CObj;
extern u8 func_02012B70(const struct BigObj *p);
extern int func_02012B80(void *);
extern int func_021583EC(void *a0, int a1);
extern u8 func_0200855C(const struct Sub0200852CObj *obj);
int func_0215843C(void *p)
{
    void *q = (void *)func_02026478(p);
    u8 id;
    if (func_02012B70(q) == 0)
        return 21;
    id = func_02012B80(q);
    return func_0200855C((const struct Sub0200852CObj *)func_021583EC(q, id));
}
