/*
 * function: TR_AI_Delete
 * address: 0x02188080
 * packet: pkt_ov096_02188080
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: Extent ends with two-byte zero alignment padding.
 * symbols:
 *   func_02011324 0x02011324 thumb
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_020307B0 0x020307B0 arm
 *   VM_Delete 0x02011264 thumb
 *   WAZA_TOOL_IsCacheCreated 0x0201C408 thumb
 *   WAZA_TOOL_DeleteCache 0x0201C3C0 thumb
 *   TR_AI_FreeScriptCache 0x0218A458 thumb ov096
 */
#include "../include/Obj13649.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct ScriptVm;
extern void *func_02011324(struct ScriptVm *vm);
extern void ARC_TOOL_DeleteHandle(void *);
extern u32 func_020307B0(void *p);
extern void VM_Delete(void *);
extern u32 WAZA_TOOL_IsCacheCreated(void);
extern void WAZA_TOOL_DeleteCache(void);
extern void TR_AI_FreeScriptCache(void);
void TR_AI_Delete(void *a)
{
    u8 *p;
    p = func_02011324(a);
    ARC_TOOL_DeleteHandle(((struct Obj13649 *)p)->fA4);
    ARC_TOOL_DeleteHandle(((struct Obj13649 *)p)->fA8);
    func_020307B0(p);
    VM_Delete(a);
    if (WAZA_TOOL_IsCacheCreated() == 1) WAZA_TOOL_DeleteCache();
    TR_AI_FreeScriptCache();
}
