/*
 * function: func_0215E364
 * address: 0x0215E364
 * packet: pkt_ov010_0215E364
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200D418 0x0200D418 thumb
 *   func_02012984 0x02012984 thumb
 *   func_0200D488 0x0200D488 thumb
 *   func_0215E358 0x0215E358 thumb ov010
 */
typedef unsigned char u8;
typedef unsigned int   u32;
struct Big;
struct Blk38;
extern void *func_02012EBC(struct Big *p);
extern void *func_0200D418(void *);
struct BigObj;
extern u8 func_02012984(const struct BigObj *p);
extern u8 func_0200D488(struct Blk38 *p, u32 i);
extern void func_0215E358(int a, int b, int c);
void func_0215E364(void *a)
{
    u8 i;
    void *q;
    void *p;
    p = func_0200D418(func_02012EBC(a));
    q = (void *)func_02012984(a);
    for (i = 0; i < 2; i++) {
        if (func_0200D488(p, i) != 0) func_0215E358((int)p, (int)q, i);
    }
}
