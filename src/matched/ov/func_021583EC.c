/*
 * function: func_021583EC
 * address:  0x021583EC
 * packet:   pkt_021583EC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Dispatch on the record's key: an equal key goes to the
 * single-argument arm9 read, anything else to the pair form.
 *
 * symbols:
 *   func_02012B58   0x02012B58  thumb
 *   func_02012944   0x02012944  thumb
 *   func_02012950   0x02012950  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct BigObj;
extern u8 func_02012B58(const struct BigObj *p);
struct Rec44;
struct Sub24;
extern u8 *func_02012944(void *p);
extern struct Rec44 *func_02012950(struct Sub24 *p, u32 i);

int func_021583EC(void *a0, int a1)
{
    if (func_02012B58(a0) == a1)
        return (int)func_02012944(a0);

    return (int)func_02012950(a0, a1);
}

