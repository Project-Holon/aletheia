/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * function: ARC_UTIL_LoadAnimBankFromHandle, ARC_UTIL_LoadMultiAnimBankFromArchive, ARC_UTIL_LoadMultiAnimBankFromHandle
 * address:  0x0204A0FC
 * packet:   pkt_0204A03C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   ARC_UTIL_LoadHandleMember  0x0204A380  arm
 *   func_02062920  0x02062920  arm
 *   func_020307B0  0x020307B0  arm
 *   ARC_UTIL_LoadMember  0x0204A1BC  arm
 *   func_0206267C  0x0206267C  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern int ARC_UTIL_LoadMember(int a0, int a1, int a2, int a3);
extern void *ARC_UTIL_LoadHandleMember(void *a0, u32 a1, u32 a2, u32 a3);
extern int func_02062920(u32 a, u32 *out);
extern int   func_0206267C(void *ptr, u32 val);
extern u32 func_020307B0(void *p);

void *ARC_UTIL_LoadAnimBankFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = ARC_UTIL_LoadHandleMember(a0, a1, a2, a4);
    if (res != 0) {
        if (!func_02062920((u32)res, (u32 *)a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}

void *ARC_UTIL_LoadMultiAnimBankFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = (void *)ARC_UTIL_LoadMember(a0, a1, a2, a4);
    if (res != 0) {
        if (!func_0206267C(res, a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}

void *ARC_UTIL_LoadMultiAnimBankFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = ARC_UTIL_LoadHandleMember(a0, a1, a2, a4);
    if (res != 0) {
        if (!func_0206267C(res, a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}
