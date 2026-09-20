/*
 * function: func_0202B4BC
 * address:  0x0202B4BC
 * packet:   pkt_0202B4BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * note:     re-verified 2026-09-20: MATCH; see verify output
 *
 * Blocked: the THM_CALL at +0024 to func_0202B59C has no manifest entry yet;
 * it is the last of four sites (str_020A772C resolves on `string`).  Chain:
 * 0x0202B59C needs 0x0202B64C, which needs 0x0202C070, which needs 0x0202C148 -
 * and 0x0202C148 is a DIFF (see docs/notes/pkt_0202C148.c.txt), so this row is
 * capped for this pass.  Every concrete byte reproduces.
 * symbols:
 *   str_020A772C  0x020A772C  data
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern const u8 str_020A772C[];

extern void  *func_02030734(int a, int b, int c, void *d, int e);
extern void   func_0202B584(void *p);
extern void   func_0202B59C(void *p, u32 a, u32 b);

void *func_0202B4BC(u32 a, u32 b)
{
    void *p = func_02030734(b, 0x28, 0, (void *)str_020A772C, 0xa3);

    func_0202B584(p);
    func_0202B59C(p, a, b);
    return p;
}
