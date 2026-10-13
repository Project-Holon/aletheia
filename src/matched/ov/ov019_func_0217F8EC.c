/*
 * function: UNION_EFF_Delete
 * address: 0x0217F8EC
 * packet: pkt_ov019_0217F8EC
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   UNION_EFF_DeleteIconGroupObjs 0x0217FCE4 thumb ov019
 *   UNION_EFF_ExitIconGroup 0x0217FBD0 thumb ov019
 *   UNION_EFF_DeleteAnimGroupObjs 0x0217FABC thumb ov019
 *   UNION_EFF_ExitAnimGroup 0x0217F9BC thumb ov019
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct E;
extern void UNION_EFF_DeleteIconGroupObjs(struct E *p);
extern void UNION_EFF_ExitIconGroup(char *p);
extern void UNION_EFF_DeleteAnimGroupObjs(u32 *p);
extern void UNION_EFF_ExitAnimGroup(char *p);
extern u32 func_020307B0(void *p);
void UNION_EFF_Delete(char *p) { if(p) { UNION_EFF_DeleteIconGroupObjs((struct E *)(p+0x20)); UNION_EFF_ExitIconGroup(p+0x20); UNION_EFF_DeleteAnimGroupObjs((u32 *)p); UNION_EFF_ExitAnimGroup(p); func_020307B0(p); } }
