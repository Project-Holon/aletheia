/*
 * function: func_02008F08
 * address:  0x02008F08
 * packet:   pkt_02008F08
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   MAIL_FileName      0x020A716C  data
 */

extern char MAIL_FileName[];
typedef unsigned short u16;
typedef unsigned int   u32;
struct Sub02008EACObj;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02008EAC(struct Sub02008EACObj *obj);
void *func_02008F08(int a0)
{
    void *p = func_02030734((unsigned short)((a0 & 0x7fff) | 0x8000), 0x38, 0, MAIL_FileName, 0x87);
    func_02008EAC(p);
    return p;
}
