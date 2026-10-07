/*
 * file:     unit_02175C40_p06.c
 * unit:     yes
 * function: func_02176200, func_0217620C, func_02176230
 * address:  0x02176200
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02175B14 0x02175B14 thumb ov011
 *   func_02026478 0x02026478 thumb
 *   func_02012B58 0x02012B58 thumb
 */
struct BigObj;
typedef unsigned char u8;

typedef unsigned int u32;

extern int func_02175B14(u8 *p);
extern u32 func_02026478(void *p);
extern u8 func_02012B58(const struct BigObj *p);
void func_02176200(char *p);
int func_0217620C(u8 *p, int key);
u8 func_02176230(u8 *p, u8 *q);

void func_02176200(char *p)
{
    p[0x1a3] = 0;
}

/*
 * extent: two alignment bytes at 0217622E.
 */
int func_0217620C(u8 *p, int key)
{
    if (func_02175B14(p) == 0) return 0;
    if (p[0xa0] == key) return 1;
    return 0;
}

/*
 * extent: two alignment bytes at 02176256.
 * interface: original +0x1A/+0x1C narrows the full-width call result;
 * the callee's filed u8 return removes this pair (r2: DIFF 9 bytes).
 */
u8 func_02176230(u8 *p, u8 *q)
{
    if (func_02175B14(q) == 0) {
        return (int)func_02012B58((const void *)func_02026478(((void **)p)[1]));
    }
    return q[0xa0];
}
