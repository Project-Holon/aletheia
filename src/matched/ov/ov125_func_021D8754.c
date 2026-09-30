/*
 * function: func_021D8754
 * address: 0x021D8754
 * packet: pkt_ov125_021D8754
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * lever: The source Data pointer is non-const; const swaps the initial
 * strh lr,[sp] and mov r4,r1 (six concrete bytes differ).
 * symbols:
 *   func_021D7A10 0x021D7A10 arm ov125
 */
typedef struct { unsigned words[4]; } Data;
typedef struct { unsigned short a,b; Data data; unsigned tail[2]; } Packet;
extern int func_021D7A10(int, const void *, int, int);
int func_021D8754(Data *data, int n) {
 Packet p;
 p.a = 0;
 p.data = *data;
 p.a = 0; p.b = 0;
 return func_021D7A10(0x55f1, &p, n, -1);
}
