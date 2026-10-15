/*
 * function: TR_AI_Think
 * address: 0x02187FB0
 * packet: pkt_ov096_02187FB0
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: unsigned count/u64 draw reproduce the guarded high multiply;
 *   the callee result is returned through the final flag clear, keeping r0 live.
 * symbols:
 *   VM_GetUserData 0x02011324 thumb
 *   TR_AI_ThinkSingle 0x0218814C thumb ov096
 *   TR_AI_ThinkMulti 0x02188284 thumb ov096
 *   TR_AI_GetPoke 0x0218A2FC thumb ov096
 *   BTL_POKEPARAM_IsFainted 0x021D5B68 thumb ov093
 *   GF_STANDARD_Rand 0x0203F0A8 arm
 *   _ull_mul 0x0209C054 arm
 */
#include "../include/Obj00067.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;
struct ScriptVm;
extern void *VM_GetUserData(struct ScriptVm *vm);
extern int TR_AI_ThinkSingle(u8 *, u8 *);
extern int TR_AI_ThinkMulti(u8 *, u8 *);
extern u8 *TR_AI_GetPoke(u8 *p, u8 i);
extern int BTL_POKEPARAM_IsFainted(void *m);
extern u32 GF_STANDARD_Rand(void);
int TR_AI_Think(u8 *a)
{
    u8 *p;
    u32 n;
    int candidates[3];
    u64 r;
    int result;
    p = VM_GetUserData((struct ScriptVm *)a);
    if (((struct Obj00067 *)p)->f98 == 0) {
        p[0x95] = p[0x94] ^ 1;
        return TR_AI_ThinkSingle(a, p);
    }
    if (((struct Obj00067 *)p)->f98 == 1 || ((struct Obj00067 *)p)->f98 == 2) {
        return TR_AI_ThinkMulti(a, p);
    }
    n = 0;
    for (p[0x95] = 0; p[0x95] < 6; p[0x95]++) {
        if (p[0x95] != p[0x94] && (p[0x95] & 1) != (p[0x94] & 1)) {
            if (BTL_POKEPARAM_IsFainted(TR_AI_GetPoke(p, p[0x95])) != 1)
                candidates[n++] = p[0x95];
        }
    }
    r = GF_STANDARD_Rand();
    if (n != 0)
        r = (r * n) >> 32;
    p[0x95] = candidates[r];
    result = TR_AI_ThinkSingle(a, p);
    if (result == 0)
        p[0x47] = 0;
    return result;
}
