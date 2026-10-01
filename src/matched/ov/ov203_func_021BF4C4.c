/*
 * function: func_021BF4C4
 * address: 0x021BF4C4
 * packet: pkt_ov203_021BF4C4
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BF7AC 0x021BF7AC thumb ov203
 *   func_021BF510 0x021BF510 thumb ov203
 *   d_0209DF08 0x0209DF08 data a1
 */
extern const unsigned char d_0209DF08;
extern int func_021BF7AC(char *,int);
extern void func_021BF510(char *,int,int,int,int,int,int);
void func_021BF4C4(char *p,int unused,int *record)
{
    int a,b,c;
    if(record[0]==0xFF || record[0]==d_0209DF08) {
        a=func_021BF7AC(p,record[4]);b=func_021BF7AC(p,record[5]);c=func_021BF7AC(p,record[6]);
        func_021BF510(p,record[1],record[2],record[3],a,b,c);
    }
}
