/*
 * function: ISS_SYS_Create
 * address:  0x0202B4BC
 * packet:   pkt_0202B4BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blocked: the THM_CALL at +0024 to ISS_SYS_Setup has no manifest entry yet;
 * it is the last of four sites (ISS_SYS_FileName resolves on `string`).  Chain:
 * 0x0202B59C needs 0x0202B64C, which needs 0x0202C070, which needs 0x0202C148 -
 * and 0x0202C148 is a DIFF (see docs/notes/pkt_0202C148.c.txt), so this row is
 * capped for this pass.  Every concrete byte reproduces.
 * symbols:
 *   ISS_SYS_FileName  0x020A772C  data
 *   ISS_SYS_Setup  0x0202B59C  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern const u8 ISS_SYS_FileName[];

typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void   func_0202B584(void *p);
struct SaveBlock;
extern void ISS_SYS_Setup(u8 *p, struct SaveBlock *a, u32 b);

void *ISS_SYS_Create(struct SaveBlock *a, u32 b)
{
    void *p = func_02030734(b, 0x28, 0, (void *)ISS_SYS_FileName, 0xa3);

    func_0202B584(p);
    ISS_SYS_Setup(p, a, b);
    return p;
}
