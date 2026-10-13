/*
 * function: ARC_UTIL_LoadMultiCellBankFromArchive
 * address:  0x0204A03C
 * packet:   pkt_0204A03C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   ARC_UTIL_LoadMember  0x0204A1BC  arm
 *   func_02062670  0x02062670  arm
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern int ARC_UTIL_LoadMember(int a0, int a1, int a2, int a3);
extern int   func_02062670(void *ptr, u32 val);
extern u32 func_020307B0(void *p);

void *ARC_UTIL_LoadMultiCellBankFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = (void *)ARC_UTIL_LoadMember(a0, a1, a2, a4);
    if (res != 0) {
        if (!func_02062670(res, a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}
