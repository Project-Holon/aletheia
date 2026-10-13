/*
 * function: func_021DF838
 * address: 0x021DF838
 * packet: pkt_ov183_021DF838
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * 2026-10-05 (D8 lane19): re-verified, status unchanged; sole blocker is arm9 callee 0x0200B98C (no witness outside the caller). Needs a label seed. Source is byte-correct; no C change possible.
 * blocker: 0x0200B98C arm9 thumb, no witness outside caller; scratch one EXACT, blocker-r2.log.
 * blocker-symbols: BattleRecModeTable 0x0209DDCC data a4
+ *   typedef unsigned char u8;
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
 *       case 1:
 *           return *(u8 *)(p + index + 0x18) & 0x7F;
 *       case 2:
 *           v = *(u16 *)(p + 0x24);
 *           if (v > 0x270F) return 0x270F;
 *           return v;
 *       case 3:
 *           for (i = 0; i < 0x29; i++) {
 *               if (*(u16 *)(p + 0x26) == BattleRecModeTable[i]) return i;
 *           }
 *           return 0;
 *       case 4:
 *           return *(u64 *)(p + 0x38);
 *       case 5:
 *           return *(u8 *)(p + 0x2A);
 *       case 6:
 *           return (*(u8 *)(p + index + 0x18) & 0x80) >> 7;
 *       case 7:
 *           return *(u8 *)(p + 0x2B);
 *       default:
 *           return 0;
 *       }
 *   }
 * checks: 1 full callee reads 3 args, 64-bit return; 2 no filed twin; 3 int base/long index unchanged (2/2); 4 named base and second declaration order close DIFF (2/2); 5 fresh idiom/neighbour reread, no stack-object residue. Both reorder variants consumed.
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   BATTLE_REC_GetHeaderParam 0x0200B98C thumb
 */
extern void MI_CpuFill8(void *, int, unsigned int);
typedef unsigned char  u8;
extern unsigned long long BATTLE_REC_GetHeaderParam(u8 *p, int selector, int index);
void func_021DF838(int p, char *out)
{
    long i;
    int a, b, c;
    void *base;
    int special, n = 0;
    unsigned int count;
    MI_CpuFill8(out, 0, 0x48);
    base = (void *)(p + 0x80);
    switch ((int)BATTLE_REC_GetHeaderParam(base, 3, 0)) {
    case 16: case 17: case 18: case 19: case 22:
        special = 1;
        count = 9;
        break;
    default:
        special = 0;
        count = 6;
        break;
    }
    for (i = 0; i < count; i++) {
        if (special && i >= 3 && i <= 5) continue;
        a = BATTLE_REC_GetHeaderParam(base, 0, i);
        b = BATTLE_REC_GetHeaderParam(base, 1, i);
        c = BATTLE_REC_GetHeaderParam(base, 6, i);
        if (a >= 0x28B) a = 0;
        if (a != 0) {
            *(int *)(out + n * 4) = a;
            *(int *)(out + n * 4 + 0x18) = b;
            *(int *)(out + n * 4 + 0x30) = c;
            n++;
        }
    }
}
