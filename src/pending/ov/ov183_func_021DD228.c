/*
 * function: func_021DD228
 * address: 0x021DD228
 * packet: pkt_ov183_021DD228
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: MATCH*
 * blocker: 0x0200B98C arm9 thumb, no witness outside caller; verified Thumb EXACT C copied from ov183_func_021DCBD8.c (original ov183_func_021DF838.c), Ilias-owned.
 * blocker-symbols: func_0200B98C_Table 0x0209DDCC data a4
 *   typedef unsigned char u8;
 *   typedef unsigned short u16;
 *   typedef unsigned long long u64;
 *   extern const u16 func_0200B98C_Table[];
 *   u64 func_0200B98C(char *p, int selector, int index)
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
 *               if (*(u16 *)(p + 0x26) == func_0200B98C_Table[i]) return i;
 *           }
 *           return 0;
 *       case 4: return *(u64 *)(p + 0x38);
 *       case 5: return *(u8 *)(p + 0x2A);
 *       case 6: return (*(u8 *)(p + index + 0x18) & 0x80) >> 7;
 *       case 7: return *(u8 *)(p + 0x2B);
 *       default: return 0;
 *       }
 *   }
 * symbols:
 *   func_0200B98C 0x0200B98C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
extern u64 func_0200B98C(void *,int,int);
int func_021DD228(void *p) { switch((int)func_0200B98C(p,3,0)) { case 16: case 17: case 18: case 19: case 22: return 1; case 20: case 21: default: return 0; } }
