/*
 * function: FLD_FACEUP_Finish
 * address: 0x021649C8
 * packet: pkt_ov010_021649C8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAMESYSTEM_GetFieldMap 0x0201210C thumb
 *   FLD_FACEUP_Delete 0x021F5578 thumb ov082
 *   SCRIPT_WORK_ResetCheckFlag 0x02159168 thumb ov010
 *   func_02034A5C 0x02034A5C arm
 *   ov_id_52 0x00000052 data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void FLD_FACEUP_Delete(u8 *p);
extern void SCRIPT_WORK_ResetCheckFlag(int);
extern void func_02034A5C(int handle);
extern u8 ov_id_52[];
int FLD_FACEUP_Finish(void **p){FLD_FACEUP_Delete(GAMESYSTEM_GetFieldMap(*p));SCRIPT_WORK_ResetCheckFlag(7);func_02034A5C((int)ov_id_52);return 1;}
