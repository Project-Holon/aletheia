/*
 * function: func_02029DFC
 * address:  0x02029DFC
 * packet:   pkt_02029DFC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  02028900 label
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


struct BigObj;
extern u32 func_02012A30(const struct BigObj *p);
extern void *func_02028900(void *p);

void *func_02029DFC(const void *p)
{
    return func_02028900((void *)func_02012A30(p));
}
