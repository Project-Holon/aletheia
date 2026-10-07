/*
 * function: func_021990A0
 * address:  0x021990A0
 * packet:   pkt_ov009_021990A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      GetClientUniqueID (natneg.o)
 *
 * 2026-10-01 (w4 research lane): closed with the vendor source shape, no stand-ins. The Debug
 *   build of natneg.o (same 4.0.0.1025 stamp) branches over the generator block and reloads
 *   ClientUniqueID for the return, and the .debug_line rows (72 if, 74 seed, 75 both argument
 *   constants, 78 return) give `if (ClientUniqueID == 0) { seed; ClientUniqueID =
 *   RandInt(1, 0x7fffffff); } return ClientUniqueID;`. The earlier `if (x) return x;` early
 *   return kept `mov r0,#1` in the same extended block as the bound, so 1.1p1 derived it as
 *   `sub r1,r0,#0x80000002`; inside the if block it selects `mvn r1,#0x80000000`. Every earlier
 *   enum/clamp/pointer spelling is superseded. ClientUniqueID is the global .bss int at
 *   negotiateList+0x14: the twelve 4-byte .bss variables of natneg.o are defined here (DWARF
 *   names and types; static where the object symbol is local) in the order that makes 1.1p1
 *   lay them out at the vendor offsets, so the access goes through the section base like the
 *   vendor's. An extern struct at the anchor instead reloads the field after the store.
 *
 * symbols:
 *   func_0217F264     0x0217F264  arm  ov009
 *   func_0217F790     0x0217F790  arm  ov009
 *   func_0217F7AC     0x0217F7AC  arm  ov009
 *   negotiateList     0x021AE698  data
 *   Matchup3Hostname  0x021AE69C  data
 *   natMappingScheme  0x021AE6A0  data
 *   natifyCallback    0x021AE6A4  data
 *   natifyStartTime   0x021AE6A8  data
 *   ClientUniqueID    0x021AE6AC  data
 *   Matchup2Hostname  0x021AE6B0  data
 *   Matchup1Hostname  0x021AE6B4  data
 *   activeNatify      0x021AE6B8  data
 *   matchup3ip        0x021AE6BC  data
 *   matchup2ip        0x021AE6C0  data
 *   matchup1ip        0x021AE6C4  data
 */

struct DArrayImplementation;
typedef struct DArrayImplementation *DArray;
struct _NAT;
typedef enum { NAT_MAPPING_UNKNOWN } NatMappingScheme;

extern unsigned int func_0217F264(void);
extern void func_0217F790(unsigned long seed);
extern unsigned int func_0217F7AC(unsigned int min, unsigned int max);

unsigned int matchup2ip = 0;
unsigned int matchup3ip = 0;
static int activeNatify = 0;
char *Matchup1Hostname = 0;
char *Matchup2Hostname = 0;
int ClientUniqueID = 0;
static unsigned int natifyStartTime = 0;
void (*natifyCallback)(int, struct _NAT) = 0;
static NatMappingScheme natMappingScheme = 0;
char *Matchup3Hostname = 0;
DArray negotiateList = 0;
unsigned int matchup1ip = 0;

int func_021990A0(void)
{
    if (ClientUniqueID == 0)
    {
        func_0217F790(func_0217F264());
        ClientUniqueID = func_0217F7AC(1, 0x7fffffff);
    }
    return ClientUniqueID;
}
