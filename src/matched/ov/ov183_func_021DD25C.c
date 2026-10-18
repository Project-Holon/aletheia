/*
 * function: BR_CODEIN_RecordIsType2
 * address: 0x021DD25C
 * packet: pkt_ov183_021DD25C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * 2026-10-05 (D8 lane19): re-verified, status unchanged; sole blocker is arm9 callee 0x0200B98C (no witness outside the caller). Needs a label seed. Source is byte-correct; no C change possible.
 * blocker: 0x0200B98C arm9 thumb, no witness outside caller; verified Thumb EXACT C copied from ov183_func_021DCBD8.c (original BR_CODEIN_SearchBuildHeader.c), integrator-owned.
 * blocker-symbols: BattleRecModeTable 0x0209DDCC data a4
 *   typedef unsigned char u8;
 *   typedef unsigned short u16;
 *   typedef unsigned long long u64;
 *   extern const u16 BattleRecModeTable[];
 *   u64 BATTLE_REC_GetHeaderParam(char *p, int selector, int index)
 *   {
 *       int i;
 *       u16 v;
 *       switch (selector) {
 *       case 0:
 *           v = ((u16 *)p)[index];
 *           if (v > 0x289) return 0;
 *           return v;
 *       case 1: return *(u8 *)(p + index + 0x18) & 0x7F;
 *       case 2:
 *           v = *(u16 *)(p + 0x24);
 *           if (v > 0x270F) return 0x270F;
 *           return v;
 *       case 3:
 *           for (i = 0; i < 0x29; i++) {
 *               if (*(u16 *)(p + 0x26) == BattleRecModeTable[i]) return i;
 *           }
 *           return 0;
 *       case 4: return *(u64 *)(p + 0x38);
 *       case 5: return *(u8 *)(p + 0x2A);
 *       case 6: return (*(u8 *)(p + index + 0x18) & 0x80) >> 7;
 *       case 7: return *(u8 *)(p + 0x2B);
 *       default: return 0;
 *       }
 *   }
 * lever: Shared success label and final unequal exit preserve equality branches.
 * symbols:
 *   BATTLE_REC_GetHeaderParam 0x0200B98C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
extern unsigned long long BATTLE_REC_GetHeaderParam(u8 *p, int selector, int index);
int BR_CODEIN_RecordIsType2(void *p) { int result; int v; result=0; v=(int)BATTLE_REC_GetHeaderParam(p,3,0); if(v==20) goto yes; if(v==21) goto yes; if(v!=22) goto no; yes: return 1; no: return result; }
